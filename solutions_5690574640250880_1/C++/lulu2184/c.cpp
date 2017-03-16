#include <iostream>
#include <cstring>
#include <cstdio>
using namespace std;

char ans[55][55];
int T,TT,R,C,mines,empty;

bool construct()
{
	if (R==1)
	{
		for (int i=1;i<=empty;i++) ans[1][i]='.';
		return true;
	}
	if (C==1) 
	{
		for (int i=1;i<=empty;i++) ans[i][1]='.';
		return true;
	}
	for (int i=2;i<=R;i++)
	{	
		int rest=empty%i;
		int cols=empty/i;
		for (int j=1;j<=R;j++)
			for (int k=1;k<=C;k++)
				ans[j][k]='*';
		for (int j=1;j<=i;j++)
			for (int k=1;k<=cols;k++) 
				ans[j][k]='.';
	
		if (cols>C) continue;
		if (cols==1) continue;
		if (rest==1 && (i<=2 || cols<=2)) continue;
		if (rest==1)
		{
			ans[i][cols]='*';
			if (i<R)
			{
				ans[i+1][1]=ans[i+1][2]='.';
			}else ans[1][cols+1]=ans[2][cols+1]='.';
			return true;
		}else
		{
			if (i<R)
			{	
				for (int j=1;j<=rest;j++)
					ans[i+1][j]='.';
			}else
			{
				for (int j=1;j<=rest;j++)
					ans[j][cols+1]='.';
			}
		}
		return true;
	}
	return false;
}

void print()
{
	for (int i=1;i<=R;i++)
	{
		for (int j=1;j<=C;j++)
		{
			printf("%c",ans[i][j]);
		}
		printf("\n");
	}
}

int main()
{
	scanf("%d",&T);
	while (T--)
	{
		printf("Case #%d:\n",++TT);
		scanf("%d%d%d",&R,&C,&mines);
		empty=R*C-mines;
		for (int i=1;i<=R;i++)
			for (int j=1;j<=C;j++)
				ans[i][j]='*';
		if (empty==1)
		{
			ans[1][1]='c';
			print();
			continue;
		}
		if (empty<4 && R>1 && C>1) printf("Impossible\n");
		else
		{
			if (construct())
			{
				ans[1][1]='c';
				print();
			}else
			{
				printf("Impossible\n");
			}
		}
	}

	return 0;
}