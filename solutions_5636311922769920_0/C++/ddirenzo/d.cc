#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ld = long double;

int main() {
  int T, K, C, S;
  scanf("%d",&T);
  for (int i = 1; i <= T; ++i) {
    scanf("%d%d%d",&K,&C,&S);
    printf("Case #%d: ",i);
    for (int j = 1; j <= K; ++j) {
      printf("%d ",j);
    }
    printf("\n");
  }
  return 0;
}
