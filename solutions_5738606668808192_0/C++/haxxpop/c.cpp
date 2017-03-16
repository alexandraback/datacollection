#include <stdio.h>
typedef long long ll;
int count = 0;
ll iscom(ll x){
  if( x%2 == 0 ) return 2;
  for(ll i = 3 ; i<50 && i*i <= x ; i+=2 ){
    if( x%i == 0 ) return i;
  }
  return 0;
}
int check(ll x){
  ll div[12];
  for(int b = 2 ; b <= 10 ; b++ ){
    ll tx = x;
    ll res = 0;
    ll mul = 1;
    for( ; tx > 0 ; ){
      ll dig = tx%2;
      tx/=2;
      res += dig*mul; 
      mul *= b;
    }
    ll prime = iscom(res);
    if( prime == 0 ){
      return 0;
    }
    div[b] = prime;
  }
  count++;
  int ct =0;
  int bin[40];
  for( ; x != 0 ; ){
    bin[ct++] = x%2;
    x/=2;
  }
  for(int i = ct-1 ; i>= 0 ;i-- ) printf("%d",bin[i]);
  for(int i = 2 ; i <= 10 ; i++ ){
    printf(" %lld",div[i]);
  }
  printf("\n");
}
int main(){
  int t;
  scanf("%d",&t);
  ll n,m;
  scanf("%lld %lld",&n,&m);
  printf("Case #1:\n");
  for(ll x = 0; x < (1LL<<(n-2)) ; x++ ){
    check((x<<1) +(1LL<<(n-1))+1);
    if( count == m ) break; 
  }
}
