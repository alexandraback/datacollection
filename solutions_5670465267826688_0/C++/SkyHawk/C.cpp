#include <cassert>
#include <iostream>
#include <iomanip>
#include <cstdio>
#include <cstring>
#include <cmath>
#include <iterator>
#include <utility>
#include <algorithm>
#include <list>
#include <string>
#include <vector>
#include <map>
#include <set>
#include <queue>

using namespace std;

#define pb push_back
#define sz(v) ((long long)v.size())
#define mp make_pair
#define FOR(i,n) for(int i = 0;i < (n);++i)

long long MOD = 1000000007;

int T;

int mul(int l, char r) {
    int ml = (l > 0 ? l : -l);
    int s = (l > 0 ? 1 : -1);
    if (ml == '1') {
        return s * r;
    } else if (ml == 'i') {
        switch (r) {
            case 'i': return -'1' * s;
            case 'j': return 'k' * s;
            case 'k': return -'j' * s;
            default: assert(0);
        }
    } else if (ml == 'j') {
        switch (r) {
            case 'i': return -'k' * s;
            case 'j': return -'1' * s;
            case 'k': return 'i' * s;
            default: assert(0);
        }
    } else if (ml == 'k') {
        switch (r) {
            case 'i': return 'j' * s;
            case 'j': return -'i' * s;
            case 'k': return -'1' * s;
            default: assert(0);
        }
    } else {
        assert(0);
    }
}

int main() {
    cin >> T;
    FOR(itest, T) {
        int l, x;
        string s;
        cin >> l >> x;
        cin >> s;
        int t = '1';
        int ok1 = 0, ok2 = 0, ok3 = 0;
        for(int i = 0; i < l*x; ++i) {
            t = mul(t, s[i%l]);
            if (t == 'i') {
                ok1 = i+1;
                break;
            }
        }
        if (!ok1) {
            cout << "Case #" << (itest + 1) << ": " << "NO" << endl;
            continue;
        }
        t = '1';
        for(int i = ok1; i < l*x; ++i) {
            t = mul(t, s[i%l]);
            // cerr << i << " " << s[i%l] << " " << (char)t << endl;
            if (t == 'j') {
                ok2 = i+1;
                break;
            }
        }
        if (!ok2) {
            // cerr << ok2 << endl;
            cout << "Case #" << (itest + 1) << ": " << "NO" << endl;
            continue;
        }
        t = '1';
        for(int i = ok2; i < l*x; ++i) {
            t = mul(t, s[i%l]);
            if (t == 'k') {
                ok3 = i+1;
                break;
            }
        }
        if (!ok3) {
            cout << "Case #" << (itest + 1) << ": " << "NO" << endl;
            continue;
        }
        t = '1';
        for(int i = ok3; i < l*x; ++i) {
            t = mul(t, s[i%l]);
        }
        if (t != '1') {
            cout << "Case #" << (itest + 1) << ": " << "NO" << endl;
            continue;
        }
        cout << "Case #" << (itest + 1) << ": " << "YES" << endl;
    }
}