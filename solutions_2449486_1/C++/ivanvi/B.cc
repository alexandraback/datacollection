#include <cstdio>

using namespace std;

#define MAX 128

void input(void);
void solve(void);

int n, m;
int A[MAX][MAX];
int case_cnt = 1;

int main(void) {
  int t;
  scanf("%d", &t);
  while (t--) {
    input();
    solve();
  }
  return 0;
}

void input(void) {
  scanf("%d %d", &n, &m);
  for (int i = 0; i < n; i++) for (int j = 0; j < m; j++) {
    scanf("%d", &A[i][j]);
  }
}

void solve(void) {
  int good = true;
  for (int i = 0; i < n; i++) for (int j = 0; j < m; j++) {
    bool row = true;
    bool col = true;
    for (int k = 0; k < n; k++) {
      if (A[k][j] > A[i][j]) col = false;
    }
    for (int k = 0; k < m; k++) {
      if (A[i][k] > A[i][j]) row = false;
    }
    if (!row && !col) {
      good = false;
    }
  }

  printf("Case #%d: %s\n", case_cnt++, good ? "YES" : "NO");
}


