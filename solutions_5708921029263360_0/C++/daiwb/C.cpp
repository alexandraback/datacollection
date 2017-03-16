#include <algorithm>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>
#include <queue>
#include <set>
#include <map>
#include <cstdio>
#include <cstdlib>
#include <cctype>
#include <cmath>
#include <string>
#include <cstring>
using namespace std;

#define REP(i,n) for(int i=0;i<(n);++i)
#define FOR(i,a,b) for(int i=(a);i<=(b);++i)
#define RFOR(i,a,b) for(int i=(a);i>=(b);--i)
typedef long long LL;

string i2s(int n) {
    stringstream ss;
    ss << n;
    string res;
    ss >> res;
    return res;
}

int J, P, S, K;
int res;
vector<string> out;

void isok(int st) {
    int idx = 0;
    map<int, int> mp[3];
    vector<string> tmp;
    FOR(i1, 1, J) {
        FOR(i2, 1, P) {
            FOR(i3,1, S) {
                if (st & (1 << idx)) {
                    int num[3] = { i1 * 10 + i2, i1 * 10 + i3, i2 * 10 + i3 };

                    tmp.push_back(i2s(i1) + " " + i2s(i2) + " " + i2s(i3));

                    REP(i, 3) {
                        if (mp[i].find(num[i]) == mp[i].end()) mp[i][num[i]] = 0;
                        mp[i][num[i]] += 1;
                        if (mp[i][num[i]] > K) {
                            return;
                        }
                    }
                }
                ++idx;
            }
        }
    }

    res = tmp.size();
    out = tmp;
}

void run() {
    cin >> J >> P >> S >> K;
    map<int, int> mp[3];
    vector<string> tmp;
    FOR(i1, 1, J) {
        FOR(i2, 1, P) {
            FOR(i3, 1, S) {
                int num[3] = { i1 * 10 + i2, i1 * 10 + i3, i2 * 10 + i3 };

                REP(i, 3) {
                    if (mp[i].find(num[i]) == mp[i].end()) mp[i][num[i]] = 0;
                }
                bool fine = true;
                REP(i, 3) {
                    if (mp[i][num[i]] + 1 > K) {
                        fine = false;
                        break;
                    }
                }
                if (!fine) continue;
                REP(i, 3) {
                    mp[i][num[i]] += 1;
                }
                tmp.push_back(i2s(i1) + " " + i2s(i2) + " " + i2s(i3));
            }
        }
    }

    cout << tmp.size() << endl;
    REP(i, tmp.size()) cout << tmp[i] << endl;

    //int tot = J * P * S;
    //res = 0;
    //RFOR(st, (1 << tot) - 1, 1) {
    //    int cnt = 0;
    //    /*REP(i, tot) {
    //        if (st & (1 << i)) ++cnt;
    //    }*/
    //    cnt = __builtin_popcount(st);
    //    if (cnt <= res) continue;
    //    isok(st);
    //}
    //cout << res << endl;
    //REP(i, res) cout << out[i] << endl;
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
