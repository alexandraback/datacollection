#include <cstdio>
#include <vector>
#include <queue>
#include <string>
#include <cstring>
#include <list>
#include <map>
#include <set>
#include <stack>
#include <bitset>
#include <climits>
#include <utility>
#include <cstdlib>
#include <algorithm>
#include <iostream>
#include <cmath>
#define REP(i,n) for( int (i)=0;(i)<(int)(n); ++(i))
#define REPR(i,n) for( int (i) = n; (i)>=0; --(i))
#define REPN(i,x,y) for( int i = x; (i) < (int)(y); (i)++ )
#define REPIT(c,itr) for(__typeof((c).begin()) itr=(c).begin();itr!=(c).end();itr++)
#define ZERO(x) memset(x,0,sizeof(x))
#define RI(n) scanf("%d",&(n))
#define RII(x,y) scanf("%d %d",&(x),&(y))
#define OI(x) printf("%d\n",(x))
#define OII(x,y) printf("%d %d\n",(x),(y))
#define FT first
#define SD second
using namespace std;
typedef long long LL;
typedef unsigned long long ULL;
typedef pair<int,int> PII;
LL LLMAX = 9223372036854775807LL;
const int MOD = 1000000007;
const int maxn = 1000000+10;
struct tr{
    int d,n,w,e,s,dd,dp,ds;
    bool operator<(const tr& r)const{
        return d>r.d || d==r.d && s>r.s;
    }
};
int N;
tr TR[20];
int* Wall;
int main()
{
#ifndef ONLINE_JUDGE
	freopen("C-large.in","r",stdin);
	freopen("out.txt","w",stdout);
#endif
return 0;
    int T;
    RI(T);
    Wall = new int[2000010];
    REP(kase,T){
        /*LL ans=0;
        memset(Wall,0,sizeof(int)*2000010);
        RI(N);
        priority_queue<tr> pq;
        REP(i,N){
            scanf("%d%d%d%d%d%d%d%d",&TR[i].d,&TR[i].n,&TR[i].w,&TR[i].e,&TR[i].s,&TR[i].dd,&TR[i].dp,&TR[i].ds);
            TR[i].e += maxn;
            TR[i].w += maxn;
            pq.push(TR[i]);
        }
        while(!pq.empty()){
            tr r=pq.top();pq.pop();
            if(r.n==0)continue;
            bool f = 0;

            for(int i=r.w;i<r.e;++i){
                if(Wall[i]<r.s){
                    f=1;
                    Wall[i] = r.s;
                }
            }
            //printf("%d %d %d %d\n",r.d,r.w,r.e,r.s);

            if(f)ans++;
            r.d += r.dd;
            r.e += r.dp;
            r.w += r.dp;
            r.s += r.ds;
            r.n--;
            pq.push(r);*/
        }
        int ans;
        printf("Case #%d: %lld\n",kase+1,ans);
    }
}
