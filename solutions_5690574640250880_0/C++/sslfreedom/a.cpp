#include <iostream>
#include <cstdio>
#include <deque>
#include <cstring>
#include <algorithm>
#include <map>
using namespace std; 

const int N=52;

int cas, n, m, mine;
int a[N][N];

void print()
{
	for (int i=1; i<=n; ++i)
	{
		for (int j=1; j<=m; ++j)
			if (a[i][j]==0)
				printf("*");
			else if (a[i][j]==1)
				printf(".");
			else printf("c");
		printf("\n");
	}
}

void work1()
{
	if (n==1)
	{
		for (int i=1; i<=mine; ++i)
			printf("*");
		for (int i=mine+1; i<m; ++i)
			printf(".");
		printf("c");
		printf("\n");
	}
	else 
	{
		for (int i=1; i<=mine; ++i)
			printf("*\n");
		for (int i=mine+1; i<n; ++i)
			printf(".\n");
		printf("c\n");
	}
}

void work2()
{
	if (n*m-mine==1)
	{
		memset(a, 0, sizeof(a));
		a[1][1]=2; 
		print();
		return; 
	}
	if (mine%2==1 || (n*m-mine)/2<=1) 
	{
		printf("Impossible\n");
		return; 
	}
	if (n==2)
	{
		for (int i=1; i<=mine/2; ++i)
			printf("*");
		for (int i=mine/2+1; i<=m; ++i)
			printf(".");
		printf("\n");
		for (int i=1; i<=mine/2; ++i)
			printf("*");
		for (int i=mine/2+1; i<m; ++i)
			printf(".");
		printf("c\n");
	}
	else
	{
		for (int i=1; i<=mine/2; ++i)
			printf("**\n");
		for (int i=mine/2+1; i<n; ++i)
			printf("..\n");
		printf(".c\n");
	}
}



void work3()
{
	if (n*m-mine==1)
	{
		memset(a, 0, sizeof(a));
		a[1][1]=2;
		print();
		return;
	}
	memset(a, 0, sizeof(a));
	if (n*m-mine<4||n*m-mine==5||n*m-mine==7) 
	{
		printf("Impossible\n");
		return;
	}
	int re=n*m-mine;
	if (m*2<=re)
	{
		int row=re/m;
		int col=re%m;
		for (int i=1; i<=row; ++i)
			for (int j=1; j<=m; ++j)
				a[i][j]=1;
		for (int i=1; i<=col; ++i)
			a[row+1][i]=1;
		if (col==1)
		{
			a[row+1][col+1]=1;
			a[row][m]=0;
			if (row==2)
			{
				a[row+1][col+2]=1;
				a[row-1][m]=0;
			}
		}
		a[1][1]=2;
	}
	else 
	{
		for (int i=1; i<=re/2; ++i)
		{
			a[1][i]=1;
			a[2][i]=1;
		}
		if (re%2==1)
		{
			a[1][re/2]=0; a[2][re/2]=0;
			a[3][1]=1; a[3][2]=1; a[3][3]=1;
		}
		a[1][1]=2;
	}
	print();
}

void cal()
{
	if (n==1||m==1)
		work1();
	else 
	if (n==2||m==2)
		work2();
	else work3();
}

int main()
{
	//freopen("a.in","r",stdin);
	//freopen("a.out","w",stdout);
	scanf("%d", &cas);
	for (int k=1; k<=cas; ++k)
	{
		printf("Case #%d:\n", k);
		scanf("%d%d%d", &n, &m, &mine);
		//cout << n << ' ' << m << ' ' << mine << endl;
		cal();
	}
	return 0;
}
