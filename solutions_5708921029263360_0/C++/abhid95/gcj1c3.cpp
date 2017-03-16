#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define pii pair< ll, ll >
#define piii pair< pii, ll >
ll t, _t, i, j, k, jt, kt, st, K, pt, sz;
ll mjp[1005][1005];
ll mjs[1005][1005];
ll mps[1005][1005];
int main() {
    cin>>t;
    for(_t = 1; _t <= t; _t++) {
        vector< piii > v;
        cin>>jt>>pt>>st>>K;
        memset(mjp, 0, sizeof mjp);
        memset(mjs, 0, sizeof mjs);
        memset(mps, 0, sizeof mps);
        for(k = 0; k < st; k++) {
            for(j = 0; j < pt; j++) {
                for(i = 0; i < jt; i++) {
                    mjp[i][j]++;
                    mjs[i][k]++;
                    mps[j][k]++;
                    if(mjp[i][j] > K || mjs[i][k] > K || mps[j][k] > K) {
                        mjp[i][j]--;
                        mjs[i][k]--;
                        mps[j][k]--;
                        continue;
                    }
                    v.push_back(piii(pii(i, j), k));
                }
            }
        }
        sz = v.size();
        printf("Case #%lld: %lld\n", _t, sz);
        for(i = 0; i < sz; i++) {
            printf("%lld %lld %lld\n", v[i].first.first+1, v[i].first.second+1, v[i].second+1);
        }
        v.clear();
    }
    return 0;
}
