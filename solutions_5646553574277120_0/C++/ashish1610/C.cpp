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
int ar[105];
bool covered[105];
int main()
{
	int t, tcase;
	si(t);
	rep(tcase, 1, t)
	{
		memset(covered, false, sizeof(covered));
		int c, d, v;
		cin>>c>>d>>v;
		int i, j;
		rep(i, 0, d - 1)
		{
			cin>>ar[i];
			covered[ar[i]] = true;
		}
		sort(ar, ar + d);
		rep(i, 0, (1 << d) - 1)
		{
			int sum = 0;
			rep(j, 0, d - 1)
			{
				if(i & (1 << j))
					sum += ar[j];
			}
			covered[sum] = true;
		}
		int ans = 0;
		rep(i, 1, v)
		{
			if(!covered[i])
			{
				ans++;
				vector<int> nC;
				rep(j, 0, v)
					if(covered[j])
						nC.push_back(i + j);
				rep(j, 0, (int)(nC.size() - 1))
					covered[nC[j]] = true;
			}
		}
		cout<<"Case #"<<tcase<<": ";
		cout<<ans<<endl;
	}
	return 0;
}