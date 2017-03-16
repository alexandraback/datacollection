
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cassert>

#define REP(a,b) for(int a=0;a<(b);a++)
#define PER(a,b) for(int a=(b)-1;a>=0;a--)

int T;
int dig[10];

void mark(long long c){
    while(c!=0)
        dig[c%10]=1,c/=10;
}

int main(){
    scanf("%d",&T);
    long long c,d;
    REP(i,T){
        scanf("%lld",&d);
        if(d==0){
            printf("Case #%d: INSOMNIA\n",i+1);
            continue;
        }
        REP(j,10) dig[j]=0;
        c=d;
        while(1){
            mark(c);
            int flag=0;
            REP(j,10){
                if(dig[j]==0) break;
                if(j==9) flag=1;
            }
            if(flag){
                printf("Case #%d: %lld\n",i+1,c);
                break;
            }
            c+=d;
        }
    }
    return 0;
}

