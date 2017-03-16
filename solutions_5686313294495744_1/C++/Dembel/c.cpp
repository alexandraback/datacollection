#include <bits/stdc++.h>

using namespace std;

#ifdef DBG1
    #define dbg(...) fprintf(stderr, __VA_ARGS__),fflush(stderr)
#else
    #define dbg(...)
#endif

typedef long long ll;
typedef unsigned long long ull;
typedef pair <int, int> pii;

bool dfs(int s, const vector < vector <int> > & ed, vector <int> & ans, vector <int> & used, int color) {
  if (used[s] == color) {
    return false;
  }
  used[s] = color;
  for (int i = 0; i < int(ed[s].size()); ++i) {
    int v = ed[s][i];
    if (ans[v] == -1 || dfs(ans[v], ed, ans, used, color)) {
      ans[v] = s;
      return true;
    }
  }
  return false;
}

int getWordNumber(map<string,int> & w, const string & s) {
  map<string,int>::iterator it = w.find(s);
  if (it == w.end()) {
    int num = (int)w.size();
    w[s] = num;
    return num;
  }
  return it->second;
}

void solve() {
  int n;
  cin >> n;
  map <string, int> w1;
  map <string, int> w2;
  vector <vector <int> > ed;
  for (int i = 0; i < n; ++i) {
    string s1, s2;
    cin >> s1 >> s2;
    int u = getWordNumber(w1, s1);
    int v = getWordNumber(w2, s2);
    dbg("u %d v %d\n", u, v);
    while ((int)ed.size() <= u) {
      ed.push_back(vector<int>());
    }
    ed[u].push_back(v);
  }

  vector <int> ans(w2.size(), -1);
  vector <int> used(w1.size(), -1);
  int match = 0;
  int _time = 0;
  for (int i = 0; i < (int)w1.size(); ++i) {
    if (dfs(i, ed, ans, used, ++_time)) {
      dbg("i %d matched\n", i);
      ++match;
    }
  }
  printf("%d\n", n - (int(w1.size() + w2.size()) - match));
}

int main()
{
#ifdef DBG1
  assert(freopen("input.txt", "r", stdin));
  assert(freopen("output.txt", "w", stdout));
  assert(freopen("err.txt", "w", stderr));
#endif

  int tt;
  assert (scanf("%d", &tt) == 1);
  for (int ii = 1; ii <= tt; ++ii) {
    dbg("Case %d\n", ii);
    printf("Case #%d: ", ii);
    solve();
    fflush(stdout);
  }

  return 0;
}

