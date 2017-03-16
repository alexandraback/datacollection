#include<stdio.h>
#include<string.h>
int main()
{
	freopen("A-large.txt","r",stdin);
	freopen("pA_out.txt","w",stdout);
	int n,t,i,j;
	char map[5][5];
	scanf("%d",&n);
	for(t=1;t<=n;t++)
	{
		int x=0,o=0,dot=0;
		int rsx=1,rso=1,lsx=1,lso=1;
		for(i=0;i<4;i++)scanf("%s",map[i]);
		for(i=0;i<4;i++)
		{
			if(map[i][i]!='X'&&map[i][i]!='T')lsx=0;
			if(map[i][i]!='O'&&map[i][i]!='T')lso=0;
			if(map[i][3-i]!='X'&&map[i][3-i]!='T')rsx=0;
			if(map[i][3-i]!='O'&&map[i][3-i]!='T')rso=0;
		}
		if(lsx||rsx)x=1;
		else if(lso||rso)o=1;
		else 
			for(i=0;i<4;i++)
			{
				int cx=1,co=1,rx=1,ro=1;
				for(j=0;j<4;j++)
				{
					if(map[i][j]!='X'&&map[i][j]!='T')cx=0;
					if(map[i][j]!='O'&&map[i][j]!='T')co=0;
					if(map[j][i]!='X'&&map[j][i]!='T')rx=0;
					if(map[j][i]!='O'&&map[j][i]!='T')ro=0;
					if(map[i][j]=='.')dot=1;
				}
				if(cx||rx)x=1;
				if(co||ro)o=1;
				if(x||o)break;
			}
		printf("Case #%d: ",t);
		if(x)printf("X won\n");
		else if(o)printf("O won\n");
		else if(!dot)printf("Draw\n");
		else printf("Game has not completed\n");
	}
	return 0;
}
