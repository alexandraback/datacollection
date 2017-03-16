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
	int t,r,c,w,ans,test,k;
	cin>>t;
	for(test=1;test<=t;test++)
	{
		cin>>r>>c>>w;
		ans=0;
		k=(r-1)*(c/w);
		while(c>=2*w)
		{
			c-=w;
			ans++;
		}
		if(c==w) c=0; else c=1;
		cout<<"Case #"<<test<<": ";
		cout<<ans+w+k+c<<endl;
	}
	return 0;
}