#include <cstdio>
#include <algorithm>

using namespace std;
#define fr(a,b,c) for(int a = b; a < c; ++a)

int n;
char s[2000];

void doit() {
  scanf("%d%s", &n, s);
  n++;
  int acc = 0, res = 0;
  for (int i = 0; i < n; ++i) {
    if (acc < i) res += i - acc, acc = i;
    acc += s[i] - '0';
  }
  printf("%d\n", res);
}

int main() {
  int t; scanf("%d", &t);
  for (int i = 1; i <= t; ++i) {
    printf("Case #%d: ", i);
    doit();
  }
  return 0;
}