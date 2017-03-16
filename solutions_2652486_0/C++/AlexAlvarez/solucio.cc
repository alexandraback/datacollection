#include <iostream>
#include <vector>
#include <set>
using namespace std;

typedef long long ll;
typedef vector<ll> VI;
typedef vector<VI> VVI;

void rec(VI& sol, VVI& all, int x, int m, int n) {
  if (n == 0) {
    all.push_back(sol);
    return;
  }
  sol.push_back(x);
  rec(sol, all, x, m, n - 1);
  sol.pop_back();
  if (x < m) rec(sol, all, x + 1, m, n);
}

int main() {
  int casos;
  cin >> casos;
  for (int cas = 1; cas <= casos; ++cas) {
    int r, m, n, k;
    cin >> r >> n >> m >> k;
    VVI all;
    VI sol;
    rec(sol, all, 2, m, n);
    vector<set<ll> > prods(all.size());
    for (int i = 0; i < all.size(); ++i) {
      set<ll> aux;
      for (int j = 0; j < (1 << n); ++j) {
        ll x = 1;
        for (int k = 0; k < n; ++k) if ((j >> k)&1) x *= all[i][k];
        aux.insert(x);
      }
      prods[i] = aux;
    }
    cout << "Case #" << cas << ":" << endl;
    for (int i = 0; i < r; ++i) {
      ll x;
      cin >> x;
      VI guess;
      for (int j = 0; j < prods.size(); ++j) if (prods[j].count(x)) guess.push_back(j);
      VI input(k - 1);
      for (int j = 0; j + 1 < k; ++j) cin >> input[j];
      for (int j = 0; j < guess.size(); ++j) {
        bool ok = true;
        for (int h = 0; h < input.size() and ok; ++h) if (not prods[guess[j]].count(input[h])) ok = false;
        if (ok) {
          for (int h = 0; h < all[guess[j]].size(); ++h) cout << all[guess[j]][h];
          cout << endl;
          break;          
        }
      }
    }
  }
}