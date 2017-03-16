#include <algorithm>
#include <functional>

#include <cassert>
#include <cstdio>
#include <cstdlib>
#include <cstring>

#include <string>
#include <vector>

using namespace std;

typedef long long llint;

const int MAXLEN = 100100;

int k;
char S[MAXLEN];
int len;

bool cons(char c) {
  if (c == 'a') return false;
  if (c == 'e') return false;
  if (c == 'i') return false;
  if (c == 'o') return false;
  if (c == 'u') return false;
  return true;
}

int main(void)
{
  int T; scanf("%d", &T);

  for (int counter = 0; counter < T; ++counter) {
    scanf("%s %d", S, &k);
    len = strlen(S);

    for (int i = 0; i < len; ++i) {
      S[i] = cons(S[i]);
    }

    llint cnt = 0;

    for (int i = 0; i < len; ++i)
      for (int j = i; j < len; ++j) {
        int maks = 0;
        int curr = 0;
        for (int it = i; it <= j; ++it) {
          if (S[it]) {
            ++curr;
            if (curr > maks)
              maks = curr;
          } else {
            curr = 0;
          }
        }
        if (maks >= k) ++cnt;
      }

    printf("Case #%d: %lld\n", counter + 1, cnt);
    fflush(stdout);
  }

  return (0-0);
}
