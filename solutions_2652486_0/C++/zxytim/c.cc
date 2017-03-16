/*
 * $File: c.cc
 * $Date: Sat Apr 27 10:56:28 2013 +0800
 * $Author: Xinyu Zhou <zxytim[at]gmail[dot]com>
 */

#include <cstdio>
#include <cstring>
#include <map>
#include <vector>

using namespace std;

typedef long long ll;
typedef long double ld;

// <perm, prod> -> count (prob)
map<ll, map<ll, ll> > count;

// <perm, prod> -> P(perm | prod) = count[perm][prod] / count(prod)
map<ll, map<ll, ld> > P;

ld perm_prob[100000];
int r, n, m, K;
ll perm[1000000];
int nperm;
void solve()
{
	printf("\n");
	scanf("%d%d%d%d", &r, &n, &m, &K);
	for (int case_id = 0; case_id < r; case_id ++)
	{
		int prod[20] = {0};
		memset(perm_prob, 0, sizeof(perm_prob[0]) * nperm);
		ll ans = -1;
		ld pr = -1;
		for (int i = 0; i < K; i ++)
		{
			scanf("%d", prod + i);
			for (int p = 0; p < nperm; p ++)
			{
				ll per = perm[p];
				ld pr0 = P[per][prod[i]];
				perm_prob[p] += pr0;
			}
		}
		for (int p = 0; p < nperm; p ++)
		{
			ld pr0 = perm_prob[p];
			if (pr0 > pr)
				pr = pr0, ans = perm[p];
		}
		/*
		for (int i = 0; i < nperm; i ++)
			if (perm_prob[i] > 0)
				printf("%lld, %Lf\n", perm[i], perm_prob[i]);
		*/
		printf("%lld\n", ans);
	}
}

void dfs(ll perm, ll prod, int step)
{
	if (step == 0)
		count[perm][prod] += 1;
	else
		for (int i = 2; i <= m; i ++)
			dfs(perm * 10 + i, prod * i, step - 1);
}

void init()
{
	n = 3;
	m = 5;
	K = 7;

	dfs(0, 1, n);

	nperm = 0;
	for (auto &a: count)
	{
		perm[nperm ++] = a.first;
		for (auto &b: a.second)
			P[a.first][b.first] = count[a.first][b.first] / (ld)a.second.size();
	}
}

int main()
{
	init();
	int ncase;
	scanf("%d", &ncase);
	for (int i = 1; i <= ncase; i ++)
	{
		printf("Case #%d: ", i);
		solve();
	}
	return 0;
}


/**
 * vim: syntax=cpp11 foldmethod=marker
 */

