#include <cstdio>
#include <cstring>
#include <map>
using namespace std;

char buf[8][8];

char check(char *s) {
  map<char,int> cnt;
  for (int i = 0 ; i < 4 ; ++i) {
    ++cnt[s[i]];
  }
  if (cnt['X'] == 4 || cnt['X'] == 3 && cnt['T'] == 1)
    return 'X';
  if (cnt['O'] == 4 || cnt['O'] == 3 && cnt['T'] == 1)
    return 'O';
  return 0;
}

int main() {
  int T;
  scanf("%d",&T);
  for (int ca = 1 ; ca <= T ; ++ca) {
    int unf = 0;
    for (int i = 0 ; i < 4 ; i++) {
      scanf("%s", buf[i]);
      for (int j = 0 ; j < 4 ; j++)
        if (buf[i][j] == '.') unf = 1;
    }
    char tmp[8];
    memset(tmp, 0, sizeof(tmp));
    char ans = 0;
    for (int i = 0 ; i < 4 ; i++) {
      if (ans = check(buf[i])) {
        break;
      }
    }
    if (ans == 0) {
      for (int j = 0 ; j < 4 ; j++) {
        for (int i = 0 ; i < 4 ; i++)
          tmp[i] = buf[i][j];
        if (ans = check(tmp)) {
          break;
        }
      }
    }
    if (ans == 0) {
      for (int i = 0 ; i < 4 ; i++)
        tmp[i] = buf[i][i];
      ans = check(tmp);
    }
    if (ans == 0) {
      for (int i = 0 ; i < 4 ; i++)
        tmp[i] = buf[i][3-i];
      ans = check(tmp);
    }
    printf("Case #%d: ", ca);
    if (ans) printf("%c won\n", ans);
    else if (unf) printf("Game has not completed\n");
    else printf("Draw\n");
  }
  return 0;
}

