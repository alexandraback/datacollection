#include <cstdio>
#include <vector>
#include <string>
#include <iostream>
using namespace std;
typedef long long ll;

int main() {
  int T;
  cin>>T;
  for (int t=1; t <= T; t++) {
    int n, m;
    scanf("%d%d", &n, &m); n -= 2;
    vector<vector<ll> > ans;
    vector<string> coins;
    for (int coin = 0; coin < 1 << n; coin++) {
      vector<ll> v;
      bool ok = true;
      for (int b = 2; b <= 10; b++) {
        ll num = 1, pot = 1;
        for (int i = 0; i < n; i++) {
          pot *= b;
          if (coin & (1 << i))
            num += pot;
        }
        num += pot * b;

        if (num % 2 == 0) {
          v.push_back(2);
          continue;
        }

        ok = false;
        for (ll x=3; x * x <= num; x += 2) if (num % x == 0) {
          v.push_back(x);
          ok = true;
          break;
        }

        if (!ok)
          break;
      }

      if (ok) {
        ans.push_back(v);
        string s = "";
        for (int i = n-1; i >= 0; i--)
          s += ((coin & (1 << i)) ? "1" : "0");
        coins.push_back("1" + s + "1");
        if (ans.size() == m) {
          break;
        }
      }
    }

    printf("Case #%d:\n", t);
    for (int i=0; i < m; i++) {
      cout << coins[i];
      for (int j=0; j < ans[i].size(); j++)
        cout << " " << ans[i][j];
      cout << endl;
    }

  }
  return 0;
}
