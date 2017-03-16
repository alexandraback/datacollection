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
	freopen("213.in","r",stdin);
	freopen("213.out","w",stdout);
	lld t;
	cin>>t;
	string x,y;
	rep(ttt,1,t+1)
	{
		cin>>x;
		lld k=x.size();
		y=x[0];
		rep(i,1,k)
		{
			if(x[i]>=y[0]) y=x[i]+y;
			else y=y+x[i];
		}
		printf("Case #%lld: ",ttt);
		cout<<y<<endl;
	}
	return 0;
}


