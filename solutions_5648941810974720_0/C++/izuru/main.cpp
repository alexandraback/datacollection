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

    string s;
    void input() {
        s.clear();
        cin >> s;
    }

    void solve() {
        map<char, int> M;
        for (int i = 0; i < s.size(); i++) {
            char c = s[i];
            M[c]++;
        }

        map<int, int> X;
        X[0] += M['Z'];
        X[2] += M['W'];
        X[4] += M['U']; M['F'] -= M['U'];
        X[5] += M['F']; M['V'] -= M['F']; M['I'] -= M['F'];
        X[6] += M['X']; M['I'] -= M['X'];
        X[7] += M['V']; M['N'] -= M['V'];
        X[8] += M['G']; M['I'] -= M['G']; M['H'] -= M['G'];
        X[9] += M['I']; M['N'] -= M['I'] * 2;
        X[1] += M['N'];
        X[3] += M['H'];

        string ans;
        for (int i = 0; i <= 9; i++) {
            for (int j = 0; j < X[i]; j++) {
                ans.push_back(char(i + '0'));
            }
        }
        cout << ans << endl;
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

