#include <cmath>
#include <ctime>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cassert>
#include <climits>
#include <map>
#include <set>
#include <queue>
#include <deque>
#include <stack>
#include <bitset>
#include <vector>
#include <sstream>
#include <iostream>
#include <algorithm>
#include <unordered_map>

using namespace std;

#pragma comment(linker, "/STACK:64000000")

#define f first
#define s second
#define mp make_pair
#define pb push_back
#define sqr(x) ((x) * (x))
#define sz(v) (int)(v).size()
#define all(v) (v).begin(), (v).end()

typedef long long ll;
typedef long double ld;
typedef vector <int> vi;
typedef pair <int, int> pii;

string s, t;
int d = INT_MAX;
string x, y;

int get(const string &s) {
    int res = 0;
    for (int i = 0; i < sz(s); i++) {
        res  = res * 10 + (s[i] - '0');
    }
    return res;
}

void rec(int v) {
    if (v == sz(s) + sz(t)) {
//        cout << s << " " << t << "\n";
        int a = get(s);
        int b = get(t);
        int cur = abs(a - b);
        if (cur < d) {
            d = cur;
            x = s;
            y = t;
        }
    } else {
        if (v < sz(s)) {
            if (s[v] == '?') {
                for (char ch = '0'; ch <= '9'; ch++) {
                    s[v] = ch;
                    rec(v + 1);
                }
                s[v] = '?';
            } else {
                rec(v + 1);
            }
        } else {
            int p = v - sz(s);
            if (t[p] == '?') {
                for (char ch = '0'; ch <= '9'; ch++) {
                    t[p] = ch;
                    rec(v + 1);
                }
                t[p] = '?';
            } else {
                rec(v + 1);
            }
        }
    }
}

int main() {
    freopen("/Users/nurlan/Dropbox/Programming/contest/contest/input", "r", stdin);
    freopen("/Users/nurlan/Dropbox/Programming/contest/contest/output", "w", stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int tests;
    cin >> tests;
    for (int test = 1; test <= tests; test++) {
        cout << "Case #" << test << ": ";
        cin >> s >> t;
        d = INT_MAX;
        rec(0);
        cout << x << " " << y;
        cout << "\n";
    }
    return 0;
}