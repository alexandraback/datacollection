// @author peter50216
// #includes {{{
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<functional>
#include<math.h>
#include<assert.h>
#include<stdarg.h>
#include<time.h>
#include<limits.h>
#include<ctype.h>
#include<string>
#include<map>
#include<set>
#include<queue>
#include<algorithm>
#include<vector>
#include<iostream>
#include<sstream>
using namespace std;
// }}}
// #defines {{{
#define FOR(i,c) for(__typeof((c).begin()) i=(c).begin();i!=(c).end();i++)
#define SZ(x) ((int)(x).size())
#define ALL(x) (x).begin(),(x).end()
#define REP(i,n) for(int i=0;i<(n);i++)
#define REP1(i,a,b) for(int i=(a);i<=(b);i++)
#define REPL(i,x) for(int i=0;x[i];i++)
#define PER(i,n) for(int i=(n)-1;i>=0;i--)
#define PER1(i,a,b) for(int i=(a);i>=(b);i--)
#define RI(x) scanf("%d",&x)
#define DRI(x) int x;RI(x)
#define RII(x,y) scanf("%d%d",&x,&y)
#define DRII(x,y) int x,y;RII(x,y)
#define RIII(x,y,z) scanf("%d%d%d",&x,&y,&z)
#define DRIII(x,y,z) int x,y,z;RIII(x,y,z)
#define RS(x) scanf("%s",x)
#define PI(x) printf("%d\n",x)
#define PIS(x) printf("%d ",x)
#define CASET int ___T,cas=1;scanf("%d ",&___T);while(___T--)
#define CASEN0(n) int cas=1;while(scanf("%d",&n)!=EOF&&n)
#define CASEN(n) int cas=1;while(scanf("%d",&n)!=EOF)
#define MP make_pair
#define PB push_back
#define MS0(x) memset(x,0,sizeof(x))
#define MS1(x) memset(x,-1,sizeof(x))
#define SEP(x) ((x)?'\n':' ')
#define F first
#define S second
#ifdef ONLINE_JUDGE
#define FILEIO(x) freopen(#x ".in","r",stdin);freopen(#x ".out","w",stdout);
#define FILEIOS freopen("input.txt","r",stdin);freopen("output.txt","w",stdout);
#else
#define FILEIO(x) ;
#define FILEIOS ;
#endif
typedef pair<int,int> PII;
typedef long long LL;
typedef unsigned long long ULL;
// }}}

vector<pair<vector<int>,map<LL,int> > > all; 
int n,m,k;
vector<int> now;
inline void dfs(int np,int p){
    if(np==n){
        map<LL,int> mp;
        REP(i,(1<<n)){
            LL s=1;
            REP(j,n)if(i&(1<<j))s*=now[j];
            mp[s]++;
        }
        all.PB(MP(now,mp));
        return;
    }
    for(now[np]=p;now[np]<=m;now[np]++)dfs(np+1,now[np]);
}
int in[20];
int main(){
    CASET{
        printf("Case #%d:\n",cas++);
        DRI(r);
        RIII(n,m,k);
        now.resize(n);
        dfs(0,2);
        //printf("%d\n",all.size());
        while(r--){
            REP(i,k)RI(in[i]);
            int ma=0,mp=-1;
            REP(i,SZ(all)){
                LL c=1;
                REP(j,k)c*=(all[i].S)[in[j]];
                if(c>ma){
                    ma=c;
                    mp=i;
                }
            }
            REP(i,n)printf("%d",(all[mp].F)[i]);
            puts("");
        }
    }
}
// vim: fdm=marker:commentstring=\ \"\ %s:nowrap:autoread

