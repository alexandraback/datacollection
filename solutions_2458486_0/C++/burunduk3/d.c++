#include <cassert>
#include <cstdio>
#include <cstring>

#include <vector>

using namespace std;

int main() {
  int tn;
  assert(scanf("%d", &tn) == 1);
  for (int t = 1; t <= tn; t++) {
    int a, k, n;
    int have[200];
    memset(have, 0, sizeof(have[0]) * 200);
    assert(scanf("%d%d", &k, &n) == 2);
    for (int i = 0; i < k; i++) {
      assert(scanf("%d", &a) == 1);
      have[a - 1]++;
    }
    int key[n];
    vector <int> tr[n];
    vector <int> chest[200];
    for (int i = 0; i < n; i++) {
      int cnt;
      assert(scanf("%d%d", &key[i], &cnt) == 2);
      key[i]--;
      // fprintf(stderr, "key = %d\n", key[i]);
      chest[key[i]].push_back(i);
      for (int j = 0; j < cnt; j++) {
        assert(scanf("%d", &a) == 1);
        tr[i].push_back(a - 1);
      }
    }
    int open[n];
    memset(open, 0, sizeof(open[0]) * n);
    bool ok = false;
    vector <int> ans;
    // fprintf(stderr, "meow\n");
    while (1) {
      // fprintf(stderr, "0\n");
      ok = true;
      for (int i = 0; i < n && ok; i++)
        if (!open[i])
          ok = false;
      if (ok)
        break;
      // fprintf(stderr, "1\n");
      int go[200][200], rcnt[200], somech[200];
      for (int i = 0; i < 200; i++)
        for (int j = 0; j < 200; j++)
          go[i][j] = -1;
      memset(rcnt, 0, sizeof(rcnt));
      for (int i = 0; i < 200; i++) {
        // if (i < 10)
        //   fprintf(stderr, "[i=%d]\n", i);
        for (int j = 0; j < (int)chest[i].size(); j++) {
          if (open[chest[i][j]]) {
            // fprintf(stderr, "open: %d\n", chest[i][j]);
            continue;
          }
          if (rcnt[i]++ == 0)
            somech[i] = chest[i][j];
          // fprintf(stderr, "chest: %d\n", chest[i][j]);
          for (int k = 0; k < (int)tr[chest[i][j]].size(); k++) {
            // fprintf(stderr, "go: i=%d, tr: %d\n", i, tr[chest[i][j]][k]);
            go[i][tr[chest[i][j]][k]] = chest[i][j];
          }
        }
      }
      for (int k = 0; k < 200; k++)
        for (int i = 0; i < 200; i++)
          for (int j = 0; j < 200; j++)
            if (go[i][k] + 1 && go[k][j] + 1 && (go[i][j] == -1 || go[i][j] > go[i][k])) {
              go[i][j] = go[i][k];
            }
      /*
       for (int i = 0; i < 200; i++)
          for (int j = 0; j < 200; j++)
             if (go[i][j] + 1)
               fprintf(stderr, "key: %d -> %d (%d)\n", i, j, go[i][j]);
        */
      int move = n + 1;
      for (int i = 0; i < 200; i++) {
        // if (i < 10)
        //   fprintf(stderr, "have[i=%d]: %d of %d\n", i, have[i], rcnt[i]);
        if (rcnt[i] > 0 && have[i] > 0 && (go[i][i] + 1 || have[i] >= rcnt[i])) {
          int rr;
          if (go[i][i] + 1)
            rr = go[i][i];
          else
            rr = somech[i];
          move = min(move, rr);
          // fprintf(stderr, "  -- move=%d\n", move);
        }
      }
      // fprintf(stderr, "2 move = %d\n", move);
      if (move == n + 1)
        break;
      have[key[move]]--;
      open[move] = 1;
      for (int i = 0; i < (int)tr[move].size(); i++)
        have[tr[move][i]]++;
      ans.push_back(move + 1);
    }
    if (!ok)
      printf("Case #%d: IMPOSSIBLE\n", t);
    else {
      printf("Case #%d:", t);
      for (int i = 0; i < (int)ans.size(); i++)
        printf(" %d", ans[i]);
      printf("\n");
    }
  }
  return 0;
}

