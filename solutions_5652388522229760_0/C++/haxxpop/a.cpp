#include <stdio.h>
typedef long long ll;
int tmp[10];
int count =0;
int check(ll x){
  while( x!=0 ){
    if( tmp[x%10] == 0 ){
      count++;
      tmp[x%10] = 1;
    }
    x/=10;
  }
}
int main(){
  int t;
  scanf("%d",&t);
  for(int e = 0 ; e < t  ; e++ ){
    ll n;
    count = 0;
    for(int i = 0 ; i < 10 ; i++ ) tmp[i] = 0;
    scanf("%lld",&n);
    printf("Case #%d: ",e+1);
    if( n == 0 ){
      printf("INSOMNIA\n");
      continue;
    }
    for(ll ans = 1 ; ; ans++ ){
      check(ans*n);
      if( count == 10 ){
        printf("%lld\n",ans*n);
        break;
      }
    }
  }
}
