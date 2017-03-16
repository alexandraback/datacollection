#include<stdio.h>

int T;
unsigned long long P;
unsigned long long Q;
const unsigned long long M=0x10000000000;

unsigned long long
gcd ( unsigned long long a, unsigned long long b )
{
  unsigned long long c;
  while ( a != 0 ) {
     c = a; a = b%a;  b = c;
  }
  return b;
}

main(){
    scanf("%d",&T);
    for(int num=1;num<=T;++num){
        scanf("%lld / %lld",&P,&Q);
        //printf("%lld %lld\n",P,Q);
        unsigned long long R=gcd(P,Q);
        P/=R;Q/=R;
        //printf(" %lld",R);
        printf("Case #%d: ",num);
        if(M%Q!=0){
            printf("impossible\n");
            continue;
        }
        unsigned long long i=M/Q,x=M;
        P*=i;
        int ans=0;
        while(P<x){
            ans++;
            x/=2;
        }
        printf("%d\n",ans);
    }
}
