#include <cstdio>
#include <cassert>
#include <cstdlib>
#include <cmath>
#include <cstring>
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
#define FOR(v, it) for (auto it = v.begin(); it != v.end(); ++it)

int main() {
  int n_cases;
  scanf("%d", &n_cases);
  for (int ctr = 0; ctr < n_cases; ++ctr) {
    char s[1024];
    scanf("%s", s);
    int n = strlen(s);
    deque<char> dq;
    dq.push_back(s[0]);
    for (int i = 1; i < n; ++i) {
      if (s[i] < dq.front()) {
        dq.push_back(s[i]);
      } else {
        dq.push_front(s[i]);
      }
    }

    printf("Case #%d: ", ctr+1);
    while (dq.size()) {
      printf("%c", dq.front());
      dq.pop_front();
    }
    puts("");
  }
  return 0;
}
