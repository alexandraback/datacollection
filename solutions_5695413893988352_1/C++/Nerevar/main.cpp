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

ll toLL(string s) {
    istringstream in(s);
    ll res;
    in >> res;
    return res;
}

string toString(ll v, int n) {
    ostringstream out;
    out << v;
    string res = out.str();
    while (res.size() < n) res = "0" + res;
    return res;
}

string makeSmallest(string s) {
    forv(i, s) if (s[i] == '?') s[i] = '0';
    return s;
}

string makeLargest(string s) {
    forv(i, s) if (s[i] == '?') s[i] = '9';
    return s;
}

bool better(ll x1, ll y1, ll x2, ll y2) {
    ll d1 = abs(x1 - y1);
    ll d2 = abs(x2 - y2);
    if (d1 != d2) return d1 < d2;
    if (x1 != x2) return x1 < x2;
    return y1 < y2;
}

void solveCase(int tc) {
    printf("Case #%d: ", tc);
    cerr << tc << endl;
    string s, t;
    cin >> s >> t;
    int n = (int)s.size();
    
    ll bestX = -1, bestY = 1e18;
    
    forn(i, n) {
        ll x, y;
        if (s[i] == '?' && t[i] == '?') {
            s[i] = '1';
            t[i] = '0';
            x = toLL(makeSmallest(s));
            y = toLL(makeLargest(t));
            if (better(x, y, bestX, bestY)) {
                bestX = x;
                bestY = y;
            }
            s[i] = '0';
            t[i] = '1';
            x = toLL(makeLargest(s));
            y = toLL(makeSmallest(t));
            if (better(x, y, bestX, bestY)) {
                bestX = x;
                bestY = y;
            }
            s[i] = t[i] = '0';
        } else if (s[i] == '?') {
            if (t[i] > '0') {
                s[i] = t[i] - 1;
                x = toLL(makeLargest(s));
                y = toLL(makeSmallest(t));
                if (better(x, y, bestX, bestY)) {
                    bestX = x;
                    bestY = y;
                }
            }
            if (t[i] < '9') {
                s[i] = t[i] + 1;
                x = toLL(makeSmallest(s));
                y = toLL(makeLargest(t));
                if (better(x, y, bestX, bestY)) {
                    bestX = x;
                    bestY = y;
                }
            }
            
            s[i] = t[i];
        } else if (t[i] == '?') {
            if (s[i] > '0') {
                t[i] = s[i] - 1;
                x = toLL(makeSmallest(s));
                y = toLL(makeLargest(t));
                if (better(x, y, bestX, bestY)) {
                    bestX = x;
                    bestY = y;
                }
            }
            if (s[i] < '9') {
                t[i] = s[i] + 1;
                x = toLL(makeLargest(s));
                y = toLL(makeSmallest(t));
                if (better(x, y, bestX, bestY)) {
                    bestX = x;
                    bestY = y;
                }
            }
            
            
            t[i] = s[i];
        } else if (s[i] < t[i]) {
            x = toLL(makeLargest(s));
            y = toLL(makeSmallest(t));
            if (better(x, y, bestX, bestY)) {
                bestX = x;
                bestY = y;
            }
            break;
        } else if (s[i] > t[i]) {
            x = toLL(makeSmallest(s));
            y = toLL(makeLargest(t));
            if (better(x, y, bestX, bestY)) {
                bestX = x;
                bestY = y;
            }
            break;
        }
    }
    
    ll x = toLL(makeSmallest(s));
    ll y = toLL(makeLargest(t));
    if (better(x, y, bestX, bestY)) {
        bestX = x;
        bestY = y;
    }
    
    cout << toString(bestX, n) << " " << toString(bestY, n) << endl;
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    int tc; cin >> tc;
    forn(it, tc) solveCase(it + 1);
    return 0;
}
