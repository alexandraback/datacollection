#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cmath>

#define MAX 1001

using namespace std;

int cnt[MAX];

bool pal(int i) {
  int pal = 0, j = i;
  while (j != 0) {
    pal = (pal * 10) + (j % 10);
    j /= 10;
  }

  return pal == i;
}

bool fas(int i) {
  int r = sqrt(i);
  if (r * r != i)
    return false;

  return pal(r) && pal(i);
}

int main() {
  cnt[0] = 0;
  for (int i = 1; i < MAX; i++) {
    cnt[i] = cnt[i - 1] + fas(i);
  }

  int ncases, a, b;
  scanf("%i", &ncases);
  for (int caseno = 1; caseno <= ncases; caseno++) {
    scanf("%i%i", &a, &b);
    printf("Case #%i: %i\n", caseno, cnt[b] - cnt[a - 1]);
  }
}
