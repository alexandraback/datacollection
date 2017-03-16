#include <vector>
#include<cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>
#include <string>
#include <map>
#include <deque>
#include <set>
#ifdef __GXX_EXPERIMENTAL_CXX0X__
#include <unordered_map>
#include <unordered_set>
#include <cassert>
#endif
#include <ctime>
#include <queue>
#include <stack>
#include<iomanip>
#include <sstream>
#include <cmath>
#include <list>

using namespace std;

typedef long long ll;
typedef pair<int, int> PII;
typedef pair<int, double> PID;
typedef pair<string, int> PSI;
typedef pair<string, string> PSS;
typedef pair<PII, int> PIP;

PII calc_status(string& haystack, string& needle) {
        int n = haystack.size();
        int m = needle.size();
        vector<int> next(m, -1);
        int p = -1;
        for(int i = 1; i < m; i ++) {
            while(p >= 0 && needle[p + 1] != needle[i]) p = next[p];
            if (needle[p + 1] == needle[i]) {
                p ++;
            }
            next[i] = p;
        }
        p = -1;
        int ret = 0;
        for(int i = 0; i < n; i ++) {
            if (p == m - 1) p = next[p];
            while(p + 1 < m && p >= 0 && needle[p + 1] != haystack[i]) p = next[p];
            if (p + 1 < m && needle[p + 1] == haystack[i]) {
                p ++;
            }
            if (p == m - 1) {
                ret ++;
            }
        }
        return PII(ret, p + 1);
}
void solve(int ncase) {
    int k, l, s;
    cin >> k >> l >> s;
    string keys, word;
    cin >> keys >> word;
    vector<int> keycnt(26, 0);
    for(auto c : keys) keycnt[c - 'A'] ++;
    vector<vector<int>> status_mat(1, vector<int>(26, -1));
    vector<PII> status;
    map<PII, int> status2idx;
    vector<string> status_str;
    status.push_back(PII(0, 0));
    status2idx[status[0]] = 0;
    status_str.push_back("");
    vector<double> p(1, 1);
    for(int z = 0; z < s; z ++) {
        //cout << "z = " << z << endl;
        vector<double> np(status.size());
        int sz = status.size();
        for(int i = 0; i < sz; i ++) {
            //if (p[i] < 1e-8) continue;
            string cur = status_str[i];
            for(int j = 0; j < 26; j ++) {
                if (keycnt[j] == 0) continue;
                //cout << "j = " << j << endl;
                double p0 = keycnt[j] * 1.0 / keys.size();
                if (status_mat[i][j] != -1) {
                    np[status_mat[i][j]] += p[i] * p0;
                    continue;
                }
                cur.push_back('A' + j);

                PII nstatus = calc_status(cur, word);
                //cout << cur << " " << nstatus.first << " " << nstatus.second << endl;
                if (status2idx.find(nstatus) == status2idx.end()) {
                    status2idx[nstatus] = status.size();
                    status.push_back(nstatus);
                    status_mat.push_back(vector<int>(26, -1));
                    np.push_back(0.0);
                    status_str.push_back(cur);
                }
                cur.pop_back();
                status_mat[i][j] = status2idx[nstatus];
                //cout << i << " " << j << " in loop " << status_mat[i][j] << " " << p[i] << " " << p0 << endl;
                np[status_mat[i][j]] += p[i] * p0;
            }
        }
        p = np;
    }

#if 0
    for(int i = 0; i < status.size(); i ++) {
        cout << "status " << i << ", " << status[i].first << "_" << status[i].second << ", prob = " << p[i] << endl;
    }
#endif

    double ret = 0;
    int max_banana = 0;
    for(auto st : status) max_banana = max(max_banana, st.first);
    for(int i = 0; i < status.size(); i ++) {
        ret += p[i] * (max_banana - status[i].first);
    }
    cout << "Case #" << ncase << ": " << std::fixed << setprecision(16) << ret << endl;

}
int main() {
    //ios::sync_with_stdio(false);
    //cout << std::fixed << setprecision(16);
#ifdef _zzz_
    //freopen("in.txt", "r", stdin);
    freopen("B-large.in", "r", stdin);
    freopen("out.txt", "w", stdout);
#endif
    int T = 1;
    cin >> T;
    //scanf("%d", &T);
    //pre_calc();
    int ncase = 0;
    while(T --) {
        solve(++ ncase);
    }
}
