#include <cstdio>

int T;
int A, B, K;
int ans;

int main(){
  int i, j;

  freopen( "B-small-attempt0.in", "r", stdin);
  freopen( "New_Lottery_Game_s.txt", "w", stdout);

  scanf("%d", &T);
  for( int tt = 1; tt <= T; tt++){
    scanf("%d %d %d", &A, &B, &K);
    
    ans = 0;
    for( i = 0; i < A; i++){
      for( j = 0; j < B; j++){
	if( ( i & j) < K)ans++; 
      }
    }

    printf("Case #%d: %d\n", tt, ans);
  }
}
