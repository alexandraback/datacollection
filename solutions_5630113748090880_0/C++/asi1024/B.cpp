#include <bits/stdc++.h>

#define REP(i,n) for(int i=0;i<(int)(n);i++)
#define ALL(x) (x).begin(),(x).end()

using namespace std;

void solve() {
  int N;
  cin >> N;
  vector<int> a(3000);
  REP(i,2*N-1) REP(j,N) {
    int p; cin >> p;
    a[p] = 1 - a[p];
  }
  vector<int> res;
  REP(i,3000) {
    if (a[i]) res.push_back(i);
  }
  assert ((int)res.size() == N);
  REP(i,N) cout << res[i] << " \n"[i == N-1];
}

int main() {
  int T;
  cin >> T;
  for (int cas = 1; cas <= T; ++cas) {
    cout << "Case #" << cas << ": ";
    solve();
  }
  return 0;
}
