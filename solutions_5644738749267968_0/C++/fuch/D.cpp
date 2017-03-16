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

const int MAX_N = 1000;

int n;
double m1[MAX_N], m2[MAX_N];

int dp(double m1[], double m2[])
{
	static int f[MAX_N][MAX_N];
	for (int i = 0; i < n; ++i)
	{
		for (int j = 0; j < n; ++j)
		{
			f[i][j] = std::max((i > 0) ? f[i - 1][j] : 0, (j > 0) ? f[i][j - 1] : 0);
			int tmp = ((i > 0 && j > 0) ? f[i - 1][j - 1] : 0) + ((m1[i] < m2[j]) ? 1 : 0);
			f[i][j] = std::max(f[i][j], tmp);
		}
	}
	return f[n - 1][n - 1];
}

int solve1()
{
	return dp(m2, m1);
}

int solve2()
{
	return n - dp(m1, m2);
}

int main()
{
	int t;
	scanf("%d", &t);
	for (int cs = 1; cs <= t; ++cs)
	{
		scanf("%d", &n);
		for (int i = 0; i < n; ++i) scanf("%lf", &m1[i]);
		for (int i = 0; i < n; ++i) scanf("%lf", &m2[i]);
		std::sort(m1, m1 + n);
		std::sort(m2, m2 + n);
		printf("Case #%d: %d %d\n", cs, solve1(), solve2());
	}
	return 0;
}
