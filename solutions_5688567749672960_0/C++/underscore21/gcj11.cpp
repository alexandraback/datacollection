/*
** lovish_21/underscore21/lovish21 **
*/
#include <bits/stdc++.h>
#define ll long long
#define mp make_pair
#define pb push_back
#define try1(a) cout<<a<<endl;
#define try2(a,b) cout<<a<<" "<<b<<" "<<endl;
#define try3(a,b,c) cout<<a<<" "<<b<<" "<<c<<endl;
#define try4(a,b,c,d) cout<<a<<" "<<b<<" "<<c<<" "<<d<<endl;



using namespace std;

int main() {
	
	
freopen("inp3.txt","r",stdin);

freopen("out3.txt","w",stdout);

	ll t;
	ll dp[1000006]={};
	dp[1]=1;
	dp[2]=2;
	for(ll i=3;i<1000006;i++)
	{
		ll rev=0,temp=i;
		while(temp)
		{
			rev=rev*10+(temp%10);
			temp/=10;
		}
		// try2(i,rev);
		if(rev<i && i%10!=0)
		{
		
			dp[i]=min(dp[i-1],dp[rev])+1;
		}
		else
		{
			dp[i]=dp[i-1]+1;
		}
		
	}
	
	// for(ll i=0;i<23;i++)
	// try1(dp[i]);
	cin>>t;
	ll k=0;
	while(t--)
	{
		k++;
		ll n;
		cin>>n;
		// Case #1:
		cout<<"Case #"<<k<<": "<<dp[n]<<endl;
		
	}
	
	return 0;
}