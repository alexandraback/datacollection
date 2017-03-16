#define NDEBUG
#include <algorithm>
#include <cassert>
#include <cstdio>
#include <iostream>
#include <queue>
#include <string>
#include <vector>
using namespace std;

#define repeat(n) for (int repc = (n); repc > 0; --repc)
template<typename List, typename Element> inline bool inlist( const List &L, const Element &E ) { return find( L.begin(), L.end(), E ) != L.end(); }
#define ALL(x) (x).begin(), (x).end()

const int MAXN = 55;
vector<int> adj[MAXN];

bool connected(vector<char> bio, const vector<int> &srcs) {
  queue<int> q;
  for (int src : srcs) {
    q.push(src);
    assert(bio[src]);
  }
  while (!q.empty()) {
    int a = q.front(); q.pop();
    for (int b : adj[a]) {
      if (!bio[b]) {
        q.push(b);
        bio[b] = true;
      }
    }
  }
  return count(ALL(bio), true) == (int)bio.size();
}

void solve1() {
  int N, M;
  cin >> N >> M;
  vector<string> zips(N);
  for (string& zip : zips) cin >> zip;

  vector<int> order(N);
  for (int i=0; i<N; ++i) {
    order[i] = i;
  }
  auto cmp = [=](int a, int b) {
    return zips[a] < zips[b];
  };
  sort(ALL(order), cmp);

  for (int i=0; i<N; ++i) {
    adj[i].clear();
  }
  repeat (M) {
    int a, b;
    cin >> a >> b;
    --a; --b;
    adj[a].push_back(b);
    adj[b].push_back(a);
  }

  for (int i=0; i<N; ++i) {
    sort(ALL(adj[i]), cmp);
  }

  vector<char> bio(N);
  vector<int> stek;

  int start = order[0];
  stek.push_back(start);
  string out = zips[start];
  bio[start] = 1;
  repeat (N-1) {
    // debug(out);
    // debug(stek);
    bool found = false;
    for (int next_candidate : order) {
      if (bio[next_candidate]) {
        continue;
      }

      for (int pos=(int)stek.size()-1; pos>=0; --pos) {
        if (!inlist(adj[stek[pos]], next_candidate)) {
          continue;
        }
        vector<int> new_stek(stek.begin(), stek.begin() + pos + 1);
        new_stek.push_back(next_candidate);
        bio[next_candidate] = 1;
        if (connected(bio, new_stek)) {
          stek = new_stek;
          out += zips[next_candidate];
          found = true;
          break;
        }
        bio[next_candidate] = 0;
      }
      if (found) {
        break;
      }
    }
    assert(found);
  }

  printf("%s\n", out.c_str());
}

int main() {
  ios_base::sync_with_stdio(0);

  int T;
  cin >> T;
  for (int tt=1; tt<=T; ++tt) {
    printf("Case #%d: ", tt);
    solve1();
    fflush(stdout);
  }
}
