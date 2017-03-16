#include <cstdio>
#include <cstring>

int H[2000], d[100], c[100], w[100], e[100], s[100], dd[100], dp[100], ds[100];

int main () {
  int tn;
  scanf ("%d", &tn);
  for (int t = 1; t <= tn; t++) {
    memset (H, 0, sizeof (H));
    int n;
    scanf ("%d", &n);
    for (int i = 0; i < n; i++) {
      scanf ("%d%d%d%d%d%d%d%d", &d[i], &c[i], &w[i], &e[i], &s[i], &dd[i], &dp[i], &ds[i]);
    }
    int ans = 0;
    for (int cd = 0; cd <= 700000; cd++) {
      for (int i = 0; i < n; i++)
	if (d[i] == cd && c[i] > 0) {
	  for (int j = w[i]; j < e[i]; j++)
	    if (H[1000 + j] < s[i]) {
	      ++ans;
	      break;
	    }
	}
      for (int i = 0; i < n; i++) 
	if (d[i] == cd && c[i] > 0) {
	  for (int j = w[i]; j < e[i]; j++)
	    if (H[1000 + j] < s[i]) {
	      H[1000 + j] = s[i];
	    }
	  c[i]--;
	  d[i] += dd[i];
	  w[i] += dp[i];
	  e[i] += dp[i];
	  s[i] += ds[i];
	}
    }

    printf ("Case #%d: %d\n", t, ans);
  }
  return 0;
}
