
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cassert>

#define REP(a,b) for(int a=0;a<(b);a++)
#define PER(a,b) for(int a=(b)-1;a>=0;a--)

long long T,K,C,S;

long long aux(long long p){
    long long pos=p;
    for(int j=2;j<=C;j++)
        if(p+j-1>K)
            pos=(pos-1)*K+K;
        else
            pos=(pos-1)*K+p+j-1;
    return pos;
}

int main(){
    scanf("%lld",&T);
    REP(i,T){
        scanf("%lld %lld %lld",&K,&C,&S);
        int cases = K/C + (K%C ?1:0);
        if(S< cases){
            printf("Case #%d: IMPOSSIBLE\n",i+1);
            continue;
        }
        printf("Case #%d: ",i+1);
        for(int j=0;j<cases;j++)
            printf("%lld ",aux(C*j+1));
        printf("\n");
    }

    return 0;
}

