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
typedef long long LL;

double solve(double C, double F, double X)
{
	double ans = X / 2.0;
	double sum = 0.0;
	for (int n = 1; n <= 1000000; ++n)
	{
		sum += C / (2.0 + (n - 1) * F);
		double tmp = sum + X / (2.0 + n * F);
		ans = std::min(ans, tmp);
	}
	return ans;
}

int main()
{
	int t;
	scanf("%d", &t);
	for (int cs = 1; cs <= t; ++cs)
	{
		double C, F, X;
		scanf("%lf%lf%lf", &C, &F, &X);
		printf("Case #%d: %.10f\n", cs, solve(C, F, X));
	}
	return 0;
}
