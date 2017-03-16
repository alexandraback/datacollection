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
	int t,test,c,d,v,i,sum,ans,num;
	cin>>t;
	for(test=1;test<=t;test++)
	{
		cin>>c>>d>>v;
		int arr[v+1];
		for(i=0;i<=v;i++) arr[i]=0;
		for(i=0;i<d;i++)
		{
			cin>>num;
			arr[num]=1;
		}
		sum=0; ans=0;
		for(i=1;i<=v;i++)
		{
			if(!arr[i])
			{
				if(sum<i)
				{
					sum+=i;
					ans++;
				}
			}
			else sum+=i;
		}
		cout<<"Case #"<<test<<": ";
		cout<<ans<<endl;
	}
	return 0;
}