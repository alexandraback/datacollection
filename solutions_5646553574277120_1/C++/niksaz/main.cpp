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

vector<long long> a;

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    ios_base::sync_with_stdio(false);
    cout << setprecision(9) << fixed;
    int tests;
    cin >> tests;
    for (int t = 1; t <= tests; t++) {
        a.clear();
        int c;
        int d;
        long long v;
        cin >> c >> d >> v;
        for (int i = 0; i < d; i++) {
            long long x;
            cin >> x;
            a.push_back(x);
        }
        sort(a.begin(), a.end());
        long long limit = 0;
        int it = 0;
        int ans = 0;
        while (limit < v) {
            if (it < d && a[it] <= limit + 1) {
                limit += a[it] * c;
                it++;
            } else {
                long long add = limit + 1;
                ans++;
                limit += add * c;
            }
        }
        cout << "Case #" << t << ": " << ans << "\n";
    }
    return 0;
}