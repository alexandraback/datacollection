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


double	p[100005];
int	A, B;


double	goon()
{
	double	P = 1;
	for (int i = 1; i <= A; ++ i) P *= p[i];
	return P * (B - A + 1) + (1.0 - P) * (B - A + 1 + B + 1);
}

double	dele()
{
	double	P = 1;
	double	ret = 1e20;
	for (int i = 0; i <= A; ++ i)
	{
		minn(ret, P * (A - i + B - i + 1) + (1.0 - P) * (A - i + B - i + 1 + B + 1));
		P *= p[i + 1];
	}
	return ret;
}

double	ente()
{
	return 1 + B + 1;
}

int	main()
{
	freopen("A.in", "r", stdin);
	freopen("A.out", "w", stdout);
	
	int	Test;
	scanf("%d", &Test);
	for (int test = 1; test <= Test; ++ test)
	{
		scanf("%d%d", &A, &B);
		for (int i = 1; i <= A; ++ i) scanf("%lf", &p[i]);
		
		double	ans = 1e20;
		minn(ans, goon());
		minn(ans, dele());
		minn(ans, ente());
		
		printf("Case #%d: %.9lf\n", test, ans);
	}
	
	return 0;
}
