/*       GCJ - Speaking in Tongues       */
#include <cstdio>

using namespace std;

void process(int c);

int main(void) {
  int n; scanf("%d", &n);
  for (int i = 1; i <= n; i++)
    process(i);
  return 0;
}

void process(int c) {
  int n, s, p, count = 0;
  scanf("%d%d%d", &n, &s, &p);
  for (int i = 1; i <= n; i++) {
    int t; scanf("%d", &t);
    int normal = t / 3;
    if (t % 3) normal += 1;
    if (normal >= p) count++;
    else if (t % 3 != 1 && normal + 1 >= p && s && (t % 3 != 0 || normal > 0))
        count++, s--;
  }
  printf("Case #%d: %d\n", c, count);
}