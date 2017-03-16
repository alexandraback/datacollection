#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>
#include <vector>
#include <cmath>
#include <map>
using namespace std;
const int N = 500005;
int n;
string s[N];
int f[N] , ans;
void dfs (int cnt , int state , string e) {
    if (cnt == n) {
        ans ++;
        return;
    }
    for (int i = 0 ; i < n ; i ++) {
        if (f[i] == 0) {
            int q = state , ok = 1;
            string p = e[e.size() - 1] + s[i];
            for (int j = 1 ; j < p.size() ; j ++) {
                if (p[j] != p[j - 1]) {
                    if (q & (1 << (p[j] - 'a'))) {
                        ok = 0;
                        break;
                    }
                }
                q |= 1 << (p[j] - 'a');
            }
            if (!ok) continue;
            f[i] = 1;
            dfs (cnt + 1 , q , e + s[i]);
            f[i] = 0;
        }
    }
}
int main () {
#ifndef ONLINE_JUDGE
    freopen ("input.txt" , "r" , stdin);
    freopen ("output.txt" , "w" , stdout);
#endif
    int t , cas = 0;
    cin >> t;
    while (t --) {
        cin >> n;
        for (int i = 0 ; i < n ; i ++) {
            cin >> s[i];
        }
        ans = 0;
        dfs (0 , 0 , "");
        printf ("Case #%d: %d\n" , ++ cas , ans);
    }
    return 0;
}