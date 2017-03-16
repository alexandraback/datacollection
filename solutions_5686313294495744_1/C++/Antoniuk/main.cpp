//#include "testlib.h"
//#include <spoj.h>

#include <iostream>
#include <stdio.h>
#include <vector>
#include <string>
#include <algorithm>
#include <math.h>
#include <assert.h>
#include <time.h>
#include <memory.h>
#include <set>
#include <numeric>
#include <map>
#include <queue>
#include <stack>
#include <bitset>
//#include <unordered_map>

using namespace std;

int n;
pair<string, string> th[1111];
bool used[1111];

int solve() {
    memset(used, 0, sizeof used);
    map<string, int> mp1, mp2;
    for(int i = 0; i < n; ++i)
        mp1[th[i].first]++, mp2[th[i].second]++;

    int ans = 0;
    set<string> del1, del2;
    bool fl = 1;
    while (fl) {
        fl = 0;
        string del = "-1";
        for(map<string, int>::iterator it = mp1.begin(); it != mp1.end(); ++it)
        if (it->second == 1) {
            del = it->first;
            break;
        }
        if (del != "-1" && 0) {
            fl = 1;
            int id = 1;
            for(int i =0; i < n; ++i)
            if (!used[i] && del == th[i].first) {
                id = i;
                break;
            }


            if (del1.find(th[id].first) != del1.end() && del2.find(th[id].second) != del2.end())
                ans++;


            del1.insert(th[id].first);
            del2.insert(th[id].second);
            used[id] = 1;
            mp1[th[id].first]--;
            mp2[th[id].second]--;
            continue;
        }
        del = "-1";
        for(map<string, int>::iterator it = mp2.begin(); it != mp2.end(); ++it)
        if (it->second == 1) {
            del = it->first;
            break;
        }
        if (del != "-1" && 0) {
            fl = 1;
            int id = 1;
            for(int i =0; i < n; ++i)
            if (!used[i] && del == th[i].second) {
                id = i;
                break;
            }

            if (del1.find(th[id].first) != del1.end() && del2.find(th[id].second) != del2.end())
                ans++;

            del1.insert(th[id].first);
            del2.insert(th[id].second);
            used[id] = 1;
            mp1[th[id].first]--;
            mp2[th[id].second]--;
            continue;
        }


        vector<int> v;
        for(int i = 0; i < n; ++i)
        if (!used[i])
            v.push_back(i);

        if (v.size() == 0) break;


        fl = 1;
        int ddd = 0;
        vector<int> vv;
        for(int i = 0; i < v.size(); ++i)
        if (mp1[th[v[i]].first] + mp2[th[v[i]].second] > ddd) {
            ddd = mp1[th[v[i]].first] + mp2[th[v[i]].second];
            vv.clear();
            vv.push_back(v[i]);
        }else if (mp1[th[v[i]].first] + mp2[th[v[i]].second] == ddd) {
            vv.push_back(v[i]);
        }


        int id = vv[rand() % vv.size()];

        if (del1.find(th[id].first) != del1.end() && del2.find(th[id].second) != del2.end())
            ans++;

        del1.insert(th[id].first);
        del2.insert(th[id].second);
        used[id] = 1;
        mp1[th[id].first]--;
        mp2[th[id].second]--;
    }

    return ans;
}

int solve1() {
    memset(used, 0, sizeof used);
    map<string, int> mp1, mp2;
    for(int i = 0; i < n; ++i)
        mp1[th[i].first]++, mp2[th[i].second]++;

    int ans = 0;
    set<string> del1, del2;
    bool fl = 1;
    while (fl) {
        fl = 0;
        string del = "-1";
        for(map<string, int>::iterator it = mp1.begin(); it != mp1.end(); ++it)
        if (it->second == 1) {
            del = it->first;
            break;
        }
        if (del != "-1") {
            fl = 1;
            int id = 1;
            for(int i =0; i < n; ++i)
            if (!used[i] && del == th[i].first) {
                id = i;
                break;
            }


            if (del1.find(th[id].first) != del1.end() && del2.find(th[id].second) != del2.end())
                ans++;


            del1.insert(th[id].first);
            del2.insert(th[id].second);
            used[id] = 1;
            mp1[th[id].first]--;
            mp2[th[id].second]--;
            continue;
        }
        del = "-1";
        for(map<string, int>::iterator it = mp2.begin(); it != mp2.end(); ++it)
        if (it->second == 1) {
            del = it->first;
            break;
        }
        if (del != "-1") {
            fl = 1;
            int id = 1;
            for(int i =0; i < n; ++i)
            if (!used[i] && del == th[i].second) {
                id = i;
                break;
            }

            if (del1.find(th[id].first) != del1.end() && del2.find(th[id].second) != del2.end())
                ans++;

            del1.insert(th[id].first);
            del2.insert(th[id].second);
            used[id] = 1;
            mp1[th[id].first]--;
            mp2[th[id].second]--;
            continue;
        }


        vector<int> v;
        for(int i = 0; i < n; ++i)
        if (!used[i])
            v.push_back(i);

        if (v.size() == 0) break;


        fl = 1;
        int ddd = 0;
        vector<int> vv;
        for(int i = 0; i < v.size(); ++i)
        if (mp1[th[v[i]].first] + mp2[th[v[i]].second] > ddd) {
            ddd = mp1[th[v[i]].first] + mp2[th[v[i]].second];
            vv.clear();
            vv.push_back(v[i]);
        }else if (mp1[th[v[i]].first] + mp2[th[v[i]].second] == ddd) {
            vv.push_back(v[i]);
        }


        int id = vv[rand() % vv.size()];

        if (del1.find(th[id].first) != del1.end() && del2.find(th[id].second) != del2.end())
            ans++;

        del1.insert(th[id].first);
        del2.insert(th[id].second);
        used[id] = 1;
        mp1[th[id].first]--;
        mp2[th[id].second]--;
    }

    return ans;
}

int solve3() {
    memset(used, 0, sizeof used);
    map<string, int> mp1, mp2;
    for(int i = 0; i < n; ++i)
        mp1[th[i].first]++, mp2[th[i].second]++;

    int ans = 0;
    set<string> del1, del2;
    bool fl = 1;
    while (fl) {
        fl = 0;
        string del = "-1";
        for(map<string, int>::iterator it = mp1.begin(); it != mp1.end(); ++it)
        if (it->second == 1) {
            del = it->first;
            break;
        }
        if (del != "-1" && 0) {
            fl = 1;
            int id = 1;
            for(int i =0; i < n; ++i)
            if (!used[i] && del == th[i].first) {
                id = i;
                break;
            }


            if (del1.find(th[id].first) != del1.end() && del2.find(th[id].second) != del2.end())
                ans++;


            del1.insert(th[id].first);
            del2.insert(th[id].second);
            used[id] = 1;
            mp1[th[id].first]--;
            mp2[th[id].second]--;
            continue;
        }
        del = "-1";
        for(map<string, int>::iterator it = mp2.begin(); it != mp2.end(); ++it)
        if (it->second == 1) {
            del = it->first;
            break;
        }
        if (del != "-1" && 0) {
            fl = 1;
            int id = 1;
            for(int i =0; i < n; ++i)
            if (!used[i] && del == th[i].second) {
                id = i;
                break;
            }

            if (del1.find(th[id].first) != del1.end() && del2.find(th[id].second) != del2.end())
                ans++;

            del1.insert(th[id].first);
            del2.insert(th[id].second);
            used[id] = 1;
            mp1[th[id].first]--;
            mp2[th[id].second]--;
            continue;
        }


        vector<int> v;
        for(int i = 0; i < n; ++i)
        if (!used[i])
            v.push_back(i);

        if (v.size() == 0) break;


        fl = 1;
        int ddd = 0;
        vector<int> vv;
        for(int i = 0; i < v.size(); ++i)
        if (mp1[th[v[i]].first] + mp2[th[v[i]].second] > ddd) {
            ddd = mp1[th[v[i]].first] + mp2[th[v[i]].second];
            vv.clear();
            vv.push_back(v[i]);
        }else if (mp1[th[v[i]].first] + mp2[th[v[i]].second] == ddd) {
            vv.push_back(v[i]);
        }


        int id = v[rand() % v.size()];

        if (del1.find(th[id].first) != del1.end() && del2.find(th[id].second) != del2.end())
            ans++;

        del1.insert(th[id].first);
        del2.insert(th[id].second);
        used[id] = 1;
        mp1[th[id].first]--;
        mp2[th[id].second]--;
    }

    return ans;
}


int dp[1<<17];

int solve2() {
    for(int i = 0; i < (1 << n); ++i)
        dp[i] = 99999;
    set< pair<int, int> > q;
    for(int i = 0; i < n; ++i) {
        q.insert(make_pair(1, (1<<i)));
        dp[1<<i] = 1;
    }

    while (!q.empty()) {
        int dd, nv, v = q.begin()->second;
        int d = q.begin()->first;
        q.erase(q.begin());

        if (dp[v] != d) continue;

        set<string> h1, h2;
        for(int i = 0; i < n; ++i)
        if ((v & (1 << i)))
            h1.insert(th[i].first), h2.insert(th[i].second);

        for(int i = 0; i < n; ++i)
        if ((v & (1 << i)) == 0) {
            nv = v | (1 << i);
            if (dp[nv] <= dp[v]) continue;

            dd = 1;
            if (h1.find(th[i].first) != h1.end() &&
                h2.find(th[i].second) != h2.end())
                dd = 0;


            if (dp[v] + dd < dp[nv]) {
                dp[nv] = dp[v] + dd;
                q.insert(make_pair(dp[nv], nv));
            }
        }
    }
    return n - dp[(1 << n)-1];
}

int main() {
    ios::sync_with_stdio(0);
    freopen("input.txt", "r", stdin); freopen("output1.txt", "w", stdout);
    int tt;
    cin >> tt;
    for(int i = 0; i < tt; ++i) {
        cerr << i << "\n";
        cin >> n;
        for(int i = 0; i < n; ++i)
            cin >> th[i].first >> th[i].second;

        cout << "Case #" << i+1 << ": ";
        if (n <= 16) {
            cout << solve2() << "\n";
        }
        else {
            int ans = solve();
            for(int i = 0; i < 10; ++i)
                ans = max(ans, solve()),
                ans = max(ans, solve3()),
                ans = max(ans, solve1());
            cout << ans << "\n";
        }
    }

    return 0;
}
