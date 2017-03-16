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
		int n;
		cin>>n;
		ll d1, d2, h1, h2, m1, m2;
		if(n == 1)
			cin>>d1>>h1>>m1;
		else
			cin>>d1>>h1>>m1>>d2>>h2>>m2;
		cout<<"Case #"<<tcase<<": ";
		if(n == 1 && h1 <= 1)
			cout<<"0\n";
		else
		{
			if(n == 1)
			{
				m2 = m1 + 1;
				d2 = d1;
				h2 = 0;
			}
			d1 = 360 - d1;
			d2 = 360 - d2;
			if(m1 < m2)
			{
				if((d1 + 360) * m1 > d2 * m2)
					cout<<"0\n";
				else
					cout<<"1\n";
			}
			else
			{
				if((d2 + 360) * m2 > d1 * m1)
					cout<<"0\n";
				else
					cout<<"1\n";
			}
		}
	}
	return 0;
}