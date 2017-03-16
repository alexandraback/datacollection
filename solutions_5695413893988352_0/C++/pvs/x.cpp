#include <cstdio>
#include <cstring>
#include <vector>
#include <map>
#include <cmath>
#include <algorithm>

using namespace std;

bool m(char *a, int n) {
  char b[4]; sprintf(b, "%0*d", strlen(a), n);
  for (int i=0; i<strlen(a); ++i) {
    if (a[i]=='?') continue;
    if (a[i]!=b[i]) return false;
  }
  return true;
}

void f(char *a, char *b, int n) {
  int rx=0, ry=n;
  for (int x=0; x<n; ++x) for (int y=0; y<n; ++y) {
    if (abs(x-y) > abs(rx-ry)) continue;
    if (m(a, x) && m(b, y)) {
      if (abs(x-y) < abs(rx-ry)) { rx=x; ry=y; continue; }
      if (x<rx) { rx=x; ry=y; continue; }
      if (x>rx) continue;
      if (y<ry) { rx=x; ry=y; continue; }
    }
  }
  printf("%0*d ", strlen(a), rx);
  printf("%0*d\n", strlen(a), ry);
}

int main() {
  int n; scanf("%d\n", &n);
  for (int i=0; i<n; ++i) {
    char a[4], b[4]; scanf("%s\n%s\n", a, b);
    int p10=1;
    for (int i=0; i<strlen(a); ++i) p10*=10;
    printf("Case #%d: ", i+1); f(a, b, p10);
  }
}
