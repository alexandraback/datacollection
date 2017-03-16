#include <bits/stdc++.h>
using namespace std;

int g[50][50];
bool kr[50], kc[50];
int N;
bool done;
vector<vector<int> >v;
void solve() {
  if (v.size() == 0) {
    if (done) return;
    done = true;
    for (int i=0; i < N; i++) {
      for (int j=0; j < N; j++) {
        if (!kr[i]) cout << " " << g[i][j];
        else if (!kc[i]) cout << " " << g[j][i];
      }
    }
    cout << endl;
    return;
  }
  for (int j=0; j < N; j++) {
    if (!kr[j]) {
      bool good = true;
      for (int k=0; k < N; k++) {
        if (kc[k] && g[j][k] != v.back()[k]) good = false;
      }
      if (good) {
        kr[j] = true;
        for (int k=0; k < N; k++) if (!kc[k]) g[j][k] = v.back()[k];
        vector<int> vv = v.back(); v.pop_back();
        solve();
        v.push_back(vv);
        kr[j] = false;
      }
    }
    if (!kc[j]) {
      bool good = true;
      for (int k=0; k < N; k++) {
        if (kr[k] && g[k][j] != v.back()[k]) good = false;
      }
      if (good) {
        kc[j] = true;
        for (int k=0; k < N; k++) if (!kr[k]) g[k][j] = v.back()[k];
        vector<int> vv = v.back(); v.pop_back();
        solve();
        v.push_back(vv);
        kc[j] = false;
      }
    }
  }
}

int main() {
  int T; cin >> T;
  for (int zz=1; zz <= T; zz++) {
    cout << "Case #" << zz << ":";
    cin >> N;
    v.clear();
    for (int i=0; i < 2*N-1; i++) {
      vector<int> vv;
      for (int j=0; j < N; j++) {
        int c; cin >> c;
        vv.push_back(c);
      }
      v.push_back(vv);
    }
    memset(kr, 0, sizeof kr); memset(kc, 0, sizeof kc);
    int m = 2501, mi = -1;
    for (int i=0; i < v.size(); i++) {
      if (v[i][0] < m) m = v[i][0], mi = i;
    }
    for (int i=0; i < N; i++) {
      g[0][i] = v[mi][i];
    }
    kr[0] = true;
    v.erase(v.begin()+mi);
    done = false;
    solve();
  }
  return 0;
}
