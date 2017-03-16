#include <iostream>
#include <string>
#include <algorithm>
#include <cmath>
#include <set>
#include <map>
#include <vector>
#include <bitset>
#include <cstdio>
#include <ctime>
#include <queue>

using namespace std;

set<char> FBD;

void precalc () {

}

bool valid (const string& s) {
    for (int i = 0; i < s.size(); ++i) {
        if (FBD.find(s[i]) != FBD.end()) {
            return false;
        }
    }

    set<char> f;
    for (int i = 1; i < s.size(); ++i) {
        if (s[i] != s[i - 1]) {
            f.insert(s[i - 1]);
        }
        if (f.find(s[i]) != f.end()) {
            return false;
        }
    }
    return true;
}

bool valid(const vector<string>& v) {
    string s;
    for (int i = 0; i < v.size(); ++i) {
        s += v[i];
        while ('0' <= *s.rbegin() && *s.rbegin() <= '9') {
            s.pop_back();
        }
    }
    return valid(s);
}

void solve () {
    FBD.clear();

    int n;
    cin >> n;

    vector<string> v(n);
    for (int i = 0; i < n; ++i) {
        cin >> v[i];

        if (!valid(v[i])) {
            cout << 0 << endl;
            return;
        }
        
        int x = v[i].size(), y = 0;
        for (int j = 1; j < v[i].size(); ++j) {
            if (v[i][j] != v[i][j - 1]) {
                x = min(x, j);
                y = max(y, j);
            }
        }

        for (int j = x; j < y; ++j) {
            FBD.insert(v[i][j]);
        }

        if (v[i][0] != v[i][v[i].size() - 1])
            v[i] = string(1, v[i][0]) + v[i][v[i].size() - 1];
        else
            v[i] = string(1, v[i][0]);

        char* buf = new char[10];
        v[i] += itoa(i, buf, 10);
    }
    sort(v.begin(), v.end());

    long long res = valid(v);
    while (next_permutation(v.begin(), v.end())) {
        res += valid(v);
    }
    cout << res % 1000000007LL << endl;
}

int main() {
	freopen("B-small-attempt2.in","r",stdin);
	freopen("output.txt","w",stdout);

  precalc();
    int t = clock();
	int T;
	cin >> T;
	for (int test = 1; test <= T; ++test) {
		cout << "Case #" << test << ": ";
    cerr << test << endl;
    solve();
	}
    cerr << (clock() - t) / 1000 << endl;
	return 0;
}
