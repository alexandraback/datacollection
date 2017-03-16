#include <bits/stdc++.h>

using namespace std;

void solve() {
    string s;
    cin >> s;
    string t = "";
    for (char x : s) {
        if (t.size() == 0) {
            t += string(1, x);
        } else {
            if (t[0] > x) {
                t += string(1, x);
            } else {
                t = string(1, x) + t;
            }
        }
    }
    cout << t << endl;
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