#include <iostream>
#include <cstdio>
#include <cstring>
#include <cmath>
#include <algorithm>
using namespace std;
typedef long long LL;
//const long long MOD = 1000000007;
LL dp[64][8], sum[64][8];

LL get(LL a, LL b, LL e) {
    if (a < 0 || b < 0) return 0;
    memset(dp, 0, sizeof(dp));
    memset(sum, 0, sizeof(sum));
    dp[63][0] = 1;
    for (int i = 62; i >= 0; i--) {
        LL z = 1LL << i;
        for (int pre = 0; pre < 8; pre++) {
            LL cnt = dp[i + 1][pre];
            LL val = sum[i + 1][pre];
            if (cnt == 0) continue;
            for (int st = 0; st < 4; st++) {//00 01 10 11
                int u = st & 1, v = st >> 1;
                //u是A这位填什么,v是B这位填什么
                //ABE
                int cur = 0;
                if (pre & 4) cur |= 4;
                else if (!u && (a & z)) cur |= 4;
                else if (u && !(a & z)) continue;

                if (pre & 2) cur |= 2;
                else if (!v && (b & z)) cur |= 2;
                else if (v && !(b & z)) continue;

                if (pre & 1) cur |= 1;
                else if ((u & v) && !(e & z)) continue;
                else if (!(u & v) && (e & z)) cur |= 1;

                dp[i][cur] = (dp[i][cur] + cnt);// % MOD;
                if (u ^ v) {
                    //sum[i][cur] = (sum[i][cur] + val + (z % MOD * cnt) % MOD) % MOD;
                    //sum[i][cur] = (sum[i][cur] + val + (z % MOD * cnt) % MOD) % MOD;
                } else {
                    //sum[i][cur] = (sum[i][cur] + val) % MOD;
                }
            }
        }
    }
    LL ans =  0;
    for (int i = 1; i < 8; i += 2) {
        ans = (ans + dp[0][i]);// % MOD;
    }
    return ans;
}

int main() {
    int cas;
    LL a, b, c, d, e;
    scanf("%d", &cas);
    for (int T = 1; T <= cas; T++) {
        //scanf("%I64d%I64d%I64d%I64d%I64d", &a, &b, &c, &d, &e);
        //LL ans =  (get(b, d, e) - get(b, c - 1, e) - get(a - 1, d, e) + get(a - 1, c - 1, e)) % MOD;
        scanf("%lld %lld %lld", &a, &b, &e);
        a = a - 1;
        b = b - 1;
        LL ans = get(a, b, e);
        //while (ans < 0) ans += MOD;
        printf("Case #%d: %lld\n", T, ans);
    }
}