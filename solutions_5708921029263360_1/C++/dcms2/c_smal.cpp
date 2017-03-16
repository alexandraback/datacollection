#include <bits/stdc++.h>

using namespace std;

typedef pair<int, int> ii;

struct Outfit {
  int j, p, s;
  Outfit() {}
  Outfit(int j, int p, int s) : j(j), p(p), s(s) {}
} arr[10000], ans[30], aux[30];

int k;

bool ok(int i, map<ii, int>& num_used) {
  int a = arr[i].j, b = arr[i].p;
  if (num_used[ii(a,b)] == k) return false;
  int c = arr[i].j, d = arr[i].s;
  if (num_used[ii(c,d)] == k) return false;
  int e = arr[i].p, f = arr[i].s;
  if (num_used[ii(e,f)] == k) return false;

  num_used[ii(a,b)]++;
  num_used[ii(c,d)]++;
  num_used[ii(e,f)]++;
  return true;
}

int main() {
  srand(time(NULL));
  int nt; scanf("%d", &nt);
  for (int caso = 1; caso <= nt; ++caso) {
    int j, p, s; scanf("%d %d %d %d", &j, &p, &s, &k);
    int sz = 0;

    for (int a = 0; a < j; ++a) {
      for (int b = 0; b < p; ++b) {
        for (int c = 0; c < s; ++c) {
          arr[sz++] = Outfit(a, b + j, c + j + p);
        }
      }
    }

    int ans_sz = 0;

    for (int _try = 0; _try < 20000; ++_try) {
      random_shuffle(arr, arr + sz);

      map<ii, int> num_used;

      int aux_sz = 0;

      for (int i = 0; i < sz; ++i) {
        if (ok(i, num_used)) {
          aux[aux_sz++] = arr[i];
        }
      }

      if (aux_sz > ans_sz) {
        ans_sz = aux_sz;
        for (int i = 0; i < aux_sz; ++i) ans[i] = aux[i];
      }
    }

    printf("Case #%d: %d\n", caso, ans_sz);
    for (int i = 0; i < ans_sz; ++i) {
      printf("%d %d %d\n", ans[i].j + 1, ans[i].p + 1 - j, ans[i].s + 1 - j - p);
    }

  }
  return 0;
}