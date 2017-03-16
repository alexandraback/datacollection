#include<iostream>
#include<fstream>
#include<cstdio>
#include<cmath>
#include<cstdlib>
#include<iomanip>
#include<ctime>
#include<cstring>
#include<climits>
#include<string>
#include<vector>
#include<map>
#include<queue>
#include<set>
#include<algorithm>
#include<stack>
#include<deque>
#include<list>
#include<vector>
#define LL long long
using namespace std;
int n,m,cnt,snt,times;
LL oo=1000000007;
char a[100][100];
void work(int lab)
{
	printf("Case #%d:\n",lab);
	scanf("%d%d%d",&n,&m,&cnt);
    if (n*m-1==cnt)
	{
		for (int i=1;i<n;i++)
		{
			for (int j=1;j<=m;j++) printf("*");
			printf("\n");
		}
		for (int i=1;i<m;i++) printf("*");
		printf("c\n");
	}
	else if (n==1) 
	{
		for (int i=1;i<=cnt;i++) printf("*");
		for (int i=cnt+1;i<m;i++) printf(".");
		printf("c\n");
	}
	else if (m==1)
	{
		for (int i=1;i<=cnt;i++) printf("*\n");
		for (int i=cnt+1;i<n;i++) printf(".\n");
		printf("c\n");
	}
	else if (n==2)
	{
		if (cnt==n*m-2||(cnt&1))
		{
			printf("Impossible\n");return;
		}
		for (int j=1;j<=cnt/2;j++) printf("*");
		for (int j=cnt/2+1;j<=m;j++) printf(".");
		printf("\n");
		for (int j=1;j<=cnt/2;j++) printf("*");
		for (int j=cnt/2+1;j<m;j++) printf(".");
		printf("c\n");
	}
	else if (m==2)
	{
		if (cnt==n*m-2||(cnt&1))
		{
			printf("Impossible\n");return;
		}
		printf("c.\n");
		for (int j=cnt/2+1;j<n;j++) printf("..\n");
		for (int j=1;j<=cnt/2;j++) printf("**\n");
	}
	else 
	{
		snt=(n-2)*(m-2);
		memset(a,'.',sizeof(a));
		if (cnt<=snt)
		{
			for (int i=1;i<=n-2;i++)
			for (int j=1;j<=m-2;j++)
			if (cnt>0)
			{
				cnt--;a[i][j]='*';
			}
			a[n][m]='c';
			for (int i=1;i<=n;i++)
			{
				for (int j=1;j<=m;j++) printf("%c",a[i][j]);
				printf("\n");
			}
		}
		else 
		{
			for (int i=1;i<=n-2;i++)
			for (int j=1;j<=m-2;j++) a[i][j]='*';
			cnt-=snt;
			if (cnt<=2*(n+m-6))
			{
				if (cnt&1) 
				{
					cnt++;a[n-2][m-2]='.';
				}
				for (int i=1;i<=n-3;i++)
				for (int j=m-1;j<=m;j++)
				if (cnt>0)
				{
					a[i][j]='*';cnt--;
				}
				for (int i=1;i<=m-3;i++)
				for (int j=n-1;j<=n;j++)
				if (cnt>0)
				{
					a[j][i]='*';cnt--;
				}
				a[n][m]='c';
				for (int i=1;i<=n;i++)
				{
					for (int j=1;j<=m;j++) printf("%c",a[i][j]);
					printf("\n");
				}
			}
			else 
			{
				memset(a,'*',sizeof(a));
				cnt-=2*(n+m-6);
				cnt+=1;
				if (cnt==3)
				{
					for (int i=n-1;i<=n;i++)
					for (int j=m-2;j<=m;j++) a[i][j]='.';
					a[n][m]='c';
					for (int i=1;i<=n;i++)
					{
						for (int j=1;j<=m;j++) printf("%c",a[i][j]);
						printf("\n");
					}
				}
				else if (cnt==5) 
				{
					for (int i=n-1;i<=n;i++)
					for (int j=m-1;j<=m;j++) a[i][j]='.';
					a[n][m]='c';
					for (int i=1;i<=n;i++)
					{
						for (int j=1;j<=m;j++) printf("%c",a[i][j]);
						printf("\n");
					}
				}
				else printf("Impossible\n");
			}
		}
	}
}
int main()
{
	freopen("data.in","r",stdin);
	freopen("data.out","w",stdout);
	scanf("%d",&times);
	for (int i=1;i<=times;i++)
	work(i);
    return 0;
}



