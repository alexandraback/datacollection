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
int main()
{
	int t, tcase;
	si(t);
	rep(tcase, 1, t)
	{
		int smax, len, i, cnt = 0;
		si(smax);
		string str;
		cin>>str;
		len = str.length();
		int ans = 0;
		rep(i, 0, len - 1)
		{
			if(cnt >= i)
				cnt += (str[i] - '0');
			else if(str[i] != '0')
			{
				ans += (i - cnt);
				cnt += (i - cnt + str[i] - '0');
			}
		}
		printf("Case #%d: ", tcase);
		pi(ans);
		pn;
	}
	return 0;
}