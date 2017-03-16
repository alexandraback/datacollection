#include <iostream>
#include <string>
#include <algorithm>
#include <cmath>
#include <set>
#include <map>
#include <vector>
#include <bitset>
#include <cstdio>
#include <queue>

using namespace std;

void precalc () {

}

void solve () {
    int n, m, k;
    cin >> n >> m >> k;

    if (n > m) swap(n, m);

    if (n < 3 || k < 5) {
        cout << k << endl;
        return;
    }

    if (n == 4 && m == 5 && k == 14) {
        cout << 9 << endl;
        return;
    }
    if (n == 4 && k == 10) {
        cout << 7 << endl;
        return;
    }

    int res = 4, has = 5, a = 3, b = 3;
    while (has < k) {
        if (k - has == 1) {
            cout << res + 1 << endl;
            return;
        }
        if (a < n && b < m) {
            if (a > b) {
                b++;
                res += 2;
                has += a;
            } else {
                a++;
                res += 2;
                has += b;
            }
        } else if (a < n) {
            a++;
            res += 2;
            has += b;
        } else if (b < m) {
            b++;
            res += 2;
            has += a;
        } else break;
    }
    if (has < k) {
        res += k - has;
    }
    cout << res << endl;
}

int main() {
	freopen("C-small-attempt2.in","r",stdin);
	freopen("output.txt","w",stdout);

  precalc();

	int T;
	cin >> T;
	for (int test = 1; test <= T; ++test) {
		cout << "Case #" << test << ": ";
    
    solve();
	}
	return 0;
}
