#include <stdio.h>

long long GCD(long long a,long long b){
    while (b > 0) {
        a = a % b;
        a ^= b; b ^= a; a ^= b;
    }
    return a;
}

int isPow2(long long n){
    int i=63;
    int cant=0;
    for(i=0;i<64;i++){
        if(n&1){
            cant++;
        }
        n=n>>1;
    }
    if(cant==1){
        return 1;
    }
    return 0;
}

int getGen(long long p, long long q){
    long long mid=q/2;
    int i;
    int flag;
    for(i=1;i<40&&p<mid;i++){
        p*=2;
    }
    return i;
}

int main(){
    freopen("A-small-attempt0.in","r", stdin);
    freopen("A-small-attempt0.txt","w", stdout);

    long long p, q, g;
    int T;
    int i,j,k;
    int caso=1;
    int acum;

    scanf("%d",&T);
    while(T--){
        scanf("%lld%*c%lld", &p, &q);
        acum=0;

        g=GCD(p,q);
        p/=g;
        q/=g;

        if(isPow2(q)){
            //all
            acum=getGen(p,q);
            printf("Case #%d: %d\n",caso, acum);
        }else{
            printf("Case #%d: impossible\n", caso);
        }
        caso++;
    }
}
