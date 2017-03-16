#include <cstdio>
#include <cstring>

typedef struct {
	char * string;
	char gotten;
	int index;
} Element;

Element elementOrder[10] = {
	{"ZERO",  'Z',0},
	{"TWO", 'W',2},
	{"SIX", 'X',6},
	{"EIGHT", 'G',8},
	{"THREE", 'H',3},
	{"FOUR", 'U',4},
	{"FIVE", 'F',5},
	{"NINE", 'I',9},
	{"SEVEN", 'V',7},
	{"ONE", 'O',1}};

char input[2001];
int calcTest()
{
	int inputSize;
	int numbers[10];
	for (int c = 0; c < 10; c++)
	{
		numbers[c] = 0;
	}
	gets(input);
	inputSize = strlen(input);
	for (int c = 0; c < 10; c++) 
	{

		int letterCount;
		letterCount = 0;
		for (int d = 0; d < inputSize; d++) // count
		{
			if (input[d] == elementOrder[c].gotten) 
			{
				letterCount++;
			}	
		}
		numbers[elementOrder[c].index] = letterCount;
		
		if (letterCount > 0) 
		{
		
			int elementSize = strlen(elementOrder[c].string);			
			for (int e = 0; e < elementSize; e++) //remove from string
			{
				int removed;
				removed = 0;
				for (int d = 0; d < inputSize; d++)
				{
					if (input[d] == elementOrder[c].string[e])
					{
						input[d] = '?';
						removed++;
						if (removed == letterCount)
						{
							break;
						}
					}
				}
			}
		}
	}
	
	
	for (int c = 0; c < 10; c++)
	{
		while(numbers[c] >0) {
			numbers[c]--;
			printf("%d",c);
		}
	}
	printf("\n");	
}


int main()
{
	int nTest;
	scanf("%d",&nTest);
	gets(input);
	for (int c = 1; c<= nTest; c++)
	{
		printf("Case #%d: ",c);
		int r = calcTest();
	}
}
