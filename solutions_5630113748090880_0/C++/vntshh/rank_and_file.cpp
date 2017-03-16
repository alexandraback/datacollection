//Author: Vineet Shah
//IIT Indore
#include<bits/stdc++.h>
#define rep(i,start,lim) for(long long i=start;i<lim;i++)
#define repd(i,start,lim) for(long long i=start;i>=lim;i--)
#define MOD 1000000007
#define scan(x) scanf("%lld",&x)
#define print(x) printf("%lld",x)
#define sz(a) int((a).size())
#define pb push_back
#define mp make_pair
#define all(c) (c).begin(),(c).end()
#define present(c,x) ((c).find(x) != (c).end())
#define cpresent(c,x) (find(all(c),x) != (c).end())
#define br printf("\n")
#define bit(x,i) (x&(1<<i))
using namespace std;
typedef long long lld;
int main()
{
	freopen("B-small-attempt0.in","r",stdin);
	freopen("B-small-attempt0.out","w",stdout);
	lld t,x,n;
	cin>>t;
	rep(ttt,1,t+1)
	{
		map<lld,lld> m;
		vector<lld> v;
		cin>>n;
		rep(i,0,2*n-1)
		{
			rep(j,0,n)
			{
				cin>>x;
				m[x]++;
			}
		}
		for(map<lld,lld>::iterator it=m.begin();it!=m.end();it++)
			if(it->second % 2==1)
				v.pb(it->first);
		printf("Case #%lld: ",ttt);
		rep(i,0,v.size())
			cout<<v[i]<<" ";cout<<endl;
	}
	return 0;
}


