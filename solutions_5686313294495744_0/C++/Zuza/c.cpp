#include <cassert>
#include <cstring>

#include <cstdio>
#include <cstdlib>

#include <map>
#include <set>
#include <algorithm>
#include <iostream>

using namespace std;

#define FOR(i, a, b) for (int i = (a); i < int(b); ++i)
#define REP(i, n) FOR(i, 0, n)
#define TRACE(x) cout << #x << " = " << x << endl
#define _ << " _ " <<

typedef long long llint;

map<string, vector<string> > E;

map<string, string> dad;
set<string> A, B, bio;

bool match(const string& a) {
  if (bio.count(a)) return false;
  bio.insert(a);
  for (const string& b : E[a]) {
    if (dad[b].size() == 0 || match(dad[b])) {
      dad[b] = a;
      return true;
    }
  }
  return false;
}

int main(void) {
  cin.sync_with_stdio(false);
  int ntc; cin >> ntc;

  REP(tc, ntc) {
    cout << "Case #" << tc+1 << ": ";
    int n; cin >> n;

    E.clear(); A.clear(); B.clear(); dad.clear(); bio.clear();

    REP(i, n) {
      string a, b;
      cin >> a >> b;
      E[a].push_back(b);
      A.insert(a);
      B.insert(b);
    }

    int f = 0;
    for (string a : A) {
      bio.clear();
      f += match(a);
    }

    int min_keep = f + (A.size()+B.size()-2*f);
    int ans = n - min_keep;
    cout << ans << endl;
  }

  return 0;
}   
