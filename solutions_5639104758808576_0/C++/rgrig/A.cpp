#include <stdio.h>
#include <algorithm>

using namespace std;

int main() {
  int tests; scanf("%d",&tests);
  for (int t = 1; t <= tests; ++t) {
    int smax; scanf("%d", &smax);
    char *s = (char*)malloc((smax + 2) * sizeof(char));
    scanf("%s", s);
    int result = 0;
    int seen = 0;
    int i;
    for (i = 0; i <= smax; ++i) {
      result = max(result, i - seen);
      seen += s[i] - '0';
    }
    free(s);
    printf("Case #%d: %d\n", t, result);
  }
}
