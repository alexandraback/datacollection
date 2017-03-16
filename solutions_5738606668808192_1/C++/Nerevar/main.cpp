#include <iostream>
#include <cstdio>
#include <string.h>
#include <algorithm>
#include <vector>
#include <string>
#include <queue>
#include <stack>
#include <set>
#include <map>
#include <sstream>
#include <cmath>

typedef long long ll;

#define forn(i, n) for (int i = 0; i < (int)(n); i++)
#define forv(i, v) forn(i, v.size())

using namespace std;



int rem(const string& s, int d, int base) {
    int r = 0;
    forv(i, s) {
        r = (r * base + s[i] - '0') % d;
    }
    return r;
}

vector<int> isJam(string s) {
    vector<int> result;
    for (int base = 2; base <= 10; base++) {
        bool ok = false;
        for (int d = 2; d <= 1000; d++) {
            if (rem(s, d, base) == 0) {
                ok = true;
                result.push_back(d);
                break;
            }
        }
        if (!ok) return vector<int>();
    }
    return result;
}

void gen(int n, int count) {
    map<string, vector<int> > jam;
    int it = 0;
    while ((int)jam.size() < count) {
        it++;
        if (it % 1000 == 0) {
            cerr << it << " " << jam.size() << endl;
        }
        string s = "1";
        forn(i, n - 2) s += char('0' + rand() % 2);
        s += '1';
        vector<int> r = isJam(s);
        if (!r.empty()) {
            jam[s] = r;
        }
    }
    for (auto p : jam) {
        cout << p.first;
        for (int d : p.second) {
            cout << " " << d;
        }
        cout << endl;
    }
}

void solveCase(int tc) {
    printf("Case #%d:\n", tc);
    cerr << tc << endl;
    int n, count;
    cin >> n >> count;
    gen(n, count);
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    //gen(16, 50);
    //gen(32, 500);
    int tc; cin >> tc;
    forn(it, tc) solveCase(it + 1);
    return 0;
}
