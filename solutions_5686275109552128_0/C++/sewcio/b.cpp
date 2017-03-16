#include <bits/stdc++.h>

using namespace std;

const int N = 1000;

int P[N+2];

int scoreFor(int D, int M){
  int score = M;
  for(int i = 0; i < D; i++) score += (P[i] - 1) / M;
  return score;
}

int main(){
  int T;
  scanf("%d", &T);
  for(int t = 1; t <= T; t++){
    int D;
    scanf("%d", &D);
    for(int *p = P; p != P + D; p++) scanf("%d", p);
    int Pmax = *max_element(P, P + D);
    int minScore = accumulate(P, P + D, 0);
    for(int i = 1; i <= Pmax; i++){
      minScore = min(minScore, scoreFor(D, i));
    }
    printf("Case #%d: %d\n", t, minScore);
  }
}
