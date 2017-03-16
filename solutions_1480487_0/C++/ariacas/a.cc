#include <cstdio>
#include <cstdlib>
#include <cassert>
#include <iostream>
#include <set>
#include <vector>
#include <cstring>
#include <string>
#include <algorithm>
#include <numeric>
#include <cmath>
#include <map>
using namespace std;
typedef long long ll;
typedef vector<int> vi;
typedef vector<ll> vl;
typedef vector<vi> vvi;
typedef vector<double> vd;
typedef pair<int, int> pii;
typedef pair<double, double> pdd;
typedef vector<pii> vii;

int main() {
    int T, n;
    cin >> T;
    for (int test = 1; test <= T; ++test) {
        cin >> n;
        vd s(n);
        double sum = 0;
        for (int i = 0; i < n; ++i) {
            scanf("%lf", &s[i]);
            sum += s[i];
        }
        cout << "Case #" << test << ":";
        for (int i = 0; i < n; ++i) {
            double l = 0, r = 1;
            while (r - l > 1e-8) {
                double x = (r + l) / 2.;
                double cur = s[i] + x * sum;
                double rem = 0;
                for (int j = 0; j < n; ++j) if (j != i && s[j] < cur) {
                    rem += (cur - s[j]) / sum;
                }
                if (rem > 1 - x)
                    r = x;
                else l = x;
            }
            printf(" %.8lf", (l + r) * 50.);
        }
        cout << endl;
    }
    return 0;
}
