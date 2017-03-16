#include <stdio.h>
#include <stdlib.h>

int main()
{
	int numCases = 0;

	int X,Y;
	
	int i,j;

	char solution[501];

	int step = 0;

	scanf("%d",&numCases);

	for (i=0;i<numCases;i++)
	{	
		scanf("%d",&X);
		scanf("%d",&Y);

		step = 0;

		/* use successive movement to move to the goal unit by unit */
		/* first X */
		if (X<0)
		{
			for (j=0;j<-X;j++)
			/*first E then W */
			{
				solution[step++]='E';
				solution[step++]='W';
			}
		}
		else
		{
			for (j=0;j<X;j++)
			/*first W then E */
			{
				solution[step++]='W';
				solution[step++]='E';
			}
		}

		/* now Y */
		if (Y<0)
		{
			for (j=0;j<-Y;j++)
			/*first N then S */
			{
				solution[step++]='N';
				solution[step++]='S';
			}
		}
		else
		{
			for (j=0;j<Y;j++)
			/*first S then N */
			{
				solution[step++]='S';
				solution[step++]='N';
			}
		}

		solution[step++]='\0';

		printf("Case #%d: %s\n",i+1,solution);
	}

	return 0;
	
}
