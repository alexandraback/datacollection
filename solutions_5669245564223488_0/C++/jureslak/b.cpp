#include <vector>
#include <iostream>
#include <algorithm>
#include <string>
#include <cstring>
#include <map>

using namespace std;

bool valid(const vector<string>& s) {
    int l[26];
    memset(l, 0, sizeof l);
    char p = '1';
    for (int i = 0; i < s.size(); ++i) {
        for (int j = 0; j < s[i].size(); ++j) {
            if (p != s[i][j]) {
                p = s[i][j];
                if (l[p-'a'] > 0) return false;
                l[p-'a'] = 1;
            }
        }
    }
    return true;
}



int main() {
    int t, n;
    cin >> t;

    for (int tt = 1; tt <= t; ++tt) {
        map<string, int> c;
        cin >> n;
        vector<string> s(n);
        for (int i = 0; i < n; ++i) {
            cin >> s[i];
            c[s[i]]++;
        }

        sort(s.begin(), s.end());
        int r = 0;
        do {
            if (valid(s)) r++;
        } while (next_permutation(s.begin(), s.end()));

        for (auto& i : c) {
            r *= i.second;
        }

        cout << "Case #" << tt << ": " << r << endl;

    }
    return 0;
}

