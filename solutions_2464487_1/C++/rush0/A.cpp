#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <algorithm>
#include <iostream>
#include <map>
#include <set>
#include <string>
#include <vector>
#define OUT(x) cerr << #x << ": " << (x) << endl
#define SZ(x) ((int)x.size())
#define FOR(i, n) for (int i = 0; i < (n); ++i)
using namespace std;
typedef long long LL;

const double pi = acos(-1.0);
const double eps = 1.0e-9;
int T;
LL r, t;

int main() {
    cin >> T;
    for (int id = 1; id <= T; ++id) {
        cin >> r >> t;
        LL low = 1, high = 2e18 + 5;
        while (low < high) {
            LL n = (low + high) / 2;
            double tmp = (double)t / n - (n - 1) * 2.0;
            //LL tmp2 = (LL)tmp;
            //if (abs(tmp - (tmp2 + 1)) < eps) tmp2 += 1;
            if (2 * r + 1 <= tmp) {
                low = n + 1;
            } else {
                high = n;
            }
        }
        cout << "Case #" << id << ": " << low - 1 << endl;
    }
    return 0;
}
