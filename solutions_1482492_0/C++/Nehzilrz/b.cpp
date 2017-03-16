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

const double precision = 1e-10;

struct Tdata
{
	double t , x , v;
};

int testcase , T;
int n , m , A;
double min_t , D , ans;
Tdata data[3000];

void init()
{
	scanf("%lf%d%d" , &D , &n , &m);
	int i , j , k;
	FOR (i , 1 , n)
	{
		scanf("%lf%lf" , &data[i].t , &data[i].x);
		if (i > 1)
		{
			data[i].v = (data[i].x - data[i - 1].x) / (data[i].t - data[i - 1].t);
		}
	}
}

inline int cmp(const double& x)
{
	return ((x < -precision) ? -1 : (x > precision));
}

void work(double a)
{
	int i , j , k;
	double t = data[2].v + sqrt(data[2].v * data[2].v + 2.0 * a * data[1].x);
	t /= a;
	min_t = (D - data[1].x) / data[2].v;
	if (cmp(t - min_t) < 0) ans = min_t;
	else ans = sqrt(2.0 * D / a);
	if (n == 1) ans = sqrt(2.0 * D / a);
	printf("%.8lf\n" , ans);
}

int main()
{
	freopen("b.in" , "r" , stdin);
	freopen("b.out" , "w" , stdout);
	scanf("%d" , &testcase);
	FOR (T , 1 , testcase)
	{
		init();
		printf("Case #%d:\n" , T);
		for (int i = 1; i <= m; ++i)
		{
			double acc;
			scanf("%lf" , &acc);
			work(acc);
		}
	}
	return 0;
}
