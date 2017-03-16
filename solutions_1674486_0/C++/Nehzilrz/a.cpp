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

struct Tedge
{
	int x , y , next;
};

int n , m , tot , testcase , T;
Tedge g[maxn * maxn];
int f[maxn] , first[maxn] , ind[maxn] , q[maxn];
bool found;

inline int add(int x , int y)
{
	++m;
	g[m].x = x; g[m].y = y;
	g[m].next = first[x]; first[x] = m;
}

void init()
{
	scanf("%d" , &n);
	int i , j , k , x , y;
	m = 0; MM(first , 255);
	MM(ind , 0);
	FOR (i , 1 , n)
	{
		scanf("%d" , &k);
		FOR (j , 1 , k)
		{
			scanf("%d" , &y);
			add(i , y);
			ind[y]++;
		}
	}
}

bool bfs(int st)
{
	MM(f , 0);
	f[st] = 1;
	int front = 0 , rear = 1;
	q[1] = st;
	while (front < rear)
	{
		int x = q[++front];
		for (int tp = first[x]; tp != -1; tp = g[tp].next)
		{
			int y = g[tp].y;
			if (f[y] == 0)
			{
				q[++rear] = y;
			}
			f[y] += f[x];
			if (f[y] >= 2) return 1;
		}
	}
}

void work()
{
	int i , j , k;
	printf("Case #%d: " , T);
	FOR (i , 1 , n)
	{
		if (!ind[i])
		{
			if (bfs(i))
			{
				printf("Yes\n");
				return;
			}
		}
	}
	printf("No\n");
}

int main()
{
	freopen("a.in" , "r" , stdin);
	freopen("a.out" , "w" , stdout);
	scanf("%d" , &testcase);
	FOR (T , 1 , testcase)
	{
		init();
		work();
	}
	return 0;
}
