#include <iostream>
#include <cstdio>
using namespace std;

int _N;
const int _N_MAX = 1010;
int a[_N_MAX], b[_N_MAX], flg[_N_MAX];

void solve(int run) {
  scanf("%d", &_N);
  for (int i = 0; i < _N; ++i) {
    scanf("%d %d", &a[i], &b[i]); 
    flg[i] = 0;
  }
  int cnt = 0;
  int star = 0;
  int tot = _N;
  while (true) {
    bool mk = false;
    for (int i = 0; i < _N; ++i)
      if (flg[i] != 2 && star >= b[i]) {
        if (flg[i] == 0)
          star += 2;
        else
          star += 1;
        flg[i] = 2;
        mk = true;
        --tot;
        ++cnt;
      }
    if (tot == 0) break;
    if (mk) continue;
    for (int i = 0; i < _N; ++i)
      if (flg[i] == 0 && star >= a[i]) {
        star++;
        flg[i] = 1;
        mk = true;
        ++cnt;
        break;
      }
    if (mk) continue;
    else break;
  }
  printf("Case #%d: ", run);
  if (tot != 0) printf("Too Bad\n");
  else printf("%d\n", cnt);
}

int main() {
  int runs;
  scanf("%d", &runs);
  for (int i = 1; i <= runs; ++i)
    solve(i);
  return 0;
}
