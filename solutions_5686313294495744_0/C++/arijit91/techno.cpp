#include<iostream>
#include<map>
#include<set>
#include<vector>
#include<string>
using namespace std;

int main() {
  int t;
  cin>>t;
  for (int cas = 1; cas <= t; cas++) {
    map<string, int> M;
    int word_index = 0;
    int ans = 0;
    vector<pair<int, int> > V;
    int n;
    cin>>n;

    for (int i = 0; i < n; i++) {
      string x, y;
      cin >> x >> y;
      int a, b;
      if (M.find(x) == M.end()) {
        M[x] = word_index;
        word_index++;
      }
      if (M.find(y) == M.end()) {
        M[y] = word_index;
        word_index++;
      }
      a = M[x];
      b = M[y];
      V.push_back(make_pair(a, b));
    }

    for (int i = 0; i < (1<<n); i++) {
      set<int> P;
      set<int> Q;
      for (int j = 0; j < n; j++) {
        if (i & (1<<j)) {
          P.insert(V[j].first);
          Q.insert(V[j].second);
        }
      }

      int faked = 0;
      bool ok = true;
      for (int j = 0; j < n; j++) {
        if (!(i & (1<<j))) {
          if (P.find(V[j].first) == P.end()) {
            ok = false;
            break;
          }

          if (Q.find(V[j].second) == Q.end()) {
            ok = false;
            break;
          }
          faked += 1;
        }
      }

      if (ok) {
        ans = max(ans, faked);
      }
    }

    cout << "Case #" << cas << ": " << ans << endl;
  }
}
