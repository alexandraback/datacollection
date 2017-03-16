/*
Author:wuhuajun
*/
#include <cmath>
#include <cstdio>
#include <algorithm>
#include <cstring>
#include <string>
#include <cstdlib>
using namespace std;

typedef long long ll;
typedef double dd;
const int maxn=210;

int blank,n,m,c,mod,row,T;
char ans[maxn][maxn];

void close()
{
	exit(0);
}

void im()
{
	puts("Impossible");
}
void print()
{
	for (int i=1;i<=n;i++)
	{
		for (int j=1;j<=m;j++)
			printf("%c",ans[i][j]);
		puts("");
	}
}

void work()
{
	if (n == 1 && m == 1)
	{
		if (c == 1)
			im();
		else
			printf("c\n");
		return;
	}
	if (n == 1)
	{
		printf("c");
		for (int i=2;i<=blank;i++)
			printf(".");
		for (int i=1;i<=c;i++)
			printf("*");
		puts("");
		return;
	}
	if (m == 1)
	{
		printf("c\n");
		for (int i=2;i<=blank;i++)
			printf(".\n");
		for (int i=1;i<=c;i++)
			printf("*\n");
		return;
	}
	if (blank == 1)
	{
		for (int i=1;i<=n;i++)
		{
			for (int j=1;j<=m;j++)
				if (i == 1 && j == 1)
					printf("c");
				else
					printf("*");
			puts("");
		}
		return;
	}
	for (int i=2;i<=min(blank, m);i++) //枚举m这条边该放多少个
	{
		row = blank / i;//边的长度
		mod = blank % i;//剩下的那条边的长度
		if (mod != 0) row++;
		if (row > n || (row == 1) || (row == 2 && mod != 0)) continue; //超出了边界

		if (mod >= 2 || mod == 0 || (row >= 4 && i > 2 && mod == 1)) //合法，输出
		{
			for (int j=1;j<=n;j++)
			{
				for (int k=1;k<=m;k++)
				{
					if (j == 1 && k == 1) 
					{
						ans[j][k] = 'c';
						continue;
					}
					if ((row > j && k <= i) || (row == j && mod == 0 && k <= i) || (row == j && k <= mod))
					{
						ans[j][k] = '.';
						continue;
					}
					ans[j][k] = '*';
				}
			}
			if (row>=4 && i > 2 && mod == 1)
			{
				ans[row-1][i] = '*';
				ans[row][2] = '.';
			}
			print();
			return;
		}

	}

	for (int i=2;i<=min(blank, n);i++) //枚举m这条边该放多少个
	{
		row = blank / i;//边的长度
		mod = blank % i;//剩下的那条边的长度
		if (mod != 0) row++;
		if (row > m || (row == 1) ||  (row == 2 && mod != 0)) continue; //超出了边界
		if (mod >= 2 || mod == 0 || (row >= 4 && i > 2 && mod == 1)) //合法，输出
		{
			for (int j=1;j<=n;j++)
			{
				for (int k=1;k<=m;k++)
				{
					if (j == 1 && k == 1) 
					{
						ans[j][k] = 'c';
						continue;
					}
					if ((row > k && j <= i) || (row == k && mod == 0 && j <= i) || (row == k && j <= mod))
					{
						ans[j][k] = '.';
						continue;
					}
					ans[j][k] = '*';
				}
			}
			if (row >= 4 && i > 2 && mod == 1)
			{
				ans[i][row-1] = '*';
				ans[2][row] = '.';
			}
			print();
			return;
		}

	}

	im();
}

void init()
{
	//freopen("mine.in","r",stdin);
	//freopen("mine.out","w",stdout);
	scanf("%d",&T);
	for (int cas=1;cas<=T;cas++)
	{
		printf("Case #%d:\n",cas);
		scanf("%d %d %d",&n,&m,&c);
		blank = n * m - c;
		work();
		//close();

	}
}

int main ()
{
	init();
	close();
	return 0;
}

