#include <bits/stdc++.h>

using namespace std;

namespace {

    typedef double real;
    typedef long long ll;

    template<class T> ostream& operator<<(ostream& os, const vector<T>& vs) {
        if (vs.empty()) return os << "[]";
        os << "[" << vs[0];
        for (int i = 1; i < vs.size(); i++) os << " " << vs[i];
        return os << "]";
    }
    template<class T> istream& operator>>(istream& is, vector<T>& vs) {
        for (auto it = vs.begin(); it != vs.end(); it++) is >> *it;
        return is;
    }

    int N;
    vector<string> A, B;
    void input() {
        A.clear(); B.clear();
        cin >> N;
        A.resize(N); B.resize(N);
        for (int i = 0; i < N; i++) {
            cin >> A[i] >> B[i];
        }
    }

    bool check(int bit) {
        for (int i = 0; i < N; i++) {
            if (not (bit & (1 << i))) {
                bool a = false, b = false;
                for (int j = 0; j < N; j++) {
                    if (not (bit & (1 << j))) continue;
                    if (A[i] == A[j]) a = true;
                    if (B[i] == B[j]) b = true;
                }
                if ((not a) || (not b)) return false;
            }
        }
        return true;
    }

    void solve() {
        int ans = N;
        for (int bit = 0; bit < (1 << N); bit++) {
            if (check(bit)) {
                ans = min(ans, __builtin_popcount(bit));
            }
        }
        cout << N - ans << endl;
    }
}

int main() {
    int T; cin >> T;
    for (int t = 1; t <= T; t++) {
        input();
        cout << "Case #" << t << ": ";
        solve();
    }
    return 0;
}

