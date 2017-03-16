#include <bits/stdc++.h>

using namespace std;

#define MAXN 20

int k, l, s, maxi;
char ans[MAXN], alp[MAXN], r[MAXN];
double prob, res;

void solve(int pass) {
    if (pass == s) {
        int x = 0;
        for (int i = 0; i <= s - l; i++) {
            bool cond = true;
            for (int j = 0; j < l; j++) {
                if (ans[i+j] != r[j]) {
                    cond = false;
                    break;
                }
            }
            if (cond) {
                x++;
            }
        }

        maxi = max(maxi, x);
        res += (x * prob);
    } else {
        for (int i = 0; i < k; i++) {
            ans[pass] = alp[i];
            solve(pass+1);
        }
    }
}


int main() {
    ios::sync_with_stdio(false);
    int t;
    scanf("%d", &t);
    for (int z = 1; z <= t; z++) {
        scanf("%d %d %d", &k, &l, &s);
        scanf("%s %s", alp, r);
        prob = 1.0;
        maxi = 0;
        res = 0.0;
        for (int i = 0; i < s; i++) {
            prob /= (double)k;
        }
        solve(0);
        printf("Case #%d: %.7lf\n", z, (double)maxi - res);
    }

    return 0;
}

