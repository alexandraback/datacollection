#include <bits/stdc++.h>
using namespace std;

typedef long long LL;

const int N = int(2e7);

int dp[N], que[N];
LL tenTo[20];

map<LL, int> res;

inline LL flip (LL i)
{
	LL a = 0, b = i;
	while (b) a = a * 10 + b % 10, b /= 10;
	return a;
}

inline LL getNxt (LL x)
{
	int u = int(floor(log10(1.0 * x)));
	LL p = (u + 2) / 2, nxt;
	if (x <= tenTo[u] + tenTo[p])
	{
		nxt = tenTo[u] - tenTo[(u + 1) / 2];
	}
	else	
	{
		nxt = (x - 1) / tenTo[p] * tenTo[p];
	}
	return nxt;
}

int calc (LL x)
{
	if (x < 1000) return dp[x];
	if (res.count(x)) return res[x];
	LL nxt = getNxt(x);
	return res[x] = (x - nxt) + calc(flip(nxt + 1));
}

int main ()
{
#ifdef LOCAL
	freopen("in", "r", stdin);
#endif
	int tk;
	cin >> tk;
	dp[1] = 1;
	tenTo[0] = 1;
	for (int i = 1; i < 20; ++i) tenTo[i] = tenTo[i - 1] * 10LL;
	LL last = -1;
	for (int i = 2; i < N; ++i)
	{
		dp[i] = dp[i - 1] + 1;
		if (i % 10)
		{
			int a = 0, b = i;
			while (b) a = a * 10 + b % 10, b /= 10;
			if (a < i && dp[a] + 1 < dp[i])
			{
				last = i;
				dp[i] = dp[a] + 1;
			}
		}
		assert(i < 1000 || (i >= 1000 && getNxt(i) + 1 == last));
	}
/*	for (int i = 1002; i < N; ++i)
	{
		if (calc(i) != dp[i])
		{
			throw;
		}
		if (i % 100 == 0) printf("%d\n", i);
	}*/
	int t = 0;
	while (tk--)
	{
		LL s;
		cin >> s;
		cout << "Case #" << ++t << ": " << calc(s) << endl;
	}
}
