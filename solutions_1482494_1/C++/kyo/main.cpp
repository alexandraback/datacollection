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
int a[MAXN];
int b[MAXN];
vector<pair<int,int> > vp;
int visited[MAXN];
bool isover()
{
    REP(i,N) if(visited[i]!=2) return false;
    return true;
}
int solve()
{
    clr(visited);
    int so=0;
    int ret=0;
    while(!isover())
    {
        int xuan=-1;
        REP(i,SZ(vp))
        {
            if(visited[i]!=2&&vp[i].SE<=so)
            {
                so+=2-visited[i];
                visited[i]=2;
                xuan=i;break;
            }
        }
        if(xuan!=-1)
        {
            ret++;
            continue;
        }
        int mx=-1;
        REP(i,SZ(vp))
        {
            if(visited[i]==0&&vp[i].FI<=so)
            {
                if(vp[i].SE>mx) mx=vp[i].SE,xuan=i;
            }
        }
        if(xuan==-1) return inf;
        visited[xuan]=1;
        so++;
        ret++;
    }
    if(!isover()) return inf;
    return ret;
}
int main()
{
   	fin=fopen("B-large.in","r");
	fout=fopen("output.txt","w");
	fscanf(fin,"%d",&T);
    rep(rds,1,T+1)
	{
         	 printf("Case #%d: ",rds);
          	fprintf(fout,"Case #%d: ",rds);
		  fscanf(fin,"%d",&N);
		  REP(i,N) fscanf(fin,"%d%d",a+i,b+i);
		  vp.clear();
		  REP(i,N) vp.PB(MP(a[i],b[i]));
		  sort(ALL(vp));
		  int ret=solve();
          if(ret>=inf)
          {
            fprintf(fout,"Too Bad\n");
            printf("Too Bad\n");
          }
          else {
		  fprintf(fout,"%d\n",ret);
		  printf("%d\n",ret);
          }
	}
}
