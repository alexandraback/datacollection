#include<iostream>
#include<list>
#include<string>
#include<cstring>
#include<sstream>
#include<cctype>
#include<string.h>
#include<algorithm>
#include<cmath>
#include<stack>
#include<fstream>
#include<cstdlib>
#include<vector>
#include<map>
#include<set>
#include<utility>
#include<iomanip>
#include<queue>

using namespace std;

#define INF (1<<29)
#define SET(a) memset(a,-1,sizeof(a))
#define ALL(a) a.begin(),a.end()
#define CLR(a) memset(a,0,sizeof(a))
#define FILL(a,v) memset(a,v,sizeof(a))
#define PB push_back
#define FOR(i,n) for(int i = 0;i<n;i++)
#define PI acos(-1.0)
#define EPS 1e-9
#define MP(a,b) make_pair(a,b)
#define min3(a,b,c) min(a,min(b,c))
#define max3(a,b,c) max(a,max(b,c))
#define READ freopen("input.txt", "r", stdin)
#define WRITE freopen("output.txt", "w", stdout)
#define LL long long
#define MX 1003
#define MOD 1000000007

#define p(x) printf("%d",x)
#define inp(x) scanf("%d",&x)
#define inpll(x) scanf("%lld",&x)
#define getcx getchar_unlocked
/*inline void inp( int &n ) 
 {
    n=0;
    int ch=getcx();int sign=1;
    while( ch < '0' || ch > '9' ){if(ch=='-')sign=-1; ch=getcx();}
 
    while(  ch >= '0' && ch <= '9' )
            n = (n<<3)+(n<<1) + ch-'0', ch=getcx();
    n=n*sign;
  }*/

using namespace std;
int v[MX];
int main()
{
    int t,e,i,r,n,ce,st,ed,g1,g2;
	inp(t);
	for(int j=1;j<=t;j++)
	{
		int gain=0;
		inp(e);
		inp(r);
		inp(n);
		for( i=0;i<n;i++)
		inp(v[i]);
		st=0,ed=n-1;
		sort(v,v+n);
		gain+=v[ed--]*e;
		ce=r;
		if(r>e)
		r=e;
		for( i=st;i<ed;i++)
		{
			//printf("%d: %d\n",i,gain);
			if(ce+r>=e)
			{
				/*if(ed==i+1)
				{
					gain+=v[ed]*e;
					ce=0;
					continue;
				}*/
				g1=v[ed-1]*r;
				g2=v[ed]*(e-ce);
				if(g1>g2)
				{
					gain+=v[ed--]*ce;
					ce=r;
					i--;
				}
				else
				{
					gain+=v[ed--]*e;
					ce=0;
				}
			}
			else
			ce+=r;
		}
		if(i==ed)
		gain+=v[ed]*ce;
		printf("Case #%d: %d\n",j,gain);
	}
	return 0;
}