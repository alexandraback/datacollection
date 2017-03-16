#include <algorithm>
#include <cassert>
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iostream>
#include <map>
#include <set>
#include <stack>
#include <string>
#include <vector>
#include <queue>

using namespace std;

#define TRACE(x) cerr << #x << " " << x << endl
#define FOR(i, a, b) for (int i = (a); i < int(b); ++i)
#define REP(i, n) FOR(i, 0, n)
#define _ << " " <<

#define fst first
#define snd second

typedef long long llint;
typedef pair<int, int> pii;

const int B = 27397, MOD = 1e9 + 7;
const int B1 = 33941, MOD1 = 1e9 + 9;

int T, n;

vector <pair <string, string> > v; 

inline void init() {
  v.clear();
}

bool check(int mask) {
  for (int i = 0; i < n; ++i) {
    if ((mask & (1 << i)) != 0) continue;
    bool l = false, r = false; 
    for (int j = 0; j < n; ++j) {
      if ((mask & (1 << j)) == 0) continue;
      l |= v[i].fst == v[j].fst; 
      r |= v[i].snd == v[j].snd;
    }
    if (!l || !r) return false;
  }
  return true;
}

void small(int t) {
  
  init();

  cin >> n; 
  for (int i = 0; i < n; ++i) {
    string s1, s2; cin >> s1; cin >> s2; 
    v.emplace_back(s1, s2); 
  }
    
  int sol = 0;
  for (int i = 0; i < 1 << n; ++i) 
    if (check(i))
      sol = max(sol, n - __builtin_popcount(i));

  printf("Case #%d: ", t);
  printf("%d\n", sol);

}

int main(void) {

  scanf("%d", &T);
  for (int t = 0; t < T; ++t)
    small(t + 1);

  return 0;

}

