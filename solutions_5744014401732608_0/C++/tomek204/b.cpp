#include <bits/stdc++.h>

using namespace std;

typedef long long int ll;
typedef vector<int> vi;
typedef vector<vector<int> > vvi;

struct solution {
  int n;
  vvi arr;
  solution() { n = 0; }
  solution(int _n) {
    n = _n;
    for (int i = 0; i < n; i++) {
      arr.push_back(vi(n, 0));
    }
  }
  solution copyAndExtend() {
    solution ret = solution(n+1);
    for (int i = 0; i < n; i++) {
      for (int j = 0; j < n; j++) {
        ret.arr[i][j] = arr[i][j];
      }
    }
    return ret;
  }
  ll countWays() {
    ll ile[n];
    fill(ile, ile+n, 0);
    ile[0] = 1;
    for (int i = 0; i < n; i++) {
      for (int j = 0; j < n; j++) {
        if (arr[i][j]) {
          ile[j] += ile[i];
        }
      }
    }
    return ile[n-1];
  }
  vector<solution> generate() {
    vector<solution> ret;
    if (n == 0) return ret;
    for (int bm = 0; bm < (1<<n); bm++) {
      solution tmp = copyAndExtend();
      for (int i = 0; i < n; i++) if (bm&(1<<i)) {
        tmp.arr[i][n] = 1;
      }
      ret.push_back(tmp);
    }
    return ret;
  }
  void print() {
    if (n == 0) printf("IMPOSSIBLE\n");
    else {
      printf("POSSIBLE\n");
      for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
          printf("%d", arr[i][j]);
        }
        printf("\n");
      }
    }
  }
} TAB[7][2000];

void init() {
  TAB[1][1] = solution(1);
  for (int i = 1; i < 6; i++) {
    for (int j = 1; j <= 20; j++) {
      vector<solution>tmp = TAB[i][j].generate();
      for (int k = 0; k < int(tmp.size()); k++) {
        solution cur = tmp[k];
        TAB[i+1][cur.countWays()] = cur;
      }
    }
  }
}

void solve() {
  int n, m; scanf("%d%d", &n, &m);
  TAB[n][m].print();
}

int main() {
  init();
  int t; scanf("%d", &t);
  for (int ct = 1; ct <= t; ct++) {
    printf("Case #%d: ", ct);
    solve();
  }
  return 0;
}
