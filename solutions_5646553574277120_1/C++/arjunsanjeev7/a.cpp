#include <bits/stdc++.h>

#define PB push_back
#define MP make_pair
#define F first
#define S second
#define SET(a,b) memset(a,b,sizeof(a))
#define LET(x,a) __typeof(a) x(a)
#define si(n) scanf("%d",&n)
#define pi(n) printf("%d",n)
#define piw(n) printf("%d ",n)
#define pin(n) printf("%d\n",n)
#define sorti(a) sort(a.begin(),a.end())
#define sortd(a) sort(a.begin(),a.end(),greater<__typeof(a[0])>()) 
#define LEN(s) s.length
#define SZ(s) s.size()

#define LL long long int
#define PII pair<int,int>
#define VI vector<int>
#define VPII vector< PII >
#define mod 1000000007
#define INF 2000000000

using namespace std;

int main()
{
	LL t,test,c,d,v,i,sum,ans,num,x;
	cin>>t;
	for(test=1;test<=t;test++)
	{
		cin>>c>>d>>v;
		LL arr[d+1];
		for(i=0;i<d;i++)
		{
			cin>>arr[i];
		}
		sum=0; ans=0; arr[d]=v+1;
		if(arr[0]!=1)
		{
			sum=1;
			ans++;
		}
		for(i=0;i<d+1;i++)
		{
			x=arr[i];
			while(c*sum<x && c*sum+1!=x)
			{
				sum+=(c*sum+1);
				ans++;
			}
			sum+=x;
		}
		cout<<"Case #"<<test<<": ";
		cout<<ans<<endl;
	}
	return 0;
}