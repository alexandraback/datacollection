#include <iostream>
#include <algorithm>
#include <cmath>
#include <cstdio>
#include <cstdlib> 
#include <cstring>



using namespace std;

int n,m,k;
int findans(){
 
 if(n<3 || m<3) return k;
 if(k<=4) return k;
 else{

   int now=5;
   int N,M;
   N=M=1;
   int pre=now;
   while(N+2<n && M+2<m){
     //  printf("%d %d\n",N,M);
     pre=now;
     if(N<M){
       N++;
       now+=2+M;
       if(now>k) return min(N*2+M*2,(N-1)*2+M*2+k-pre); 
    }else{
       M++;
       now+=2+N;
       if(now>k) return min(N*2+M*2,N*2+(M-1)*2+k-pre);
    }

     if(now==k) return N*2+M*2;
         
   }
   while(N+2<n){
    pre =now;
    N++;
    now+=2+M;
    if(now>k) return min(N*2+M*2,(N-1)*2+M*2+k-pre) ;
    if(now==k) return N*2+M*2;  
  }
   while(M+2<m){
     pre =now;
     M++;
     now+=2+N;
    // printf("%d %d\n",N,M);
     if(now>k) return min(N*2+M*2,N*2+(M-1)*2+k-pre);
     if(now==k) return N*2+M*2;  
  
   }
   if(now<k) return N*2+M*2+k-now;

 }  


   

}
int main(){
freopen("cs.out","w",stdout);
  int ca;
  int cs;
  scanf("%d",&ca);
 
  for(cs=1;cs<=ca;cs++){
    
    scanf("%d%d%d",&n,&m,&k);
   
    printf("Case #%d: %d\n",cs,findans()) ;

  }


  return 0;
}
