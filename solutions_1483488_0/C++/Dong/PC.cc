#include <stdio.h>
#include <set>

int main()
{
  int ntc;
  scanf("%d", &ntc);
  for (int tc = 0; tc < ntc;) {
    int A, B;
    int answer = 0;
    scanf("%d%d", &A, &B);
    int len = 0, p10 = 1;
    for (int tmp = A; tmp > 0; tmp /= 10) {
      ++len;
      p10 *= 10;
    }
    p10 /= 10;
    for (int n = A; n <= B; ++n) {
      int m = n;
      std::set<int> set;
      for (int i = 1; i < len; ++i) {
	m = (m % 10) * p10 + (m / 10);
	if (n < m && m <= B) set.insert(m);
      }
      answer += (int)set.size();
    }
    printf("Case #%d: %d\n", ++tc, answer);
  }
  return 0;
}
