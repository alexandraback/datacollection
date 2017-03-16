#include <stdio.h>
#include <vector>

using namespace std;
typedef long long int lld;


lld kc[64];
lld get_idx(const vector<lld>& now,const lld K, const lld C) {
    lld ret = 1;
    for (int i=0; i<now.size(); i++) {
        ret += (now[i]-1) * kc[C-1-i];
    }
    return ret;
}
void solve() {
    lld K, C, S; scanf("%lld %lld %lld", &K, &C, &S);


    kc[0]= 1;
    for (int i=1; i<64 && kc[i-1] < ( lld(1) << lld(55)); i++) {
        kc[i] = kc[i-1] * K;
    }

    lld req = (K % C == 0 ? 0 : 1) + K / C;

    if (req > S) printf("IMPOSSIBLE");
    else {
        for (lld i=0; i<K/C; i++) {
            vector<lld> now;
            for (lld j=1; j<=C; j++) {
                now.push_back(i * C + j);
            }
            printf("%lld ", get_idx(now, K, C));
        }
        if (K% C != 0) {

            vector<lld> now;

            for (lld j=1; j<=K%C; j++) {
                now.push_back( (K/C) * C + j);
            }
            printf("%lld ", get_idx(now, K, C));
        }
    }
}
int main(void) {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    int T; scanf("%d", &T);
    for (int tc=1; tc<=T; tc++) {
        printf("Case #%d: ", tc);
        solve();
        printf("\n");
    }
}