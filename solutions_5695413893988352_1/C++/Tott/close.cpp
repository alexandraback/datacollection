#include <cstdio>
#include <cstring>

int fitChar(char input,int number){
	if (input =='?') return 1;
	if ((input - '0') == number) return 1;
	return 0;
}


int fits(char * input1, char * input2, int output1, int output2, int begin, int size)
{
	int o2 = output2;
	int o1 = output1;
	for (int c = (begin + size); c > begin; c--) {
//		printf(".");
		if (!fitChar(input1[c-1],output1%10))
		return 0;
		if (!fitChar(input2[c-1],output2%10))
		return 0;
		output1 = output1 / 10;
		output2 = output2 / 10;
	}
//	printf("fits %s %s %d %d\n",input1, input2,o1,o2);
	return 1;
}
int betterDistance(int output1,int output2,int choosen1,int choosen2){
	int distance = output1 - output2;
	int choosenDistance = choosen1 - choosen2;
	if (distance < 0) distance = distance*(-1);
	if (choosenDistance < 0) choosenDistance = choosenDistance*( -1);
	if (distance < choosenDistance)
	{
	    return 1;
	}
	return 0;
}


void change(char * input1,char * input2,int choosen1, int choosen2, int begin, int size) {
//    printf("i1=%s i2=%s begin=%d size=%d",input1, input2,begin,size);
	if (size == 1) {
		input1[begin] = choosen1 + '0';
		input2[begin] = choosen2 + '0';
	}
	
	if (size == 2) {
		input1[begin] = (choosen1/10) + '0';
		input2[begin] = (choosen2/10) + '0';
		input1[begin+1] = (choosen1%10) + '0';
		input2[begin+1] = (choosen2%10) + '0';
	}

	if (size == 3) {
		input1[begin] = (choosen1/100) + '0';
		input2[begin] = (choosen2/100) + '0';
		input1[begin+1] = ((choosen1/10)%10) + '0';
		input2[begin+1] = ((choosen2/10)%10) + '0';
	}
//    printf("i1=%s i2=%s\n",input1, input2);


}

void printResults(char * input1,char *input2,int choosen1,int choosen2)
{
	int size = strlen(input1);
	if (size > 2) {
		input1[size-1] = choosen1%10 + '0';
		input2[size-1] = choosen2%10 + '0';
	}
	printf("%s %s\n",input1,input2);
}

void calcTest()
{
	char input1[200];
	char input2[200];
	int output1, output2;
	int choosen1;
	int choosen2;
	memset(input1,0,200);
	memset(input2,0,200);
	scanf("%s ",input1);
	gets(input2);
	int inputSize = strlen(input1);
	//printf("input = %s %s\n", input1, input2);
    int firstRound;
    int firstRoundSize;
    if (inputSize == 1) {
    	firstRound = 10;
    	firstRoundSize = 1;
	} else if (inputSize == 2) {
		firstRound = 100;
    	firstRoundSize = 2;
	} else {
		firstRound = 1000;
    	firstRoundSize = 3;
	}
	int isToBreak = 0;
	choosen1 = 0;
	choosen2 = 1000;
	for (output1 = 0; output1 < firstRound; output1++) {
		for (output2 = 0; output2 < firstRound; output2++) {
			if (fits(input1,input2,output1,output2,0,firstRoundSize))
			{
				if (betterDistance(output1,output2,choosen1,choosen2))
				{
//   				    printf("better %d %d\n",output1,output2);
					choosen1 = output1;
					choosen2 = output2;
				}
			}
			
		}
	}
	change(input1,input2,choosen1,choosen2,0,firstRoundSize);
	
	int begin;
	for (int c = 3; c < inputSize; c++) {
		choosen1 = 0;
		choosen2 = 1000;
		begin = c-2;
		for (output1 = 0; output1 < 1000; output1++) {
			for (output2 = 0; output2 < 1000; output2++) {
				if(fits(input1,input2,output1,output2,begin,3))
                {
					if (betterDistance(output1,output2,choosen1,choosen2))
					{
						choosen1 = output1;
						choosen2 = output2;
					}
				}
				
			}
		}
		change(input1,input2,choosen1,choosen2,begin,3);
	}
	
	printResults(input1,input2,choosen1,choosen2);
	

}


int main()
{
	int nTest;
	char getout[10];
	scanf("%d",&nTest);
	gets(getout);
	for (int c = 1; c<= nTest; c++)
	{
		printf("Case #%d: ",c);
		calcTest();
	}
}
