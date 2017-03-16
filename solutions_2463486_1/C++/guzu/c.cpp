#include <algorithm>
#include <bitset>
#include <cassert>
#include <cctype>
#include <climits>
#include <cmath>
#include <complex>
#include <cstddef>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <ctime>
#include <fcntl.h>
#include <fstream>
// #include <hash_map>
#include <iomanip>
#include <iostream>
#include <iterator>
#include <list>
#include <map>
#include <numeric>
#include <queue>
#include <set>
#include <sstream>
#include <stack>
#include <string>
#include <unistd.h>
#include <utility>
#include <vector>

using namespace std;
// using namespace __gnu_cxx;  // Essential if you want to use hash_map.

typedef long long ll;

typedef pair<int, int> pii;
typedef pair<double, double> pdd;
typedef pair<string, string> pss;
typedef pair<ll, ll> pll;

typedef vector <int> vi;
typedef vector <vi> vvi;
typedef vector <ll> vl;
typedef vector <double> vd;
typedef vector <string> vs;
typedef vector <pii> vpii;

#define all(x) (x).begin(), (x).end()
#define rep(i, n) for (int i = 0; i < (n); ++i)
#define fe(it, X) for (typeof((X).begin()) it = (X).begin(); it != (X).end(); ++it)  // -std=gnu++98, 0x, 11.
#define fev(i, v) for (int i = 0; i < sz(v); ++i)
#define pb push_back
#define pf pop_front
#define mp(a, b) make_pair(a, b)
#define sz(x) (static_cast<int> ((x).size()))
#define sqr(x) ((x) * (x))

ll A, B;

bool isPalindrome(ll n) {
    char buf[110];
    lltoa(n, buf, 10);
    int len = strlen(buf);
    for (int i = 0; 2 * i < len - 1; ++i) {
        if (buf[i] != buf[len - 1 - i]) {
            return false;
        }
    }
    return true;
}

ll solve() {  // For small case, no need to cache.
    ll cnt = 0;
    rep(i, 32) {  // i * i.
        ll ii = i;
        ii *= i;
        if (isPalindrome(i) && isPalindrome(ii) && ii >= A && ii <= B) {
            // cout << "\t" << i << " " << ii << endl;
            ++cnt;
        }
    }
    return cnt;
}

void output() {
    rep(i, 32) {
        ll ii = i;
        ii *= i;
        if (isPalindrome(i) && isPalindrome(ii)) {
            cout << "\t" << i << " " << ii << endl;
        }
    }
}

set<ll> cache;

const int kMax = 10000000 + 1;

void once() {
    assert(cache.empty());
    rep(i, kMax) {
        if (isPalindrome(i)) {
            ll ii = i;
            ii *= i;
            if (isPalindrome(ii)) {
                cache.insert(ii);
                // cout << "\t" << i << " " << ii << endl;
            }
        }
    }
    cout << "Total: " << sz(cache) << endl;
}

ll solveLg1() {
    set<ll>::const_iterator a = cache.lower_bound(A), b = cache.upper_bound(B);
    ll cnt = 0;
    for (set<ll>::const_iterator it = a; it != b; ++it) {
        ++cnt;
    }
    return cnt;
}

void main2() {
    assert(isPalindrome(0));
    assert(isPalindrome(6));
    assert(isPalindrome(11));
    assert(isPalindrome(121));
    assert(isPalindrome(22));
    assert(isPalindrome(676));
    assert(!isPalindrome(12));
    assert(!isPalindrome(223));
    assert(!isPalindrome(2244));
    assert(!isPalindrome(16));
    assert(!isPalindrome(26));
    // output();
    once();
    /*
    A = 2000000;
    B = 10000000;
    assert(solveLg1() == 1);
    */
    /*ifstream in("sample.txt");
    ofstream out("sample.output");*/
    /*ifstream in("C-small-attempt0.in");
    ofstream out("C-small-attempt0.output");*/
    ifstream in("C-large-1.in");
    ofstream out("C-large-1.output");
    int num_cases;
    in >> num_cases;
    cout << num_cases << endl;
    for (int i = 1; i <= num_cases; ++i) {
        in >> A >> B;
        // cout << A << " " << B << endl;
        ll ans = solveLg1();
        // cout << "Case #" << i << ": " << ans << endl;
        out << "Case #" << i << ": " << ans << endl;

    }
    in.close();
    out.close();
}

int main() {
    main2();

    return 0;
}
