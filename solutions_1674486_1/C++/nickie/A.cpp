#undef DEBUG

#ifdef DEBUG
#define debug(...) fprintf(stderr, __VA_ARGS__)
#else
#define debug(...) do ; while(0)
#define NDEBUG
#endif

#include <assert.h>
#include <stdio.h>
#include <stdbool.h>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;
typedef long int time;

int main ()
{
  int tests;

  scanf("%d\n", &tests);

  for (int test=1; test<=tests; test++) {
    // input
    int n;
    scanf("%d", &n);
    vector<int> k(n);
    vector< vector<int> > e(n);
    queue<int> remaining;
    for (int i=0; i<n; i++) {
      scanf("%d", &(k[i]));
      e[i].resize(k[i]);
      for (int j=0; j<k[i]; j++) {
        int v;
        scanf("%d", &v);
        e[i][j] = v-1;
      }
      remaining.push(i);
    }
    // calculate
    bool diamond = false;
    vector<bool> seen(n);
    for (int i=0; i<n; i++)
      seen[i] = false;
    while (!remaining.empty()) {
      int s = remaining.front();
      remaining.pop();
      debug("starting from %d\n", s+1);
      if (seen[s]) {
        debug("  skipped\n");
        continue;
      }
      seen[s] = true;
      vector<bool> visited(n);
      for (int i=0; i<n; i++)
        visited[i] = false;
      queue<int> q;
      q.push(s);
      while (!q.empty()) {
        int t = q.front();
        q.pop();
        debug("  at %d\n", t+1);
        if (visited[t]) {
          debug("    found diamond\n");
          diamond = true;
          goto the_end;
        }
        visited[t] = seen[t] = true;
        for (int i=0; i<k[t]; i++) {
          debug("    pushing %d\n", e[t][i] + 1);
          q.push(e[t][i]);
        }
      }
    }
  the_end:
    // output
    printf("Case #%d: %s\n", test, diamond ? "Yes" : "No");
  }
  return 0;
}
