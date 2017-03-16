#include <cstdio>
#include <cstdlib>
#include <iostream>
#include <algorithm>
#include <set>
#include <vector>
#include <cstring>
#include <string>
using namespace std;

string stringGenome(string s) {
    string ideal_str = "";
    for (int i = 0; i < s.size(); i++) {
        if (ideal_str.size() == 0) {
            ideal_str += s[i];
        }
        else {
            int sz = ideal_str.size();
            if (s[i] == ideal_str[sz - 1]) ;
            else ideal_str += s[i];
        }
    }
    return ideal_str;
}

int main() {
    freopen("input.txt", "rt", stdin);
    freopen("output.txt", "wt", stdout);

    int tests;
    cin >> tests;
    for (int i = 1; i <= tests; i++) {
        int n; cin >> n;
        string s[105];
        for (int j = 0; j < n; j++) cin >> s[j];
        int answer = 0;
        int cnt[105][105];
        memset(cnt, 0, sizeof(cnt));
        for (int j = 0; j < n; j++) {
            int count = 1;
            int sz = 0;
            for (int k = 1; k < s[j].size(); k++) {
                if (s[j][k] == s[j][k - 1]) count++;
                else {
                    cnt[j][sz++] = count;
                    count = 1;
                }
            }
            cnt[j][sz++] = count;
            s[j] = stringGenome(s[j]);
        }
        for (int j = 1; j < n; j++) {
            if (s[j] != s[j - 1])
                answer = -1;
        }
        if (answer >= 0) {
            for (int j = 0; j < 105; j++) {
                int mn = 1e9;
                for (int k = 0; k < 505; k++) {
                    int need = 0;
                    for (int e = 0; e < n; e++) {
                        need += abs(cnt[e][j] - k);
                    }
                    mn = min(mn, need);
                }
                answer += mn;
            }
        }

        if (answer == -1) {
            cout << "Case #" << i << ": " << "Fegla Won" << endl;
            cout.flush();
        }
        else {
            cout << "Case #" << i << ": " << answer << endl;
            cout.flush();
        }
    }

    return 0;
}
