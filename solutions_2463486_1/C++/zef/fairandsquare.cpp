#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cmath>

#define MAX 100000001ULL
#define LEN 100

using namespace std;

typedef unsigned long long int big;

big fas[LEN];

bool pal(big i) {
  big pal = 0ULL, j = i;
  while (j != 0ULL) {
    pal = (pal * 10) + (j % 10);
    j /= 10;
  }

  return pal == i;
}

int bin_search(int lo, int hi, big t) { // [lo, hi)
  if (lo + 1 >= hi)
    return lo;

  int mid = (lo + hi) / 2;
  if (fas[mid] > t)
    return bin_search(lo, mid, t);
  else
    return bin_search(mid, hi, t);
}

int main() {
  int cnt = 0;
  fas[cnt++] = 0;
  for (big i = 1; i < MAX; i++)
    if (pal(i) && pal(i * i))
      fas[cnt++] = i * i;

  int ncases;
  big a, b;
  scanf("%i", &ncases);
  for (int caseno = 1; caseno <= ncases; caseno++) {
    cin >> a >> b;
    printf("Case #%i: %i\n", caseno, bin_search(0, cnt, b) - bin_search(0, cnt, a - 1));
  }
}
