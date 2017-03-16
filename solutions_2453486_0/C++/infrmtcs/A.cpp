#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <algorithm>
#define fi "A.INP"
#define fo "A.OUT"
#define nmax
#define INF 1000000000
using namespace std;

//VARIABLES
int a[10][10],x,y;
char s[10];
//MAIN
int Process(int tc)
{
	for (int i=1;i<=4;++i)
	{
		scanf("%s",&s);
		for (int j=1;j<=4;++j)
		{
			if (s[j-1]=='T') a[i][j]=3; else
			if (s[j-1]=='X') a[i][j]=1; else
			if (s[j-1]=='O') a[i][j]=2; else
			a[i][j]=0;
		}
	}
	for (int i=1;i<=4;++i)
	{
		x=y=0;
		for (int j=1;j<=4;++j)
		{
			if (a[i][j]==1) ++x;
			if (a[i][j]==2) ++y;
			if (a[i][j]==3) {++x;++y;}
		}
		if (x==4) return 1;
		if (y==4) return 2;
		x=y=0;
		for (int j=1;j<=4;++j)
		{
			if (a[j][i]==1) ++x;
			if (a[j][i]==2) ++y;
			if (a[j][i]==3) {++x;++y;}
		}
		if (x==4) return 1;
		if (y==4) return 2;
	}
	x=y=0;
	for (int i=1;i<=4;++i)
	{
		if (a[i][i]==1) ++x;
		if (a[i][i]==2) ++y;
		if (a[i][i]==3) {++x;++y;}
	}
	if (x==4) return 1;
	if (y==4) return 2;
	x=y=0;
	for (int i=1;i<=4;++i)
	{
		if (a[i][5-i]==1) ++x;
		if (a[i][5-i]==2) ++y;
		if (a[i][5-i]==3) {++x;++y;}
	}
	if (x==4) return 1;
	if (y==4) return 2;
	for (int i=1;i<=4;++i)
	for (int j=1;j<=4;++j)
	if (a[i][j]==0) return 3;
	return 0;
}
int main()
{
	int test;
       freopen(fi,"r",stdin);
       freopen(fo,"w",stdout);
       scanf("%d",&test);
       for (int tc=1;tc<=test;++tc)
	{
		int k=Process(tc);
		if (k==0) printf("Case #%d: Draw\n",tc);
		if (k==1) printf("Case #%d: X won\n",tc);
		if (k==2) printf("Case #%d: O won\n",tc);
		if (k==3) printf("Case #%d: Game has not completed\n",tc);
	}
       return 0;
}
