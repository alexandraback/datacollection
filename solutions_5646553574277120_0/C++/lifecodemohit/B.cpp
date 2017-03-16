/*
Author : lifecodemohit
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
		ll c,d,v,r,a[200],i,cnt=0,res;
		cin>>c>>d>>v;
		rep(i,1,v)
			a[i]=0;
		rep(i,0,d-1)
		{
			cin>>r;
			a[r]=1;
		}
		res=0;
		for(i=1;i<=v;i++)
		{
			if(res<i && a[i]==0)
			{
				cnt++;
				res+=i;
			//	cout<<i<<endl;
			}
			if(a[i]==1)
				res+=i;
		}
		printf("Case #%lld: %lld\n",r1,cnt);
		r1++;
	}
	return 0;
}