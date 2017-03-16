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

const int nlim=1000;

int T;
int a,b;

bool fas[nlim+1];

int lk[5], lksz;
bool pal(int k)
{
	lksz=0;
	while(k!=0)
	{
		lk[lksz++]=k%10;
		k/=10;
	}
	
	rep(i,lksz)
		if(lk[i]!=lk[lksz-1-i])
			return false;
	
	return true;
}

int main()
{
	fill(fas+1,fas+nlim+1,false);
	for(int i=1; i*i<=nlim; ++i)
		if(pal(i) and pal(i*i))
		{
			//cout<<i<<" "<<i*i<<"\n";
			fas[i*i]=true;
		}

	gi(T);
	
	rep(z,T)
	{
		gi(a); gi(b);
		
		int res=0;
		for(int i=a; i<=b; ++i)
			res+=fas[i];
		
		printf("Case #%d: %d\n",z+1,res);
	}
	
	return 0;
}