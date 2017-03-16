#include <iostream>
#include <cstdlib>
#include <iomanip>
#include <cstring>
#include <string>
#include <algorithm>
#include <queue>
#include <map>
#include <set>
#include <stack>
#include <vector>
#include <ctime>
#include <fstream>
#include <cmath>

using namespace std;

#define y1 ym37s62rw
#define x1 xm2ash4ad
#define pb push_back
#define mp make_pair
#define F first
#define S second

const int INF = 1000000007;
const long long INFll = 1000000007000000007ll;
const int MOD = 1000000007;

int n, k;
int a[100][100];
long long h[100];

inline void build(int n) {
    h[0] = 1;
    for (int i = 1; i < n; ++i) {
        for (int j = 0; j < i; ++j) {
            h[i] += h[j];
            a[j][i] = 1;
        }
    }
}

int main() {

    ios_base::sync_with_stdio(0);

#ifdef DEBUG
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#else
#endif

    int t;
    cin >> t;

    for (int i = 0; i < t; ++i) {
        long long n, k;
        cin >> n >> k;
        cout << "Case #" << i + 1 << ": ";
        long long m = (1ll << (n - 2));
        if (m < k) {
            cout << "IMPOSSIBLE" << endl;
            continue;
        }
        cout << "POSSIBLE" << endl;
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < n; ++j) {
                a[i][j] = 0;
            }
        }
        build(n - 1);
        if (m == k) {
            for (int i = 0; i < n - 1; ++i) {
                a[i][n - 1] = 1;
            }
        }
        else {
            int v = 1;
            while (k > 0) {
                if (k % 2 > 0) {
                    a[v][n - 1] = 1;
                }
                k /= 2;
                v++;
            }
        }
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < n; ++j) {
                cout << a[i][j];
            }
            cout << endl;
        }
    }

    return 0;
}
