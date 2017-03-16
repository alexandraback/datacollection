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

char s1[100],s2[100];
int f(char c){
    return c=='?'?10:1;
}
void sol(int uuu){
    RS(s1);RS(s2);
    int n(strlen(s1));
    int on(n);
    for(;n!=3;++n){
        s1[n]=s2[n]='0';
    }
    int cc[6];
    FZU(i,3)cc[i+0]=f(s1[i]);
    FZU(i,3)cc[i+3]=f(s2[i]);
    FZU(i,3)s1[i]-='0',s2[i]-='0';
    FZU(i,3){
        if(s1[i]=='?'-'0')s1[i]=0;
        if(s2[i]=='?'-'0')s2[i]=0;
    }
    auto ans=std::make_tuple(1<<30,1<<30,1<<30);
    FZ(i,cc[0])FZ(j,cc[1])FZ(k,cc[2])FZ(a,cc[3])FZ(b,cc[4])FZ(c,cc[5]){
        s1[0]+=i;
        s1[1]+=j;
        s1[2]+=k;
        s2[0]+=a;
        s2[1]+=b;
        s2[2]+=c;
        int aa = (s1[0]*100+s1[1]*10+s1[2]);
        int bb = (s2[0]*100+s2[1]*10+s2[2]);
        int nw = abs(aa-bb);
        auto na = std::make_tuple(nw,aa,bb);
        ans=min(ans,na);
        s1[0]-=i;
        s1[1]-=j;
        s1[2]-=k;
        s2[0]-=a;
        s2[1]-=b;
        s2[2]-=c;
    }
    printf("Case #%d: ",uuu);
    {
    auto t(std::get<1>(ans));
    if(on>=1)printf("%d",t/100);
    if(on>=2)printf("%d",t/10%10);
    if(on>=3)printf("%d",t%10);
    putchar(' ');
    }
    {
    auto t(std::get<2>(ans));
    if(on>=1)printf("%d",t/100);
    if(on>=2)printf("%d",t/10%10);
    if(on>=3)printf("%d",t%10);
    }
    puts("");
}
int main(){
	freopen("B-small-attempt0.in","r",stdin);
	freopen("B-small-attempt0.out","w",stdout);
	int t;
	if(RI(t)!=EOF){
		for(int ti=1;ti<=t;ti++)sol(ti);
	}
	return 0;
}

