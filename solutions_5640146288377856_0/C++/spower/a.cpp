#include<iostream>
#include<cmath>
#include<cstring>
#include<cstdio>
#include<map>
#include<vector>
#include<queue>
#include<algorithm>
using namespace std;
const int N = 1<<20;
int r, c, w, s[10];
map<int, int> mp;
inline bool check() {
    int l = c, r = -1, cnt =0;
    for(int i = 0; i < c; i++)
        if(s[i] == 1) {
            l = min(l, i);
            r = max(r, i);
            cnt ++;
        } else if(s[i] == -1)
            cnt++;
    return (l == c || r - l + 1 <= w) && cnt >= w;
}
inline int getval() {
    int ans = 0;
    for(int i = 0; i < c; i++)
        ans = ans * 3 + s[i] + 1;
    return ans;
}
int dfs(int x, int y) {
    int val = getval();
    if(mp.find(val) != mp.end())
        return mp[val];
    if(y == w)
        return mp[val] = x;
    int ans = c;
    for(int i = 0; i < c; i++)
        if(s[i] == -1) {
            int m1 = y, m2 = y;
            s[i] = 0;
            if(check())
                m1 = dfs(x+1, y);
            s[i] = 1;
            if(check())
                m2 = dfs(x+1, y+1);
            s[i] = -1;
            ans = min(ans, max(m1, m2));
        }
    return mp[val] = ans;
}
int main() {
    freopen("A-small-attempt2.in", "r", stdin);
    freopen("a-small.out", "w", stdout);
    int t;
    scanf("%d", &t);
    for(int cas = 1; cas <= t; cas++) {
        mp.clear();
        scanf("%d%d%d", &r, &c, &w);
        memset(s, -1, sizeof(s));
        printf("Case #%d: %d\n", cas, dfs(0, 0));
    }
    return 0;
}
