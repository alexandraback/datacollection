#include <iostream>
#include <algorithm>
#include <cmath>
#include <cstdio>
#include <cstdlib> 
#include <cstring>


using namespace std;
long long int gcd(long long int a,long long int b) {  while( (a%=b) && (b%=a) );  return a+b;    } 



int main(){
	
   freopen("alarge.out","w",stdout);
   long long int ca;
   long long int P,Q;
   scanf("%lld",&ca);
   for(long long int cs=1;cs<=ca;cs++)
  {
    scanf("%lld / %lld",&P,&Q);
    long long int gcdPQ = gcd(P,Q);
    P/=gcdPQ;
    Q/=gcdPQ;
    printf("Case #%lld: ",cs);
    long long int tq =Q;
    while(tq%2==0){
      tq/=2;
    }
    if(tq!=1) {
      printf("impossible\n");
    }else{
      long long int ans=0;
      while(P<Q){
        P*=2;
        ans++;
      }
      printf("%lld\n",ans);
      
    }


  }

  return 0;
}
