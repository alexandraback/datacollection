#include<bits/stdc++.h>
using namespace std;
#define FZ(i,n) for(int i=0;i<(n);++i)
#define FB(i,n) for(int i=(n)-1;i>=0;--i)
#define FV(i,st,ed) for(int i=(st);i<(ed);++i)
#define FZU(i,n) for(ust i=0;i<(n);++i)
#define FVU(i,st,ed) for(ust i=(st);i<(ed);++i)
#define SZ(x) ((int)x.size())
#define ALL(x) (x).begin(),(x).end()

#define RI(x) scanf("%d",&(x))
#define RII(x,y) scanf("%d %d",&(x),&(y))
#define RS(x) scanf("%s",x)
#define RI64(x) scanf("%I64d",&(x))
#define RII64(x,y) scanf("%I64d%I64d",&(x),&(y))

#define FIR first
#define SEC second
#define pritnf printf
#define N 100514
typedef long long int lnt;
typedef unsigned long long int unt;
typedef unsigned ust;
typedef double dou;
typedef pair<int,int> P;

void sol(int uuu){
    int K,C,S;
    RII(K,C); RI(S);
    auto s = K/C+!!K%C;
    printf("Case #%d:",uuu);
    if(s>S){
        puts(" IMPOSSIBLE");
    }else{
        for(auto k=K,p=0;k;){
            auto a=0llu;
            auto dk = min(k,C); k-= dk;
            for(;dk;--dk){
                a*=K;
                a+=p++;
            }
            printf(" %llu",a+1);
        }puts("");
    }
}
int main(){
	freopen("D-large.in","r",stdin);
	freopen("DLout.txt","w",stdout);
	int t;
	if(RI(t)!=EOF){
		for(int ti=1;ti<=t;ti++)sol(ti);
	}
	return 0;
}

