#include<bits/stdc++.h>
/*#include <boost/multiprecision/cpp_int.hpp> */
#define ll long long
#define pb push_back
#define mp make_pair
#define mod 1000000007
#define gc getchar_unlocked
#define pp pair<int,int>
#define bigint boost::multiprecision::cpp_int
#define bsize 600
using namespace std;

ll rev(ll val)
{
	vector<int> v;
 
	do
	{
		v.pb(val%10);
		val/=10;
	}while(val);

	reverse(v.begin(),v.end());
	ll res=0,curr=1;

   for(auto i:v)
   {
   	res+=curr*i;
   	curr*=10;
   }

   return res;
}

ll dp[10000000];
ll solve(ll val)
{
	if(val==1)return 1LL;
	if(dp[val]>=0)return dp[val];
	
    ll temp=rev(val);
	if(temp<val && rev(temp)==val)return dp[val]=min(solve(temp)+1LL,solve(val-1)+1LL);
	return dp[val]=solve(val-1)+1LL;
}
int main()
{
	ll T,cas=1;
	ll n;
 scanf("%lld",&T);
memset(dp,-1,sizeof(dp));

for(ll i=1;i<=1000000;i++)dp[i]=solve(i);
	while(T--)
	{
	

      scanf("%lld",&n);
     ll an=dp[n];



	cout<<"Case #"<<cas++<<": "<<an<<"\n";
	}
return 0;
}