#include <iostream>
#include <cstdio>
#include <string>
#include <string.h>
using namespace std;

const int maxn = 100 + 10;
char st[maxn];

int f[maxn][maxn], d[maxn][maxn];
int fr[maxn][maxn], dr[maxn][maxn];

int min(int x, int y) {
  if (x < 0) return y;
  if (y < 0) return x;
  return x < y ? x : y;
}

int dr_c(int i, int j);
int fr_c(int i, int j);
int f_c(int i, int j);
int d_c(int i, int j);

int dr_c(int i, int j) {
  if (i == j) return st[j] != '+';
  if (dr[i][j] >= 0) return dr[i][j];
  if (st[i] == '+') {
    return dr[i][j] = dr_c(i+1,j);
  }
  int min_ans = -1;
  for (int k = i+1; k <= j; k++) {
    min_ans = min(min_ans, 1 + fr_c(k, j) + d_c(i, k-1));
  }
  return dr[i][j] = min_ans;
}

int fr_c(int i, int j) {
  if (i == j) return st[j] != '-';
  if (fr[i][j] >= 0) return fr[i][j];
  if (st[i] == '-') {
    return fr[i][j] = fr_c(i+1,j);
  }
  int min_ans = -1;
  for (int k = i+1; k <= j; k++) {
    min_ans = min(min_ans, 1 + dr_c(k, j) + f_c(i, k-1));
  }
  return fr[i][j] = min_ans;
}

int d_c(int i, int j) {
  if (i == j) return st[j] != '-';
  if (d[i][j] >= 0) return d[i][j];
  if (st[j] == '-') {
    return d[i][j] = d_c(i, j-1);
  }
  int min_ans = -1;
  for (int k = i; k < j; k++) {
    min_ans = min(min_ans, 1 + f_c(i, k) + dr_c(k+1, j));
  }
  return d[i][j] = min_ans;
}

int f_c(int i, int j) {
  if (i == j) return st[j] != '+';
  if (f[i][j] >= 0) return f[i][j];
  if (st[j] == '+') {
    return f[i][j] = f_c(i, j-1);
  }
  int min_ans = -1;
  for (int k = i; k < j; k++) {
    min_ans = min(min_ans, 1 + d_c(i, k) + fr_c(k+1, j));
  }
  return f[i][j] = min_ans;
}


int main() {
  freopen("B-large.in", "r", stdin);
  freopen("B-large.out", "w", stdout);

  int TextN;
  scanf("%d", &TextN);
  for (int TT = 1; TT <= TextN; TT++) {
    scanf("%s", st);
    memset(f, -1, sizeof(f));
    memset(d, -1, sizeof(d));
    memset(fr, -1, sizeof(fr));
    memset(dr, -1, sizeof(dr));
    int ans = f_c(0, strlen(st) - 1);
    printf("Case #%d: %d\n", TT, ans);
  }
  return 0;
}