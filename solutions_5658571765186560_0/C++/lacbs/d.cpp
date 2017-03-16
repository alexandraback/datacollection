#include <cstdio>
#include <algorithm>
#include <queue>

using namespace std;
#define fr(a,b,c) for(int a = b; a < c; ++a)

void doit() {
  int x,r,c;
  scanf("%d%d%d", &x, &r, &c);
  if (r*c % x != 0) {
    puts("RICHARD");
    return;
  }
  if (x > max(r,c)) {
    puts("RICHARD");
    return;
  }
  if ((x+1)/2 > min(r,c)) {
    puts("RICHARD");
    return;
  }
  puts("GABRIEL");
  // I'm so silly :P
}

int main() {
  int t; scanf("%d", &t);
  for (int i = 1; i <= t; ++i) {
    printf("Case #%d: ", i);
    doit();
  }
  return 0;
}