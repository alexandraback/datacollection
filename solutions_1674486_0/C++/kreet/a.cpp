#include <cstdio>
#include <cassert>
#include <cmath>
#include <cstdlib>
#include <cstring>
#include <cctype>
#include <algorithm>
#include <vector>
#include <iostream>
#include <string>
#include <map>
#include <set>
#include <utility>
#include <sstream>
using namespace std;
typedef long long ll;

vector<int> g[1000];

int main() {

  int T;
  scanf(" %d", &T);

  for (int ii = 0; ii < T; ii++) {
    int N; scanf(" %d", &N);
    for (int i = 0; i < N; ++i) {
      g[i].clear();
      int m; scanf(" %d", &m);
      for (int j = 0; j < m; ++j) {
	int d; scanf(" %d", &d);
	g[i].push_back(d-1);
      }
      sort(g[i].begin(), g[i].end());
      g[i].erase(unique(g[i].begin(), g[i].end()), g[i].end());
    }
    bool found = false;
    for (int i = 0; i < N; ++i) {
      vector<int> v1,v2;
      v1.push_back(i);
      bool memo[1000] = {};
      
      for (;;) {
	if (v1.empty()) break;
	for (int j = 0; j < v1.size(); ++j) {
	  for (int k = 0; k < g[v1[j]].size(); ++k) {
	    int val = g[v1[j]][k];
	    if (memo[val]) {
	      found = true;
	    }
	    memo[val] = true;
	    v2.push_back(val);
	  }
	}
	v1.clear();
	v1.swap(v2);
      }
      if (found) break;
    }
    printf("Case #%d: %s\n", ii + 1, found ? "Yes" : "No");
  }
}
