#include <bits/stdtr1c++.h>
using namespace std;

struct s {
  int a, b, c;
  s(int aa, int bb, int cc) : a(aa), b(bb), c(cc) {}
};

vector<int> v[28];
int ab[10][10], ac[10][10], bc[10][10];

int main() {
  int t; cin >> t;
  for (int T = 1; T <= t; T++) {
    for (int i = 1; i < 28; i++)
      v[i].clear();
    cout << "Case #" << T << ": ";
    int J, P, S, K;
    cin >> J >> P >> S >> K;
    for (int i = 1; i < (1<<(J*P*S)); i++)
      v[__builtin_popcount(i)].push_back(i);
    bool d = false;
    for (int i = J*P*S; i; i--) {
      for (int j : v[i]) {
        vector<s> vs;
        bool g = true;
        memset(ab, 0, sizeof ab);
        memset(ac, 0, sizeof ac);
        memset(bc, 0, sizeof bc);
        for (int k = 0; k < J*P*S; k++) {
          if (!((1<<k) & j))
            continue;
          int c = k%S, b = (k/S)%P, a = (k/S/P)%J;
          vs.push_back(s(a+1,b+1,c+1));
          ab[a][b]++; ac[a][c]++; bc[b][c]++;
          if (ab[a][b] > K || ac[a][c] > K || bc[b][c] > K) {
            g = false;
            break;
          }
        }
        if (g) {
          cout << i << "\n";
          for (s S : vs)
            cout << S.a << " " << S.b << " " << S.c << "\n";
          d = true;
          break;
        }
      }
      if (d)
        break;
    }
  }
  return 0;
}
