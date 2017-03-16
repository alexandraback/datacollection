#include <vector>
#include <list>
#include <map>
#include <set>
#include <queue>
#include <deque>
#include <stack>
#include <bitset>
#include <algorithm>
#include <functional>
#include <numeric>
#include <utility>
#include <sstream>
#include <iostream>
#include <iomanip>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <ctime>
#include <limits>
#include <string>
#include <cassert>

using namespace std;

#define all(X) (X).begin(), (X).end()

typedef long long LL;
typedef pair<int, int> PII;
typedef vector<int> VI;
typedef vector<VI> VVI;

const int mod = 1e9 + 7;
const int maxn = 100001;

string a, b, s, t;
int N;
LL res;

void solve(int pos, LL diff) {
    if (pos == N) {
        if (abs(diff) < res || (abs(diff) == res && (s < a || (s == a && t < b)))) {
            res = abs(diff);
            a = s;
            b = t;
        }
        return;
    }
    char _s = s[pos], _t = t[pos];
    if (s[pos] != '?' && t[pos] != '?') {
        solve(pos + 1, diff * 10 + (s[pos] - t[pos]));
    } else {
        if (diff > 0) {
            if (s[pos] == '?') s[pos] = '0';
            if (t[pos] == '?') t[pos] = '9';
            solve(pos + 1, diff * 10 + (s[pos] - t[pos]));
        } else if (diff < 0) {
            if (s[pos] == '?') s[pos] = '9';
            if (t[pos] == '?') t[pos] = '0';
            solve(pos + 1, diff * 10 + (s[pos] - t[pos]));
        } else {
            if (s[pos] == '?' && t[pos] == '?') {
                s[pos] = '1'; t[pos] = '0';
                solve(pos + 1, diff * 10 + (s[pos] - t[pos]));

                s[pos] = '0'; t[pos] = '1';
                solve(pos + 1, diff * 10 + (s[pos] - t[pos]));

                s[pos] = '0'; t[pos] = '0';
                solve(pos + 1, diff * 10 + (s[pos] - t[pos]));
            } else if (s[pos] == '?') {
                s[pos] = min((char)(t[pos] + 1), '9');
                solve(pos + 1, diff * 10 + (s[pos] - t[pos]));

                s[pos] = max((char)(t[pos] - 1), '0');
                solve(pos + 1, diff * 10 + (s[pos] - t[pos]));

                s[pos] = t[pos];
                solve(pos + 1, diff * 10 + (s[pos] - t[pos]));
            } else {
                t[pos] = min((char)(s[pos] + 1), '9');
                solve(pos + 1, diff * 10 + (s[pos] - t[pos]));

                t[pos] = max((char)(s[pos] - 1), '0');
                solve(pos + 1, diff * 10 + (s[pos] - t[pos]));

                t[pos] = s[pos];
                solve(pos + 1, diff * 10 + (s[pos] - t[pos]));
            }
        }
    }
    s[pos] = _s; t[pos] = _t;
}

int main() {
    int T;
    cin >> T;
    for (int _test = 1; _test <= T; ++_test) {
        cout << "Case #" << _test << ": ";
        cerr << "On test:" << _test << "\n";
        cin >> s >> t;
        N = s.size();
        if (N == 1) {
            if (s[0] == '?' && t[0] == '?') {
                cout << "0 0\n";
            } else if (s[0] != '?' && t[0] == '?') {
                cout << s << " " << s << "\n";
            } else if (t[0] != '?' && s[0] == '?') {
                cout << t << " " << t << "\n";
            } else {
                cout << s << " " << t << "\n";
            }
        } else {
            for (int i = 0; i + 1 < N; ++i) {
                if (s[i] == t[i] && s[i] == '?') {
                    if (s[i + 1] == '?' && t[i + 1] == '?') {
                        s[i] = t[i] = '0';
                    } else {
                        break;
                    }
                }
            }
            a = string(1, (char)200);
            b = a;
            res = numeric_limits<LL>::max();
            solve(0, 0);
            cout << a << " " << b << "\n";
        }
    }
    return 0;
}