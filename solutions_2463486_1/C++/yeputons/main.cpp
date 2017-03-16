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

const ll MAXN = ll(1e14) + 1000;

/*
all.txt:

1
4
9
121
484
10201
12321
14641
40804
44944
1002001
1234321
4008004
100020001
102030201
104060401
121242121
123454321
125686521
400080004
404090404
10000200001
10221412201
12102420121
12345654321
40000800004
1000002000001
1002003002001
1004006004001
1020304030201
1022325232201
1024348434201
1210024200121
1212225222121
1214428244121
1232346432321
1234567654321
4000008000004
4004009004004
*/

vector<ll> goods;
void solve() {
  ll l, r;
  scanf("%I64d%I64d", &l, &r);
  assert(1 <= l && l <= r && r <= MAXN);
  int ans = 0;
  for (int i = 0; i < sz(goods); i++)
    if (l <= goods[i] && goods[i] <= r)
      ans++;
  printf("%d\n", ans);
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

  {
    FILE *f = fopen("all.txt", "r");
    assert(f);
    ll x;
    while (fscanf(f, "%I64d", &x) == 1) {
      goods.pb(x);
    }
    fclose(f);
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

/*
precalc:

bool ispal(ll x) {
  char buf[30];
  snprintf(buf, sizeof buf, "%I64d", x);

  int l = strlen(buf);
  for (int i = 0; i < l; i++)
    if (buf[i] != buf[l - i - 1]) return false;
  return true;
}

const ll MAXN = ll(1e14) + 1000;

int main() {
  for (ll x = 1; x * x <= MAXN; x++) if (ispal(x)) {
    ll y = x * x;
    if (ispal(y)) {
      printf("%I64d\n", y);
    }
  }
  return 0;
}
*/
