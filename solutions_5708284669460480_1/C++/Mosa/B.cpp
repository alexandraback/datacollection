#include <bits/stdc++.h>

using namespace std;

const int N = 110;

int k, l, s;
char K[N], L[N];
int f[N];
int dpkmp[N][128];
int dpc[N][N];
double dpe[N][N];

int get(int j, char c) {
  int &res = dpkmp[j][(int)c];
  if(res != -1) return res;
  while(j > 0 && L[j] != c) {
    j = f[j - 1];
  }
  if(L[j] == c) ++j;
  return res = j;
}

int solvec(int i, int j) {
  if(i == s) {
    return 0;
  }
  int &res = dpc[i][j];
  if(res != -1) return res;
  res = 0;
  for(int c = 0; c < k; ++c) {
    int nj = get(j, K[c]);
    if(nj == l) {
      res = max(res, solvec(i + 1, f[nj - 1]) + 1);
    }else {
      res = max(res, solvec(i + 1, nj));
    }
  }
  return res;
}

double solvee(int i, int j) {
  if(i == s) {
    return 0;
  }
  double &res = dpe[i][j];
  if(res == res) return res;
  res = 0;
  for(int c = 0; c < k; ++c) {
    int nj = get(j, K[c]);
    if(nj == l) {
      res += solvee(i + 1, f[nj - 1]) + 1;
    }else {
      res += solvee(i + 1, nj);
    }
  }
  res /= k;
  return res;
}

int main() {
  freopen("B.in", "rt", stdin);
  freopen("B.out", "wt", stdout);
  int t; scanf("%d", &t);
  for(int test = 1; test <= t; ++test) {
    scanf("%d %d %d", &k, &l, &s);
    scanf("%s", K);
    scanf("%s", L);
    memset(dpkmp, -1, sizeof dpkmp);
    f[0] = 0;
    for(int i = 1, j = 0; i < l; ++i) {
      j = f[i] = get(j, L[i]);
    }
    memset(dpc, -1, sizeof dpc);
    memset(dpe, -1, sizeof dpe);
    double ans = solvec(0, 0) - solvee(0, 0);
    printf("Case #%d: %.7lf\n", test, ans);
  }
  return 0;
}
