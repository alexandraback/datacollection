#include<cstdio>
#include<vector>
#include<algorithm>
using namespace std;
int main() {
  int T;
  scanf("%d", &T);
  for (int ncase = 0; ncase < T; ncase++) {
    long long M;
    int B;
    scanf("%d%lld", &B, &M);
    long long c = (((long long) 1) << ((long long) B-2));
    //printf("M is %lld B is %d c is %lld test is %lld\n", M, B, c, test);
    printf("Case #%d:", ncase+1);
    //printf("B is %d M is %d\n", B, M);
    //printf("c is %d M is %d\n", c, M);
    if (M > c) {
      printf(" IMPOSSIBLE\n");
      continue;
    }
    printf(" POSSIBLE\n");
    vector<int> V;
    M--;
    V.push_back(1);
    while (M > 0) {
      V.push_back(M % 2);
      M /= 2;
    }
    //for (int i = 0; i < V.size(); i++)
      //printf("%d: %d\n", i, V[i]);
    for (int i = 0; i < B; i++) {
      int c = B - i - 1;
      //printf("i is %d c is %d\n", i, c);
      if (c >= V.size())
        putchar('0');
      else
        putchar(V[c] ? '1' : '0');
    }
    putchar('\n');
    for (int i = 1; i < B; i++) {
      for (int j = 0; j < B; j++) {
        if (j <= i || i == B-1)
          putchar('0');
        else
          putchar('1');
      }
      putchar('\n');
    }
  }
  return 0;
}
