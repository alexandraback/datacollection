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

bool canBe(string &a, string &b) {
    bool ok = 1;
    for (int i = 0; i < a.size(); ++i) {
        if (a[i] == b[i] || a[i] == '?' || b[i] == '?') {
            continue;
        }
        ok = 0;
    }
    return ok;
}

int main() {
    int T, N;
    string s, t;
    cin >> T;
    for (int _test = 1; _test <= T; ++_test) {
        cout << "Case #" << _test << ": ";
        cin >> s >> t;
        string a, b, _a, _b;
        int diff = 1000;
        N = s.size();
        for (int i = 0; i < 1000; ++i) {
            stringstream X; X << i; X >> a;
            if (a.size() > s.size()) break;
            while (a.size() < s.size()) a = '0' + a;
            if (!canBe(s, a)) continue;
            for (int j = 0; j < 1000; ++j) {
                stringstream Y; Y << j; Y >> b;
                if (b.size() > t.size()) break;
                while (b.size() < t.size()) b = '0' + b;
                if (!canBe(t, b)) continue;

                if (abs(i - j) < diff) {
                    diff = abs(i - j);
                    _a = a; _b = b;
                }
            }
        }
        cout << _a << " " << _b << "\n";
    }
    return 0;
}