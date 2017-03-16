#include <iostream>
#include <string>
#include <vector>
#include <set>
#include <algorithm>
#include <fstream>
#include <cstdio>
#include <cstdlib>

using namespace std;

struct Attack {
  int d, w, e, s;
  Attack() {};
  Attack(int dd, int ww, int ee, int ss) : d(dd), w(ww), e(ee), s(ss) {} 
};

bool cmp(const Attack &a1, const Attack &a2) {
  return a1.d < a2.d;
}

Attack att[105];

int h[1000], h2[1000];
int offset = 500;

int main() {
  freopen("C-small-attempt1.in", "r", stdin);
  freopen("C-small-attempt1.out", "w", stdout);

  int T;
  cin >> T;
  for (int cas = 1; cas <= T; cas++) {
    int N, d, n, w, e, s, delta_d, delta_p, delta_s;
    cin >> N;
    int tot = 0;
    for (int i = 0; i < N; i++) {
      cin >> d >> n >> w >> e >> s >> delta_d >> delta_p >> delta_s;
      for (int j = 0; j < n; j++) {
        att[tot++] = Attack(d + j * delta_d, (w + j * delta_p) * 2 + offset, (e + j * delta_p) * 2 + offset, s + j * delta_s);
      }
    }

    sort(att, att + tot, cmp);
    memset(h, 0, sizeof(h));

    int res = 0;
    for (int i = 0; i < tot;) {
      int j = i;
      memcpy(h2, h, sizeof(h));
      while (j < tot && att[j].d == att[i].d) {
        bool flag = false;
        for (int k = att[j].w; k <= att[j].e; k++) {
          if (h[k] < att[j].s) {
            flag = true;
            h2[k] = max(h2[k], att[j].s);
          }
        }
        if (flag) res++;

        j++;
      }

      memcpy(h, h2, sizeof(h));

      i = j;
    }

    cout << "Case #" << cas << ": " << res <<"\n";
  }

  return 0;
}
