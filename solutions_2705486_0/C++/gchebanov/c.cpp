#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cassert>
#include <vector>

#define fore(i,a,b) for(int i = (int)(a); i <= (int)(b); ++i)
#define forn(i, n) for(int i = 0; i < (int)(n); ++i)

using namespace std;

typedef long long i64;
typedef long double ld;

const int maxn = 5000;

vector<string> S;

void init() {
    FILE* f = fopen("slovar.txt", "r");
    char s[200];
    while( fscanf(f, "%s", s) == 1 ) {
        string _s(s);
        S.push_back(s);
    }
    fclose(f);
}

int a[100500];

int dist(string s, string t) {
    int ans = 0;
    forn(i, min(s.length(), t.length())) {
        ans += s[i] != t[i];
    }
    return ans;
}

int p[100500];
int v[100500];

string s;

void f(int i) {
    if( i > 0 ) {
        int l = S[p[i]].length();
        f(i - l);
        cerr << S[p[i]] << '(' << s.substr(i - l, l) << ')';
    }
}


int solve() {
    int n = s.length();
    forn(i, n + 1) a[i] = 100500;
    a[0] = 0;
    forn(i, n + 1) if(i) {
        forn(j, S.size() ) {
            int l = S[j].length();
            if( l <= i && a[i] > a[i-l] ) {
                int t = dist(S[j], s.substr(i - l, l));
                if( t + a[i - l] < a[i] ) {
                    a[i] = t + a[i-l];
                    p[i] = j;
                    v[i] = t;
                }
            }
        }
    }
    f(n);
    cerr << '\n';
    return a[n];
}

int main() {
    init();
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    int T;
    cin >> T;
    cout << fixed;
    cout.precision(8);
    forn(_t, T) {
        cin >> s;
        cerr << _t << '\n';
        cout << "Case #" << _t + 1 << ": " << solve() << '\n';
    }
    return 0;
}
