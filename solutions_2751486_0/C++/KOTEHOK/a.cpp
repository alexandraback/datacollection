#include <cstdio>
#include <cstring>

#define MAXL 1100000

char s[MAXL];

int main () {
  int tn;
  scanf ("%d", &tn);
  for (int t = 1; t <= tn; t++) {
    long long ans = 0;
    int n;
    scanf ("%s%d", s, &n);
    int l = strlen (s);
    int p2 = -1, cnt = 0, beg = 0;
    for (int p1 = 0; p1 < l; p1++) {
      while (cnt < n && p2 < l) {
	++p2;
	beg = p2;
	cnt = 0;
	while (p2 < l && s[p2] != 'a' && s[p2] != 'e' && s[p2] != 'i' && s[p2] != 'o' && s[p2] != 'u') {
	  ++cnt;
	  ++p2;
	}
      }
      ans += cnt < n ? 0 : l - p2 - (n - cnt) + 1;
      //printf ("%d %d %d %d\n", p1, p2, beg, cnt);
      if (p1 >= beg) {
	--cnt;
	++beg;
      }
    }
    printf ("Case #%d: %lld\n", t, ans);
  }
  return 0;
}
