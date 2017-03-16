#include <unordered_map>
#include <cstring>
#include <vector>
#include <list>
#include <map>
#include <set>
#include <queue>
#include <deque>
#include <stack>
#include <bitset>
#include <algorithm>
#include <functional>
#include <numeric>
#include <utility>
#include <sstream>
#include <iostream>
#include <iomanip>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <ctime>
#include <cassert>
#include <unordered_set>

using namespace std;

#define TASKI "in.txt"
#define TASKO "o.txt"
#define eprintf(...) fprintf(stderr, __VA_ARGS__)
#define pb push_back
#define mp make_pair
#define _map unordered_map
#define _set unordered_set
#define sz(x) ((int)(x).size())
#define it(x) (x).begin(), (x).end()
#define rt(x) (x).rbegin(), (x).rend()

#define TIMESTAMP(x)  eprintf("[" #x "] Time = %.5lfs\n",clock()*1.0/CLOCKS_PER_SEC)

#ifdef DEBUG
struct __timestamper {
  ~__timestamper() {
    TIMESTAMP(end);
  }
} __Timestamper;
#else
struct __timestamper {};
#endif

typedef long double ld;
typedef long long ll;
typedef vector<ll> vll;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<bool> vb;
typedef vector<vb> vvb;
typedef vector<string> vs;
typedef pair<int, int> pii;
typedef pair<ll, int> pli;
typedef pair<int, ll> pil;
typedef pair<ll, ll> pll;
typedef vector<pii> vpi;
typedef pair<int, char> ic;

ic mul(ic a, ic b) {
  ic res;
  res.first = a.first * b.first;
  res.second = '1';
  if (a.second == '1')
    res.second = b.second;
  else if (b.second == '1')
    res.second = a.second;
  else if (a.second == b.second) {
    res.first *= -1;
    res.second = '1';
  } else if (a.second == 'i' && b.second == 'j') {
    res.second = 'k';
  } else if (a.second == 'i' && b.second == 'k') {
    res.first *= -1;
    res.second = 'j';
  } else if (a.second == 'j' && b.second == 'i') {
    res.first *= -1;
    res.second = 'k';
  } else if (a.second == 'k' && b.second == 'j') {
    res.first *= -1;
    res.second = 'i';
  } else if (a.second == 'j' && b.second == 'k')
    res.second = 'i';
  else if (a.second == 'k' && b.second == 'i')
    res.second = 'j';
  return res;
}

char a[1001000], b[1001000];

int main(void) {
#ifdef DEBUG
  freopen(TASKI, "r", stdin);
  freopen(TASKO, "w", stdout);
#endif
  
  int tc, cs = 1;
  for (scanf("%d", &tc); tc--; cs++) {
    ll L, X;
    scanf("%lld %lld", &L, &X);
    scanf("%s", a);
    ic tmp = { 1, '1' };
    int rem = int(X % 4), res = 0;
    b[0] = 0;
    for (int i = 0; i < rem; i++)
      strcat(b, a);
    for (int i = 0; b[i]; i++)
      tmp = mul(tmp, { 1, b[i] });
    if (tmp == (ic){ -1, '1' }) {
      res = 1;
      int x = X >= 4 ? 4 : 0;
      for (int i = 0; i < x; i++)
        strcat(b, a);
      int f, s = f = -1;
      ic y, z = y = { 1, '1' };
      for (int i = 0; b[i]; i++) {
        y = mul(y, { 1, b[i] });
        if (y == (ic){ 1, 'i'}) {
          f = i; break;
        }
      }
      int len = (int)strlen(b);
      for (int i = 0; i < len; i++) {
        z = mul({ 1, b[len - i - 1] }, z);
        if (z == (ic){ 1, 'k' }) {
          s = len - i - 1;
          break;
        }
      }
      if (f >= 0 && s >= 0 && f < s + X * L - len)
        res = 1;
      else
        res = 0;
    }
    printf("Case #%d: %s\n", cs, res ? "YES" : "NO");
  }
  return 0;
}
