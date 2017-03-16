#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;

int T,TT,f[6][6],flag;
char map[6][6];

int main()
{
	freopen("a.in","r",stdin);
	
	scanf("%d",&T);
	int TT=0;
	while (T--)
	{
		printf("Case #%d: ",++TT);
		for (int i=1;i<=4;i++) scanf("%s",&map[i][1]);
		for (int i=1;i<=4;i++)
			for (int j=1;j<=4;j++)
			{
				if (map[i][j]=='X') f[i][j]=1;
				else if (map[i][j]=='O') f[i][j]=2;
				else if (map[i][j]=='T') f[i][j]=0;
				else f[i][j]=-1;
 			}
		for (int i=1;i<=4;i++)
		{
			flag=0;
			for (int j=1;j<=4;j++)
			{
				if ((flag!=f[i][j] && f[i][j] && flag) || f[i][j]<0) { flag=-1;break; } 
				flag|=f[i][j];
			}
			if (flag==1) { printf("X won\n");break; }
			if (flag==2) { printf("O won\n");break; }
		}
		if (flag>0) continue;
		for (int j=1;j<=4;j++)
		{
			flag=0;
			for (int i=1;i<=4;i++)
			{
				if ((flag!=f[i][j] && f[i][j] && flag) || f[i][j]<0) { flag=-1;break; } 
				flag|=f[i][j];
			}
			if (flag==1) { printf("X won\n");break; }
			if (flag==2) { printf("O won\n");break; }
		}
		if (flag>0) continue;
		flag=0;
		for (int i=1;i<=4;i++)
		{
			if ((flag!=f[i][i] && f[i][i] && flag) || f[i][i]<0) { flag=-1;break; } 
			flag|=f[i][i];
		}
		if (flag==1) { printf("X won\n");continue; }
		if (flag==2) { printf("O won\n");continue; }
		flag=0;
		for (int i=1;i<=4;i++)
		{
			if ((flag!=f[i][5-i] && f[i][5-i] && flag) || f[i][5-i]<0) { flag=-1;break; } 
			flag|=f[i][5-i];
		}
		if (flag==1) { printf("X won\n");continue; }
		if (flag==2) { printf("O won\n");continue; }
		flag=0;
		for (int i=1;i<=4;i++)
		{
			for (int j=1;j<=4;j++)
			{
				if (f[i][j]<0)
				{
					flag=1;
					break;
				}
			}
			if (flag) break;
		}
		if (flag) printf("Game has not completed\n");
		else printf("Draw\n");
	}
	
	return 0;
}