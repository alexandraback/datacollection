#include <cstdio>
#include <cstdlib>
#include <algorithm>

using namespace std;

char z[1500];
  int X, Y, Z;

void f() {
  char c[] = "NSWE";
  scanf("%d%d", &X, &Y);
  Z = abs(X) + abs(Y);
  if (!Z) {
    z[0] = 0;
    return;
  }
  if (Y < 0)
    swap(c[0], c[1]);
  if (X < 0)
    swap(c[2], c[3]);
  int n(1), s(1), t, u;
  while (s < Z)
    s += ++n;
  l:
  while (s - Z & 1)
    s += ++n;
  for (int i(0); i < n; i++)
    z[i] = X < 0 ? 'W' : 'E';
  z[n] = 0;
  t = s - Z >> 1;
  u = s - abs(X) - t;
  for (int i(n); i >= 2; i--)
    if (i <= t && t - i != 1) {
      z[i - 1] = c[1];
      t -= i;
    }
  if (t) {
    if (t == 1)
      z[0] = c[1];
    else
      exit(1);
  }
  for (int i(n); i >= 1; i--)
    if (i <= u && z[i - 1] != c[1]) {
      z[i - 1] = c[0];
      u -= i;
    }
  if (!u)
    return;
  for (int i(0); i < n; i++)
    z[i] = Y < 0 ? 'S' : 'N';
  z[n] = 0;
  t = s - Z >> 1;
  u = s - abs(Y) - t;
  for (int i(n); i >= 2; i--)
    if (i <= t && t - i != 1) {
      z[i - 1] = c[2];
      t -= i;
    }
  if (t) {
    if (t == 1)
      z[0] = c[2];
    else
      exit(1);
  }
  for (int i(n); i >= 1; i--)
    if (i <= u && z[i - 1] != c[2]) {
      z[i - 1] = c[3];
      u -= i;
    }
  if (!u)
    return;
  n++;
  goto l;
}

int main() {
  int T;
  scanf("%d", &T);
  for (int i(1); i <= T; i++) {
    f();
    /*int x(0), y(0);
    for (int j(0); z[j]; j++)
      switch(z[j]) {
      case 'E': x+=j+1; break;
      case 'W': x-=j+1; break;
      case 'N': y+=j+1; break;
      case 'S': y-=j+1; break;
      }
    if (x != X || y != Y)
      puts("========");*/
    printf("Case #%d: %s\n", i, z);
  }
}