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

int T;
LL r,t;
LL res;

bool bsf(LL k)
{
	return ( (2ll*r+1ll+2ll*(k-1ll)) <= (t/k) );
}

LL binsrcB(LL l, LL r) //[l,r)
{
	if(l+1==r)
		return l;
	else
	{
		LL mid=(l+r)/2ll;
		if(bsf(mid))
			return binsrcB(mid,r);
		else
			return binsrcB(l,mid);
	}
}


int main()
{
	gi(T);
	
	rep(z,T)
	{
		scanf("%lld%lld",&r,&t);
		
		res=binsrcB((LL(1)),(LL((1e9)+1)));
		
		printf("Case #%d: %lld\n",z+1,res);
	}
	
	return 0;
}