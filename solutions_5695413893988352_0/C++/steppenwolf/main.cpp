#include <iostream>
#include <sstream>
#include <set>
#include <stack>
#include <vector>
#include <algorithm>
#include <string.h>
using namespace std;

int minDiff, score1, score2;
string so[2];
string s[2];
string scores[2];
int len;

int toDec(const string& s)
{
    int r = 0;

    for (int i = 0; i < s.size(); ++i) {
        r = r * 10 + s[i] - '0';
    }

    return r;
}

void solve(int ind = 0, int lev = 0)
{
    if (lev == len) {
        if (ind) {
            int d1 = toDec(so[0]), d2 = toDec(so[1]);
            int diff = abs(d1 - d2);
            if (diff < minDiff || (diff == minDiff && d1 < score1) || (diff == minDiff && d1 == score1 && d2 < score2)) {
                minDiff = diff, score1 = d1, score2 = d2;
                scores[0] = so[0];
                scores[1] = so[1];
            }
        }
        else {
            solve(1);
        }
    }
    else {
        for (int d = '0'; d <= '9'; ++d) {
            if (s[ind][lev] == '?' || s[ind][lev] == d) {
                so[ind][lev] = d;
                solve(ind, lev + 1);
            }
        }
    }
}

int main()
{
    int T;
    cin >> T;

    cout.setf(ios::fixed, ios::floatfield);
    cout.precision(6);

    for (int test = 1; test <= T; ++test) {
        minDiff = 10000;
        cin >> s[0] >> s[1];

        len = s[0].size();

        so[0] = s[0], so[1] = s[1];
        solve();

        cout << "Case #" << test << ": " << scores[0] << " " << scores[1] << endl;
    }

    return 0;
}
