#include<iostream>
#include<cstdio>
#include<cmath>
#include<vector>
#include<map>
#include<set>
#include<algorithm>
#include<list>
#include<cstring>
#include<stack>
#include<queue>
using namespace std;
#define ll long long
#define vi vector<int>
#define vii vector<vi >
#define pp pair<int,int>
#define pb push_back
#define mp make_pair
#define ppl pair<ll,ll>
#define vl vector<ll>
#define vll vector<vl >
#define vb vector<bool>
#define llu unsigned ll
#define all(c) c.begin(),c.end()
#define mod 1000000007
#define sc scanf
#define pf printf
ll power(ll a,ll b)
{
	if(!b)
		return 1;
	if(b==1)
		return a;
	ll temp=power(a,b/2);
	temp=(temp*temp)%mod;
	if(b&1)
		temp=(temp*a)%mod;
	return temp;
}
 vl dp(10001);
void solve()
{
	int i;
	dp[0] = 1;
	for( i=1;i<=10000;i++ )
	{
		dp[i] = (dp[i-1]*i)%mod;
	}
}
ll ncr( int n,int k )
{
	k = max( k, n-k);
	if( n==k )
		return 1;
	int i;
	ll ans1, ans2;
	ans1 = dp[n];
	ans1 = (ans1*power(dp[k], mod-2) )%mod;
	ans2 = power( dp[n-k], mod-2);
	ans1 = (ans1*ans2)%mod;
	return ans1;
}
int main()
{
	//ios_base::sync_with_stdio(false);
	//solve();
	freopen( "in.txt","r", stdin );
	freopen( "out.txt", "w", stdout);
	int t, n, k, i, j, ans;
	string s1,s2;
	char ch;
	sc("%d",&t);
	for( k=1;k<=t;k++)
	{
		ans = 0;
		sc("%d",&n);
		map<string,vi > m1,m2;
		vb v(n);
		for( i=0;i<n;i++ )
		{
			cin >> s1 >> s2;
			m1[s1].pb(i);
			m2[s2].pb(i);
		}
		map<string,vi >::iterator it;
		for( it=m1.begin();it!=m1.end();it++ )
		{
			if( (it->second).size() == 1)
			{
				v[*((it->second).begin())]= true;
			}
		}
		for( it=m2.begin();it!=m2.end();it++ )
		{
			if( (it->second).size() == 1)
			{
				v[*((it->second).begin())]= true;
			}
		}
		for( i=0;i<n;i++ )
		{
			if(!v[i])
				ans++;
		}
		pf("Case #%d: %d",k,ans);
		pf("\n");
	}
	//cin >> t;
//	cin >> n;
    return 0;
}
