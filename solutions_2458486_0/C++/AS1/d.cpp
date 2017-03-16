#include <cstdio>
#include <vector>
#include <cassert>
using namespace std;

int main (void) {
  int tn;
  scanf ("%d", &tn);
  for (int ti = 1; ti <= tn; ti++) {
    int K, N;
    scanf ("%d%d", &K, &N);
    vector <int> keys(201);
    for (int i = 0; i < K; i++) {
      int key;
      scanf ("%d", &key);
      keys[key]++;
    }
    vector <vector <int> > v(N, vector <int> (201));
    vector <int> need_key (N);
    for (int i = 0; i < N; i++) {
      scanf ("%d", &need_key[i]); 
      int keys_n;
      scanf ("%d", &keys_n); 
      for (int j = 0; j < keys_n; j++) {
        int key;
        scanf ("%d", &key);
        v[i][key]++;
      }
    }
    vector <int> dp ((1 << N), -1);
    dp[(1 << N) - 1] = 0;
    for (int code = (1 << N) - 1; code >= 0; code--) {
      for (int i = 0; i < N; i++) {
        if ((code >> i) & 1) {
          continue;
        }
        int cur = need_key[i];
        int cnt = keys[cur];
        for (int j = 0; j < N; j++) {
          if ((code >> j) & 1) {
            if (need_key[j] == cur) {
              cnt--;
            }
            cnt += v[j][cur];
          }
        }
        if (cnt > 0 && dp[code | (1 << i)] != -1) {
          dp[code] = i;
          break;
        }
      }
    }
    printf ("Case #%d:", ti);
    int end_code = (1 << N) - 1;
    if (dp[0] != -1) {
      vector <int> res;
      int code = 0;
      while (code != end_code) {
        res.push_back (dp[code] + 1);
        code |= (1 << dp[code]);
      }
      for (int i = 0; i < (int)res.size(); i++) {
        printf (" %d", res[i]);
      }
      printf ("\n");
    } else {
      printf (" IMPOSSIBLE\n");
    }
  }
  return 0;
}
