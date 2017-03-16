#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define F(i,a,b) for(ll i=a;i<=b;i++)
#define ITR(x,c) for(__typeof(c.begin()) x=c.begin();x!=c.end();x++)
#define ALL(a) (a.begin()),(a.end())
#define ZERO(a) memset(a,0,sizeof(a))
#define mp make_pair
#define pb push_back 
#define X first
#define Y second
#define pi 3.14159265
#define MOD 1000000007 

ll revers(ll n){
	
	ll ans=0;
	
	while(n!=0)
	{
		ans*=10;
		ans+=n%10;
		n/=10;
    }
	
	return ans;
	
}

int main(){
    
   cin.sync_with_stdio(0);
   
   ll t;
   
   cin>>t;
   
   ll dp[1000010];
   
   F(i,1,1000000)
   dp[i]=i;
   
   F(i,1,1000000)
   {
		ll r=revers(i); 
		
		dp[i]=min(dp[i-1]+1,dp[i]);
		
		if(r>1000000)
		continue; 
		
		if(dp[i]+1<dp[r])
		dp[r]=dp[i]+1;
	   
   }
   
   F(T,1,t){
	   
	   ll n;
	   
	   cin>>n;
       
       cout<<"Case #"<<T<<": "<<dp[n]<<"\n";   
       
   }
  
    return 0;
  
}
