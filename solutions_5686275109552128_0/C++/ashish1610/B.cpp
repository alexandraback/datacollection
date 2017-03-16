/*
ID: ashish1610
PROG:
LANG: C++
*/
#include<bits/stdc++.h>
using namespace std;
#define ll				long long int
#define vi				vector<int>
#define vl				vector<ll>
#define	pii				pair<int,int>
#define pil				pair<int, ll>
#define pll				pair<ll, ll>
#define pli 			pair<ll, int>
#define pb(v, a)		v.push_back(a)
#define mp(a, b)		make_pair(a, b)
#define MOD				1000000007
#define rep(i, a, b)	for(i=a; i<=b; ++i)
#define rrep(i, a, b)	for(i=a; i>=b; --i)
#define si(a)			scanf("%d", &a)
#define sl(a)			scanf("%lld", &a)
#define pi(a)			printf("%d", a)
#define pl(a)			printf("%lld", a)
#define pn 				printf("\n")
ll pow_mod(ll a, ll b)
{
	ll res = 1;
	while(b)
	{
		if(b & 1)
			res = (res * a) % MOD;
		a = (a * a) % MOD;
		b >>= 1;
	}
	return res;
}
int p[1005];
int main()
{
	int t, tcase;
	si(t);
	rep(tcase, 1, t)
	{
		int d, i, j, maxx = 0, ans;
		si(d);
		int p[d];
		rep(i, 0, d - 1)
		{
			si(p[i]);
			maxx = max(maxx, p[i]);
			ans = maxx;
		}
		rep(i, 1, maxx)
		{
			int tmp_ans = 0, tmp_max = 0;
			rep(j, 0, d - 1)
			{
				if(i >= p[j])
					tmp_max = max(tmp_max, p[j]);
				else
				{
					tmp_ans += ((p[j] + i - 1) / i - 1);
					tmp_max = max(tmp_max, i);
				}
			}
			ans = min(ans, tmp_max + tmp_ans);
		}
		printf("Case #%d: ", tcase);
		pi(ans);
		pn;
	}
	return 0;
}