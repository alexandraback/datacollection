#include <stdio.h>


int arr[15];
int DP[15][10];

int main(){
  int jcase;
  int E, R, N;
  
  freopen("B-small-attempt0.in", "r", stdin);
  freopen("B-small-attempt0.out", "w", stdout);
  //freopen("A-large.in", "r", stdin);
  scanf("%d", &jcase);
  
  for(int icase=0; icase<jcase; icase++){
    scanf("%d %d %d", &E, &R, &N);
    for(int i=1; i<=N; i++) scanf("%d", &arr[i]);
    
    for(int i=0; i<=N; i++){
      for(int j=0; j<=E; j++) DP[i][j] = 0;
    }
    
    for(int i=1; i<=N; i++){
      for(int j=E; j>=0; j--){
        int dt = j-R;
        if(dt < 0) dt = 0;
        DP[i][j] = DP[i-1][dt];
        for(int k=j; k<=E; k++){
          if(DP[i][j] < DP[i][k] + arr[i]*(k-j)) DP[i][j] = DP[i][k] + arr[i]*(k-j);
        }
      }
    }
    
    printf("Case #%d: %d\n", icase+1, DP[N][0]);
  }
  return 0;
}
