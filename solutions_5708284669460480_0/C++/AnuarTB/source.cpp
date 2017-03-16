#include <bits/stdc++.h>

#define pii pair<int, int>

#define pb push_back
#define mp make_pair

#define f first
#define s second

using namespace std;

typedef long long ll;
typedef vector<int> big;

const double EPS = 1e-9;
const double PI = acos(-1);

const int MAXN = (int) 1e5 + 7;
const int INF = (int) 1e9 + 7;

int t, n, L, S;
string keys, target, s;

vector<int> all;

void rec(int pos) {
  if (pos == S) {
    int cnt = 0;
    for (int i = 0; i + L - 1 < S; i++) {
      if (s.substr(i, L) == target)
        ++cnt;
    }
    all.pb(cnt);    
  }
  else {
    for (auto put : keys) {
      s.pb(put);
      rec(pos + 1);
      s.pop_back();
    }
  }
}

int main() {
  #ifdef LOCAL
  freopen("in", "r", stdin);
  freopen("out", "w", stdout);
  #endif

  scanf("%d", &t);
  for (int cases = 1; cases <= t; cases++) {
    printf("Case #%d: ", cases);
    all.clear();
    scanf("%d%d%d", &n, &L, &S);
    cin >> keys >> target;
    rec(0);
    int maxC = *max_element(all.begin(), all.end());
    double res = 0;
    for (int i = 0; i < (int)all.size(); i++)
      res += maxC - all[i];

    res /= double(all.size());
    cerr<<"fast plz\n";
    cout << fixed << setprecision(6) << res << "\n";
  }
  return 0;
}
