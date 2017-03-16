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
#define mp make_pairn
#define all(c) (c).begin(),(c).end()
#define present(c,x) ((c).find(x) != (c).end())
#define cpresent(c,x) (find(all(c),x) != (c).end())
#define br printf("\n")
#define bit(x,i) (x&(1<<i))
using namespace std;
typedef long long lld;
int main()
{
	freopen("A-small-attempt0.in","r",stdin);
	freopen("A-small-attempt0.out","w",stdout);
	lld t,ans,n;
	cin>>t;
	set<int> s;
	rep(ttt,1,t+1)
	{
		scan(n);
		if(n==0)
			printf("Case #%lld: INSOMNIA\n",ttt);
		else
		{
			s.clear();
			rep(i,1,101)
			{
				lld tmp=n*i;
				while(tmp>0)
				{
					s.insert((tmp%10));
					tmp/=10;
				}
				if(s.size()==10)
				{
					printf("Case #%lld: %lld\n",ttt,n*i);
					break;
				}
			}
		}
	}
	return 0;
}


