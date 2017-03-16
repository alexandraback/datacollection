#include <bits/stdc++.h>

using namespace std;

const int maxn = 1000050;

int c, d, v;
vector<int> a;
int cnt[maxn];
bool create[maxn];

bool dfs(int x) {
    if(x == 0) {
        return true;
    }
    bool res = false;
    for(int i = 0; i < a.size(); ++ i) {
        if(x >= a[i] && cnt[a[i]] >= 1){
            cnt[a[i]] --;
            res |= dfs(x - a[i]);
            cnt[a[i]] ++;
        }
    }
    return res;
}

int main () {
    freopen("C-small-attempt0.in", "r", stdin);
    freopen("C-small-attempt0.out", "w", stdout);
    int t;
    cin >> t;
    for(int cas = 1 ; cas <= t ; cas ++) {
        a.clear();
        cin >> c >> d >> v;
        for (int i = 0; i < d; ++ i) {
            int tt;
            cin >> tt;
            a.push_back(tt), cnt[tt] = c;
        }
        for (int i = 1; i <= v; ++ i) {
            if(dfs(i));
            else {
                a.push_back(i);
                cnt[i] = c;
            }
        }
        cout << "Case #" << cas << ": " << a.size() - d << endl;
    }
    return 0;
}
