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

const int maxV = 10000001;
int a[10001], n, nxt[10001];
LL r, e;
int dp[10][10];
int f[maxV+10];

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

void fAdd(int pos, int t)
{
	pos = maxV-pos+1;
	for(int x=pos; x <= maxV; x|=(x+1))
		f[x] = min(f[x], t);
}

int fGet(int pos)
{
	pos = maxV-pos+1;
	int res = maxV;
	for(int x=pos; x>=0; x=(x&(x+1))-1)
		res = min(res, f[x]);

	return res;
}

LL Solve()
{
	FOR(i, 0, maxV+1) f[i] = 100000000;
	fAdd(maxV, n);
	FORD(i, n, 0)
	{
		nxt[i] = fGet(a[i]);
		fAdd(a[i], i);
	}

	LL res = 0, curr = e;
	FOR(i, 0, n)
	{
		if (nxt[i] == n)
		{
			res += (LL)a[i]*curr;
			curr = 0;
		}
		else
		{
			int diff = nxt[i] - i;
			if ((LL)diff*r+curr<e) goto step;

			LL t = (LL)diff*r+curr-e;
			t = min(curr, t);

			res += (LL)a[i]*t;
			curr -= t;
		}

step:
		curr = min(curr+r, e);
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
		
		scanf("%lld %lld %d", &e, &r, &n);
		FOR(i, 0, n) scanf("%d", a+i);
		r = min(r, e);

		LL res = Solve();

		printf("Case #%d: %lld\n", ind, res);
	}

	return 0;
}