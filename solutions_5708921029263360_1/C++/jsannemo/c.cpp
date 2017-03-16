#include <bits/stdc++.h>
using namespace std;

#define rep(i, a, b) for(int i = a; i < int(b); ++i)
#define trav(a, v) for(auto& a : v)
#define all(x) x.begin(), x.end()
#define sz(x) (int)(x).size()
#define D(x) cerr << #x << " = " << x << endl

typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;

void solve(int tc) {
  printf("Case #%d: ", tc);
  int J, P, S, K;
  scanf("%d%d%d%d", &J, &P, &S, &K);

  int ans = J * P * min(S, K);

  vector<vector<int>> jp(J, vector<int>(P));
  vector<vector<int>> js(J, vector<int>(S));
  vector<vector<int>> ps(P, vector<int>(S));
  vector<vector<vector<int>>> jps(J, ps);
  printf("%d\n", ans);
  for (int i = 0; i < ans; ++i) {
    int j = i / (P * min(S, K));
    int p = i % P;
    int s = (i % P + i / P) % S;
    assert(++jp[j][p] <= K);
    assert(++js[j][s] <= K);
    assert(++ps[p][s] <= K);
    assert(++jps[j][p][s] <= 1);
    printf("%d %d %d\n", j+1, p+1, s+1);
  }
  return;
}

int main() {
  int N;
  scanf("%d", &N);
  rep(i,1,N+1) solve(i);
}
