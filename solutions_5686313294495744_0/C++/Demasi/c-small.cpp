#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <vector>
#include <set>
#include <vector>
#include <string>

using namespace std;

int main() {
  int T;

  scanf("%d", &T);
  for(int caso = 1; caso <= T; caso++) {
    vector<string> w1, w2;
    int N;
    int r = 0;

    scanf("%d", &N);
    for(int i = 0; i < N; i++) {
      char s1[32], s2[32];
      scanf("%s %s", s1, s2);
      w1.push_back(string(s1));
      w2.push_back(string(s2));
    }

    for(int i = 0; i < (1<<N); i++) {
      int c = 0;
      int ok = 1;
      for(int j = 0; j < N && ok; j++) {
        if (i&(1<<j)) {
          int p1, p2;
          p1 = p2 = 0;
          c++;
          for(int k = 0; k < N; k++) {
            if (!(i&(1<<k))) {
              if (p1 == 0 && w1[j] == w1[k]) p1 = 1;
              if (p2 == 0 && w2[j] == w2[k]) p2 = 1;
            }
          }
          ok = (p1 && p2);
        }
      }
      if (ok) r = max(r, c);
    }

    printf("Case #%d: %d\n", caso, r);
  }
  return 0;
}

