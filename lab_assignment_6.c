#include <stdio.h>
#include <stdlib.h>

int search(int numbers[], int low, int high, int value) 
{ if (low <= high) //value is not found if low is bigger than high (base condition)
{
	int mid = low + (high - low) / 2; //calculating the mid of the array or (high+low)/2
	if (numbers[mid] ==value) { //seeing whether mid us equal to the value 
			return mid; 	} //if so, return 
		else if(numbers[mid] > value) {  //if not,..
			return search(numbers, low, mid-1, value);} //if value is smaller than mid, check left 
			else {
				return search(numbers, mid+1, high, value); //if value is bigger than mid, check right 
		}
}
	return -1; //value is not found in the array
}

void printArray(int numbers[], int sz)
{
	int i;
	printf("Number array : ");
	for (i = 0;i<sz;++i)
	{
		printf("%d ",numbers[i]);
	}
	printf("\n");
}

int main(void)
{
	int i, numInputs;
	char* str;
	float average;
	int value;
	int index;
	int* numArray = NULL;
	int countOfNums;
	FILE* inFile = fopen("input.txt","r");

	fscanf(inFile, " %d\n", &numInputs);
	
	while (numInputs-- > 0)
	{
		fscanf(inFile, " %d\n", &countOfNums);
		numArray = (int *) malloc(countOfNums * sizeof(int));
		average = 0;
		for (i = 0; i < countOfNums; i++)
		{
			fscanf(inFile," %d", &value);
			numArray[i] = value;
			average += numArray[i];
		}

		printArray(numArray, countOfNums);
		value = average / countOfNums;
		index = search(numArray, 0, countOfNums - 1, value);
		if (index >= 0)
		{
			printf("Item %d exists in the number array at index %d!\n",value, index);
		}
		else
		{
			printf("Item %d does not exist in the number array!\n", value);
		}

		free(numArray);
	}

	fclose(inFile);
}
