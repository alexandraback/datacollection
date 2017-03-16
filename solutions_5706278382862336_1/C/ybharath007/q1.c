#include<stdio.h>
#include<string.h>

int power(long long r){
while(r % 2 == 0){
    r = r/2;
}
if(r == 1){
    return 1;
}
else{
    return 0;
}
}

long long gcd ( long long a, long long b )
{
  long long c;
  while ( a != 0 ) {
     c = a; a = b%a;  b = c;
  }

  return b;
}

int main(){
    int t,i;
    int k = 0;
    scanf("%d",&t);
    long long p,q;

    for(i=1;i<=t;i++){
        long long m = 1;
        long long j = 1;
        scanf("%lld/%lld",&p,&q);
        long long g  = gcd(p,q);
        p = p/g;
        q = q/g;

        if(power(q)){
        while(p/q < 1){
            p = p*2;
            k++;
        }
        printf("Case #%d: %d\n",i,k);
        k = 0;
        }
        else{
            printf("Case #%d: impossible\n",i);
        }
    }
return 0;
}

