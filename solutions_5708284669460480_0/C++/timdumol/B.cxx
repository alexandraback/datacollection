#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <cstring>
#include <cassert>
#include <complex>
#include <numeric>
#include <ext/numeric>
#include <iostream>
#include <algorithm>
#include <set>
#include <string>
#include <map>
#include <functional>
#include <utility>
#include <vector>
#include <list>
#include <queue>
#include <bitset>

using namespace std;
using namespace __gnu_cxx;

typedef unsigned long long ullong;
typedef long long llong;
typedef list<int> EdgeList;
typedef vector<EdgeList> AdjList;
typedef pair<int, int> ii;
typedef vector<ii> vii;

#define FOR_EDGE(adj,v,it) for (EdgeList::iterator it = adj[v].begin(); \
    it != adj[v].end(); ++it)

int k, l, s;
char board[101];
char target[101];
char str[101];
llong cnt;
llong given;
llong high;

void recurse(int idx) {
  if (idx == s) {
    cnt += 1;
    llong matches = 0;
    str[s] = 0;
    #ifdef DEBUG
    //printf("ss: %s\n", str);
    #endif
    for (int i = 0; i <= s-l; ++i) {
      if (strncmp(str + i, target, l) == 0) {
        ++matches;
      }
    }
    given += matches;
    high = max(matches, high);
    return;
  }
  for (int i = 0; i < k; ++i) {
    str[idx] = board[i];
    recurse(idx+1);
  }
}

int main() {
  int n_cases;
  scanf("%d", &n_cases);

  for (int ctr = 0; ctr < n_cases; ++ctr) {
    memset(board, 0, sizeof(board));
    memset(target, 0, sizeof(target));
    scanf("%d%d%d", &k, &l, &s);
    scanf("%s", board);
    scanf("%s", target);
    #ifdef DEBUG
    printf("b:%s\n", board);
    printf("t:%s\n", target);
    #endif

    cnt = high = given = 0;

    recurse(0);

    #ifdef DEBUG
    printf("h: %lld; g: %lld; c: %lld\n", high, given, cnt);
    #endif
    printf("Case #%d: %.8lf\n", ctr+1, (double)(high - given/(double)cnt));
    //printf("Case #%d: %lf", ctr+1, (high*(double)cnt - given)/(double)cnt);
  }
  return 0;
}
