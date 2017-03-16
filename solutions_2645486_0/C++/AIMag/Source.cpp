#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <cmath>

using namespace std;

#define SZ(a) (int)(a).size()
#define FILL(a, b) memset(a, b, sizeof(a))
#define FOR(i, a, b) for(int i=(a), _b(b); i<_b; i++)
#define FORD(i, b, a) for(int i=(b)-1, _a(a); i>=_a; i--)

typedef vector<int> VI;
typedef pair<int, int> PII;
typedef long long LL;

int a[10], n, r, e;
int dp[10][10];

int Rec(int pos, int en)
{
	if (pos >= n) return 0;

	int& res = dp[pos][en];
	if (res != -1) return res;

	FOR(i, 0, en+1)
	{
		res = max(res, Rec(pos+1, min(e, en-i+r)) + i*a[pos]);
	}

	return res;
}

int main()
{
	freopen("Input.txt", "r", stdin);
	freopen("Output.txt", "w", stdout);

	int tc, ind=0; scanf("%d", &tc);

	while (tc --> 0)
	{
		ind++;
		
		scanf("%d %d %d", &e, &r, &n);
		FOR(i, 0, n) scanf("%d", a+i);

		FILL(dp, -1);

		int res = Rec(0, e);

		printf("Case #%d: %lld\n", ind, res);
	}

	return 0;
}