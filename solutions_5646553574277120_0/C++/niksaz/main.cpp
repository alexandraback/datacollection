#include <algorithm>
#include <cstdio>
#include <iostream>
#include <iomanip>
#include <vector>
#include <map>
#include <set>
#include <cmath>
#include <cstdlib>
#include <ctime>
#include <cstring>
#include <string>
#include <sstream>
#include <queue>
#include <bitset>
#include <fstream>
#include <stack>
#include <deque>
#include <utility>
#include <numeric>

using namespace std;
typedef long long ll;
typedef pair <int, int> pii;
const int N = 100;

bool f[N];

void addcoin(int x) {
    for (int i = N - 1; i >= 0; i--) {
        if (f[i] == true && i + x < N) {
            f[i + x] = true;
        }
    }
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    ios_base::sync_with_stdio(false);
    cout << setprecision(9) << fixed;
    int tests;
    cin >> tests;
    for (int t = 1; t <= tests; t++) {
        memset(f, false, sizeof(f));
        f[0] = true;
        int c;
        int d;
        int v;
        cin >> c >> d >> v;
        for (int i = 1; i <= d; i++) {
            int x;
            cin >> x;
            addcoin(x);
        }
        int ans = 0;
        for (int i = 1; i <= v; i++) {
            if (f[i] == false) {
                addcoin(i);
                ans++;
            }
        }
        cout << "Case #" << t << ": " << ans << "\n";
    }
    return 0;
}