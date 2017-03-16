#include <stdio.h>

int main()
{
  int ntc;

  scanf("%d", &ntc);
  for (int tc = 0; tc < ntc;) {
    int n, k;
    int p;
    int total[100];
    int answer = 0;

    scanf("%d%d%d", &n, &k, &p);
    for (int i = 0; i < n; ++i)
      scanf("%d", &total[i]);
    for (int i = 0; i < n; ++i) {
      if ((total[i] + 2) / 3 >= p)
	++answer;
      else if (total[i] >= 2 && (total[i] + 4) / 3 >= p) {
	if (k > 0) {
	  ++answer;
	  --k;
	}
      }
    }
    printf("Case #%d: %d\n", ++tc, answer);
  }

  return 0;
}
