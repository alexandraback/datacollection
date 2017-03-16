#include <iostream>
#include <string>
#include <iterator>
#include <vector>
#include <ctime>
#include <map>
#include <memory.h>
#include <cstdio>

using namespace std;

#define FOR(i, a, b) for(int i=(a), _b(b); i<_b; i++)
#define FORD(i, b, a) for(int i=(b)-1, _a(a); i>=_a; i--)
#define HAS(a, b) ((a).find(b) != (a).end())
#define SZ(a) (int)(a).size()
#define FILL(a, b) memset(a, b, sizeof(a))

typedef long long LL;
typedef vector<int> VI;
typedef pair<int, int> PII;
typedef pair<int, LL> PIL;

int n, p;
int t[111];
int dp[111][111];

int Rec(int pos, int left)
{
	if (pos==n) return (left>0)*(-1000000);

	int& res = dp[pos][left];
	if (res != -1) return res;

	res = 0;
	int a, b, c;
	FOR(k, 0, 11)
	{
		if (3*k>t[pos]) break;

		if (left)
		{
			a = k; b = k+2; c = t[pos]-a-b; if (a>b) swap(a, b); if (a>c) swap(a, c); if (b>c) swap(b, c);
			if (0<=a && a<=b && b<=c && c<=10 && a+2==c)
				res = max(res, Rec(pos+1, left-1) + (c>=p));
		}

		a = k; b = (t[pos]-a)/2; c = t[pos]-a-b; if (a>b) swap(a, b); if (a>c) swap(a, c); if (b>c) swap(b, c);
		if (0<=a && a<=b && b<=c && c<=10 && a+1>=c)
			res = max(res, Rec(pos+1, left) + (c>=p));
	}

	return res;
}

int main()
{
#ifdef ALMAG_LOCAL
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif

	int tc, ind=0; scanf("%d", &tc);

	while (tc --> 0)
	{
		int s; scanf("%d %d %d", &n, &s, &p);
		FOR(i, 0, n) scanf("%d", t+i);
		
		FILL(dp, -1);
		printf("Case #%d: %d\n", ++ind, Rec(0, s));
	}

    return 0;
}
