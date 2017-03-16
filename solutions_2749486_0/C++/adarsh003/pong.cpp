#include<iostream>
#include<map>
#include<vector>
#include<string>
#include<math.h>
#include<algorithm>
using namespace std;


#define MAX(Z,Y) max((Z),(Y))
#define MIN(X,Y) min((X),(Y))

FILE* fpOut;


void solve(int t, int X, int Y)
{
//traverse x
	int step = 1;
	for(int x=0;x!=X;)
	{
		int diff = X-x;
		if(diff==0)
			break;
		else if(diff>0)
		{
			if(diff>=step)
			{
				printf("%c", 'E');
				x = x+step;
			}
			else
			{
				printf("%c", 'W');
				x = x-step;
			}
		}
		else
		{
			diff = -diff;
			if(diff>=step)
			{
				printf("%c", 'W');
				x = x-step;
			}
			else
			{
				printf("%c", 'E');
				x = x+step;
			}
		}
		step++;
	}

	//traverse y
	for(int y=0;y!=Y;)
	{
		int diff = Y-y;
		if(diff==0)
		{
			printf("%c", '\n');
			break;
		}
		else if(diff>0)
		{
			if(diff>=step)
			{
				printf("%c", 'N');
				y = y+step;
			}
			else
			{
				printf("%c", 'S');
				y = y-step;
			}
		}
		else
		{
			diff = -diff;
			if(diff>=step)
			{
				printf("%c", 'S');
				y = y-step;
			}
			else
			{
				printf("%c", 'N');
				y = y+step;
			}
		}
		step++;
	}

}

int main()
{
	FILE * fpIn = fopen("B-small-attempt0.in","r");
	fpOut = stdout;
	

    int T;
	fscanf(fpIn,"%d",&T);

	for(int t=1;t<=T;t++)
	{
		int X,Y;
		fscanf(fpIn,"%d %d", &X, &Y);
		printf("Case #%d: ", t);
		solve(t,X,Y);
		printf("%c", '\n');
	}

	fclose(fpIn);

}
