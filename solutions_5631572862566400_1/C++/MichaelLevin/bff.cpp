#include <algorithm>
#include <cassert>
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <ctime>
#include <deque>
#include <iostream>
#include <limits>
#include <numeric>
#include <map>
#include <queue>
#include <set>
#include <sstream>
#include <stack>
#include <string>
#include <utility>
#include <vector>

using namespace std;

#define MP make_pair
#define all(v) (v).begin(), (v).end()
#define PROBLEM_ID "C"

typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<vvi> vvvi;
typedef vector<bool> vb;
typedef vector<vb> vvb;
typedef vector<vvb> vvvb;
typedef long double ld;
typedef pair<int, int> pii;
typedef long long ll;
typedef vector<ll> vl;
typedef vector<vl> vvl;
typedef vector<vvl> vvvl;
typedef pair<ll, ll> pll;
typedef vector<double> vd;
typedef vector<vd> vvd;
typedef vector<vvd> vvvd;

bool IsGoodCircle(const vi& circle, const vi& bff) {
  for (int i = 0; i < circle.size(); ++i) {
    int nxt = (i + 1) % circle.size();
    int prv = (i + circle.size() - 1) % circle.size();
    if (circle[nxt] != bff[circle[i]] && circle[prv] != bff[circle[i]]) {
      return false;
    }
  }
  return true;
}

int MaxKidsSlow(int n, const vi& bff) {
  vi perm;
  for (int i = 0; i < n; ++i) {
    perm.push_back(i);
  }
  int res = 0;
  do {
    for (int len = 1; len <= n; ++len) {
      int a = perm[len - 1];
      if ((bff[a] == perm[0] || (len > 1 && bff[a] == perm[len - 2])) && (len == 1 || bff[perm[0]] == perm[1] || bff[perm[0]] == perm[len - 1])) {
        res = max(res, len);
      }
      if (len > 1 && bff[a] != perm[len - 2] && (len == n || bff[a] != perm[len])) {
        break;
      }
    }
  } while (next_permutation(perm.begin(), perm.end()));
  return res;
}

void dfs(int a, const vvi& G, vb& done, vi& comp) {
  done[a] = true;
  comp.push_back(a);
  for (int i = 0; i < G[a].size(); ++i) {
    int other = G[a][i];
    if (!done[other]) {
      dfs(other, G, done, comp);
    }
  }
}

int FarthestChild(int n, const vvi& G, int from) {
  int start = from;
  queue<int> q;
  vb done(n, false);
  vi dist(n, -1);
  q.push(start);
  done[start] = true;
  dist[start] = 0;
  while (!q.empty()) {
    int cur = q.front();
    q.pop();
    for (int i = 0; i < G[cur].size(); ++i) {
      int other = G[cur][i];
      if (done[other]) {
        continue;
      }
      done[other] = true;
      dist[other] = dist[cur] + 1;
      q.push(other);
    }
  }
  return *max_element(dist.begin(), dist.end());
}

int ComputeLoopLength(int n, const vi& next, int& for_two) {
  vi first(n, -1);
  int start = 0;
  vi seq;
  int cur = start;
  while (first[cur] == -1) {
    first[cur] = seq.size();
    seq.push_back(cur);
    cur = next[cur];
  }
  int loop_length = seq.size() - first[cur];
  if (loop_length == 2) {
    vvi G(n);
    for (int i = 0; i < n; ++i) {
      if (next[i] != seq.back() || i != seq[seq.size() - 2]) {
        G[next[i]].push_back(i);
      }
    }
    for_two = FarthestChild(n, G, seq.back()) + 1;
    G.assign(n, vi());
    for (int i = 0; i < n; ++i) {
      if (next[i] != seq[seq.size() - 2] || i != seq.back()) {
        G[next[i]].push_back(i);
      }
    }    
    for_two += FarthestChild(n, G, seq[seq.size() - 2]) + 1;
  }
  return loop_length;
}

int MaxKids(int n, const vi& bff) {
  vvi G(n);
  for (int i = 0; i < n; ++i) {
    G[i].push_back(bff[i]);
    G[bff[i]].push_back(i);
  }
  vvi comps;
  vb done(n, false);
  for (int i = 0; i < n; ++i) {
    vi comp;
    if (!done[i]) {
      dfs(i, G, done, comp);
      comps.push_back(comp);
    }
  }
  vi index_in_comp(n);
  for (int i = 0; i < comps.size(); ++i) {
    for (int j = 0; j < comps[i].size(); ++j) {
      index_in_comp[comps[i][j]] = j;
    }
  }
  int res = 0;
  int res2 = 0;
  for (int i = 0; i < comps.size(); ++i) {
    vi next(comps[i].size());
    for (int j = 0; j < comps[i].size(); ++j) {
      next[j] = index_in_comp[bff[comps[i][j]]];
    }
    int for_two;
    int loop_length = ComputeLoopLength(comps[i].size(), next, for_two);
    res = max(res, loop_length);
    if (loop_length == 2) {
      res2 += for_two;
    }
  }
  return max(res, res2);
}

int main() {
  /*while (true) {
    int n = rand() % 8 + 3;
    vi bff(n);
    for (int i = 0; i < n; ++i) {
      int a = rand() % (n - 1);
      if (a >= i) {
        ++a;
      }
      bff[i] = a;
    }
    cerr << n << endl;
    for (int i = 0; i < n; ++i) {
      cerr << bff[i] + 1 << ' ';
    }
    cerr << endl;
    int res1 = MaxKids(n, bff);
    int res2 = MaxKidsSlow(n, bff);
    if (res1 != res2) {
      cerr << "Wrong answer" << endl;
      cerr << res1 << ' ' << res2 << endl;
      break;
    } else {
      cerr << "OK " << res1 << endl;
    }
  }*/
  freopen(PROBLEM_ID".in", "r", stdin);
  freopen(PROBLEM_ID".out", "w", stdout);
  int tests;
  cin >> tests;
  for (int test_index = 0; test_index < tests; ++test_index) {
    int n;
    cin >> n;
    vi bff(n);
    for (int i = 0; i < n; ++i) {
      cin >> bff[i];
      --bff[i];
    }
    int max_kids = MaxKids(n, bff);
    cout << "Case #" << (test_index + 1) << ": " << max_kids << endl;
    cerr << "Case #" << (test_index + 1) << ": " << max_kids << endl;    
  }
  return 0;
}
