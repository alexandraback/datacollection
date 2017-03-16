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


int	f[1 << 22], a[22], N;


int	main()
{
	freopen("B-small-attempt2.in", "r", stdin);
	freopen("B-small-attempt2.out", "w", stdout);
	
	int	Test;
	scanf("%d", &Test);
	for (int test = 1; test <= Test; ++ test)
	{
		scanf("%d", &N);
		for (int i = 0; i < N; ++ i) scanf("%d%d", &a[i * 2], &a[i * 2 + 1]);
		
		memset(f, 60, sizeof(f)); f[0] = 0;
		for (int x = 0; x < 1 << N + N; ++ x)
		{
			int	S = 0;
			for (int i = 0; i < N + N; i += 2)
			{
				if (x & (1 << i)) S += 1;
				if (x & (1 << i + 1)) S += 1;
			}
			
			for (int i = 0; i < N + N; i += 2)
				if (!(x & (1 << i)) && a[i] <= S)
					minn(f[x | (1 << i)], f[x] + 1);
			
			for (int i = 1; i < N + N; i += 2)
				if (!(x & (1 << i)) && a[i] <= S)
					minn(f[x | (1 << i) | (1 << i - 1)], f[x] + 1);
		}
		
		int	ans = f[(1 << N + N) - 1];
		
		printf("Case #%d: ", test);
		if (ans > 1 << 29) puts("Too Bad"); else printf("%d\n", ans);
	}
	
	return 0;
}
