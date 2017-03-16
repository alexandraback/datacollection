#include "stdio.h"
#include "stdlib.h"
#include "string.h"

char game[5][5];
int xrow[4],orow[4],xcol[4],ocol[4];
int xdia1,xdia2,odia1,odia2;

int main()
{
	int T;
	int t=1;
	int i;
	int j;
	int flag;
	scanf("%d",&T);
	while(t<=T)
	{
		flag=3;
		xdia1=xdia2=odia1=odia2=0;
		for(i=0;i<4;i++)
		{
			xrow[i]=orow[i]=xcol[i]=ocol[i]=0;
			scanf("%s",game[i]);
		}
		for(i=0;i<4;i++)
		{
			for(j=0;j<4;j++)
			{
				if(game[i][j]=='.')
				{
					flag=4;
				}
				else if(game[i][j]=='X')
				{
					xrow[i]++;xcol[j]++;
					if(i==j)xdia1++;
					if(i+j==3)xdia2++;
				}
				else if(game[i][j]=='O')
				{
					orow[i]++;ocol[j]++;
					if(i==j)odia1++;
					if(i+j==3)odia2++;
				}
				else
				{
					xrow[i]++;xcol[j]++;
					orow[i]++;ocol[j]++;
					if(i==j)
					{
						xdia1++;
						odia1++;	
					}
					if(i+j==3)
					{
						xdia2++;
						odia2++;
					}
				}
			}
		}
		for(i=0;i<4;i++)
		{
			if(xrow[i]==4){flag=1;break;}
			if(orow[i]==4){flag=2;break;}
			if(xcol[i]==4){flag=1;break;}
			if(ocol[i]==4){flag=2;break;}
		}
		if(xdia1==4||xdia2==4)
		{
			flag=1;
		}
		if(odia1==4||odia2==4)
		{
			flag=2;
		}
		switch(flag)
		{
			case 1: printf("Case #%d: X won\n",t);
					break;
			case 2: printf("Case #%d: O won\n",t);
					break;
			case 3: printf("Case #%d: Draw\n",t);
					break;
			case 4: printf("Case #%d: Game has not completed\n",t);
					break;  
		}
		t++;
	}
	return 0;
}