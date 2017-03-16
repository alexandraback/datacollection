#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <vector>
#include <set>
#include <vector>

using namespace std;

#define MAX 128
char s[MAX];
int N;

int faz(int i, int b) {
  int c = 0;

  if (b && s[i] != '+') c = 1;
  else if (!b && s[i] != '-') c = 1;

  if (i == 0) return c;

  return c+faz(i-1, c ? (1-b) : b);
}

int main() {
  int T;

  scanf("%d", &T);
  for(int caso = 1; caso <= T; caso++) {
    scanf("%s", s);
    N = strlen(s);
    printf("Case #%d: %d\n", caso, faz(N-1, 1));
  }
  return 0;
}

