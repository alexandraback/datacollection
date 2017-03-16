#include <iostream>
#include <vector>
#include <algorithm>
#include <cstdlib>
#include <cmath>
using namespace std;

long long solve_dumb(int e, int r, const vector<int> &v, int cure, int pos) {
    if (pos == v.size()) {
        return 0;
    }
    long long maxe = -1;
    for (int i = 0; i <= cure; i++) {
        maxe = max(maxe, solve_dumb(e, r, v, min(e, cure - i + r), pos + 1) + v[pos] * i);
    }
    return maxe;
}

long long solveft(long long e, long long r, const vector<int> &v, int from, int to, long long frome, long long toe) {
    if (from == to) {
        return 0;
    }
    // std::cerr << "from " << from << " to " << to << endl;
    // std::cerr << "frome " << frome << " toe " << toe << endl;
    long long maxi = distance(v.begin(), max_element(v.begin() + from, v.begin() + to));
    // std::cerr << "maxi " << maxi << endl;
    long long maxe = min(e, frome + r * (maxi - from));
    // std::cerr << "maxe " << maxe << endl;
    long long leave = max(0ll, toe - r * (to - maxi)); // TODO CHECK CAREFULLY
    // std::cerr << "leave " << leave << endl;
    long long ans = (maxe - leave) * v[maxi];
    // std::cerr << "ans " << ans << endl;
    // cerr << endl;
    ans += solveft(e, r, v, from, maxi, frome, max(0ll, maxe));
    ans += solveft(e, r, v, maxi + 1, to, min(e, leave + r), toe);
    return ans;
}

int main() {
    int t;
    cin >> t;
    for (int test = 0; test < t; test++) {
        int e, r, n;
        cin >> e >> r >> n;
        vector<int> v(n);
        for (int i = 0; i < n; i++) {
            cin >> v[i];
        }
        // long long ans2 = solve_dumb(e, r, v, e, 0);
        // std::cerr << "Dumb: " << ans2 << endl;
        long long ans = solveft(e, r, v, 0, n, e, 0);
        cout << "Case #" << test + 1 << ": " << ans << endl;
    }
    return 0;
}