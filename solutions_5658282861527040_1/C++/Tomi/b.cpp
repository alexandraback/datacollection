#include <cstdio>
#include <cmath>
#include <vector>
#include <algorithm>
#include <set>
#include <map>
#include <queue>
#include <string>
using namespace std;

void masks(long long x, vector<string>& res) {
  string bin(32, '0');
  for (int i = 0; i < 32; i++) if (x & (1LL<<i)) bin[32-1-i] = '1';
  for (int i = 0; i < 32; i++) if (bin[i] == '1') {
    string q(bin);
    q[i] = '0';
    for (int j = i+1; j < 32; j++) q[j] = '?';
    res.push_back(q);
  }
}

int main() {
  int TT;
  scanf("%d", &TT);
  for (int tc = 1; tc <= TT; tc++) {
    int A, B, K;
    scanf("%d%d%d", &A, &B, &K);

    vector<string> Am, Bm, Km;
    masks(A, Am);
    masks(B, Bm);
    masks(K, Km);

    long long R = 0;

    for (int aa = 0; aa < Am.size(); aa++) {
      for (int bb = 0; bb < Bm.size(); bb++) {
        for (int kk = 0; kk < Km.size(); kk++) {
          long long me = 1;
          for (int i = 0; i < 32; i++) {
            long long thisidx = 0;
            for (int av = 0; av < 2; av++) for (int bv = 0; bv < 2; bv++) {
              int kv = av & bv;
              if (Am[aa][i] != '?' && Am[aa][i] != '0'+av) continue;
              if (Bm[bb][i] != '?' && Bm[bb][i] != '0'+bv) continue;
              if (Km[kk][i] != '?' && Km[kk][i] != '0'+kv) continue;
              thisidx++;
            }
            me *= thisidx;
          }
          R += me;
        }
      }
    }

    printf("Case #%d: %lld\n", tc, R);
  }
}
