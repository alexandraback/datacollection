#include <cstdio>
#include <algorithm>

using namespace std;

int lawn[100][100], M, N;

int sol_i[100], sol_j[100];

bool sat() {
  for(int i = 0; i < N; i++) {
    for(int j = 0; j < M; j++) {
      if(lawn[i][j] == sol_i[i] || lawn[i][j] == sol_j[j]) {}
      else return false;
    }
  }
  return true;
}

bool solve() {
  for(int i = 0; i < N; i++) {
    sol_i[i] = 0;
    for(int j = 0; j < M; j++) {
      sol_i[i] = max(sol_i[i], lawn[i][j]);
    }
  }
  for(int j = 0; j < M; j++) {
    sol_j[j] = 0;
    for(int i = 0; i < N; i++) {
      sol_j[j] = max(sol_j[j], lawn[i][j]);
    }
  }
  return sat();
}

int main(){
  int K;
  scanf("%d\n", &K);
  for(int n = 1; n <= K; n++) {
    scanf("%d%d", &N, &M);
    for(int i=0; i < N; i++) 
    {
      for(int j = 0; j < M; j++) {
        scanf("%d", &lawn[i][j]);
      }
    }
    printf("Case #%d: ", n);
    if(solve()) {
      printf("YES");
    } else {
      printf("NO");
    }
    printf("\n");
  }
  return 0;
}
