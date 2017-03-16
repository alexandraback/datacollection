#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <vector>
#include <set>
#include <vector>

#define MAX 2048

using namespace std;
char s[MAX];

int main() {
  int T;

  scanf("%d", &T);
  for(int caso = 1; caso <= T; caso++) {
    vector<int> d(10, 0);
    vector<int> c(256, 0);

    scanf("%s", s);
    for(int i = 0; s[i]; i++) {
      c[(int)s[i]]++;
    }

    if (c[(int)'Z'] > 0) {
      d[0] = c[(int)'Z'];
      c[(int)'Z'] -= d[0];
      c[(int)'E'] -= d[0];
      c[(int)'R'] -= d[0];
      c[(int)'O'] -= d[0];
    }
    if (c[(int)'X'] > 0) {
      d[6] = c[(int)'X'];
      c[(int)'S'] -= d[6];
      c[(int)'I'] -= d[6];
      c[(int)'X'] -= d[6];
    }
    if (c[(int)'S'] > 0) {
      d[7] = c[(int)'S'];
      c[(int)'S'] -= d[7];
      c[(int)'E'] -= d[7];
      c[(int)'V'] -= d[7];
      c[(int)'E'] -= d[7];
      c[(int)'N'] -= d[7];
    }
    if (c[(int)'V'] > 0) {
      d[5] = c[(int)'V'];
      c[(int)'F'] -= d[5];
      c[(int)'I'] -= d[5];
      c[(int)'V'] -= d[5];
      c[(int)'E'] -= d[5];
    }
    if (c[(int)'F'] > 0) {
      d[4] = c[(int)'F'];
      c[(int)'F'] -= d[4];
      c[(int)'O'] -= d[4];
      c[(int)'U'] -= d[4];
      c[(int)'R'] -= d[4];
    }
    if (c[(int)'G'] > 0) {
      d[8] = c[(int)'G'];
      c[(int)'E'] -= d[8];
      c[(int)'I'] -= d[8];
      c[(int)'G'] -= d[8];
      c[(int)'H'] -= d[8];
      c[(int)'T'] -= d[8];
    }
    if (c[(int)'H'] > 0) {
      d[3] = c[(int)'H'];
      c[(int)'T'] -= d[3];
      c[(int)'H'] -= d[3];
      c[(int)'R'] -= d[3];
      c[(int)'E'] -= d[3];
      c[(int)'E'] -= d[3];
    }
    if (c[(int)'T'] > 0) {
      d[2] = c[(int)'T'];
      c[(int)'T'] -= d[2];
      c[(int)'W'] -= d[2];
      c[(int)'O'] -= d[2];
    }
    if (c[(int)'O'] > 0) {
      d[1] = c[(int)'O'];
      c[(int)'O'] -= d[1];
      c[(int)'N'] -= d[1];
      c[(int)'E'] -= d[1];
    }

    d[9] = c[(int)'I'];

    printf("Case #%d: ", caso);
    for(int i = 0; i < (int)d.size(); i++) {
      while(d[i] > 0) {
        printf("%d", i);
        d[i]--;
      }
    }
    printf("\n");
  }
  return 0;
}

