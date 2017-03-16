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
#include <cstring>
#include <ctime>
#include <queue>
using namespace std;
#define   sqr(a)         ((a)*(a))
#define   rep(i,a,b)  for(int i=(a);i<(int)(b);i++)
#define   per(i,a,b)  for(int i=((a)-1);i>=(int)(b);i--)
#define   PER(i,n)     per(i,n,0)
#define   REP(i,n)     rep(i,0,n)
#define   FOREACH(it,c) for(typeof((c).begin()) it=(c).begin();it!=(c).end();++it)
#define   clr(a)      memset((a),0,sizeof (a))
#define   SZ(a)         ((int)((a).size()))
#define   CLEAR(a, v)    memset((a), (v), sizeof(a))
#define   ALL(v)          (v).begin(), (v).end()
#define   mabs(a)       ((a)>0?(a):(-(a)))
#define   inf         1000000001
#define  MAXN     100061
#define  eps      1e-6
#define   PB push_back
#define   FI 		first
#define   SE 		second
#define   MP 		make_pair
template<class T> inline void checkmin(T &a,T b){if(b<a) a=b;}
template<class T> inline void checkmax(T &a,T b){if(b>a) a=b;}
typedef long long int64;
FILE *fin;
FILE *fout;
//int64 inf=100000000000000000LL;
int T,N;
char c[MAXN];
double s[MAXN];
double p[MAXN];
bool check(vector<pair<double,double> > &vp)
{
    sort(ALL(vp));
    REP(i,SZ(vp)-1)  if(!(vp[i].FI<=vp[i+1].FI&&vp[i].SE<=vp[i+1].SE)) return false;
    return true;
}
bool isover()
{
    vector<pair<double,double> > vp;
    REP(i,N) if(c[i]=='L') vp.PB(MP(p[i],s[i]));
    if(!check(vp)) return false;
    vp.clear();
    REP(i,N) if(c[i]=='R') vp.PB(MP(p[i],s[i]));
    if(!check(vp)) return false;
    return true;
}
double solve()
{
    double ret=0;
    while(!isover())
    {
        double t=1.0*inf;int x=-1,y=-1;
        REP(i,N) REP(j,i) if(c[i]==c[j])
        {
            double p1=p[i],p2=p[j];
            double v1=s[i],v2=s[j];
            if(p1>p2) swap(p1,p2),swap(v1,v2);
            if(v2>=v1) continue;
            double tt=(p2-p1-5)/(v1-v2);
            if(tt<t) t=tt,x=i,y=j;
        }
        if(x==-1) return 2.0*inf;
        REP(i,N) p[i]+=s[i]*t;
        ret+=t;
        if(t<eps) return ret;
        if(s[x]<s[y]) swap(x,y);
        if(c[x]=='L') c[x]='R';else c[x]='L';
        REP(i,N) REP(j,i)  if(c[i]==c[j]&&fabs(p[i]-p[j])<5.0-eps) return ret;
    }
    return 2.0*inf;
}
int main()
{
   	fin=fopen("C-small-attempt1.in","r");
	fout=fopen("output.txt","w");
	fscanf(fin,"%d",&T);
    rep(rds,1,T+1)
	{
         	 printf("Case #%d: ",rds);
          	fprintf(fout,"Case #%d: ",rds);
		  fscanf(fin,"%d",&N);
          REP(i,N)
          {
              char cs[5];fscanf(fin,"%s",cs);
              fscanf(fin,"%lf%lf",s+i,p+i);
              c[i]=cs[0];
          }
          double ret=solve();
          if(ret>=inf)
          {
             fprintf(fout,"Possible\n");
                printf("Possible\n");
          }
          else
          {
                fprintf(fout,"%.10lf\n",ret);
                printf("%.10lf\n",ret);
          }

	}
}
