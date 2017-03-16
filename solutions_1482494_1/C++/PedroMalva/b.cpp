#include <stdio.h>

using namespace std;

#define MAX 99999

int main()
{
	int cases;
	int c=1;
	int levels,i;
	int stars[1000][2];
	int st,levs,comp,start;
	bool changed;
	int tmp,ltmp;

	for(scanf("%d",&cases);cases>0;cases--,c++)
	{
		for(scanf("%d",&levels),i=0;i<levels;i++)
		{
			scanf("%d%d",&(stars[i][0]),&(stars[i][1]));	
		}

		st=0;
		levs=0;
		comp = 0;
		start = 0;
		changed = false;

		while(comp<levels)
		{
			changed = false;
			for(i=start;i<levels;i++)
			{
				if(st>= stars[i][1])
					break;
			}

			if(i<levels)
			{
				changed = true;
				if(stars[i][0]==MAX)
					st+=1;
				else 
					st+=2;
				levs+=1;
				comp+=1;
				stars[i][1] = MAX;
			}
			else
			{
				tmp = levels;
				ltmp = -1;
				for(i=start;i<levels;i++)
					if(st>=stars[i][0] && stars[i][1]!=MAX)
					{
						if(stars[i][1] > ltmp)
						{
							ltmp = stars[i][1];
							tmp = i;
						}
					}
				if(tmp<levels)
				{
					changed = true;
					st+=1;
					levs+=1;
					stars[tmp][0] = MAX;
				}
			}

			for(i=start;i<levels;i++)
				if(stars[i][1]!=MAX)
				{
					start=i;
					break;
				}

			if(!changed)
				break;
		}

		printf("Case #%d: ",c);
		if(!changed)
			printf("Too Bad\n");
		else
			printf("%d\n",levs);
	}

	return 0;
}
