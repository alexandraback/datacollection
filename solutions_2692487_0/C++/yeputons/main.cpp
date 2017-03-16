#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cmath>
#include <cassert>
#include <algorithm>
#include <string>
#include <vector>
#include <deque>
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
typedef pair<int, int> pii;

void solve() {
  int n; ll start;
  scanf("%I64d%d", &start, &n);

  vector<ll> as(n);
  for (int i = 0; i < n; i++)
    scanf("%I64d", &as[i]);
  sort(as.begin(), as.end());

  n = sz(as);

  const int MAXANS = 30;
  vector<vll> dyn(n + 1, vll(MAXANS + 1, -1));
  dyn[0][0] = start;
  for (int i = 0; i < n; i++)
  for (int was = 0; was <= MAXANS; was++) {
    ll cur = dyn[i][was];
    if (cur < 0) continue;

    if (cur > as[i])
      dyn[i + 1][was] = max(dyn[i + 1][was], cur + as[i]);

    if (was < MAXANS) {
      dyn[i + 1][was + 1] = max(dyn[i + 1][was + 1], cur);
      dyn[i][was + 1] = max(dyn[i][was + 1], 2 * cur - 1);
    }
  }
  for (int was = 0; was <= MAXANS; was++) 
    if (dyn[n][was] >= 0) {
      printf("%d\n", was);
      return;
    }
  assert(false);
}

bool endsWith(string a, string b) {
  return a.length() >= b.length() && string(a, a.length() - b.length()) == b;
}

int main(int argc, char *argv[]) {
  {
    string fn = "";
    if (argc >= 2) fn = argv[1];
    if (endsWith(fn, ".in")) fn = string(fn, 0, fn.length() - 3);
    freopen((fn + ".in").c_str(), "r", stdin);
    freopen((fn + ".out").c_str(), "w", stdout);
  }

  int TC;
  assert(scanf("%d", &TC) >= 1);
  for (int TN = 1; TN <= TC; TN++) {
    eprintf("Case #%d:\n", TN);
    printf("Case #%d: ", TN);
    try {
      solve();
    } catch (...) {
      eprintf("Catched exception at test case #%d\n", TN);
      return 1;
    }
  }
  return 0;
}
