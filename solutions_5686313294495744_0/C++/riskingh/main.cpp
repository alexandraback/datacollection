#include <iostream>
#include <fstream>
#include <string>
#include <map>
#include <vector>
#include <algorithm>

using namespace std;

vector<pair<int, int> > A;
vector<vector<int> > L1;
vector<vector<int> > L2;
int cnt1, cnt2;
vector<int> was, was1, was2;

int res;

void gen(int k, int c) {
    if (k == cnt1 + cnt2) {
        if (c > A.size())
            cerr << "ERROR: " << c << "\n";
        res = min(res, c);
        return;
    }

    int t, i;
    if (k < cnt1) {
        t = k;
        if (was1[t]) {
            gen(k + 1, c);
            return;
        }
        for (i = 0; i < L1[t].size(); ++i) {
            was1[t]++;
            was2[A[L1[t][i]].second]++;
            gen(k + 1, c + 1);
            was2[A[L1[t][i]].second]--;
            was1[t]--;
        }
    }
    else {
        t = k - cnt1;
        if (was2[t]) {
            gen(k + 1, c);
            return;
        }
        for (i = 0; i < L2[t].size(); ++i) {
            was2[t]++;
            was1[A[L2[t][i]].first]++;
            gen(k + 1, c + 1);
            was1[A[L2[t][i]].first]--;
            was2[t]--;
        }
    }
}

void solve() {
    A.clear();
    L1.clear();
    L2.clear();
    was1.clear();
    was2.clear();
    int n, i, j;
    cnt1 = 0;
    cnt2 = 0;
    map<string, int> frst;
    map<string, int> scnd;

    cin >> n;
    string s, t;
    for (i = 0; i < n; ++i) {
        cin >> s >> t;
        if (frst.find(s) == frst.end())
            frst[s] = cnt1++;
        if (scnd.find(t) == scnd.end())
            scnd[t] = cnt2++;
        A.push_back(make_pair(frst[s], scnd[t]));
    }

    L1.resize(cnt1);
    L2.resize(cnt2);

    for (i = 0; i < n; ++i) {
        L1[A[i].first].push_back(i);
        L2[A[i].second].push_back(i);
    }

    was1.resize(cnt1, 0);
    was2.resize(cnt2, 0);

    res = n + 1;
    gen(0, 0);
    cout << n - res;
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    int t, T;
    for (cin >> T, t = 1; t <= T; ++t) {
        cout << "Case #" << t << ": ";
        solve();
        cout << "\n";
    }
    return 0;
}
