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

const int maxn = 100008;

int n , m , testcase , T;
double p[maxn] , ans;

void init()
{
	scanf("%d%d" , &m , &n);
	int i;
	FOR (i , 1 , m) scanf("%lf" , &p[i]);
	p[0] = 1.0;
}

void work()
{
	int i , j , k;
	double ok = 1.0;
	ans = 1e20;
	FORD (i , m , 0)
	{
		ok = ok * p[m - i];
		int t1 = i + (n - (m - i)) + 1;
		int t2 = i + (n - (m - i)) + 1 + n + 1;
		double tp = ok * (double)t1 + (1 - ok) * (double)t2;
		ans = min(tp , ans);
	}
	ans = min(ans , (double)n + 2.0);
	printf("Case #%d: %.6lf\n" , T , ans);
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
