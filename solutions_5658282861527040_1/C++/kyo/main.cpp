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
#define   PB push_back
#define   FI     first
#define   SE     second
#define   MP     make_pair
template<class T> inline void checkmin(T &a,T b){if(b<a) a=b;}
template<class T> inline void checkmax(T &a,T b){if(b>a) a=b;}
typedef long long int64;
#define   inf         1000000001
#define  MAXN     20
#define  eps      1e-6
FILE *fin;
FILE *fout;
int A,B,K;
int64 ans;
int64 mem[31][2][2][2];
int64 dfs(int d,int f1,int f2,int b)
{
    if(d==-1) return 1;
    int64 &ret=mem[d][f1][f2][b];
    if(ret!=-1) return ret;
    ret=0;
    REP(i,2) REP(j,2)
    {
        if(f1==0&&(A&(1<<d))==0&&i==1) continue;
        if(f2==0&&(B&(1<<d))==0&&j==1) continue;
        int wei=i&j;
        if(b==0&&(K&(1<<d))==0&&wei==1) continue;
        int nf1=f1;if((A&(1<<d))&&i==0) nf1=1;
        int nf2=f2;if((B&(1<<d))&&j==0) nf2=1;
        int nb=b;  if((K&(1<<d))&&wei==0) nb=1;
        ret+=dfs(d-1,nf1,nf2,nb);
    }
    return ret;
}
int main()
{
   	fin=fopen("B-large.in","r");
 //fin=fopen("input.txt","r");
	fout=fopen("output.txt","w");
	int T;
	fscanf(fin,"%d",&T);
    int rounds;
	for (rounds=1;rounds<=T;rounds++)
	{
        fscanf(fin,"%d%d%d",&A,&B,&K);A--,B--,K--;
        CLEAR(mem,-1);
        int64 ret=dfs(30,0,0,0);
            printf("Case #%d: %I64d\n",rounds,ret);
            fprintf(fout,"Case #%d: %I64d\n",rounds,ret);

    }
}
