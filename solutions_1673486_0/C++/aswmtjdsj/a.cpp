#include <iostream>
#include <cstdio>
#include <cstring>
#include <string>
#include <cstdlib>
#include <cctype>
#include <map>
#include <set>
#include <bitset>
#include <queue>
#include <deque>
#include <list>
#include <vector>
#include <algorithm>
#include <cmath>
#include <complex>
using namespace std;

#define len(x) (x).size()
#define PB push_back
#define MP make_pair
#define FORALL(i, a, n, c) for(int i = (a);i < (n);i += c)
#define FOR(i, a, b) FORALL(i, a, b, 1)
#define rep(i, n) FOR(i, 0, n)
#define TYPE int

typedef long long int64;
typedef pair<TYPE,TYPE> pii;
typedef vector<int> vi;
typedef vector<string> vs;
typedef set <int> si;
typedef vi::iterator vip;

pii operator - (const pii &a)
{
	return pii(-a.first,-a.second);
}
pii operator + (const pii &a,const pii &b)
{
	return pii(a.first+b.first, a.second+b.second);
}
pii operator - (const pii &a, const pii &b)
{
	return a + (-b);
}

const int inf = ~0u >> 1;
const double eps = 1e-8;
const double pi = acos(-1.0);
int sgn(double x)
{
	return fabs(x) < eps ? 0:x < -eps?-1:1;
}
int a, b;
#define maxn 100005
double p[maxn];
double p1[maxn];
int main()
{
	/*
	   rep(i, 10) cout << i << endl;
	   pii a = MP(1,2), b= a;
	   b = -b;
	   a + b;
	   a - b;
	   int b[] = {1,2,3,4,5,6,7};
	   vi vec(b,b + 7);
	 */
	int t;
	scanf("%d",&t);
	for(int cas = 1;cas <= t;cas++)
	{
		double ans;
		scanf("%d %d", &a, &b);
		double ps = 1;
		p1[0] = 1.0;
		for(int i = 0;i < a;i++)
		{
			scanf("%lf",&p[i]);
			ps *= p[i];
			p1[i+1] = p[i] * p1[i];
			//cout << p1[i+1] << ' ' << i << endl;
		}
		double temp1 = (b - a + 1) * ps + (b - a + 1 + b + 1) * (1.0 - ps);
		double temp2 = b + 2;
		ans = min(temp1, temp2);
		for(int i = a;i >= 1;i--)
		{
			double temp = (i + b - (a - i) + 1) * p1[a-i] + (i + b - (a-i) + 1 + b + 1) * (1.0 - p1[a-i]);
			//cout << i << ' ' << a - i << ' '<< p1[a-i] << ' ' << temp << endl;
			ans = min(ans,temp);
		}
		printf("Case #%d: %.6lf\n", cas, ans);
	}
}
