#include<iostream>
#include<set>

using namespace std;

#define rep(i, n) for (int i = 0; i < int(n); ++i)

int main() {
  int t;
  cin >> t;
  cout << "Case #1:" << endl;
  int r, n, m, k;
  cin >> r >> n >> n >> k;
  rep (i, r) {
    int v[k];
    rep (j, k) cin >> v[j];
    for (int a = 2; a <= 5; ++a) {
      for (int b = 2; b <= 5; ++b) {
	for (int c = 2; c <= 5; ++c) {
	  set<int> s;
	  rep (aa, 2) rep (bb, 2) rep (cc, 2) {
	    s.insert((aa ? a : 1) * (bb ? b : 1) * (cc ? c : 1));
	  }
	  bool ok = true;
	  rep (j, k) if (s.count(v[j]) == 0) ok = false;
	  if (ok) {
	    cout << a << b << c << endl;
	    goto next;
	  }
	}
      }
    }
  next:;
  }
  return 0;
}
