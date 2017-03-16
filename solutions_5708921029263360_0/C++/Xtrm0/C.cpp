#include <bits/stdc++.h>
#define _ ios_base::sync_with_stdio(0);cin.tie(0);
using namespace std;
int J, P, S, K;
int taken[10][10][10];
int used[3][10][10];
int print = 0;
int best = 0;
int dfs(int j, int p, int s, int cnt) {
  if (j==J) {
    if (print) {
      if (best == cnt) {
        return 1;
      } else {
        return 0;
      }
    } else {
      if (cnt > best) {
        best = cnt;
      }
      return 0;
    }
  }
  if (p==P) return dfs(j+1,0,0,cnt);
  if (s==S) return dfs(j,p+1,0,cnt);
  if (used[0][j][p] < K && used[1][j][s] < K && used[2][p][s] < K) {
    used[0][j][p]++;
    used[1][j][s]++;
    used[2][p][s]++;
    taken[j][p][s] = 1;
    if (dfs(j,p,s+1,cnt+1) && print) {
      printf("%d %d %d\n", j+1, p+1, s+1);
      return 1;
    }
    used[0][j][p]--;
    used[1][j][s]--;
    used[2][p][s]--;
  }

  taken[j][p][s] = 0;
  if (dfs(j,p,s+1,cnt) && print) {
    return 1;
  }
  return 0;
}

int main() {_;
  int T;
  scanf("%d", &T);

  for (int t=1; t<=T; t++) {
    printf("Case #%d: ", t);
    scanf("%d %d %d %d", &J, &P, &S, &K);
    best = 0;
    for (int i=0; i<10; i++) for (int ii=0; ii<10; ii++) used[0][i][ii] = used[1][i][ii] = used[2][i][ii] = 0;
    for (int i=0; i<10; i++) for (int ii=0; ii<10; ii++) for (int iii=0; iii<10; iii++) taken[i][ii][iii] = 0;
    print = 0;
    dfs(0,0,0,0);
    for (int i=0; i<10; i++) for (int ii=0; ii<10; ii++) used[0][i][ii] = used[1][i][ii] = used[2][i][ii] = 0;
    for (int i=0; i<10; i++) for (int ii=0; ii<10; ii++) for (int iii=0; iii<10; iii++) taken[i][ii][iii] = 0;
    print = 1;
    printf("%d\n", best);
    dfs(0,0,0,0);
  }
  return 0;
}
