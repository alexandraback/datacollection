#include <iostream>
#include <vector>
#include <cstring>
using namespace std;

typedef long long ll;

ll M[2][2][2][50];

ll a, b, k;

ll dp(ll la, ll lb, ll lk, ll p) {
  if (p == -1) return 1;
  
  ll &ans = M[la][lb][lk][p];
  if (ans == -1) {
    ans = 0;

    for (int ba = 0; ba < 2; ++ba) {
      if (ba > ((a >> p)&1) and la == 0) continue;
      for (int bb = 0; bb < 2; ++bb) {
        if (bb > ((b >> p)&1) and lb == 0) continue;
        if ((ba & bb) > ((k >> p)&1) and lk == 0) continue;
        int newla = (ba == 0 and ((a >> p)&1) == 1) ? 1 : 0;
        int newlb = (bb == 0 and ((b >> p)&1) == 1) ? 1 : 0;
        int newlk = ((ba & bb) == 0 and ((k >> p)&1) == 1) ? 1 : 0;
        ans += dp(la | newla, lb | newlb, lk | newlk, p - 1);
      }
    }
  }
  return ans;
}

ll solve() {
  cin >> a >> b >> k;
  --a; --b; --k;
  memset(M, -1, sizeof(M));
  return dp(0, 0, 0, 40);
}

int main() {
  int casos;
  cin >> casos;
  for (int cas = 1; cas <= casos; ++cas) {
    cout << "Case #" << cas << ": " << solve() << endl;
  }
}
