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
#define maxn 10000

typedef pair<int, int> pii;

int e, r, n, v[maxn];
map<pii, ll> memo;

ll f(int in, int ie) {
  if (in == n) return 0;
  if (memo.count(pii(in, ie))) return memo[pii(in, ie)];

  ll maxv = 0;

  for (int i = 0; i <= ie; i++)
    maxv = max(maxv, i * v[in] + f(in + 1, min(ie - i + r, e)));

  //  if (e > 0) maxv = max(maxv, e * v[in] + f(in + 1, r));
  //  if (e + )

  return (memo[pii(in, ie)] = maxv);
}

void docase(int icase) {
  scanf("%d %d %d", &e, &r, &n);

  for (int i = 0; i < n; i++)
    scanf("%d", &v[i]);

  memo.clear();

  printf("Case #%d: %lld\n", icase, f(0, e));
}

int main() {
  int t;
  scanf("%d", &t);

  for (int i = 0; i < t; i++)
    docase(i + 1);

  return 0;
}
