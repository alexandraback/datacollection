#include <stdio.h>
#include <algorithm>
using namespace std;

int T,N, resp1, resp2, ini1, fim1, ini2, fim2;
double v[1010];
double w[1010];

int compara(double a, double b){
  return a>b;
}

int main(){
  scanf(" %d", &T);
  for(int u=1; u<=T; u++){
    scanf(" %d", &N);
    for(int i=0; i<N; i++){
      scanf(" %lf", &v[i]);
    }
    for(int i=0; i<N; i++){
      scanf(" %lf", &w[i]);
    }
    sort(v,v+N,compara);
    sort(w,w+N,compara);
    
    resp2 = 0;
    ini2 = 0;
    fim2 = N-1;
    for(int i=0; i<N; i++){
      if(v[i] > w[ini2]){
        resp2++;
        fim2--;
      }
      else{
        ini2++;
      }
    }
    
    resp1 = 0;
    ini1 = 0;
    fim1 = N-1;
    ini2 = 0;
    fim2 = N-1;
    for(int i=0; i<N; i++){
      if(v[fim1] > w[fim2]){
        resp1++;
        fim1--;
        fim2--;
      }
      else{
        fim1--;
        ini2++;
      }
    }
    
    printf("Case #%d: %d %d\n", u, resp1, resp2);
  }
  return 0;
}
