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
vector<string> v;
void dfs(int rem, int n, string str, string res)
{
	if(rem < 0)
		return;
	if(rem == 0)
	{
		v.push_back(res);
		return;
	}
	int i;
	rep(i, 0, n - 1)
		dfs(rem - 1, n, str, res + str[i]);
}
int main()
{
	int t, tcase;
	si(t);
	rep(tcase, 1, t)
	{
		v.clear();
		int n, m, s, i, j, k;
		cin>>n>>m>>s;
		string str1, str2;
		cin>>str1>>str2;
		string res = "";
		dfs(s, n, str1, res);
		int sz = v.size();
		int val = 0, tc = 0;
		rrep(i, sz - 1, 0)
		{
			int cnt = 0;
			int len = v[i].length();
			rep(j, 0, len - 1)
			{
				bool flag = false;
				rep(k, 0, m - 1)
				{
					if(j + k >= len || v[i][j + k] != str2[k])
					{
						flag = true;
						break;
					}
				}
				if(!flag)
					cnt++;
			}
			tc += cnt;
			val = max(val, cnt);
		}
		cout<<"Case #"<<tcase<<": ";
		if(tc == 0 || v.size() == 0 || val == 0)
			printf("0.000000\n");
		else
		{
			double res = tc;
			res /= v.size();
			double final_res = val;
			final_res -= res;
			printf("%.6lf\n", final_res);
		}
	}
	return 0;
}