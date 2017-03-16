#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iostream>
#include <cmath>
#include <vector>
#include <string>
#include <map>
#include <algorithm>
using namespace std;
#define MM(a , x) memset(a , x , sizeof(a))
#define sqr(x) ((x) * (x))
#define abs(x) ((x > 0) ? (x) : -(x))
#define REP(i , n) for ((i) = 0; (i) < (n); ++(i))
#define FOR(i , a , b) for ((i) = (a); (i) <= (b); ++(i))
#define FORD(i , a , b) for ((i) = (a); (i) >= (b); --(i))
typedef long long LL;

const int maxn = 1008;

int n , m , testcase , T;
int data[maxn][2] , ans;
bool vis[maxn][2];

void init()
{
	scanf("%d" , &n);
	int i;
	FOR (i , 1 , n) scanf("%d%d" , &data[i][0] , &data[i][1]);
}

void work()
{
	MM(vis , 0);
	int i , j , k , stars = 0;
	ans = 0;
	printf("Case #%d: " , T);
	bool flag;
	for (;;)
	{
		k = -1;
		flag = 1;
		FOR (i , 1 , n)
		{
			if (!vis[i][1] && !vis[i][0])
			{
				flag = 0;
				if (stars >= data[i][1])
				{
					k = i;
					break;
				}
			}
		}
		if (k != -1)
		{
			stars += 2; ;
			vis[k][0] = vis[k][1] = 1;
			ans++;
			continue;
		}

		FOR (i , 1 , n)
		{
			if (vis[i][0] && (!vis[i][1]))
			{
				flag = 0;
				if (stars >= data[i][1])
				{
					k = i;
					break;
				}
			}
		}
		if (k != -1)
		{
			stars++;
			vis[k][1] = 1;
			ans++;
			continue;
		}

		FOR (i , 1 , n)
		{
			if (!vis[i][0])
			{
				flag = 0;
				if (stars >= data[i][0])
				{
					if (k == -1) k = i;
					else
					{
						if (data[i][1] > data[k][1]) k = i;
					}
				}
			}
		}
		if (k != -1)
		{
			stars++;
			vis[k][0] = 1;
			ans++;
			continue;
		}
		if (flag) break;
		if (!flag && k == -1)
		{
			printf("Too Bad\n");
			return;
		}
	}
	printf("%d\n" , ans);
}

int main()
{
	freopen("b.in" , "r" , stdin);
	freopen("b.out" , "w" , stdout);
	scanf("%d" , &testcase);
	FOR (T , 1 , testcase)
	{
		init();
		work();
	}
	return 0;
}
