#include <cstdio>
#include <algorithm>

using namespace std;

const int N = 110;

int n,m;
int r[N],c[N],x[N][N];

int main () {
  int test;
  scanf ("%d", &test);

  for (int Case = 1;Case <= test;Case ++) {
    scanf ("%d %d", &n, &m);

    for (int i = 0;i < n;i ++) {
      r[i] = 0;
    }
    for (int i = 0;i < m;i ++) {
      c[i] = 0;
    }

    for (int i = 0;i < n;i ++) {
      for (int j = 0;j < m;j ++) {
	scanf ("%d", &x[i][j]);
	r[i] = max (r[i], x[i][j]);
	c[j] = max (c[j], x[i][j]);
      }
    }

    bool yes = 1;
    for (int i = 0;i < n;i ++) {
      for (int j = 0;j < m;j ++) {
	if (x[i][j] != min (r[i], c[j])) {
	  yes = 0;
	  goto f;
	}
      }
    }
  f:;
    printf ("Case #%d: %s\n", Case, (yes ? "YES" : "NO"));
  }
}
