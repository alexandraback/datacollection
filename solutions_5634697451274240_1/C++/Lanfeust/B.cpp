#include "cmath"
#include "cstdio"
#include "cstring"
#include "algorithm"
#include "map"
#include "numeric"
#include "queue"
#include "set"
#include "string"
#include "utility"
#include "vector"

using namespace std;

typedef long long i64;

int solve(char *s) {
  int len = strlen(s);
  int top = 0, bottom = len - 1;
  int nb_flip = 0;
  //fprintf(stderr, "|%s|\n", s);
  bool done = false;
  char bottom_target = '+';
  while (!done) {
    if (nb_flip > 10)
      return -1;
    //fprintf(stderr, "%d %d %d\n", top, bottom, nb_flip);
    if (s[bottom] == bottom_target) {
      if (top == bottom)
        done = true;
      else
        bottom = bottom + (bottom > top ? -1 : 1);
    } else {
      nb_flip++;
      if (s[top] == bottom_target) {
        int cur = top, incr = top < bottom ? 1 : -1;
        while (s[top] == bottom_target) {
          s[top] = bottom_target == '+' ? '-' : '+';
          top += incr;
        }
      } else {
        int tmp = top;
        top = bottom;
        bottom = tmp;
        bottom_target = bottom_target == '+' ? '-' : '+';
      }
    }
  }
  return nb_flip;
}

int main() {
  int T;
  scanf("%d", &T);
  for (int Ti = 1; Ti <= T; ++Ti) {
    fprintf(stderr, "Case #%d of %d...\n", Ti, T);
    char s[101];
    scanf("%100s", s);
    printf("Case #%d: %d\n", Ti, solve(s));
  }
  return 0;
}
