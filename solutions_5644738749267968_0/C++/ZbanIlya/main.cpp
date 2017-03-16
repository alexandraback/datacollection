#include <iostream>
#include <string>
#include <map>
#include <math.h>
#include <vector>
#include <algorithm>
#include <cstdio>
#include <set>
#include <queue>
#include <sstream>
#include <deque>
#include <memory.h>
#include <cassert>
#include <ctime>


using namespace std;

#define ll long long
#define y1 _dfdfdfd


const int maxn = 1 << 10;
const int inf = 1000000007;
const int mod = 1000000007;

int n;
double a[maxn], b[maxn];
 
int solve1() {
    int ans = 0;
    int l = 0, r = n - 1;
    for (int i = 0; i < n; i++) {
        if (a[i] > b[l]) {
            l++;
            ans++;
        } else r--;
    }
    return ans;
}
 
int solve2() {
    vector<char> f(n);
    int ans = 0;
    for (int i = 0; i < n; i++) {
        bool was = 0;
        for (int j = 0; j < n; j++) {
            if (!f[j] && b[j] > a[i]) {
                was = 1;
                f[j] = 1;
                break;
            }
        }
        if (!was) {
            for (int j = 0; j < n; j++) {
                if (!f[j] && b[j] < a[i]) {
                    f[j] = 1;
                    break;
                }
            }
            ans++;
        }
    }
    return ans;
}
 
int solve3() {
    vector<char> f(n);
    int ans = 0;
    for (int i = n - 1; i >= 0; i--) {
        bool was = 0;
        for (int j = 0; j < n; j++) {
            if (!f[j] && b[j] > a[i]) {
                was = 1;
                f[j] = 1;
                break;
            }
        }
        if (!was) {
            for (int j = 0; j < n; j++) {
                if (!f[j] && b[j] < a[i]) {
                    f[j] = 1;
                    break;
                }
            }
            ans++;
        }
    }
    return ans;
} 

void gen() {
    n = rand() % 1000 + 1;
    for (int i = 0; i < n; i++) {
        a[i] = rand() % 99999 + 1;
        a[i] /= 100000.0;
        b[i] = rand() % 99999 + 1;
        b[i] /= 100000.0;
    }
    sort(a, a + n);
    sort(b, b + n);
}

void stress(bool f) {
    if (!f) return;
    for (int it = 0; it < 1e6; it++) {
        gen();
        if (solve2() != solve3()) {
            cout << solve2() << " " << solve3() << endl;
            cout << n << endl;
            for (int i = 0; i < n; i++) printf("%.5lf%c", a[i], " \n"[i + 1 == n]);
            for (int i = 0; i < n; i++) printf("%.5lf%c", b[i], " \n"[i + 1 == n]);
            break;
        }
        if (it % 100 == 0)
            cerr << it << endl;
    }
    exit(0);
}
 
int main() {
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);

    stress(0);

    int tests;
    cin >> tests;
    for (int test = 1; test <= tests; test++) {
        cout << "Case #" << test << ": ";

        cin >> n;
        for (int i = 0; i < n; i++) cin >> a[i];
        for (int i = 0; i < n; i++) cin >> b[i];
        sort(a, a + n);
        sort(b, b + n);
        
        cout << solve1() << " " << solve2() << endl;
        //cout << solve1() << " " << solve2() << " " << solve3() << endl;
    }

	return 0;
}
