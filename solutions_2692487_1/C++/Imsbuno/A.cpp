#include <map>
#include <set>
#include <cmath>
#include <ctime>
#include <deque>
#include <queue>
#include <cctype>
#include <cstdio>
#include <memory>
#include <string>
#include <vector>
#include <cstdlib>
#include <cstring>
#include <fstream>
#include <sstream>
#include <iostream>
#include <algorithm>
#include <windows.h>

#define sqr(x) ((x) * (x))
#define minn(x,y) (x=(y)<(x)?(y):(x))
#define maxx(x,y) (x=(y)>(x)?(y):(x))
#define pluss(x,y) (x+=(y),x%=mod)
#define random(x) ((((rand()%32767)*(rand()%32767)*(rand()%32767)%(x))+(x))%(x))

using namespace std;

typedef	long long	int64;


int	a[9999], N, A;


int	main()
{
	freopen("A-large.in", "r", stdin);
	freopen("A-large.out", "w", stdout);
	
	int	Test;
	scanf("%d", &Test);
	for (int test = 1; test <= Test; ++ test)
	{
		scanf("%d%d", &A, &N);
		
		for (int i = 1; i <= N; ++ i) scanf("%d", &a[i]);
		sort(a + 1, a + N + 1);
		
		if (A == 1)
		{
			printf("Case #%d: %d\n", test, N);
			continue;
		}
		
		int	ans = N, now = 0;
		for (int i = 1; i <= N; ++ i)
		{
			while (A <= a[i])
			{
				A += A - 1;
				++ now;
			}
			minn(ans, now + (N - i));
			A += a[i];
		}
		
		printf("Case #%d: %d\n", test, ans);
	}
	
	return 0;
}
