#include <iostream>
#include <algorithm>
#include <cmath>
#include <cstdio>
#include <cstdlib> 
#include <cstring>


using namespace std;
int gcd(int a,int b) {  while( (a%=b) && (b%=a) );  return a+b;    } 



int main(){
	
   freopen("a.out","w",stdout);
   int ca;
   int P,Q;
   scanf("%d",&ca);
   for(int cs=1;cs<=ca;cs++)
  {
    scanf("%d / %d",&P,&Q);
    int gcdPQ = gcd(P,Q);
    P/=gcdPQ;
    Q/=gcdPQ;
    printf("Case #%d: ",cs);
    int tq =Q;
    while(tq%2==0){
      tq/=2;
    }
    if(tq!=1) {
      printf("impossible\n");
    }else{
      int ans=0;
      while(P<Q){
        P*=2;
        ans++;
      }
      printf("%d\n",ans);
      
    }


  }

  return 0;
}
