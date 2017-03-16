#include <bits/stdc++.h>
using namespace std;

int t, d, tot, pan[1100];

int test[1001][1001];

int search(int a, int b) {
  // test[a][b] = min steps required to get a stack of a to b
  if (test[a][b] != -1) return test[a][b];

  // Splitting this into 2 stacks of i and a-i
  int m = INT_MAX;
  for (int i=1; i<a; i++) {
    m = min(m, search(i,b)+search(a-i,b)+1);
  }
  test[a][b] = m;
  return m;
}

void initTable() {
  memset(test, -1, sizeof(test));

  for (int i=0; i<=1000; i++) {
    test[i][1] = i;
    for (int j=i; j<=1000; j++) {
      test[i][j] = 0;
    }
  }
}

int guage(int ceiling) {
  tot = ceiling;
  for (int i=1000; i>ceiling; i--) {
    if (pan[i] > 0) {
      tot += pan[i] * search(i, ceiling);
    }
  }
  return tot;
}

int main() {
  initTable();
  scanf("%d", &t);

  for (int ca=1; ca<=t; ca++) {
    scanf("%d", &d);
    memset(pan, 0, sizeof(pan));
    int p, highest = 0;
    for (int i=0; i<d; i++) {
      scanf("%d", &p);
      pan[p]++;
      highest = max(highest, p);
    }

    for (int i=1; i<highest; i++) {
      int v = guage(i);
      if (v < highest) highest = v;
    }
    printf("Case #%d: %d\n", ca, highest);
  }
}

