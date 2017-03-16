#include <vector>
#include <list>
#include <map>
#include <set>
#include <queue>
#include <deque>
#include <stack>
#include <cassert>
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

const int max_m=5;
const int max_k=10;

int T,R;
int n,m,k;

int ap[max_k];
bool pp[max_m*max_m*max_m+1];

int main()
{
	gi(T);
	gi(R); gi(n); gi(m); gi(k);
	
	assert(n==3);
	
	printf("Case #1:\n");
	rep(z,R)
	{		
		rep(i,k)
			gi(ap[i]);
		
		int sg[4];
		int g[4];
		for(g[0]=2; g[0]<=m; ++g[0])
		{
		for(g[1]=2; g[1]<=m; ++g[1])
		{
		for(g[2]=2; g[2]<=m; ++g[2])
		{
			fill(pp,pp+m*m*m+1,false);
			pp[1]=true;
			pp[g[0]]=true; pp[g[1]]=true; pp[g[2]]=true;
			g[3]=g[0]*g[1]*g[2];
			pp[g[3]/g[0]]=true; pp[g[3]/g[1]]=true; pp[g[3]/g[2]]=true;
			pp[g[3]]=true;
			
			/*printf("%d %d %d : \n",g[0],g[1],g[2]);
			rep(i,m*m*m+1)
				if(pp[i]) printf("%d ",i);
			pnl(); pnl();*/
			
			bool allpos=true;
			rep(i,k)
				allpos = allpos and pp[ap[i]];
			
			if(allpos)
			{
				rep(i,n)
					sg[i]=g[i];
			}
		}
		}
		}
		
		rep(i,n)
			printf("%d",sg[i]);
		printf("\n");
	}
	
	return 0;
}