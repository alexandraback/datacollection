#include <cstdio>

using namespace std;

char s[1005];

int main() {
   int T, n, s1 = 0, s2 = 0;

   scanf("%d", &T);
   for (int t = 1; t <= T; t++) {
      scanf("%d %s\n", &n, s);

      s1 = s2 = 0;
      for (int i = 0; i <= n; i++) {
         s1 += s[i] - '0';
         s2 += s[i] - '0' + (i > s2)*(i - s2);
      }

      printf("Case #%d: %d\n", t, s2 - s1);
   }
	return 0;
}
