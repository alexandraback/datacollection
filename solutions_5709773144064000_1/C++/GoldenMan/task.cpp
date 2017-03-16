#include <iostream>
#include <vector>
#include <cstdio>

using namespace std;

const unsigned int MAX_FARMS = 1000000;

long double time(long double c, long double f, long double x, unsigned int farms, const vector<long double> &costs) {
    return costs[farms] + x / (2.0L + farms * f);
}

void solve(int t) {
    long double c, f, x;
    cin >> c >> f >> x;
    vector<long double> costs;
    costs.push_back(0.0);
    for (unsigned i = 0; i < MAX_FARMS; ++i) {
        costs.push_back(costs[i] + c / (2.0L + f * i));
    }
    unsigned int l_farms = 0;
    unsigned int r_farms = MAX_FARMS;
    unsigned int prev_diff = 0;
    while (r_farms - l_farms != prev_diff) {
        prev_diff = r_farms - l_farms;
        unsigned int m_farms_1 = (2 * l_farms + r_farms) / 3;
        unsigned int m_farms_2 = (l_farms + 2 * r_farms) / 3;
        long double ct1 = time(c, f, x, m_farms_1, costs);
        long double ct2 = time(c, f, x, m_farms_2, costs);
        if (ct1 > ct2) {
            l_farms = m_farms_1;
        } else {
            r_farms = m_farms_2;
        }
    }
    long double best = time(c, f, x, l_farms, costs);
    for (unsigned int i = l_farms + 1; i <= r_farms; ++i) {
        long double cur = time(c, f, x, i, costs);
        if (cur < best) {
            best = cur;
            if (i > MAX_FARMS / 2) {
                cerr << "PANIC!" << endl;
            }
        }
    }
    cout << "Case #" << t << ": ";
    cout.precision(16);
    cout << best << endl;
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    int t;
    cin >> t;
    for (int i = 0; i < t; ++i) {
        solve(i + 1);
        cerr << "Test #" << i + 1 << " solved." << endl;
    }
    return 0;
}
