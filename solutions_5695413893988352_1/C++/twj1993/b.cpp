#include <cstdio>
#include <iostream>
#include <algorithm>
#include <vector>
#include <cstring>
#include <cmath>

using namespace std;
typedef long long ll;

char s1[20], s2[20];
ll ans = -1, r1, r2;
int n, f;
char ans1[20], ans2[20];
char out1[20], out2[20];

// a == b
bool ok() {
    for(int i = 0; i < n; i ++) {
        if(s1[i] == '?' && s2[i] == '?') {
            ans1[i] = ans2[i] = '0';
        } else if(s1[i] == '?') {
            ans1[i] = ans2[i] = s2[i];
        } else if(s2[i] == '?') {
            ans1[i] = ans2[i] = s1[i];
        } else {
            if(s1[i] != s2[i]) return 0;
            ans1[i] = ans2[i] = s1[i];
        }
    }
    return 1;
}

// a < b
bool dfs(int x, int flag, char *s1, char *s2) {
    if(x == n) {
        //printf("f=%d, ans1=%s, ans2=%s\n", f, ans1, ans2);
        if(flag == 0) return 0;
        ll val1 = 0, val2 = 0, val;
        for(int i = 0; i < n; i ++) {
            val1 = val1 * 10 + ans1[i] - '0';
            val2 = val2 * 10 + ans2[i] - '0';
        }
        if(val1 > val2) val = val1 - val2; else val = val2 - val1;
        if(ans == -1 || val < ans || val == ans &&
           (f == 1 && (val1 < r1 || (val1 == r1 && val2 < r2) ) ||
            f == 2 && (val2 < r1 || (val2 == r1 && val1 < r2) )
           )
        ) {
               ans = val;
               if(f == 1) {
                   r1 = val1;
                   r2 = val2;
                   for(int i = 0; i < n; i ++) {
                       out1[i] = ans1[i];
                       out2[i] = ans2[i];
                   }
               } else {
                   r1 = val2;
                   r2 = val1;
                   for(int i = 0; i < n; i ++) {
                       out1[i] = ans2[i];
                       out2[i] = ans1[i];
                   }
               }
            out1[n] = out2[n] = 0;
        }
        return 1;
    }
    bool ret = 0;
    if(flag == 0) {
        if(s1[x] == '?' && s2[x] == '?') {
            ans1[x] = ans2[x] = '0';
            ret = dfs(x+1, flag, s1, s2);
            //if(!ret) {
                ans1[x] = '0';
                ans2[x] = '1';
                ret = dfs(x+1, 1, s1, s2);
            //}
        } else if(s1[x] == '?') {
            ans1[x] = ans2[x] = s2[x];
            ret = dfs(x+1, flag, s1, s2);
            if(s2[x] != '0') {
                ans1[x] = s2[x] - 1;
                bool ret2 = dfs(x+1, 1, s1, s2);
                if(ret2 == 1) ret = 1;
            }
        } else if(s2[x] == '?') {
            ans1[x] = ans2[x] = s1[x];
            ret = dfs(x+1, flag, s1, s2);
            if(s1[x] != '9') {
                ans2[x] = s1[x] + 1;
                bool ret2 = dfs(x+1, 1, s1, s2);
                if(ret2 == 1) ret = 1;
            }
        } else {
            ans1[x] = s1[x];
            ans2[x] = s2[x];
            if(s1[x] == s2[x]) ret = dfs(x+1, flag, s1, s2);
            else if(s1[x] < s2[x]) ret = dfs(x+1, 1, s1, s2);
            else ret = 0;
        }
    } else {
        if(s1[x] == '?' && s2[x] == '?') {
            ans1[x] = '9';
            ans2[x] = '0';
            ret = dfs(x+1, flag, s1, s2);
        } else if(s1[x] == '?') {
            ans1[x] = '9';
            ans2[x] = s2[x];
            ret = dfs(x+1, flag, s1, s2);
        } else if(s2[x] == '?') {
            ans1[x] = s1[x];
            ans2[x] = '0';
            ret = dfs(x+1, flag, s1, s2);
        } else {
            ans1[x] = s1[x];
            ans2[x] = s2[x];
            ret = dfs(x+1, flag, s1, s2);
        }
    }
    return ret;
}

int main() {
    freopen("B.in", "r", stdin);
    freopen("B.outlarge", "w", stdout);
    int T;
    scanf("%d", &T);
    
    for(int t = 1; t <= T; t ++) {
        scanf("%s%s", s1, s2);
        n = strlen(s1);
        ans = -1;
        printf("Case #%d: ", t);
        if(ok()) {
            ans1[n] = ans2[n] = 0;
            cout << ans1 << " " << ans2 << endl;
        }else {
            f = 1;
            dfs(0, 0, s1, s2);
            f = 2;
            dfs(0, 0, s2, s1);
            cout << out1 << " " << out2 << endl;
        }
    }
    return 0;
}