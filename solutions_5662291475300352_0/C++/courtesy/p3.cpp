/*  Vivek Kantariya  */
#include<iostream>
#include<string>
#include<vector>
#include<map>
#include<set>
#include<algorithm>
#include<utility>
#define PB push_back
#define pii pair<int,int>
#define MP make_pair
#define sz size()
#define fi first
#define se second
using namespace std;
typedef long long ll;
vector<pair<ll,ll> > a;
ll intr(int sp,int p)
{
	ll t1,t2,t3;
	t1=a[sp].fi*a[sp].se-a[p].fi*a[p].se;
	if(t1<0)return 0;
	t2=t1/(a[p].se*360);
	return t2+1;
}
int main()
{
	int t,i,j,k,cs,css;
	int t1,t2,t3;
	ll p1,p2,p3;
	cin>>css;
	for(cs=1;cs<=css;cs++)
	{
		cout<<"Case #"<<cs<<": ";
		cin>>k;
		a.clear();
		for(i=0;i<k;i++)
		{
			cin>>t1>>t2>>t3;
			for(j=0;j<t2;j++)a.PB(MP(t1,t3+j));
		}
		sort(a.begin(),a.end());
		ll ans=a.sz;
		for(i=0;i<a.sz;i++)
		{
			k=0;
			for(j=1;j<=i;j++)
			{
				if(a[k].fi*a[k].se<a[j].fi*a[j].se)k=j;
			}
			p1=a.sz-i-1;
			for(j=0;j<=i;j++)
			{
				if(j==k)continue;
				p2=intr(k,j);
				if(p2>0)p2--;
				p1+=p2;
			}
			for(j=i+1;j<a.sz;j++)
			{
				p2=intr(k,j);
				p1+=p2;
			}
			if(p1<ans)ans=p1;
		}
		cout<<ans<<endl;
	}
	return 0;
}
