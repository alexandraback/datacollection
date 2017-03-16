#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

typedef long long LL;
const int maxn = 30;
const int maxm = 5;
int t, a, b, c, x, tt;
int cnt[maxm][maxm][maxm];
struct node{
  int a, b, c;
  node() {}
  node(int a, int b, int c) : a(a), b(b), c(c) {}
  bool check() {
    ++cnt[1][a][b], ++cnt[2][b][c], ++cnt[3][a][c];
    return cnt[1][a][b] <= x && cnt[2][b][c] <= x && cnt[3][a][c] <= x;
  }
  void print() {
    printf("%d %d %d\n", a, b, c);
  }
} d[maxn];


int main() {
  freopen("/Users/wangchengrui/Desktop/C-small-attempt0.in.txt", "r", stdin);
  freopen("/Users/wangchengrui/Desktop/C-small-attempt0.out.txt", "w", stdout);
  scanf("%d", &t);
  while (t--) {
    scanf("%d%d%d%d", &a, &b, &c, &x);
    printf("Case #%d: ", ++tt);
    if (x >= c) {
      printf("%d\n", a * b * c);
      for (int i = 1; i <= a; ++i) {
        for (int j = 1; j <= b; ++j) {
          for (int k = 1; k <= c; ++k) {
            printf("%d %d %d\n", i, j, k);
          }
        }
      }
      continue;
    }
    int n = 0;
    for (int i = 1; i <= a; ++i) {
      for (int j = 1; j <= b; ++j) {
        for (int k = 1; k <= c; ++k) {
          d[n++] = node(i, j, k);
        }
      }
    }
    int S = (1 << n), ans = 0, Max = 0;
    for (int i = 1; i < S; ++i) {
      int num = __builtin_popcount(i);
      if (num > Max) {
        bool ok = true;
        memset(cnt, 0, sizeof cnt);
        for (int j = 0; j < n; ++j) {
          if (i & (1 << j)) {
            if(!d[j].check()) {
              ok = false;
              break;
            }
          }
        }
        if (ok) {
          Max = num;
          ans = i;
        }
      }
    }
    printf("%d\n", Max);
    for (int i = 0; i < n; ++i) {
      if (ans & (1 << i)) {
        d[i].print();
      }
    }
  }
  return 0;
}
