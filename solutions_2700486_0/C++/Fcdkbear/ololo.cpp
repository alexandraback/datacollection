#pragma comment(linker, "/STACK:500777216")
#include <vector>
#include <list>
#include <map>
#include <set>
#include <deque>
#include <stack>
#include <queue>
#include <algorithm>
#include <sstream>
#include <iostream>
#include <iomanip>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <memory.h>
#include <ctime>
#include <unordered_map>
 
using namespace std;
 
#define ABS(a) ((a>0)?a:-(a))
#define MIN(a,b) ((a<b)?(a):(b))
#define MAX(a,b) ((a<b)?(b):(a))
#define FOR(i,a,n) for (int i=(a);i<(n);++i)
#define FI(i,n) for (int i=0; i<(n); ++i)
#define pnt pair <int, int>
#define mp make_pair
#define PI 3.14159265358979
#define MEMS(a,b) memset(a,b,sizeof(a))
#define LL long long
#define U unsigned

set <pnt > s;

int main()
{
#ifdef Fcdkbear
    double beg=clock();
	freopen("in.txt","r",stdin);
    freopen("out.txt","w",stdout);
#else
	freopen("in.txt","r",stdin);
    freopen("out.txt","w",stdout);
#endif

	int t;
	scanf("%d",&t);
	FOR(now,1,t+1)
	{
		int n,x,y;
		cin>>n>>x>>y;
		int maxcnt=0;
		int tot1=0,tot2=(1<<(n-1));
		FOR(mask,0,1<<(n-1))
		{
			s.clear();
			int cnt=0;
			s.insert(mp(0,0));
			FOR(i,1,n)
			{
				int dx=1;
				if ((mask>>(i-1))&1)
					dx=-1;
				int myy=cnt+2;
				int myx=0;
				while (1)
				{
					if (myy==0)
					{
						s.insert(mp(myx,myy));
						if (myx==0)
							cnt+=2;
						break;
					}
					if ((s.find(mp(myx-1,myy-1))!=s.end()) && (s.find(mp(myx+1,myy-1))!=s.end()))
					{
						s.insert(mp(myx,myy));
						if (myx==0)
							cnt+=2;
						break;
					}
					int nx=myx+dx;
					int ny=myy-1;
					if (s.find(mp(nx,ny))==s.end())
					{
						myx=nx;
						myy=ny;
					}
					else
					{
						myx-=dx;
						myy--;
					}
				}
			}
			maxcnt=MAX(maxcnt,cnt);
			if (s.size()!=n)
				throw;
			if (s.find(mp(x,y))!=s.end())
				tot1++;
		}
		double res;
		if ((x==0) && (y==0))
			res=1;
		else
			res=tot1/(double)tot2;
		printf("Case #%d: %.15lf\n",now,res);
		fprintf(stderr,"Case #%d done\n",now);
		//cout<<maxcnt<<endl;
	}
	
#ifdef Fcdkbear
    double end=clock();
    fprintf(stderr,"*** Total time = %.3lf ***\n",(end-beg)/CLOCKS_PER_SEC);
#endif
    return 0;
}