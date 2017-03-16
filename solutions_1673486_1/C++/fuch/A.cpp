#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <climits>
#include <cstring>
#include <algorithm>
#include <vector>
#include <queue>
#include <string>
#include <set>
#include <map>
#include <numeric>
#include <functional>
#define rep(i,n) for(int i=0;i<(n);++i)
#define foreach(i,v) for(__typeof(v.begin()) i=v.begin();i!=v.end();++i)
#define ass(v) (v)||++*(int*)0;
using namespace std;
typedef pair<int,int> PII;
typedef vector<PII> VPII;
typedef vector<int> VI;
typedef vector<string> VS;
typedef vector<bool> VB;
typedef vector<double> VD;
VD p;
int m, n;
double gao1()
{
	double pp = 1.0;
	rep(i, m) pp *= p[i];
	return pp * (n - m + 1.0) + (1.0 - pp) * (n * 2 - m + 2.0);
}
double gao2()
{
	VD q(m + 1);
	q[0] = 1.0;
	rep(i, m) q[i + 1] = q[i] * p[i];
	double res = m + n + 1.0;
	rep(i, m + 1)
	{
		res = min(res, (m - i) * 2.0 + n - m + 1.0 + (1.0 - q[i]) * (n + 1.0));
	}
	return res;
}
int main()
{
	int t;
	scanf("%d", &t);
	for (int cs = 1; cs <= t; ++cs)
	{
		scanf("%d%d", &m, &n);
		p.resize(m);
		rep(i, m) scanf("%lf", &p[i]);
		double ans = n + 2.0;
		ans = min(ans, gao1());
		ans = min(ans, gao2());
		printf("Case #%d: %.9lf\n", cs, ans);
	}
	return 0;
}
