#include <vector>
#include <list>
#include <map>
#include <set>
#include <deque>
#include <stack>
#include <bitset>
#include <algorithm>
#include <functional>
#include <numeric>
#include <utility>
#include <sstream>
#include <iostream>
#include <iomanip>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <ctime>
#include <cstring>
#define INF 1<<30
#define MAXN 10010
#define MOD 1000000007
using namespace std;

char graph[55][55];

int main()
{
	/*freopen("C-large.in","r",stdin);
	freopen("C-large.out","w",stdout);*/
	int t;
	scanf("%d",&t);
	for(int r = 1;r<=t;r++)
	{
		int n ,m ,num;
		scanf("%d%d%d",&n,&m,&num);
		//printf("%d %d %d\n",n,m,num);
		for(int i = 1;i<=n;i++)
		{
			for(int j = 1;j<=m;j++)
			{
				graph[i][j] = '*';
			}
		}
		if(n*m-num==1)
		{
			graph[1][1] = 'c';
			printf("Case #%d:\n",r);
			for(int i = 1;i <=n;i++)
			{
				for(int j = 1;j<=m;j++)
				{
					printf("%c",graph[i][j]);
				}
				printf("\n");
			}
			continue;
		}
		int ans = n * m - num;
		if(n==1)
		{
			for(int i = 1;i<=ans;i++)
			{
				graph[1][i] = '.';
			}
			graph[1][1] = 'c';
			printf("Case #%d:\n",r);
			for(int i = 1;i <=n;i++)
			{
				for(int j = 1;j<=m;j++)
				{
					printf("%c",graph[i][j]);
				}
				printf("\n");
			}
			continue;
		}
		if(m==1)
		{
			for(int i = 1;i<=ans;i++)
			{
				graph[i][1] = '.';
			}
			graph[1][1] = 'c';
			printf("Case #%d:\n",r);
			for(int i = 1;i <=n;i++)
			{
				for(int j = 1;j<=m;j++)
				{
					printf("%c",graph[i][j]);
				}
				printf("\n");
			}
			continue;
		}
		if(n > m)
		{
			int s = ans / n;
			if(s >= 2)
			{
				for(int i = 1;i <= n;i++)
				{
					for(int j = 1;j <= s;j++)
					{
						graph[i][j] = '.';
					}
				}
				ans -= s * n;
				if(ans==1)
				{
					if(n<=3)
					{
						printf("Case #%d:\n",r);
						printf("Impossible\n");
						continue;
					}
					else
					{
						if(s>=3)
						{
							graph[n][s] = '*';
							graph[1][s+1] = '.';
							graph[2][s+1] = '.';
						}
						else
						{
							graph[n][1] = '*';
							graph[n][2] = '*';
							graph[1][s+1] = '.';
							graph[2][s+1] = '.';
							graph[3][s+1] = '.';
						}
					}
				}
				else
				{
					for(int i = 1;i<=ans;i++)
					{
						graph[i][s+1] = '.';
					}
				}
			}
			else
			{
				s = ans / 2;
				for(int i = 1;i <= s;i++)
				{
					for(int j = 1;j <= 2;j++)
					{
						graph[i][j] = '.';
					}
				}
				ans -= s * 2;
				if(ans==0 && s==1)
				{
					printf("Case #%d:\n",r);
					printf("Impossible\n");
					continue;
				}
				if(ans==1)
				{
					if(m==2)
					{
						printf("Case #%d:\n",r);
						printf("Impossible\n");
						continue;
					}
					if(s > 3)
					{
						graph[s][1] = '*';
						graph[s][2] = '*';
						graph[1][3] = '.';
						graph[2][3] = '.';
						graph[3][3] = '.';
					}
					else
					{
						printf("Case #%d:\n",r);
						printf("Impossible\n");
						continue;
					}
				}
				else
				{
					for(int i = 1;i<=ans;i++)
					{
						graph[i][3] = '.';
					}
				}
			}
		}
		else
		{
			int s = ans / m;
			if(s >= 2)
			{
				for(int i = 1;i <= s;i++)
				{
					for(int j = 1;j <= m;j++)
					{
						graph[i][j] = '.';
					}
				}
				ans -= s * m;
				if(ans==1)
				{
					if(m<=3)
					{
						printf("Case #%d:\n",r);
						printf("Impossible\n");
						continue;
					}
					else
					{
						if(s>=3)
						{
							graph[s][m] = '*';
							graph[s+1][1] = '.';
							graph[s+1][2] = '.';
						}
						else
						{
							graph[1][m] = '*';
							graph[2][m] = '*';
							graph[s+1][1] = '.';
							graph[s+1][2] = '.';
							graph[s+1][3] = '.';
						}
					}
				}
				else
				{
					for(int i = 1;i<=ans;i++)
					{
						graph[s+1][i] = '.';
					}
				}
			}
			else
			{
				s = ans / 2;
				for(int i = 1;i <= 2;i++)
				{
					for(int j = 1;j <= s;j++)
					{
						graph[i][j] = '.';
					}
				}
				ans -= s * 2;
				if(ans==0 && s==1)
				{
					printf("Case #%d:\n",r);
					printf("Impossible\n");
					continue;
				}
				if(ans==1)
				{
					if(n==2)
					{
						printf("Case #%d:\n",r);
						printf("Impossible\n");
						continue;
					}
					if(s > 3)
					{
						graph[1][s] = '*';
						graph[2][s] = '*';
						graph[3][1] = '.';
						graph[3][2] = '.';
						graph[3][3] = '.';
					}
					else
					{
						printf("Case #%d:\n",r);
						printf("Impossible\n");
						continue;
					}
				}
				else
				{
					for(int i = 1;i<=ans;i++)
					{
						graph[3][i] = '.';
					}
				}
			}
		}
		graph[1][1] = 'c';
		printf("Case #%d:\n",r);
		for(int i = 1;i <=n;i++)
		{
			for(int j = 1;j<=m;j++)
			{
				printf("%c",graph[i][j]);
			}
			printf("\n");
		}
	}
	return 0;
}