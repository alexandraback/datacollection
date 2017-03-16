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
typedef unsigned long long ul;
ul powm(ul base,ul exp)
{
	ul ans=1;
	while(exp)
	{
		if(exp&1) ans=(ans*base);
		exp>>=1,base=base*base;
	}
	return ans;
}
int main()
{
	freopen("C-small-attempt0.in","r",stdin);
	freopen("C-small-attempt0.out","w",stdout);
	ul t,N,j,div2,div1;
	cin>>t;
	rep(tt,1,t+1)
	{
		cin>>N>>j;
		printf("Case #%lld:\n",tt);
		rep(i,0,j)
		{
			div1=1+(powm(10,((N/2)-1)));
			rep(j,0,((N/2)-2))
				if(bit(i,j))
					div1+=(powm(10,j+1));
			cout<<div1<<div1<<" ";
			rep(j,2,11)
				cout<<(1+powm(j,(N/2)))<<" ";
			br;
		}	
		cout<<endl;
	}
	return 0;
}


