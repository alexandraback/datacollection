#include <map>
#include <set>
#include <cmath>
#include <ctime>
#include <deque>
#include <queue>
#include <cctype>
#include <cstdio>
#include <string>
#include <vector>
#include <cstdlib>
#include <cstring>
#include <sstream>
#include <iostream>
#include <algorithm>

#define sqr(x) ((x) * (x))
#define minn(x,y) (x=(y)<(x)?(y):(x))
#define maxx(x,y) (x=(y)>(x)?(y):(x))
#define pluss(x,y) (x+=(y),x%=mod)

using namespace std;

typedef	long long	int64;

struct	Pair2
{
	int	x, y;
};

Pair2	a[1005];
int	visit[1005], N;


int	work()
{
	memset(visit, 0, sizeof(visit));
	
	int	S = 0, T = 0;
	while (S < N + N)
	{
		bool	found = 0;
		
		for (int i = 1; i <= N && !found; ++ i)
			if (visit[i] < 2 && S >= a[i].y)
			{
				S += 2 - visit[i];
				T ++;
				visit[i] = 2;
				found = 1;
			}
		
		if (found) continue;
		
		int	maxY = 0, k = -1;
		for (int i = 1; i <= N; ++ i) if (!visit[i])
			if (S >= a[i].x)
			{
				if (a[i].y > maxY)
				{
					maxY = a[i].y;
					k = i;
				}
			}
		
		if (k == -1) return 1 << 30;
		
		visit[k] = 1;
		S ++;
		T ++;
	}
	
	return T;
}

int	main()
{
	freopen("B.in", "r", stdin);
	freopen("B.out", "w", stdout);
	
	int	Test;
	scanf("%d", &Test);
	for (int test = 1; test <= Test; ++ test)
	{
		scanf("%d", &N);
		for (int i = 1; i <= N; ++ i) scanf("%d%d", &a[i].x, &a[i].y);
		
		int	ans = work();
		
		printf("Case #%d: ", test);
		if (ans > 1 << 29) puts("Too Bad"); else printf("%d\n", ans);
	}
	
	return 0;
}
