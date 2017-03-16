#include <iostream>
#include <sstream>
#include <string>
#include <cstring>
#include <vector>
#include <map>
#include <set>
#include <algorithm>
using namespace std;

#define REP(i,n) for(int i=0;i<(n);++i)
#define FOR(i,a,b) for(int i=(a);i<=(b);++i)
#define RFOR(i,a,b) for(int i=(a);i>=(b);--i)
typedef long long LL;

void run() {
    int n;
    cin >> n;
    vector<pair<string, string> > vp(n);
    REP(i, n) {
        string s1, s2;
        cin >> s1 >> s2;
        vp[i] = make_pair(s1, s2);
    }

    int res = 0;
    RFOR(st, (1 << n) - 1, 1) {
        set<string> s1, s2;
        int cnt = 0;

        REP(i, n) {
            if (st & (1 << i)) {
                ++cnt;
            }
            else {
                s1.insert(vp[i].first);
                s2.insert(vp[i].second);
            }
        }
        if (cnt <= res) continue;
        bool ok = true;
        REP(i, n) {
            if (st & (1 << i)) {
                if (s1.find(vp[i].first) == s1.end()) {
                    ok = false;
                    break;
                }
                if (s2.find(vp[i].second) == s2.end()) {
                    ok = false;
                    break;
                }
            }
        }
        if (ok) res = cnt;
    }

    cout << res << endl;
}

int main() {
    int k;
    cin >> k;
    FOR(c,1,k) {
        cout << "Case #" << c << ": ";
        run();
    }
    return 0;
}
