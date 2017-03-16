/*
Author : lifecodemohit
Problem : http://www.codechef.com/MAY15/problems/CHEFCK
*/
 
#include <bits/stdc++.h>
using namespace std;
 
#define ll long long int
#define MOD 1000000007
#define sn(n) scanf("%lld",&n)
#define pn(n) printf("%lld\n",n)
#define ss(str) scanf("%s",str)
#define ps(str) printf("%s\n",str)
#define rep(i,s,e) for(i=s;i<=e;i++)
#define reprev(i,s,e) for(i=s;i>=e;i--)
#define reps(b,e,g,str) for(b=str,e=&str[g-1];b<=e;b++) 
#define mem(arr,val) memset(arr,val,sizeof(arr))
#define dis(arr,s,e) for(i=s;i<=e;i++) printf("%lld ",arr[i]); printf("\n"); 

int main()
{
	ll t,r1=1;
	cin>>t;
	while(r1<=t)
	{
		ll r,c,w,res,ans;
	cin>>r>>c>>w;
	res=c/w;
	if((w-1)>=0)
	{
		if((c-res*w)==0)
			ans=res+w-1;
		else
			ans=res+w;
	}
	else
		ans=res;
	printf("Case #%lld: %lld\n",r1,ans);
	r1++;
	}
	return 0;
}