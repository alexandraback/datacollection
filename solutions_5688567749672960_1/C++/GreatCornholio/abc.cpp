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

//find largest palindrome, smallest than this number

ll len(ll n){
	
	ll ans=0;
	
	while(n!=0)
	{
		ans++;
		n/=10;
		
	}
	
	return ans;
	
}

ll palin(ll n){
	
	ll arr[20]={0};
	
	ll temp=n;

	ll i=0;

	while(temp!=0)
	{
			arr[i++]=temp%10;
			
			temp/=10;
	}
	
	for(ll j=0;j<=i/2;j++)
	arr[j]=arr[i-j-1];
	
	ll ans=0;
	
	for(ll j=0;j<i;j++)
	{
		ans*=10;
		ans+=arr[j];
		
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
	   
	   ll ans=0;
	   
	   while(n>0)
	   {
		   
		    if(n<=1000000)
		    {
				ans+=dp[n];
				n=0;
				
				continue;
			}
		    
		    if(n%10!=0)  //make LSB 1
		    {
			    ans+=(n%10)-1;	
				n=n-n%10;
				n+=1;
			}
			else {
			
			    n--;
			   ans++;
			}
			
			if(n==0)
			continue;
			
			ll r=revers(n);
		    
		    ll p=palin(n);
		    
		    if(r<n && len(r)==len(n)) //reversing beneficial
		    {
				ans++;
				
				n=r;
			}
			
			else if( r>=n && p<=n){ //finding palindrome is beneficial
		
				ans+=n-p+1;
				
				n=p-1;	
				
			}
			
			else { //just decrement
			
				ans++;
				n--;	
				
			}
		   
		   
	   }
       
       
       cout<<"Case #"<<T<<": "<<ans<<"\n";   
       
   }
  
    return 0;
  
}
