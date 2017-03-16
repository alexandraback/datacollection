#include <cstdio>
#include <cstring>

long long a, b, k;

long long dp[64][2][2][2];

long long getDP(int p, bool la, bool lb, bool lk)
{
	if (p < 0)
		return 1;
	if (dp[p][la][lb][lk] != -1)
		return dp[p][la][lb][lk];
	long long sol = 0;
	long long po = (1LL << p);

	if (lk)
	{
		bool nla, nlb;

		nla = la; nlb = lb;
		if (a & po)
			nla = 1;
		if (b & po)
			nlb = 1;
		sol += getDP(p - 1, nla, nlb, lk);

		nla = la; nlb = lb;
		if (a & po)
			nla = 1;
		if (lb || (b & po))
			sol += getDP(p - 1, nla, nlb, lk);

		nla = la; nlb = lb;
		if (b & po)
			nlb = 1;
		if (la || (a & po))
			sol += getDP(p - 1, nla, nlb, lk);

		nla = la; nlb = lb;
		if ((la || (a & po)) && (lb || (b & po)))
			sol += getDP(p - 1, nla, nlb, lk);

		//~ printf("DP %d %d %d %d :: %lld\n", p, la, lb, lk, sol);
		return (dp[p][la][lb][lk] = sol);
	}

	if (!(k & po))
	{
		// Can't have this bit!
		// Either A or B has a zero.

		// 0 ; 0
		bool nla = la, nlb = lb;
		if (a & po)
		{
			nla = true;
		}

		if (b & po)
		{
			nlb = true;
		}
		sol += getDP(p - 1, nla, nlb, lk);

		// 0 ; 1
		nla = la; nlb = lb;
		if (a & po)
			nla = true;
		if (lb || (b & po))
		{
			sol += getDP(p - 1, nla, nlb, lk);
		}

		// 1 ; 0
		nla = la; nlb = lb;
		if (b & po)
			nlb = true;
		if (la || (a & po))
		{
			sol += getDP(p - 1, nla, nlb, lk);
		}
	}
	else
	{
		// If I put 0, I am good..
		bool nla, nlb;

		// 0 ; 0
		nla = la; nlb = lb;
		if (a & po)
			nla = 1;
		if (b & po)
			nlb = 1;
		sol += getDP(p - 1, nla, nlb, 1);

		// 0 ; 1
		nla = la; nlb = lb;
		if (a & po)
			nla = 1;
		if (lb || (b & po))
			sol += getDP(p - 1, nla, nlb, 1);

		// 1 ; 0
		nla = la; nlb = lb;
		if (b & po)
			nlb = 1;
		if (la || (a & po))
			sol += getDP(p - 1, nla, nlb, 1);

		// put 1!

		if ((la || (a & po)) && (lb || (b & po)))
		{
			sol += getDP(p - 1, la, lb, lk);
		}
	}

	dp[p][la][lb][lk] = sol;
	//~ printf("DP %d %d %d %d :: %lld\n", p, la, lb, lk, sol);
	return dp[p][la][lb][lk];
}

int main()
{
	int t, T;
	scanf("%d", &T);
	for (t = 1; t <= T; ++t)
	{
		scanf("%lld %lld %lld", &a, &b, &k);
		--a; --b; --k;
		memset(dp, -1, sizeof(dp));
		printf("Case #%d: %lld\n", t, getDP(33, 0, 0, 0));
	}
	return 0;
}
