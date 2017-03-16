#include<cstdio>
long long T,p,q,g,ok,k,ac;
long long gcd(long long u,long long v){
     if (u%v==0) return v;
     else return gcd(v,u%v);
}
int main(){
    scanf("%I64d",&T);
    for (long long o=1; o<=T; o++){
          scanf("%I64d/%I64d",&p,&q); 
          g=gcd(p,q);
          p/=g; q/=g;
          long long tmp=q;
          ok=1;
          while (tmp%2==0) tmp/=2;
          if (tmp>1) ok=0;
          printf("Case #%I64d: ",o);
          if (ok){
             ac=0;
             while (q>1){
                   k=q/2LL; ++ac;
                   if (p>=k){
                      printf("%I64d\n",ac);
                      break;          
                   }
                   q/=2;
             }
             if (ac>40) printf("impossible\n");
          }
          else{
               printf("impossible\n");     
          }
    }
    return 0;    
}
