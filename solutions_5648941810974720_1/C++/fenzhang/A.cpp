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

char s[2016],c[]="ZXGWSVFIOR";
char p[100][100]={
    "ZERO",
    "SIX",
    "EIGHT",
    "TWO",
    "SEVEN",
    "FIVE",
    "FOUR",
    "NINE",
    "ONE",
    "THREE"
};
int q[]={
    0,6,8,2,7,5,4,9,1,3
};
int ans[2016];
void sol(int uuu){
    int cnt[256]{};
    scanf("%s",s);
    for(int i=0;s[i];++i){
        cnt[int(s[i])]++;
    }
    int*a=ans;
    for(int i=0;i<10;i++){
        int t=cnt[int(c[i])];
        std::fill(a,a+t,q[i]);
        a+=t;
        for(int j=0;p[i][j];++j){
            cnt[int(p[i][j])]-=t;
            assert(cnt[int(p[i][j])]>=0);
        }
    }
    FZU(i,256)assert(cnt[i]==0);
    std::sort(ans,a);
    printf("Case #%d: ",uuu);
    FZU(i,a-ans){
        printf("%d",ans[i]);
    }
    puts("");
}
int main(){
	freopen("A-large.in","r",stdin);
	freopen("A-large.out","w",stdout);
	int t;
	if(RI(t)!=EOF){
		for(int ti=1;ti<=t;ti++)sol(ti);
	}
	return 0;
}

