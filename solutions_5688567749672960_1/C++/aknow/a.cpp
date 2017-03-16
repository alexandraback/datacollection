#include <algorithm>
#include <cassert>
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iomanip>
#include <iostream>
#include <map>
#include <queue>
#include <set>
#include <sstream>
#include <string>
#include <vector>

using namespace std;

#define clr(x) memset((x), 0, sizeof(x))
#define all(x) (x).begin(), (x).end()
#define pb push_back
#define mp make_pair
#define sz size()
#define For(i, st, en)  for(int i=(st); i<=(int)(en); i++)
#define Forn(i, st, en) for(int i=(st); i<=(int)(en); i++)
#define Ford(i, st, en) for(int i=(st); i>=(int)(en); i--)
#define forn(i, n) for(int i=0; i<(int)(n); i++)
#define ford(i, n) for(int i=(n)-1; i>=0; i--)
#define fori(it, x) for (__typeof((x).begin()) it = (x).begin(); it != (x).end(); it++)

template <class _T> inline _T sqr(const _T& x) { return x * x; }
template <class _T> inline string tostr(const _T& a) { ostringstream os(""); os << a; return os.str(); }
template <class _T> inline istream& operator << (istream& is, const _T& a) { is.putback(a); return is; }

// Types
typedef long double ld;
typedef signed   long long i64;
typedef signed   long long ll;
typedef unsigned long long u64;
typedef unsigned long long ull;
typedef set < int > SI;
typedef vector < ld > VD;
typedef vector < int > VI;
typedef vector < bool > VB;
typedef vector < string > VS;
typedef map < string, int > MSI;
typedef pair < int, int > PII;

// Constants
const ld PI = 3.1415926535897932384626433832795;
const ld EPS = 1e-11;

//#define debug(...)
#define debug printf

const ll MAX = 10000000LL;
//const int MAX = 30;

int counts[MAX + 1];

ll reverseNum(ll num) {
  ll result = 0;
  while (num) {
    result = result * 10 + (num % 10);
    num /= 10;
  }
  return result;
}

void prepare() {
  fill_n(counts, MAX, MAX);
  counts[0] = 0;
  counts[1] = 1;
  for (int i = 2; i <= MAX; ++i) {
    counts[i] = counts[i-1] + 1;
    int reverse = reverseNum(i);
    if (reverse <= MAX && reverseNum(reverse) == i) {
      counts[i] = min(counts[i], counts[reverse] + 1);
      if (counts[i] != counts[i-1] + 1) {
        cout << i << " from " << reverse << endl;
      }
    }
  }
}

vector<ll> magic;

ll shift(ll num, int len) {
  while (len) {
    num *= 10;
    len--;
  }
  return num;
}

void gen(ll N) {
  int len = 1;

  while (true) {
    //cout << "=== " << len << endl;
    for (int first_len = max(1, len-1); first_len <= len; ++first_len) {
      ll start = shift(1, first_len-1);
      ll end = shift(1, first_len) -1;

      ll whole = shift(start, len) + 1;
      if (whole >= N) return;

      // find start.
      while (reverseNum(whole) >= whole) {
        start++;
        whole = shift(start, len) + 1;
      }

      //cout << "--- " << first_len << " " << start << " " << end << endl;

      for (ll i = start; i <= end; ++i) {
        whole = shift(i, len) + 1;
        magic.push_back(whole);
        //cout << whole << endl;
      }
    }

    len++;
  }
}

ll countDown(ll num) {
  ll count = 0;

  while (true) {
    auto it = lower_bound(magic.begin(), magic.end(), num);
    if (num == *it) {
      // reverse.
      count += 1;
      num = reverseNum(num);
      continue;
    }

    if (it == magic.begin()) {
      return count + num;
    }

    --it;
    count += (num - *it);
    num = *it;
  }
}

int main() {
    int caseN;
    scanf("%d", &caseN);

    //cout << reverseNum(2300) << endl;
    //cout << reverseNum(1234) << endl;
    //prepare();

    gen(100000000000000LL);
    sort(magic.begin(), magic.end());
    //cout << magic.size() << endl;

    for (int cc = 1; cc <= caseN; ++cc) {
        printf("Case #%d: ", cc);

        ll n;
        cin >> n;
        //cout << counts[n];
        //assert(counts[n] == countDown(n));
        cout << countDown(n);

        printf("\n");
    }

    return 0;
}
