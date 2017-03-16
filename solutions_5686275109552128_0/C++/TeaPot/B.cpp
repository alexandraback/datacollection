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

const int MAXN = 2000;

int n;
int a[MAXN];

bool check (int x) {
    int num_div = 0;

    while (true) {
        int new_num_div = 0;
        for (int i = 0; i < n; ++i) {
            new_num_div += (a[i] - 1) / (x - num_div);
        }

        if (new_num_div >= x) {
            return false;
        }

        if (new_num_div == num_div) {
            return true;
        }
        num_div = new_num_div;
    }

    return true;
}

int main () {
    ios_base::sync_with_stdio(0);
	freopen("input.txt", "rt", stdin);
	freopen("output.txt", "wt", stdout);

    int tc;
    cin >> tc;

    for (int ti = 0; ti < tc; ++ti) {
        cin >> n;
        int l = 1, r = 1;
        for (int i = 0; i < n; ++i) {
            cin >> a[i];
            r = max(r, a[i]);
        }

        while (l < r) {
            int m = (l + r) / 2;
            if (check(m)) {
                r = m;
            } else {
                l = m + 1;
            }
        }

        cout << "Case #" << ti + 1 << ": " << l << endl;
    }

	return 0;
}
