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
int lps[105];
void computeLPSArray(string pat, int len)
{
	int i = 1, j = 0;
	lps[0] = 0;
	while(i < len)
	{
		if(pat[i] == pat[j])
		{
			j++;
			lps[i] = j;
			i++;
		}
		else
		{
			if(j != 0)
				j = lps[j - 1];
			else
			{
				lps[i] = 0;
				i++;
			}
		}
	}
}
double dp[105][105];
int cnt_dp[105][105];
int n, m, s;
string str1, str2;
double f(int pos, int pre)
{
	if(dp[pos][pre] != -1.0)
		return dp[pos][pre];
	if(pos == s)
		return 0.0;
	double res = 0.0;
	int i;
	rep(i, 0, n - 1)
	{
		double val = 0.0;
		int tmp = pre;
		while((str2[tmp] != str1[i]) && tmp > 0)
			tmp = lps[tmp - 1];
		if(tmp == 0 && str2[0] != str1[i])
			tmp = 0;
		else
			tmp++;
		if(tmp == m)
		{
			val = 1.0;
			tmp = lps[tmp - 1];
		}
		res = res + (1.0 / n) * (val + f(pos + 1, tmp));
	}
	return dp[pos][pre] = res;
}
int f1(int pos, int pre)
{
	if(cnt_dp[pos][pre] != -1)
		return cnt_dp[pos][pre];
	if(pos == s)
		return 0;
	int res = 0;
	int i;
	rep(i, 0, n - 1)
	{
		int val = 0;
		int tmp = pre;
		while((str2[tmp] != str1[i]) && tmp > 0)
			tmp = lps[tmp - 1];
		if(tmp == 0 && str2[0] != str1[i])
			tmp = 0;
		else
			tmp++;
		if(tmp == m)
		{
			val = 1;
			tmp = lps[tmp - 1];
		}
		res = max(res, val + f1(pos + 1, tmp));
	}
	return cnt_dp[pos][pre] = res;
}
int main()
{
	int t, tcase;
	si(t);
	rep(tcase, 1, t)
	{
		int i, j, k;
		cin>>n>>m>>s;
		cin>>str1>>str2;
		
		rep(i, 0, 104)
		{
			rep(j, 0, 104)
			{
				dp[i][j] = -1.0;
				cnt_dp[i][j] = -1;
			}
		}
		computeLPSArray(str2, str2.length());
		
		double res1 = f(0, 0);
		
		int res2 = f1(0, 0);
		
		double final_res = fabs(res2 * 1.0 - res1);
		cout<<"Case #"<<tcase<<": ";
		printf("%.6lf\n", final_res);
	}
	return 0;
}