#include <iostream>
#include <iosfwd>
#include <iomanip>
#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <ctime>
#include <cmath>
#include <cassert>
#include <cctype>
#include <climits>
#include <vector>
#include <bitset>
#include <set>
#include <queue>
#include <stack>
#include <map>
#include <deque>
#include <string>
#include <list>
#include <iterator>
#include <sstream>
#include <complex>
#include <fstream>
#include <functional>
#include <numeric>
#include <utility>
#include <algorithm>
#include <assert.h>
#include <unordered_map>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;
typedef vector < long long > vll;
typedef pair <long long, long long> pll;
typedef pair <int, int> pii;
typedef vector < int > vii;
typedef complex < double > Point;

#define csl ios_base::sync_with_stdio(false); cin.tie(NULL)
#define mp make_pair
#define fst first
#define snd second
#define prev PREV
ll t, n, m, u, v, q, r, ql, qr, k, l, s, w, h, c, z, d, x, y;
const int N = 1e5 + 500;
const long long mod = 1e9 + 7;
const long long INF = 1LL << 62LL;
const bool JUDGE = false;
string str, tr;
int main() {
    csl;
    if (JUDGE) {
        freopen("angry.in", "r", stdin);
        freopen("angry.out", "w", stdout);
    }
    cin >> t;
    for (int ii = 1; ii <= t; ++ii) {
        cout << "Case #" << ii << ": ";
        cin >> str;
        tr.clear();
        tr.push_back(str[0]);
        for (int i = 1; i < str.size(); ++i) {
            if (str[i] >= tr[0]) tr = str[i] + tr;
            else tr.push_back(str[i]);
        }
        cout << tr << '\n';
    }
    return 0;
}








