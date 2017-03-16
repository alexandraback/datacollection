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
	int t, n, k, i, j;
	char s[20000];
	char ch;
	sc("%d",&t);
	for( k=1;k<=t;k++)
	{
		sc("%c",&ch);
		sc("%s",s);
		n = strlen( s);
		vi v(26);
		for( i=0;i<n;i++ )
		{
			v[s[i]-65]++;
		}
		vi st(10);
		vi order(10);
		order[0] = 0;
		order[1]=2;
		order[2]=4;
		order[3]=6;
		order[4]=3;
		order[5]=1;
		order[6]=5;
		order[7]=8;
		order[8]=7;
		order[9]=9;
		for( j=0;j<10;j++)
		{
			i=order[j];
				if( i==0)
				{
					vi cal(4);
					cal[0] = v[25];
					cal[1] = v[4];
					cal[2] = v[14];
					cal[3] = v[17];
					sort(cal.begin(),cal.end());
					st[i] = cal[0];
					v[25] -= cal[0];
					v[4] -= cal[0];
					v[14] -= cal[0];
					v[17] -= cal[0];
				}
				else if( i==1)
				{
					vi cal(3);
					cal[0] = v[14];
					cal[1] = v[13];
					cal[2] = v[4];
					sort(cal.begin(),cal.end());
					st[i] = cal[0];
					v[14] -= cal[0];
					v[13] -= cal[0];
					v[4] -= cal[0];
				}
				else if( i==2)
				{
					vi cal(3);
					cal[0] = v[19];
					cal[1] = v[22];
					cal[2] = v[14];
					sort(cal.begin(),cal.end());
					st[i] = cal[0];
					v[19]-= cal[0];
					v[22]-=cal[0];
					v[14]-=cal[0];
				}
				else if( i==3)
				{
					vi cal(4);
					int mini;
					cal[0] = v[19];
					cal[1] = v[17];
					cal[2] = v[7];
					cal[3] = v[4];
					sort( cal.begin(),cal.begin()+3);
					mini = cal[0];
					mini = min( mini,cal[3]/2);
					v[19]-= mini;
					v[17] -=mini;
					v[7]-=mini;
					v[4]-=  2*mini;
					st[i]=mini;
				}
				else if( i==4)
				{
					vi cal(4);
					cal[0] = v[14];
					cal[1] = v[5];
					cal[2] = v[20];
					cal[3]=v[17];
					sort(cal.begin(),cal.end());
					st[i] = cal[0];
					v[14] -= cal[0];
					v[5] -= cal[0];
					v[20] -= cal[0];
					v[17] -= cal[0];
				}
				else if( i==5)
				{
					vi cal(4);
					cal[0] = v[4];
					cal[1] = v[5];
					cal[2] = v[8];
					cal[3]=v[21];
					sort(cal.begin(),cal.end());
					st[i] = cal[0];
					v[4] -= cal[0];
					v[5] -= cal[0];
					v[8] -= cal[0];
					v[21] -= cal[0];
				}
				else if( i==6)
				{
					vi cal(3);
					cal[0] = v[18];
					cal[1] = v[23];
					cal[2] = v[8];
					sort(cal.begin(),cal.end());
					st[i] = cal[0];
					v[18] -= cal[0];
					v[23] -= cal[0];
					v[8] -= cal[0];
				}
				else if( i==7)
				{
					vi cal(4);
					int mini;
					cal[0] = v[13];
					cal[1] = v[18];
					cal[2] = v[21];
					cal[3] = v[4];
					sort( cal.begin(),cal.begin()+3);
					mini = cal[0];
					mini = min( mini,cal[3]/2);
					v[13]-= mini;
					v[18] -=mini;
					v[21]-=mini;
					v[4]-=  2*mini;
					st[i]=mini;
				}
				else if( i==8)
				{
					vi cal(5);
					cal[0] = v[4];
					cal[1] = v[6];
					cal[2] = v[8];
					cal[3]=v[19];
					cal[4]=v[7];
					sort(cal.begin(),cal.end());
					st[i] = cal[0];
					v[4] -= cal[0];
					v[6] -= cal[0];
					v[8] -= cal[0];
					v[7] -= cal[0];
					v[19]-=cal[0];
				}
				else
				{
					vi cal(3);
					int mini;
					cal[0] = v[4];
					cal[1] = v[8];
					cal[2] = v[13];
					sort( cal.begin(),cal.begin()+2);
					mini = cal[0];
					mini = min( mini,cal[2]/2);
					v[4]-= mini;
					v[8] -=mini;
					v[13]-=  2*mini;
					st[i]=mini;
				}
				
		}
		pf("Case #%d: ",k);
		for( i=0;i<10;i++)
		{
			for(j=0;j<st[i];j++)
				pf("%d",i);
		}
		pf("\n");
	}
	//cin >> t;
//	cin >> n;
    return 0;
}
