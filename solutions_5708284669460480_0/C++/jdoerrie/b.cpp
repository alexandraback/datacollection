#include <bits/stdc++.h>

using namespace std;

using I = int32_t;
using LL = int64_t;
using II = pair<I,I>;
template<class T> using V = vector<T>;
template<class T> using VV = vector<vector<T>>;

LL my_max, total, cnt;
string K, L;

void solve(string S, int rem) {
  if (rem == 0) {
    LL occs = 0;
    size_t idx = -1;
    // cerr << S << endl;
    do {
      idx = S.find(L, idx + 1);
      ++occs;
    } while (idx != string::npos);

    --occs;
    my_max = std::max(my_max, occs);
    total += occs;
    ++cnt;

    return;
  }

  for (auto k: K) {
    solve(S + k, rem - 1);
  }
}

double testcase() {
  my_max = total = cnt = 0;
  int k, l, s;
  cin >> k >> l >> s;
  cin >> K >> L;

  solve("", s);
  return my_max - (total / static_cast<double>(cnt));
}


int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);

  int T;
  cin >> T;
  for (int t = 0; t < T; ++t) {
    cout << "Case #" << t+1 << ": " << std::setprecision(9) << testcase() << "\n";
  }

  return 0;
}
