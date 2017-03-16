#include <cstdio>
#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>
#include <string>
#include <set>
#include <map>
#include <ctime>
#include <cstring>
#include <cassert>
#include <bitset>
#include <sstream>
#include <queue>

#define pb push_back
#define mp make_pair
#define fs first
#define sc second
#define sz(a) ((int) (a).size())
#define eprintf(...) fprintf(stderr, __VA_ARGS__)

using namespace std;

typedef long long int64;
typedef long double ldb;

const long double eps = 1e-9;
const int inf = (1 << 30) - 1;
const long long inf64 = ((long long)1 << 62) - 1;
const long double pi = acos(-1);

template <class T> T sqr (T x) {return x * x;}
template <class T> T abs (T x) {return x < 0 ? -x : x;}

pair <int, int> mult (pair <int, int> a, pair <int, int> b) {
    int sign = a.sc * b.sc;
    if (a.fs == 0) {
        return mp(b.fs, sign);
    }

    if (b.fs == 0) {
        return mp(a.fs, sign);
    }

    a.fs--, b.fs--;
    if (a.fs == b.fs) {
        return mp(0, -sign);
    }

    if ((a.fs + 1) % 3 == b.fs) {
        return mp((b.fs + 1) % 3 + 1, sign);
    }

    assert((b.fs + 1) % 3 == a.fs);
    return mp((a.fs + 1) % 3 + 1, -sign);
}

pair <int, int> deg (pair <int, int> a, long long n) {
    if (n == 0)
        return mp(0, 1);

    pair <int, int> res = deg(a, n / 2);
    res = mult(res, res);
    if (n % 2 == 1)
        res = mult(res, a);

    return res;
}

const int MAXN = 12 * 1000;

pair <int, int> a[MAXN];
string s;

int main () {
    ios_base::sync_with_stdio(0);
	freopen("input.txt", "rt", stdin);
	freopen("output.txt", "wt", stdout);

    int tc;
    cin >> tc;

    for (int ti = 0; ti < tc; ++ti) {
        long long n, m;
        cin >> n >> m;
        cin >> s;
        for (int i = 0; i < n; ++i) {
            a[i] = mp((s[i] == 'i' ? 1 : (s[i] == 'j' ? 2 : 3)), 1);
        }

        pair <int, int> total = mp(0, 1);
        for (int i = 0; i < n; ++i) {
            total = mult(total, a[i]);
        }
        total = deg(total, m);

        if (total != mp(0, -1)) {
            cout << "Case #" << ti + 1 << ": " << "NO" << endl;
            continue;
        }

        long long ind_left = 0;
        pair <int, int> cur = mp(0, 1);
        while (ind_left < min(n * m, n * 4) && cur != mp(1, 1)) {
            cur = mult(cur, a[ind_left % n]);
            ind_left++;
        }
        if (cur != mp(1, 1)) {
            cout << "Case #" << ti + 1 << ": " << "NO" << endl;
            continue;
        }

        cur = mp(0, 1);
        long long ind_right = n * m - 1;
        while (ind_right > max((long long)-1, n * (m - 4) - 1) && cur != mp(3, 1)) {
            cur = mult(a[ind_right % n], cur);
            ind_right--;
        }
        if (cur != mp(3, 1)) {
            cout << "Case #" << ti + 1 << ": " << "NO" << endl;
            continue;
        }

        if (ind_left > ind_right + 1) {
            cout << "Case #" << ti + 1 << ": " << "NO" << endl;
            continue;
        }
        cout << "Case #" << ti + 1 << ": " << "YES" << endl;
    }

	return 0;
}
