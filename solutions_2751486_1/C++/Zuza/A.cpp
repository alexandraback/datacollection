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

const int MAXLEN = 1001000;

int k;
char S[MAXLEN];
int where[MAXLEN];
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

    int curr = 0;
    where[len] = -1;

    for (int i = len-1; i >= 0; --i) {
      where[i] = where[i+1];

      if (S[i]) {
        ++curr;
        if (curr >= k) {
          where[i] = i+k-1;
        }
      } else {
        curr = 0;
      }
    }

    llint cnt = 0;
    for (int i = 0; i < len; ++i) {
      if (where[i] == -1) continue;
      cnt += len-where[i];
    }

    printf("Case #%d: %lld\n", counter + 1, cnt);
    fflush(stdout);
  }

  return (0-0);
}
