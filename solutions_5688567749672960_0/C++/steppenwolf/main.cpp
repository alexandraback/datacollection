#include <iostream>
#include <sstream>
#include <set>
#include <stack>
#include <vector>
#include <algorithm>
#include <string.h>
using namespace std;

const long long base = 10;

long long pw(long long x, int y) {
    long long res = 1;
    for (int i = 0; i < y; ++i) {
        res *= x;
    }

    return res;
}

int main()
{
    int T;
    cin >> T;

    for (int testcase = 1; testcase <= T; ++testcase) {
        long long p, res;
        string s;
        cin >> s;

        stringstream ss(s);
        ss >> p;

        int len = s.size();
        res = p;

        long long tobase = 0;
        for (int i = 1; i < len; ++i) {
            tobase += pw(base, i / 2) + pw(base, (i + 1) / 2) - 1;
        }

        if (len > 1) {
            res = min(res, tobase + p - pw(base, len - 1));
        }

        long long r = p;
        for (int pref = 0; pref + 1 < len; ++pref) {
            string ps;
            long long v, suff;

            stringstream suffss(s.substr(pref + 1));
            suffss >> suff;

            if (s[pref] == '0' || !suff) {
                stringstream ss1(s.substr(0, pref + 1));
                long long t;
                ss1 >> t;
                t--;

                while (t) {
                    ps.push_back('0' + (t % 10));
                    t /= 10;
                }

                stringstream ss(ps);
                ss >> v;

                r = min(r, tobase + v + pw(base, len - 1 - pref));
            }
            else {
                ps = s.substr(0, pref + 1);
                reverse(ps.begin(), ps.end());
                stringstream ss(ps);
                ss >> v;
                r = min(r, tobase + v + suff);
            }
        }

        cout << "Case #" << testcase << ": " << min(res, r) << endl;
    }

    return 0;
}
