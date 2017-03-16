#include <bits/stdc++.h>
using namespace std;

const int mul[5][5] = {
    {0,  0,  0,  0,  0},
    {0,  1,  2,  3,  4},
    {0,  2, -1,  4, -3},
    {0,  3, -4, -1,  2},
    {0,  4,  3, -2, -1}
};

int multiply(int x, int y) {
    if (x < 0) return -multiply(-x, y);
    if (y < 0) return -multiply(x, -y);
    return mul[x][y];
}

int calc(string s) {
    int result = 1;
    for (char c : s) result = multiply(result, c - 'i' + 2);
    return result;
}

int calc(string s, long long rep) {
    int foo = calc(s);
    map<int, int> met;
    met[1] = 0;
    int bar = 1;
    for (int i = 1; i <= rep; ++i) {
        bar = multiply(bar, foo);
        if (met.count(bar) == 1) return calc(s, (rep - met[bar]) % (i - met[bar]) + met[bar]);
        met[bar] = i;
    }
    return bar;
}

string multiply(string s, long long x) {
    string t;
    while (x-- > 0) t += s;
    return t;
}

string runTest() {
    int n; cin >> n;
    long long x; cin >> x;
    string s; cin >> s;
    if (calc(s, x) != -1) return "NO";
    x = min(x, 20LL);
    s = multiply(s, x);
    int foo = 1;
    for (int i = 0; i < (int) s.size(); ++i) {
        foo = multiply(foo, s[i] - 'i' + 2);
        if (foo == 2) {
            for (int j = i + 1; j < (int) s.size(); ++j) {
                foo = multiply(foo, s[j] - 'i' + 2);
                if (foo == 4) return "YES";
            }
            return "NO";
        }
    }
    return "NO";
}

int main() {
    ios::sync_with_stdio(false);
    int numTests; cin >> numTests;
    for (int test = 0; test < numTests; ++test) {
        cout << "Case #" << test + 1 << ": " << runTest() << '\n';
    }
    return 0;
}
