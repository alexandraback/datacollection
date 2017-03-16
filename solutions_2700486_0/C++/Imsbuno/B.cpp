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


double	f[999][999];
int	N, X, Y;


int	main()
{
	freopen("B-small-attempt4.in", "r", stdin);
	freopen("B-small-attempt4.out", "w", stdout);
	
	int	Test;
	scanf("%d", &Test);
	for (int test = 1; test <= Test; ++ test)
	{
		scanf("%d%d%d", &N, &X, &Y);
		X = abs(X);
		Y = abs(Y);
		
		int	S = 0, L = 0;
		while (S + L * 4 + 1 <= N) S += L * 4 + 1, ++ L;
		N -= S;
		L *= 2;
		
		memset(f, 0, sizeof(f)); f[0][0] = 1;
		
		for (int i = 1; i <= N; ++ i)
		for (int j = 0; j <= L; ++ j)
		{
			if (j == L)
			{
				f[i][j] += f[i - 1][j];
				continue;
			}
			
			if (i - 1 - j == L)
			{
				f[i][j + 1] += f[i - 1][j];
				continue;
			}
			
			f[i][j] += f[i - 1][j] / 2;
			f[i][j + 1] += f[i - 1][j] / 2;
		}
		
		int	Z = X + Y;
		if (Z < L)
		{
			printf("Case #%d: %.10lf\n", test, 1.0);
			continue;
		}
		if (Z > L)
		{
			printf("Case #%d: %.10lf\n", test, 0.0);
			continue;
		}
		
		double	ans = 0;
		for (int j = Y + 1; j <= L; ++ j) ans += f[N][j];
		printf("Case #%d: %.10lf\n", test, ans);
	}
	
	return 0;
}
