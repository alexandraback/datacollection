#include <cstdio>
#include <iostream>
#include <algorithm>
#include <vector>
#include <cstring>
#include <cmath>
#include <map>

using namespace std;

map<string, int> mp;
int n;
int a[100], b[100];

vector<int> v, l[1005], r[1005];
int ans;


int main() {
    freopen("C.in", "r", stdin);
    freopen("C.out", "w", stdout);
    int T;
    scanf("%d", &T);
    
    for(int t = 1; t <= T; t ++) {
        mp.clear();
        scanf("%d", &n);
        int cnt = 0;
        for(int i = 0; i < n; i ++) {
            string x, y;
            cin >> x >> y;
            if(mp[x] == 0) mp[x] = ++ cnt;
            if(mp[y] == 0) mp[y] = ++ cnt;
            a[i] = mp[x];
            b[i] = mp[y];
        }
        v.clear();
        
        ans = -1;
        for(int dp = 0; dp < (1<<n); dp ++) {
            for(int i = 1; i <= cnt; i ++) {
                l[i].clear();
                r[i].clear();
            }
            for(int i = 0; i < n; i ++) if(dp & (1<<i)) {
                l[a[i]].push_back(i);
                r[b[i]].push_back(i);
            }
            int val = 0;
            for(int i = 0; i < n; i ++) if(!(dp & (1<<i))) {
                if(l[a[i]].size() && r[b[i]].size()) {
                    if(l[a[i]].size() > 1 || r[b[i]].size() > 1) val ++;
                    else if(l[a[i]][0] != r[b[i]][0]) val ++;
                }
            }
            if(val > ans) ans = val;
        }
        printf("Case #%d: %d\n", t, ans);
    }
    return 0;
}