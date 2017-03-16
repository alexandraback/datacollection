#include<cctype>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<ctime>
#include<cmath>
#include<cassert>
#include<algorithm>
#include<numeric>
#include<vector>
#include<string>
#include<set>
#include<map>
#include<unordered_map>
#include<queue>
#include<tuple>
using namespace std;
typedef long long int lnt;
typedef unsigned long long int unt;
typedef unsigned ust;
typedef double dou;
typedef pair<int,int> P;
#define FZ(i,n)       for(int i=0;i<(n);++i)
#define FB(i,n)       for(int i=(n)-1;i>=0;--i)
#define FV(i,st,ed)   for(int i{st};i<(ed);++i)
#define FC(i,n)       for(int i{n};i;--i)
#define FZU(i,n)      for(ust i{0};i!=(n);++i)
#define FVU(i,st,ed)  for(ust i{st};i<(ed);++i)
#define FCU(i,n)      for(ust i{n};i;--i)
#define SZ(x)         ((int)x.size())
#define ALL(x)        (x).begin(),(x).end()
#define likely(x)     __builtin_expect(!!(x), 1)
#define unlikely(x)   __builtin_expect(!!(x), 0)

#define RI(x) scanf("%d",&(x))
#define RII(x,y) scanf("%d %d",&(x),&(y))
#define RS(x) scanf("%s",x)
#define RI64(x) scanf("%I64d",&(x))
#define RII64(x,y) scanf("%I64d%I64d",&(x),&(y))

#define FIR first
#define SEC second
#define pritnf printf
constexpr ust N = 100514u;
int n;
int dp[1<<16];
char s[100];
map<string,int>aa,bb;int at,bt;
pair<int,int>c[16];
int ap[1<<16];
int bp[1<<16];
void sol(int uuu){
    RI(n);
    at=bt=0;
    FZU(i,n){
        RS(s);
        if(aa.count(s)==0)aa[s]=at++;
        c[i].FIR = aa[s];
        RS(s);
        if(bb.count(s)==0)bb[s]=bt++;
        c[i].SEC = bb[s];
    }
    aa.clear();
    bb.clear();
    memset(ap,0,sizeof(ap));
    memset(bp,0,sizeof(bp));
    FVU(m,1,1<<n){
        ap[m]=ap[m&(m-1)]|(1u<<c[__builtin_ctz(m)].FIR);
        bp[m]=bp[m&(m-1)]|(1u<<c[__builtin_ctz(m)].SEC);
    }
    memset(dp,0,sizeof(dp));
    FVU(m,1,1<<n)FZU(j,n){
        if((m>>j)%2){
            ust om(m^(1u<<j));
            dp[m]=max(dp[m],dp[om]+(((1<<c[j].FIR)&ap[om])&&((1<<c[j].SEC)&bp[om])));
        }
    }
    printf("Case #%d: %d\n",uuu,dp[(1<<n)-1]);
}
int main(){
	freopen("C-small-attempt1.in","r",stdin);
	freopen("C-small-attempt1.out","w",stdout);
	int t;
	if(RI(t)!=EOF){
		for(int ti=1;ti<=t;ti++)sol(ti);
	}
	return 0;
}

