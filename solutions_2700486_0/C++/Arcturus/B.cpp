#include <stdio.h>

int ds[10];
double C[10][10];

void prework(){
  int inc = 5;
  
  ds[0] = 1;
  for(int i=1; i<10; i++){
    ds[i] = ds[i-1] + inc;
    inc += 4;
    //printf("ds[%d] = %d\n", i, ds[i]);
  }
  
  for(int i=0; i<10; i++){
    for(int j=0; j<10; j++) C[i][j] = 0;
  }
  for(int i=0; i<10; i++){
    C[i][0] = 1;
    for(int j=1; j<i; j++) C[i][j] = C[i-1][j-1] + C[i-1][j];
    C[i][i] = 1;
  }
}

int main(){
  prework();
  
  int jcase;
  int N, x, y;
  int idx;
  int comp;
  int order;
  double ans;
  
  freopen("B-small-attempt0.in", "r", stdin);
  freopen("B-small-attempt0.out", "w", stdout);
  //freopen("A-large.in", "r", stdin);
  //freopen("A-large.out", "w", stdout);
  
  scanf("%d", &jcase);
  for(int icase=0; icase<jcase; icase++){
    scanf("%d %d %d", &N, &x, &y);
    idx = 0;
    if(x < 0) x = -x;
    
    if((x + y) % 2 == 1){//impossible
      printf("Case #%d: 0.0000000\n", icase+1);
      continue;
    }
    
    while(ds[idx] <= N){
      idx++;
    }
    comp = (x + y) / 2;
    //printf("comp=%d idx=%d\n", comp, idx);
    if(comp < idx){ //below pile
      printf("Case #%d: 1.0000000\n", icase+1);
      continue;
    }
    else if(comp > idx){ //above pile
      printf("Case #%d: 0.0000000\n", icase+1);
      continue;
    }
    
    ans = 0;
    order = N - ds[idx-1];
    
    if(order > idx*2 + y){ // left/right full
      printf("Case #%d: 1.0000000\n", icase+1);
      continue;
    }
    if(x == 0){ //not full
      printf("Case #%d: 0.0000000\n", icase+1);
      continue;
    }
    
    //printf("order = %d\n", order);
    for(int i=y+1; i<=order; i++){
      ans += C[order][i];
      //printf("ans += %lf\n", C[order][i]);
    }
    for(int i=0; i<order; i++) ans /= 2;
    printf("Case #%d: %.7f\n", icase+1, ans);
  }
  return 0;
}
