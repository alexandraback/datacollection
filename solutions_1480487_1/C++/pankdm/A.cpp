#include <stdio.h>
#include <iostream>
#include <vector>
#include <string>
#include <math.h>
#include <algorithm>
#include <bitset>
#include <set>
#include <sstream>
#include <stdlib.h>
#include <map>
#include <queue>
#include <assert.h>
#include <deque>
#include <string.h>


using namespace std;

#define sz(x) ((int)x.size())
#define all(x) (x).begin(), (x).end()
#define pb(x) push_back(x)
#define mp(x, y) make_pair(x, y)

typedef long long int64;

typedef vector <int> vi;
typedef vector <vi> vvi;


void solve() {
    int n;
    cin >> n;
    vi a(n);
    int sum = 0;
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
        sum += a[i];
    } 

    for (int i = 0; i < n; ++i) { 
        double lo = 0;
        double hi = 1.;
        for (int iter = 0; iter < 1000; ++iter) {
            double mid = (lo + hi) / 2;
            double tot = mid;
            for (int j = 0; j < n; ++j) {
                if (i == j) continue;
                double low = (a[i] - a[j] + sum * mid) / sum;
                low = max(low, 0.);
                tot += low;
            }
            if (tot < 1.) {
                lo = mid;
            } else {
                hi = mid;
            }
        }
        printf("%.8lf ", lo * 100);
    }
    cout << endl;
}


int main () {
	//freopen("", "rt", stdin);
	//freopen("", "wt", stdout);
    int T;
    cin >> T;
    for (int t = 0; t < T; ++t) {
        cout << "Case #" << t + 1 << ": ";
        solve();
    }

    return 0;
}

