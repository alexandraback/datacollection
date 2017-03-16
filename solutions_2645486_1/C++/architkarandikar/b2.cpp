#include <vector>
#include <list>
#include <map>
#include <set>
#include <queue>
#include <deque>
#include <stack>
#include <bitset>
#include <algorithm>
#include <functional>
#include <numeric>
#include <utility>
#include <sstream>
#include <iostream>
#include <iomanip>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <ctime>
#include <limits>
#include <string>

using namespace std;
typedef long long LL;
typedef pair<int,int> pii;

#define forup(i,a,b) for(int i=a; i<b; ++i)
#define fordn(i,a,b) for(int i=a; i>b; --i)
#define rep(i,a) for(int i=0; i<a; ++i)

#define dforup(i,a,b) for(i=a; i<b; ++i)
#define dfordn(i,a,b) for(i=a; i>b; --i)
#define drep(i,a) for(i=0; i<a; ++i)

#define slenn(s,n) for(n=0; s[n]!='\0'; ++n)

#define gi(x) scanf("%d",&x)
#define gl(x) cin>>x
#define gd(x) scanf("%lf",&x)
#define gs(x) scanf("%s",x)

#define pis(x) printf("%d ",x)
#define pin(x) printf("%d\n",x)
#define pls(x) cout<<x<<" "
#define pln(x) cout<<x<<"\n"
#define pds(x) printf("%.12f ",x)
#define pdn(x) printf("%.12f\n",x)
#define pnl() printf("\n")

#define fs first
#define sc second

#define pb push_back

const int inv=numeric_limits<int>::max();
const int minv=numeric_limits<int>::min();

const int max_n=10010;
const int max_e=10;

int T;
int e,r,n;
int c;
int v[max_n];
LL res;

int main()
{
	gi(T);
	
	rep(z,T)
	{
		//cerr<<"z:"<<z<<endl;
		gi(e); gi(r); gi(n);
		r=min(r,e);
		
		rep(i,n)
			gi(v[i]);
		
		res=0ll;
		c=e;
		
		for(int i=0; i<n; ++i)
		{
			//cout<<i<<" : "<<c<<" "<<res<<endl;
			if(c>=e-r)
			{
				res+=(LL(c-(e-r))*(LL(v[i])));
				c=e-r;
			}
			for(int j=i+1; j<=n; ++j)
			{
				if(j==n)
				{
					res+=(LL(c))*(LL(v[i]));
					c=0;
				}
				else
				{
					if(v[j]>=v[i])
						break;
					else
					{
						if(c>=max(0,(e-(j-i+1)*r)))
						{
							res+=(LL(c-max(0,(e-(j-i+1)*r))))*(LL(v[i]));
							c=max(0,(e-(j-i+1)*r));
						}
					}
				}
			}
			
			c+=r;
			c=min(c,e);
		}
		
		printf("Case #%d: %lld\n",z+1,res);
	}
	
	return 0;
}