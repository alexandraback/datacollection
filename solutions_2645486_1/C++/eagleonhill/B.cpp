#include <cstdio>
#include <algorithm>
#include <set>

using namespace std;
int v[10010];
int pos[10010];

bool cmp(int a, int b) {
  return v[a] > v[b];
}

long long work() {
  int e, r, n;
  scanf("%d%d%d", &e, &r, &n);
  for (int i = 0; i < n; ++i) {
    scanf("%d", &v[i]);
    pos[i] = i;
  }
  sort(pos, pos + n, cmp);
  set<int> S;
  long long ans = 0;
  for (int i = 0; i < n; ++i) {
    set<int>::iterator it = S.lower_bound(pos[i]);
    int prev, next;
    long long left = 0, start = e;
    if (it != S.end()) {
      next = *it;
      left = e - (next - pos[i] * 1LL) * r;
      if (left < 0)
        left = 0;
    }
    if (it != S.begin()) {
      --it;
      prev = *it;
      start = (1LL * pos[i] - prev) * r;
      if (start > e)
        start = e;
    }
#ifdef MY
    printf("%d %d %d %d %lld %lld\n", i, pos[i], prev, next, left, start);
#endif
    if (start > left) {
      ans += (start - left) * 1LL *  v[pos[i]];
    }
    S.insert(pos[i]);
  }
  return ans;
}

int main() {
  int t;
  scanf("%d", &t);
  for (int i = 0; i < t; ++i) {
    printf("Case #%d: %lld\n", i + 1, work());
  }
}
