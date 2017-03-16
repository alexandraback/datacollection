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
/*
i = 2
j = 3
k = 4
*/
int ar[4][4] = 
{
	{1,2,3,4},
	{2,-1,4,-3},
	{3,-4,-1,2},
	{4,3,-2,-1}
};
int main()
{
	int t, tcase;
	si(t);
	rep(tcase, 1, t)
	{
		ll l, x;
		sl(l);
		sl(x);
		string str;
		cin>>str;
		string final_str = "";
		int i;
		if(l * x <= 100000000)
		{
			l = l * x;
			rep(i, 1, x)
				final_str += str;
		}
		else if(x <= 8)
		{
			l = l * x;
			rep(i, 1, x)
				final_str += str;
		}
		else if(x % 8 != 0)
		{
			l = l * (x % 8);
			rep(i, 1, x % 8)
				final_str += str;
		}
		else if(x % 8 == 0)
		{
			l = l * 8;
			rep(i, 1, 8)
				final_str += str;
		}
		ll forw = 0, back = l - 1, val = 1;
		bool flag = true;
		while(forw < l - 1 && val != 2)
		{
			if(final_str[forw] == 'i')
			{
				int sgn = (val < 0) ? -1 : 1;
				val = ar[abs(val) - 1][1];
				val = val * sgn;
			}
			else if(final_str[forw] == 'j')
			{
				int sgn = (val < 0) ? -1 : 1;
				val = ar[abs(val) - 1][2];
				val = val * sgn;
			}
			else
			{
				int sgn = (val < 0) ? -1 : 1;
				val = ar[abs(val) - 1][3];
				val = val * sgn;
			}
			++forw;
		}
		if(val != 2)
			flag = false;
		val = 1;
		while(flag && back >= 0 && val != 4)
		{
			if(final_str[back] == 'i')
			{
				int sgn = (val < 0) ? -1 : 1;
				val = ar[1][abs(val) - 1];
				val = val * sgn;
			}
			else if(final_str[back] == 'j')
			{
				int sgn = (val < 0) ? -1 : 1;
				val = ar[2][abs(val) - 1];
				val = val * sgn;
			}
			else
			{
				int sgn = (val < 0) ? -1 : 1;
				val = ar[3][abs(val) - 1];
				val = val * sgn;
			}
			--back;
		}
		if(val != 4)
			flag = false;
		val = 1;
		rep(i, forw, back)
		{
			if(final_str[i] == 'i')
			{
				int sgn = (val < 0) ? -1 : 1;
				val = ar[abs(val) - 1][1];
				val = val * sgn;
			}
			else if(final_str[i] == 'j')
			{
				int sgn = (val < 0) ? -1 : 1;
				val = ar[abs(val) - 1][2];
				val = val * sgn;
			}
			else
			{
				int sgn = (val < 0) ? -1 : 1;
				val = ar[abs(val) - 1][3];
				val = val * sgn;
			}
		}
		if(val != 3)
			flag = false;
		printf("Case #%d: ", tcase);
		if(flag && forw <= back)
			printf("YES\n");
		else
			printf("NO\n");
	}
	return 0;
}