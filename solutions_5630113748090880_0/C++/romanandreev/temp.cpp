#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef long double ld;

#define all(c) (c).begin(),(c).end()
#define sz(c) (int)(c).size()
#define pb push_back
#define mp make_pair
#define x first
#define y second
#define image(a) {sort(all(a)), a.resize(unique(all(a)) - a.begin());}
const int MAXC = 3000;
void solve() {
  int n;
  scanf("%d", &n);
  vector<int> M(MAXC, 0);
  for (int i = 0; i < 2 * n - 1; i++) {
    for (int j = 0; j < n; j++) {
      int x;
      scanf("%d", &x);
      M[x]++;
    }
  }
  int cnt = 0;
  for (int i = 0; i < sz(M); i++) {
    if (M[i] % 2 != 0) {
      cout << " " << i;
      cnt++;
    }
  }
  cout << endl;
  assert(cnt == n);
}

int main(){
  assert(freopen("a.out","wt",stdout));
  assert(freopen("a.in","rt",stdin));
  int T;
  scanf("%d", &T);
  for (int ti = 1; ti <= T; ti++) {
    printf("Case #%d:", ti);
    solve();
  }
  return 0;
}
