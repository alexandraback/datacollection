#include <stdio.h>
#include <cstring>
#include <cmath>
#include <algorithm>

using namespace std;

int T;

int gold(int k, int c, int o, int p){
    if(c == 1) return o == p;
    if(gold(k,c-1,o,p/k)){
        return true;
    }else{
        return (p%k == o);
    }
}

unsigned long long ull_pow(int b, int e){
  unsigned long long ret = 1;
  for(int i = 0; i < e; i++) ret*= (unsigned long long) b;
  return ret;
}

int main(){
    scanf("%d", &T);
    for(int Tn = 1; Tn <= T; Tn++){
        printf("Case #%d: ", Tn);
        int k, c, s;
        scanf("%d%d%d", &k, &c, &s);
        int moves = ceil(float(k)/float(c));
        if(moves > s){
            printf("IMPOSSIBLE\n");
        }else{
          unsigned long long int start = 1;
          for(int i = 1; i<min(c,k);i++){
            for(int j = 1; j<=i; j++) start+= ull_pow(k,j-1); 
          }
          unsigned long long int diff = 0;
          for(int i = 0; i<c; i++) diff+= ull_pow(k, i);
          diff *= c;
          if(moves == 1){
              printf("%llu", start);
          }else if (k%c == 0){
             for(int i = 0; i < moves;i++){
                printf("%llu ", start + i*diff);
             } 
          }else{
             for(int i = 0; i < moves-1;i++){
                printf("%llu ", start + i*diff);
             } 
         
             if(k%c != 0 && k > c){
                printf("%llu", ull_pow(k,c) - start + 1);
             }
          } 
          printf("\n");
        }
    }
} 
