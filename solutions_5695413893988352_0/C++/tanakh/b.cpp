#include <iostream>
#include <iomanip>
#include <algorithm>
#include <string>
#include <vector>
#include <map>
#include <set>
#include <cstdio>
#include <cstring>
#include <sstream>
using namespace std;

string c, j;

int64_t rec(int cur, int up)
{
    if (cur >= c.size()) return 0;
    char x = c[cur];
    char y = j[cur];

    int64_t keta = 1;
    for (int i = 0; i < c.size() - 1 - cur; i++) keta *= 10;

    if (up != 0) {
        if (up == -1) {
            if (x == '?') x = '9';
            if (y == '?') y = '0';
        }
        else {
            if (x == '?') x = '0';
            if (y == '?') y = '9';
        }

        int64_t v = rec(cur + 1, up);
        return (x - y) * keta + v;
    }

#define v0 abs(rec(cur + 1, 0))
#define v1 abs(1 * keta + rec(cur + 1, 1))
#define v2 abs(-1 * keta + rec(cur + 1, -1))

    if (x == '?' && y == '?') {
        return min(v0, min(v1, v2));
    }
    if (x == '?') {
        if (y == '9') return min(v0, v2);
        if (y == '0') return min(v0, v1);
        return min(v0, min(v1, v2));
    }
    if (y == '?') {
        if (x == '9') return min(v0, v1);
        if (x == '0') return min(v0, v2);
        return min(v0, min(v1, v2));
    }
    if (x < y) return abs((x - y) * keta + rec(cur + 1, -1));
    if (x > y) return abs((x - y) * keta + rec(cur + 1, 1));
    return abs(rec(cur + 1, 0));
}

int ket(int i, int k)
{
    while (k--) {
        i /= 10;
    }
    return i % 10;
}

void bf()
{
    int nc, nj;
    {
        istringstream iss(c); iss >> nc;
    }
    {
        istringstream iss(j); iss >> nj;
    }

    int mind = 9999;
    pair<int, int> ans(1000, 1000);

    int mx = 1;
    for (int i = 0; i < c.size(); i++) mx *= 10;

    for (int i = 0; i < mx; i++) {
        for (int j_ = 0; j_ < mx; j_++) {
            bool mc = true, mj = true;

            for (int k = 0; k < c.size(); k++) {
                if (c[k]== '?') continue;
                if (c[k] - '0' != ket(i, c.size() - 1 - k)) mc = false;
            }
            for (int k = 0; k < j.size(); k++) {
                if (j[k]== '?') continue;
                if (j[k] - '0' != ket(j_, j.size() - 1 - k)) mj = false;
            }

            if (!(mc && mj)) continue;


            if (abs(i - j_) < mind || (abs(i - j_) == mind && make_pair(i, j_) < ans)) {
                mind = abs(i - j_);
                ans = make_pair(i, j_);
            }
        }
    }

    for (int i = 0; i < c.size(); i++) {
        cout << ket(ans.first, c.size() - 1 - i);
    }
    cout << " ";
    for (int i = 0; i < c.size(); i++) {
        cout << ket(ans.second, c.size() - 1 - i);
    }
    cout << endl;
}

void solve()
{
    cin >> c >> j;

    // bf(); return;

    for (int i = 0; i < c.size(); i++) {
        int64_t mina = 0x7fffffffffffffffULL;
        char minc;
        char cc = c[i];

        for (char d = '0'; d <= '9'; d++) {
            if (cc != '?' && cc != d) continue;
            c[i] = d;

            int64_t t = rec(0, 0);

            // cout << c << " " << j << ": " << t << endl;

            if (t < mina) {
                mina = t;
                minc = d;
            }
        }

        c[i] = minc;
    }

    for (int i = 0; i < j.size(); i++) {
        int64_t mina = 0x7fffffffffffffffULL;
        char minc;
        char cc = j[i];

        for (char d = '0'; d <= '9'; d++) {
            if (cc != '?' && cc != d) continue;
            j[i] = d;

            int64_t t = rec(0, 0);

            // cout << c << " " << j << ": " << t << endl;

            if (t < mina) {
                mina = t;
                minc = d;
            }
        }

        j[i] = minc;
    }

    cout << c << " " << j << endl;
}

int main()
{
    int t; cin >> t;
    for (int cn = 1; cn <= t; cn++) {
        cout << "Case #" << cn << ": ";
        solve();
    }
    return 0;
}