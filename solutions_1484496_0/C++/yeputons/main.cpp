#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cmath>
#include <cassert>
#include <algorithm>
#include <string>
#include <vector>
#include <map>
#include <set>

using namespace std;

#define eprintf(...) fprintf(stderr, __VA_ARGS__)
#define pb push_back
#define mp make_pair
#define sz(x) ((int)(x).size())

typedef long long ll;

typedef vector<ll> vll;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<bool> vb;
typedef vector<vb> vvb;

int n;
vi as;
void outSet(int m) {
  vi res;
  for (int i = 0; i < n; i++) if (m & (1 << i)) res.pb(as[i]);
  for (int i = 0; i < sz(res); i++)
    printf("%d%c", res[i], "\n "[i + 1 < sz(res)]);
}

void solve() {
  scanf("%d", &n);
  as = vi(n);
  for (int i = 0; i < n; i++)
    scanf("%d", &as[i]);

  map<int, int> was;
  for (int m = 1; m < (1 << n); m++) {
    int sum = 0;
    for (int i = 0; i < n; i++) if (m & (1 << i)) sum += as[i];
    if (was.count(sum)) {
      outSet(m);
      outSet(was[sum]);
      return;
    }
    was.insert(mp(sum, m));
  }
  printf("Impossible\n");
}

bool endsWith(string a, string b) {
  return a.length() >= b.length() && string(a, a.length() - b.length()) == b;
}

int main(int argc, char *argv[]) {
  {
    string fn = "std";
    if (argc >= 2) fn = argv[1];
    if (endsWith(fn, ".in")) fn = string(fn, 0, fn.length() - 3);
    freopen((fn + ".in").c_str(), "r", stdin);
    freopen((fn + ".out").c_str(), "w", stdout);
  }

  int TC;
  assert(scanf("%d", &TC) >= 1);
  for (int TN = 1; TN <= TC; TN++) {
    eprintf("Case #%d:\n", TN);
    printf("Case #%d:\n", TN);
    try {
      solve();
    } catch (...) {
      eprintf("Catched exception at test case #%d\n", TN);
      return 1;
    }
  }
  return 0;
}
