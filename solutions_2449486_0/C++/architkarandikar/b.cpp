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

const int max_n=110;
const int max_m=110;

int T;
int n,m;
int a[max_n][max_m];
bool mark[max_n][max_m];

int main()
{
	gi(T);
	
	rep(z,T)
	{
		gi(n); gi(m);
		
		rep(i,n)
			rep(j,m)
			{
				gi(a[i][j]);
				mark[i][j]=false;
			}

		bool progress;
		while(true)
		{
			int amin=inv;
			rep(i,n)
				rep(j,m)
					if(not mark[i][j])
						amin=min(amin,a[i][j]);
			
			progress=false;
			
			rep(i,n)
			{
				bool allamin=true;
				bool allmark=true;
				rep(j,m)
				{
					if(not mark[i][j])
						allmark=false;
					if((not mark[i][j]) and a[i][j]!=amin)
						allamin=false;
				}
				
				if((not allmark) and allamin)
				{
					progress=true;
					
					rep(j,m)
						mark[i][j]=true;
					
					break;
				}
			}
			
			if(progress)
				continue;
			
			rep(j,m)
			{
				bool allamin=true;
				bool allmark=true;
				rep(i,n)
				{
					if(not mark[i][j])
						allmark=false;
					if((not mark[i][j]) and a[i][j]!=amin)
						allamin=false;
				}
				
				if((not allmark) and allamin)
				{
					progress=true;
					
					rep(i,n)
						mark[i][j]=true;
					
					break;
				}
			}
			
			if(not progress)
				break;
		}
		
		bool res=true;
		rep(i,n)
			rep(j,m)
				res = res and mark[i][j];
		
		printf("Case #%d: ",z+1);
		if(res)
			printf("YES\n");
		else
			printf("NO\n");	
	}
	
	return 0;
}