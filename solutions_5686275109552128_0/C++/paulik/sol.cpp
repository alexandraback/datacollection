#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

int solve(const vector<int>& p) {
    int max_p = *max_element(p.begin(), p.end());

    int result = max_p;
    for (int h = 1; h <= max_p; ++h) {
        int cost = h;
        for (int p_val : p)
            cost += (p_val - 1) / h;
        result = min(result, cost);
    }
    return result;
}

int main() {
    int tests;
    cin >> tests;
    for (int t = 1; t <= tests; ++t) {
        int d;
        cin >> d;
        vector<int> p(d);
        for (int i = 0; i != d; ++i)
            cin >> p[i];

        cout << "Case #" << t << ": " << solve(p) << '\n';
    }

    return 0;
}

