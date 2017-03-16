#include <bits/stdc++.h>
using namespace std;
#define rep(i,a,b) for(i=a;i<b;++i)
#define repi(i,a,b) for(int i=a;i<b;++i)

#define repl(i,a,b) for(long long int i=a;i<b;++i)
#define F first
#define S second
#define mp(a,b) make_pair(a,b)
#define pii pair<int,int>
#define ppi pair<pii,int>
#define ppp pair<pii,pii>
#define vi vector<int>
#define sc(a) scanf("%d",&a)
#define pb(x) push_back(x)
long long int a[1000001];
long long int rev(long long int i)
{
	long long j=0;
	while(i>0)
	{
		j=j*10 + (i%10);
		i/=10;
	}
	return j;
}
int main()
{
	int t;
	cin>>t;
	repl(i,0,1000001)a[i]=i;

	repl(i,1,1000001)
	{
		long long j = rev(i);
		a[i] = min(a[i],a[i-1]+1);
		a[j] = min(a[j],a[i]+1);
		//cout<<i<<" "<<j<<" "<<a[i]<<endl;
	}
	repi(t_in,1,t+1)
	{
		long long x;
		cin>>x;
		cout<<"Case #"<<t_in<<": "<<a[x]<<endl;
	}
	return 0;
}