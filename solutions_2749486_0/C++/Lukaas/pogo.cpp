#include <stdio.h>

int x,y;

void printNTimes(char a, char b, int n)
{
	for(int i = 0; i< n; i++)
	{
		putchar(a);
		putchar(b);
	}
}

void printResult()
{
	if(x>0) {
		printNTimes('W', 'E', x);
	}
	if(x<0) {
		printNTimes('E', 'W', -x);
	}
	if(y>0) {
		printNTimes('S', 'N', y);
	}
	if(y<0) {
		printNTimes('N', 'S', -y);
	}
}

int main()
{

	int count;
	scanf("%d", &count);

	for(int i=0; i<count; i++)
	{
		scanf("%d%d", &x, &y);

		printf("Case #%d: ", i+1);
		printResult();
		printf("\n");
	}
	return 0;
}