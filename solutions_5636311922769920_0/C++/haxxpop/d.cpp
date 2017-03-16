#include <stdio.h>
typedef long long ll;
int main(){
  int t;
  scanf("%d",&t);
  for(int e = 0 ; e < t ; e++ ){
    ll n,m,cap;
    scanf("%lld %lld %lld",&n,&m,&cap);
    printf("Case #%d:",e+1);
    ll used = n/m;
    if( n%m != 0 ) used +=1;
    if( cap < used ){
      printf(" IMPOSSIBLE\n");
      continue;
    }
    ll k = 0 ; 
    for( ; ; ){
      ll pos = 0;
      for(ll i = 0 ; i < m ; i++ ){
        if( k < n ){
          pos*=n;
          pos+=k;
          k++;
        }else{
          pos*=n;
        }
      }
      printf(" %lld",pos+1);
      if( k >= n ) break;
    }
    printf("\n");
  }
}

