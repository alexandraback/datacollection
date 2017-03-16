#include <cstdio>
#include <string>
#include <set>
#include <map>
#include <vector>
using namespace std;

#define INF 5000

set<string> dict;
set<string> matches;

string S;
int DP[5000][5];

int getdp(int p, int w) {
//  fprintf(stderr, "getdp(%d,%d)\n", p, w);
  if (p == S.size()) return 0;
  if (DP[p][w] == -1) {
    int res = INF;
    for (int l = 1; l <= 10; l++) {
      if (p+l > S.size()) continue;
      string s = S.substr(p, l);
      for (int i = -1; i < 5; i++) {
        for (int j = -1; j < 5; j++) {
          if (i != -1 && i >= s.size()) continue;
          if (j != -1 && j+5 >= s.size()) continue;
          if (i != -1 && j != -1 && j+5 - i < 5) continue;
          if (i != -1 && i < w) continue;
          string m(s);
          if (i != -1) m[i] = '.';
          if (j != -1) m[j+5] = '.';
          if (!matches.count(m)) continue;

          int nw = max(0, w - l);
          if (i != -1) nw = max(nw, i + 5 - l);
          if (j != -1) nw = max(nw, j+5 + 5 - l);
//          fprintf(stderr, "%d\t%d\t%d\t%d\t[%s]\n", p, w, i, j, m.c_str());
          res = min(res, getdp(p+l, nw) + (i != -1) + (j != -1));
        }
      }
    }
    DP[p][w] = res;
//    fprintf(stderr, "DP[%d][%d] = %d\n", p, w, res);
  }
  return DP[p][w];
}

int main() {
  FILE *f = fopen("garbled_email_dictionary.txt", "r");
  if (f == NULL) return 47;
  while (true) {
    char buf[20];
    if (fscanf(f, "%s", buf) != 1) break;
    string s(buf);

    dict.insert(s);

    for (int i = -1; i < 5; i++) {
      for (int j = -1; j < 5; j++) {
        if (i != -1 && i >= s.size()) continue;
        if (j != -1 && j+5 >= s.size()) continue;
        if (i != -1 && j != -1 && j+5 - i < 5) continue;
        string m(s);
        if (i != -1) m[i] = '.';
        if (j != -1) m[j+5] = '.';
        matches.insert(m);
      }
    }
  }
  fprintf(stderr, "processed\n");

  int T;
  scanf("%d", &T);
  for (int tc = 1; tc <= T; tc++) {
    char buf[5000];
    scanf("%s", buf);
    S = buf;

    for (int i = 0; i < 5000; i++) for (int w = 0; w < 5; w++) DP[i][w] = -1;

    printf("Case #%d: %d\n", tc, getdp(0, 0));
  }
}
