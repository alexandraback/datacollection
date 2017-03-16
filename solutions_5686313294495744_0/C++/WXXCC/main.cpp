/*
 *
 * Tag: Implementation
 * Time: O(n)
 * Space: O(n)
 */
#include <iostream>
#include <iomanip>
#include <cstdio>
#include <cstring>
#include <cmath>
#include <cstdlib>
#include <climits>
#include <string>
#include <algorithm>
#include <vector>
#include <stack>
#include <queue>
#include <unordered_map>
#include <unordered_set>
using namespace std;
const int N = 1050;
const int M = 30110;
const long long MOD = 1000000007;
const double eps = 1e-10;
struct word{
    string first;
    string second;
}tpc[N];
unordered_set<string> dict;
unordered_map<string, int> fwd;
unordered_map<string, int> swd;
int res[N];
bool g[N][N], vis[N];
int n, cnt, nn,mm;

bool findpath(int a){
    for (int i = 1; i <= mm; ++ i) {
        if (g[a][i] && !vis[i]) {
            vis[i] = 1;
            if (res[i] == 0 || findpath(res[i])) { //
                res[i] = a;
                return true;
            }
        }
    }
    return false;
}

void solve(){
    for (int i = 1; i <= nn; ++ i) {
        memset(vis, 0, sizeof(vis));
        if (findpath(i)) {
            ++ cnt;
        }
    }
}

int main() {
    freopen("/Users/ybc/Project/CCPP/ACM/C-small-attempt0.in", "r", stdin);
    freopen("/Users/ybc/Project/CCPP/ACM/out.txt", "w", stdout);
    int T;
    scanf("%d",&T);
    for (int cas = 1; cas <= T; ++ cas) {
        scanf("%d",&n);
        dict.clear();
        fwd.clear();
        swd.clear();
        memset(g, 0, sizeof(g));
        memset(res, 0, sizeof(res));
        cnt = 0;
        int fid = 1, sid = 1;
        for (int i = 1; i <= n; ++ i) {
            cin>>tpc[i].first>>tpc[i].second;
            string key = tpc[i].first;
            key += ' ';
            key += tpc[i].second;
       //     cout<<key<<endl;
            dict.insert(key);
            if (fwd.find(tpc[i].first) == fwd.end()) {
                fwd[tpc[i].first] = fid ++;
            }
            if (swd.find(tpc[i].second) == swd.end()) {
                swd[tpc[i].second] = sid ++;
            }
        }
        for (unordered_map<string, int>::iterator fit = fwd.begin(); fit != fwd.end(); ++ fit) {
            for (unordered_map<string, int>::iterator sit = swd.begin(); sit != swd.end(); ++ sit) {
                string tmp = fit->first+' '+sit->first;
       //         cout<<tmp<<endl;
                if (dict.find(tmp) == dict.end() && fit->first != sit->first) {
                    g[fit->second][sit->second] = 1;
     //               cout<<fit->second<<" "<<sit->second<<endl;
                }
            }
        }
        nn = (int)fwd.size();
        mm = (int)swd.size();
   //     cout<<" nn = "<<nn<<" mm = "<<mm<<endl;
        solve();
        printf("Case #%d: ", cas);
        printf("%d\n",cnt);
    }
    return 0;
}
