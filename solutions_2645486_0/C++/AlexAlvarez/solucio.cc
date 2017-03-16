#include <iostream>
#include <set>
#include <vector>
#include <algorithm>
using namespace std;

typedef long long ll;
typedef pair<ll, ll> PII;

bool comp(PII a, PII b) {
  return a > b;  
}

int main() {
  int casos;
  cin >> casos;
  for (int cas = 1; cas <= casos; ++cas) {
    ll e, r, n;
    cin >> e >> r >> n;
    vector<PII> v(n);
    for (int i = 0; i < n; ++i) {
      cin >> v[i].first;
      v[i].second = i;
    }
    sort(v.begin(), v.end(), comp);
    vector<ll> in(n), out(n);
    set<int> pos, neg;
    ll res = 0;
    for (int i = 0; i < v.size(); ++i) {
      ll val = v[i].first, p = v[i].second;
      set<int>::iterator it = pos.upper_bound(p);
      int pnext, pprev;
      if (it == pos.end()) pnext = -1;
      else pnext = *it;
      it = neg.upper_bound(-p);
      if (it == neg.end()) pprev = -1;
      else pprev = -*it;
      
      ll ini_energy = ((pprev == -1) ? e : min(out[pprev] + r*ll(p - pprev), e));
      ll fin_energy;
      if (pnext == -1) fin_energy = 0;
      else {
        if (r*ll(pnext - p) >= in[pnext]) fin_energy = 0;
        else fin_energy = in[pnext] - r*ll(pnext - p);
      }
      if (fin_energy < ini_energy) {
        res += val*(ini_energy - fin_energy);
        in[p] = ini_energy;
        out[p] = fin_energy;
        pos.insert(p);
        neg.insert(-p);
      }
    }
    cout << "Case #" << cas << ": " << res << endl;
  }
}