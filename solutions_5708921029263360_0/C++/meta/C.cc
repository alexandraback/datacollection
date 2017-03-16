#include<bits/stdc++.h>
using namespace std;

using vi = vector<int>; using vvi = vector<vi>;
using ii = pair<int,int>; using vii = vector<ii>;
using l = long long; using vl = vector<l>; using vvl = vector<vl>; using vvvl = vector<vvl>;
using ll = pair<l,l>; using vll = vector<ll>; using vvll = vector<vll>;
using lu = unsigned long long;
using vb = vector<bool>; using vvb = vector<vb>;
using vd = vector<double>; using vvd = vector<vd>;
const int INF = numeric_limits<int>::max();
const double EPS = 1e-10;
const l e5 = 100000, e6 = 1000000, e7 = 10000000, e9 = 1000000000;

l J, P, S, K;
vvvl best;
l best_days;

void backtrack(l j, l p, l s, vvvl& used, vvl& jp, vvl& js, vvl& ps, l days) {
  if (s == S) { p++; s = 0; }
  if (p == P) { j++; p = 0; }
  if (j == J) {
    if (days <= best_days) return;
    best_days = days;
    best = used;
    return;
  }
  if ((jp[j][p] < K) && (js[j][s] < K) && (ps[p][s] < K)) {
    used[j][p][s] = 1;
    jp[j][p]++;
    js[j][s]++;
    ps[p][s]++;
    backtrack(j, p, s + 1, used, jp, js, ps, days + 1);
    used[j][p][s] = 0;
    jp[j][p]--;
    js[j][s]--;
    ps[p][s]--;
  }
  backtrack(j, p, s + 1, used, jp, js, ps, days);
}

int main() {
  ios_base::sync_with_stdio(false); cin.tie(0);
  l tcc; cin >> tcc;
  for (l tc = 1; tc <= tcc; tc++) {
    best_days = 0;
    cin >> J >> P >> S >> K;
    cout << "Case #" << tc << ": ";
    vvvl m(J, vvl(P, vl(S, 0)));
    vvl jp(J, vl(P));
    vvl js(J, vl(S));
    vvl ps(P, vl(S));
    backtrack(0, 0, 0, m, jp, js, ps, 0);
    cout << best_days << endl;
    for (l j = 0; j < J; j++) {
    for (l p = 0; p < P; p++) {
    for (l s = 0; s < S; s++) {
      if (best[j][p][s]) {
        cout << (j + 1) << " " << (p + 1) << " " << (s + 1) << endl;
      }
    }
    }
    }
  }
}
