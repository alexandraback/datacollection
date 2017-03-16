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

int main () {
    ios_base::sync_with_stdio(0);
    freopen("input.txt", "rt", stdin);
    freopen("output.txt", "wt", stdout);

    int tc;
    cin >> tc;

    for (int ti = 0; ti < tc; ++ti) {
        int x, n, m;
        cin >> x >> n >> m;

        if (n < m) {
            swap(n, m);
        }

        if ((n * m) % x != 0) {
            cout << "Case #" << ti + 1 << ": " << "RICHARD" << endl;
            continue;
        }

        if (x == 4) {
            if (n == 4 && m >= 3) {
                cout << "Case #" << ti + 1 << ": " << "GABRIEL" << endl;
                continue;
            }
            cout << "Case #" << ti + 1 << ": " << "RICHARD" << endl;
            continue;
        }

        if (x == 3) {
            if (m >= 2) {
                cout << "Case #" << ti + 1 << ": " << "GABRIEL" << endl;
                continue;
            }
            cout << "Case #" << ti + 1 << ": " << "RICHARD" << endl;
            continue;
        }

        cout << "Case #" << ti + 1 << ": " << "GABRIEL" << endl;
    }

	return 0;
}
