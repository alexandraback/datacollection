#include <iostream>
#include <sstream>
#include <algorithm>
#include <limits>
#include <numeric>
#include <string>
#include <vector>
#include <deque>
#include <queue>
#include <bitset>
#define phb push_back
#define ppb pop_back
#define mkp make_pair
#define frs first
#define scn second
using namespace std;

int Z;
int R, N, M, K;
vector< pair< vector< int >, vector< int > > > res;
vector< int > stk;
vector< int > qry;

void prep();
void dfs(int);
void soups_on();

inline bool check(vector< int > &ra, vector< int > &rb) {
  for (int i = 0; i < int(ra.size()); ++i) {
    if (!binary_search(rb.begin(), rb.end(), ra[i]))
      return false;
  }

  return true;
}

int main() {
  cin >> Z >> R >> N >> M >> K;
  prep();
  soups_on();

  return 0;
}

void prep() {
  dfs(0);
}

void dfs(int u) {
  if (u == N) {
    vector< int > t = stk, m = vector< int >();

    for (int i = 0; i < (1 << N); ++i) {
      int mul = 1;
      for (int j = 0; j < N; ++j)
        if (i & 1 << j)
          mul *= t[j];
      m.phb(mul);
    }

    stable_sort(m.begin(), m.end());
    res.phb(mkp(t, m));
  }
  else {
    for (int i = 2; i <= M; ++i) {
      stk.phb(i);
      dfs(u + 1);
      stk.ppb();
    }
  }
}

void soups_on() {
  cout << "Case #1:\n";

  for (int ri = 1; ri <= R; ++ri) {
    qry = vector< int >(K);
    for (int i = 0; i < K; ++i)
      cin >> qry[i];

    for (int i = 0; i < int(res.size()); ++i)
      if (check(qry, res[i].scn)) {
        for_each(res[i].frs.begin(), res[i].frs.end(), [] (int q) {
          cout << q;
        });
        cout << "\n";
        break;
      }
  }
}
