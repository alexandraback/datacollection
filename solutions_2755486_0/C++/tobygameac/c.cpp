#include <cstdio>
#include <iostream>
#include <vector>
using namespace std;

struct Tribe {
  int day, times, w, e, s, dD, dP, dS;
};

int main() {
  int T, C = 1;
  cin >> T;
  while (T--) {
    int i, n;
    cin >> n;
    vector<Tribe> v;
    for (i = 0; i < n; i++) {
      Tribe tribe;
      cin >> tribe.day >> tribe.times >> tribe.w >> tribe.e >> tribe.s >> tribe.dD >> tribe.dP >> tribe.dS;
      tribe.w += 999;
      tribe.e += 999;
      v.push_back(tribe);
    }
    int h[499999] = {}, ans = 0;
    while (1) {
      int min = 2e9;
      for (i = 0; i < v.size(); i++)
        if (v[i].times > 0 && v[i].day < min) min = v[i].day;
      if (min == 2e9) break;
      bool gg[99] = {};
      for (i = 0; i < v.size(); i++)
        if (v[i].times > 0 && v[i].day == min) {
          for (float j = v[i].w; j <= v[i].e && !gg[i]; j += 0.1) {
            if (h[(int)(j * 10)] < v[i].s) gg[i] = 1;
          }
        }
      for (i = 0; i < v.size(); i++)
        if (gg[i]) {
          //printf("%d : %d -> %d to %d, atk = %d\n", min, i, v[i].w, v[i].e, v[i].s);
          ans++;
          for (float j = v[i].w; j <= v[i].e; j += 0.1)
            h[(int)(j * 10)] = h[(int)(j * 10)] < v[i].s ? v[i].s : h[(int)(j * 10)];
        }
      for (i = 0; i < v.size(); i++)
        if (v[i].day == min) {
          v[i].day += v[i].dD;
          v[i].times--;
          v[i].w += v[i].dP;
          v[i].e += v[i].dP;
          v[i].s += v[i].dS;
        }
    }
    printf("Case #%d: %d\n", C++, ans);
  }
  return 0;
}
