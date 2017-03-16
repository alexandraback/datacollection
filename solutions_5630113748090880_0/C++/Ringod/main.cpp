#include <bits/stdc++.h>

using namespace std;

void solve() {
    int n;
    cin >> n;
    vector < bool > used(2 * n - 1, false);
    vector < vector <int> > v(2 * n - 1, vector <int>(n, 0));
    vector < vector <int> > f(n, vector <int> (n, 0));
    vector <int> h(3000, 0);
    for (int i = 0; i < 2 * n - 1; ++i) {
        for (int j = 0; j < n; ++j) {
            cin >> v[i][j];
            h[v[i][j]]++;
        }
    }
    vector <int> res;
    for (int j = 0; j < h.size(); ++j) {
        if (h[j] % 2 != 0) {
            res.push_back(j);
        }
    }
    sort(res.begin(), res.end());
    for (int x : res) {
        cout << x << " ";
    }
    cout << endl;
}


int main() {
#ifdef ALEXEY
    freopen("/home/alexey/Projects/ClionAcm/input", "r", stdin);
    freopen("/home/alexey/Projects/ClionAcm/output", "w", stdout);
#else
    std::ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.setf(std::ios_base::fixed);
    cout.precision(28);
#endif
    int t;
    cin >> t;
    for (int i = 0; i < t; ++i) {
        cout << "Case #" << i + 1 << ": ";
        solve();
    }
#ifdef ALEXEY
    fprintf(stderr, "Time: %.18lf\n", (double)clock() / CLOCKS_PER_SEC);
    fclose(stdin);
    fclose(stdout);
#endif
    return 0;
}