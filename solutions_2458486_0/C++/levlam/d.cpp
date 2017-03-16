#include <cassert>
#include <cstdio>
#include <map>
#include <set>
#include <cstring>
#include <cstdlib>
#include <algorithm>
#include <string>
#include <vector>
#include <iostream>

using namespace std;

int can[1 << 20];

int cnt[201];
int t[205];
int n;
vector <int> in[205];

int get (int mask) {
  if (can[mask] != -1) {
    return can[mask];
  }
  
  int &res = can[mask];

  if (mask == 0) {
    return res = 1;
  }

  for (int i = 0; i < n; i++) {
    if (((mask >> i) & 1) == 1 && cnt[t[i]] > 0) {
      for (int j = 0; j < (int)in[i].size(); j++) {
        cnt[in[i][j]]++;
      }
      cnt[t[i]]--;

      res = get (mask - (1 << i));

      for (int j = 0; j < (int)in[i].size(); j++) {
        cnt[in[i][j]]--;
      }
      cnt[t[i]]++;

      if (res)
        return res;
    }
  }
  return res = 0;
}

int main(void) {
  int tn, nt;
  scanf("%d", &nt);
  for (tn=1; tn<=nt; tn++) {
    printf ("Case #%d:", tn);
    fprintf (stderr, "Case #%d: \n", tn);

    int k;
    scanf("%d%d", &k, &n);

    cerr << k << " " << n << endl;

    memset (cnt, 0, sizeof (cnt));
    memset (can, -1, sizeof (can));

    for (int i = 0; i < k; i++) {
      int key;
      scanf("%d", &key);
      cnt[key]++;
    }

    for (int i = 0; i < n; i++) {
      int len;
      scanf("%d%d", &t[i], &len);
      in[i].clear();
      for (int j = 0; j < len; j++) {
        int key;
        scanf ("%d", &key);
        in[i].push_back (key);
      }
    }

    if (get ((1 << n) - 1)) {
      vector <int> res;
      int mask = (1 << n) - 1;
      for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++)
          if (((mask >> j) & 1) && can [mask - (1 << j)] == 1) {
            mask -= (1 << j);
            res.push_back (j + 1);
            break;
          }
      }

      for (int i = 0; i < n; i++)
        printf (" %d", res[i]);
      printf ("\n");
    } else {
      puts (" IMPOSSIBLE");
    }
  }

  return 0;
}
