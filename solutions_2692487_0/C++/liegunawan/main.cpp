#include <cmath>
#include <set>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <map>
#include <cstring>
#include <cctype>
#include <string>
#include <sstream>
#include <stack>
#include <queue>

using namespace std;

#define ll long long
#define maxn 100

typedef pair<ll, int> pli;

int eat(int i, int n, ll a, ll v[], int x) {
  if (x > n) return x;
  if (i == n) return x;
  if (a > v[i]) return eat(i + 1, n, a + v[i], v, x);

  int x1 = eat(i + 1, n, a, v, x + 1);

  int ix = 0;
  while (a <= v[i] && a - 1 > 0 && x + ix < n) {
    a += a - 1;
    ix++;
  }
  int x2 = (a > v[i] ? eat(i + 1, n, a + v[i], v, x + ix) : maxn * 2);

  return min(x1, x2);
}

void docase(int icase) {
  ll a, n;
  scanf("%lld %lld", &a, &n);

  ll v[maxn];
  for (int i = 0; i < n; i++)
    scanf("%lld", &v[i]);

  sort(v, v + n);

  printf("Case #%d: %d\n", icase, eat(0, n, a, v, 0));
}

int main() {
  int t;
  scanf("%d", &t);

  for (int i = 0; i < t; i++)
    docase(i + 1);

  return 0;
}
