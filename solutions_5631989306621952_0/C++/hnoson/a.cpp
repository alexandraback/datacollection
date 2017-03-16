#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

#define RREP(i,s,e) for (i = s; i >= e; i--)
#define rrep(i,n) RREP(i,n,0)
#define REP(i,s,e) for (i = s; i < e; i++)
#define rep(i,n) REP(i,0,n)
#define INF 100000000

typedef long long ll;

int main() {
    int i, t;
    cin >> t;
    rep (i,t) {
        string s, rest;
        cin >> s;
        cout << "Case #" << i+1 << ": ";
        for (auto p = s.rbegin(); p != s.rend(); p++) {
            auto c = *max_element(p,s.rend());
            if (c == *p)
                cout << c;
            else
                rest.push_back(*p);
        }
        reverse(rest.begin(),rest.end());
        cout << rest << endl;
    }
    return 0;
}

