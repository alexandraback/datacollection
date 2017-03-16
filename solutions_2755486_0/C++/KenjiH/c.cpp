#include <algorithm>
#include <iostream>
#include <climits>
#include <list>
#include <map>
#include <cmath>
#include <queue>
#include <set>
#include <sstream>
#include <stack>
#include <cstdio>
#include <string>
#include <cstring>
#include <vector>
#include <numeric>

using namespace std;

#define REP(i,n) for(int i=0; i<(int)(n); i++)
#define FOR(i,b,e) for (int i=(int)(b); i<(int)(e); i++)
#define EACH(itr,c) for(__typeof((c).begin()) itr=(c).begin(); itr!=(c).end(); itr++)  


int day[10];  // first attack day
int num[10];  // number of attacks
int west[10];
int east[10];
int strength[10];  // strength of first attack
int seq[10];      // number of days bettwen attacks
int move[10];
int diff[10];     // strength change
long long h[6000];

struct attack {
    long long s;
    long long t;
    long long pw;
};

bool check(int s, int t, long long pw) {
    s *= 2;
    t *= 2;
    s += 3000;
    t += 3000;
    for (int i = s; i < t; i++)
        if (h[i] < pw)
            return true;
    return false;
}

void update(int s, int t, long long pw) {
    s *= 2;
    t *= 2;
    s += 3000;
    t += 3000;
    for (int i = s; i < t; i++)
        h[i] = max(h[i], pw);
}

void solve() {
    int N;
    cin >> N;
    REP (i, N) {
        cin >> day[i];
        cin >> num[i];
        cin >> west[i];
        cin >> east[i];
        cin >> strength[i];
        cin >> seq[i];
        cin >> move[i];
        cin >> diff[i];
    }

    map<long long, vector<attack> > mp;   // day -> attack
    REP (i, N) {
        long long d = day[i];
        long long s = west[i];
        long long t = east[i];
        long long pw = strength[i];
        REP (j, num[i]) {
            mp[d].push_back((attack){s, t, pw});
            d += seq[i];
            s += move[i];
            t += move[i];
            pw += diff[i];
        }
    }

    int ret = 0;
    memset(h, 0, sizeof(h));

    EACH (itr, mp) {
        vector<attack> &v = itr->second;
        REP (i, v.size()) {
            long long s = v[i].s;
            long long t = v[i].t;
            long long pw = v[i].pw;

            if (check((int)s, (int)t, pw))
                ++ret;
        }

        // update
        REP (i, v.size()) {
            long long s = v[i].s;
            long long t = v[i].t;
            long long pw = v[i].pw;

            update((int)s, (int)t, pw);
        }
    }

    cout << ret << endl;
}

int main() {
    int T;
    cin >> T;

    REP (i, T) {
        printf("Case #%d: ", i+1);
        solve();
    }
    return 0;
}
