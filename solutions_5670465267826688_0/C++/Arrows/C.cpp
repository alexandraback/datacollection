#include <bits/stdc++.h>

using namespace std;

int parse(char c) {
    if(c == 'i') return 2;
    if(c == 'j') return 4;
    if(c == 'k') return 8;
}

int mul(int a, int b) {
    int sign = a * b > 0 ? 1 : -1;
    a = abs(a), b = abs(b);
    int ans;
    if(a == 1) {
        ans = b;
    } else if (a == 2) {
        if(b == 1) ans = 2;
        if(b == 2) ans = -1;
        if(b == 4) ans = 8;
        if(b == 8) ans = -4;
    } else if (a == 4) {
        if(b == 1) ans = 4;
        if(b == 2) ans = -8;
        if(b == 4) ans = -1;
        if(b == 8) ans = 2;
    } else if (a == 8) {
        if(b == 1) ans = 8;
        if(b == 2) ans = 4;
        if(b == 4) ans = -2;
        if(b == 8) ans = -1;
    }
    return ans * sign;
}

const int maxn = 10005;

int a[maxn];
int suff[maxn];

bool solve(int l, int x) {
    int pre = a[0];
    for(int i = 1; i < l*x ; i++) {
        if(pre == 2) {
            int mid = a[i];
            for(int j = i + 1; j < l*x ; j++) {
                if(mid == 4) {
                    if(suff[j] == 8) {
                        return true;
                    }
                }
                mid = mul(mid, a[j]);
            }
        }
        pre = mul(pre, a[i]);
    }
    return false;
}

int dfs(int l, int x, int i) {
    if(i == l*x - 1) return suff[i] = a[i];
    return suff[i] = mul(a[i], dfs(l, x, i+1));
}

int main() {
    freopen("C-small-attempt0.in", "r", stdin);
    freopen("C-small-attempt0.out", "w", stdout);
    int t;
    cin >> t;
    for(int cas = 1; cas <= t; cas++) {
        int l, x;
        cin >> l >> x;
        string s;
        cin >> s;
        for(int i = 0 ; i < x ; i++) {
            for(int j = 0 ; j < l; j++) {
                a[i*l+j] = parse(s[j]);
            }
        }

        // for(int i = 0 ; i < l*x ; i++) {
        //     suff[i] = a[i];
        //     for(int j = i + 1 ; j < l*x ; j++) {
        //         suff[i] = mul(suff[i], a[j]);
        //     }
        // }
        
        dfs(l, x, 0);

        if(solve(l, x)) {
            cout << "Case #" << cas << ": YES" << endl;
        } else {
            cout << "Case #" << cas << ": NO" << endl;
        }
    }
    return 0;
}
