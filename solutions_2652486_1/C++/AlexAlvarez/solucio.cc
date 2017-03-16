#include <iostream>
#include <vector>
#include <map>
#include <algorithm>
using namespace std;

typedef long long ll;
typedef vector<ll> VI;
typedef vector<VI> VVI;
typedef pair<int, ll> PII;

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

bool comp(PII a, PII b) {
  return a.second > b.second;  
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
    vector<map<ll, int> > prods(all.size());
    for (int i = 0; i < all.size(); ++i) {
      map<ll, int> aux;
      for (int j = 0; j < (1 << n); ++j) {
        ll x = 1;
        for (int k = 0; k < n; ++k) if ((j >> k)&1) x *= all[i][k];
        aux[x]++;
      }
      prods[i] = aux;
    }
    cout << "Case #" << cas << ":" << endl;
    int sure = 0;
    for (int i = 0; i < r; ++i) {
      ll x;
      cin >> x;
      VI guess;
      for (int j = 0; j < prods.size(); ++j) if (prods[j].count(x)) guess.push_back(j);

      VI input(k - 1);
      for (int j = 0; j + 1 < k; ++j) cin >> input[j];
      input.push_back(x);
      
      vector<PII> solution;
      for (int j = 0; j < guess.size(); ++j) {
        bool ok = true;
        ll weight = 1;
        for (int h = 0; h < input.size() and ok; ++h) {
          if (not prods[guess[j]].count(input[h])) ok = false;
          else weight *= prods[guess[j]][input[h]];
        }
        if (ok) solution.push_back(PII(guess[j], weight));        
      }
      
      if (solution.size() == 1) ++sure;
      sort(solution.begin(), solution.end(), comp);
      for (int j = 0; j < n; ++j) cout << all[solution[0].first][j];
      cout << endl;
    }
    cerr << sure << " sure" << endl;
  }
}