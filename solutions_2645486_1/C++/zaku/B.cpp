#include <cstdio>
#include <cstring>
#include <cmath>
#include <algorithm>
#include <string>
#include <vector>
#include <set>
#include <map>
using namespace std;

#define SZ(v) ((int)(v).size())

typedef long long LL;

#ifdef __linux__
#define FMT "%lld"
#else
#define FMT "%I64d"
#endif

const int kMaxN = 10010;

int n, E, R;
int V[kMaxN];
int imp[kMaxN];

int tree[4*kMaxN];

void solve1()
{
  int idx = n-1;
  memset(imp, 0, sizeof(imp));
  imp[n-1] = 1;
  for (int i = n-2; i >= 0; --i) {
    if (V[i] >= V[idx]) {
      imp[i] = 1;
      idx = i;
    }
  }

  if (R > E) R = E;

  LL result = 0, e = E;
  for (int i = 0; i < n; ++i) {
    if (imp[i]) {
      result += e * V[i];
      e = R;
    } else {
      if (e + R <= E) {
	e += R;
      } else {
	LL tmp = e + R - E;
	result += tmp * V[i];
	e = E;
      }
    }
  }

  printf(FMT "\n", result);
}

void solve()
{
  static LL f[2][10];

  int w = 0;
  memset(f, 0xff, sizeof(f));
  f[w][E] = 0;
  for (int i = 0; i < n; ++i) {
    memset(f[w^1], 0xff, sizeof(f[w^1]));
    for (int j = 0; j <= E; ++j) {
      if (f[w][j] < 0) continue;
      for (int l = 0; l <= j; ++l) {
	f[w^1][min(E, j-l+R)] = max(f[w][j] + l * V[i], f[w^1][min(E, j-l+R)]);
      }
    }
    w ^= 1;
  }

  LL result = 0;
  for (int i = 0; i <= E; ++i) result = max(result, f[w][i]);
  printf(FMT "\n", result);
}

void build(int l, int r, int h)
{
  if (l == r) {
    tree[h] = V[l];
    return;
  }

  int mid = (l+r)/2;
  build(l, mid, 2*h+1);
  build(mid+1, r, 2*h+2);
  tree[h] = max(tree[2*h+1], tree[2*h+2]);
}

int find_pos(int l, int r, int h, int pp, int v)
{
  if (tree[h] < v || r < pp) return -1;
  if (l == r) {
    return l;
  }

  int mid = (l+r)/2, ret = -1;
  if (tree[2*h+1] >= v && mid >= pp) ret = find_pos(l, mid, 2*h+1, pp, v);
  if (ret == -1 && tree[2*h+2] >= v && r >= pp) ret = find_pos(mid+1, r, 2*h+2, pp, v);
  return ret;
}

void solve2()
{
  memset(tree, 0, sizeof(tree));
  build(0, n-1, 0);

  LL result = 0;
  LL e = E, tmp;
  int p;
  for (int i = 0; i < n; ++i) {
    p = find_pos(0, n-1, 0, i+1, V[i]);
    //    printf("p %d\n", p);
    if (p == -1) {
      result += e * (LL)V[i];
      e = R;
    } else {
      tmp = (p - i)*R + e - E;
      tmp = min(e, tmp);
      tmp = max(0ll, tmp);
      result += tmp * (LL)V[i];
      e += R - tmp;
    }
  }

  printf(FMT "\n", result);
}

int main()
{
  int t;
  scanf("%d", &t);
  for (int l = 1; l <= t; ++l) {
    scanf("%d%d%d", &E, &R, &n);
    if (R > E) R = E;
    for (int i = 0; i < n; ++i) scanf("%d", V + i);
    printf("Case #%d: ", l);
    solve2();
  }
  return 0;
}
