#include <iostream>
#include <vector>
#include <cstring>
using namespace std;
using ll = long long;
using VI = vector<int>;
using VVI = vector<VI>;
using VVVI = vector<VVI>;

string f(int a, int b, int c, const VI &ord) {
  VI t(3);
  t[ord[0]] = a+1;
  t[ord[1]] = b+1;
  t[ord[2]] = c+1;
  return to_string(t[0]) + " " + to_string(t[1]) + " " + to_string(t[2]);
}

void calc(int a, int b, int c, int q, vector<int> ord, vector<string> &last) {
  int n = max(a,max(b,c));
  VVI ab(n, VI(n, 0)), ac(ab), bc(ab);
  VVVI used(n, ab);
  vector<string> answers;
  for (int i = 0; i < a; ++i) {
    for (int j = 0; j < b; ++j) {
      if (ab[i][j] >= q) continue;
      for (int k = 0; k < c; ++k) {
        if (ab[i][j] >= q) break;
        if (max(ac[i][k],bc[j][k]) >= q || used[i][j][k]) continue;
        answers.push_back(f(i,j,k,ord));
        ab[i][j]++;
        ac[i][k]++;
        bc[j][k]++;
        used[i][j][k] = 1;
      }
    }
  }

  if (answers.size() > last.size()) swap(last, answers);
}


int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);

  int T; cin >> T;
  int ncase = 0;
  while (T--) {
    int a, b, c, q;
    cin >> a >> b >> c >> q;
    vector<string> ans;
    calc(a,b,c,q,{0,1,2},ans);
    calc(a,c,b,q,{0,2,1},ans);
    calc(b,a,c,q,{1,0,2},ans);
    calc(b,c,a,q,{1,2,0},ans);
    calc(c,a,b,q,{2,0,1},ans);
    calc(c,b,a,q,{2,1,0},ans);

    cout << "Case #" << ++ncase << ": " << ans.size() << endl;
    for (auto &s : ans) cout << s << endl;
  }
}
