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
int T,A,B;
double p[MAXN];
double sump[MAXN];
double cuop[MAXN];
double cuos[MAXN];
double solve()
{
    double hr=1.0;REP(i,A) hr*=p[i];
    sump[0]=p[0];
    rep(i,1,A) sump[i]=sump[i-1]*p[i];
    cuop[0]=1.0-p[0];
    rep(i,1,A) cuop[i]=sump[i-1]*(1-p[i]);
    cuos[A-1]=cuop[A-1]+hr;
    for(int i=A-2;i>=0;i--) cuos[i]=cuos[i+1]+cuop[i];
    double ret=min(1.0*(2+B),hr*(B-A+1)+(1-hr)*(B-A+B+2));
    rep(i,1,A+1)
    {
        double p1=cuos[A-i],p2=1.0-cuos[A-i];
        double tmp=p1*(i+1+B-A+i)+p2*(i+1+B-A+i+B+1);
        checkmin(ret,tmp);
    }
    return ret;
}
int main()
{
   	fin=fopen("A-small-attempt0.in","r");
	fout=fopen("output.txt","w");
	fscanf(fin,"%d",&T);
    rep(rds,1,T+1)
	{
         	 printf("Case #%d: ",rds);
          	fprintf(fout,"Case #%d: ",rds);
		  fscanf(fin,"%d%d",&A,&B);
          REP(i,A) fscanf(fin,"%lf",p+i);
          double ret=solve();
		  fprintf(fout,"%.10lf\n",ret);
		  printf("%.10lf\n",ret);
	}
}
