#include <iostream>
#include <vector>
#include <deque>
#include <cstdio>
#include <climits>
#include <cstring>
using namespace std;

#define ll long long

int main() {
    int T;
    cin>>T;

    for (int t=1;t<=T;++t) {

        int N;
        cin>>N;
        vector<ll> D, M, RD;
        for (int i=0;i<N;++i) {
            ll d,h,m;
            cin>>d>>h>>m;
            for (int j=0;j<h;++j) {
                D.push_back(d);
                RD.push_back(360 - d);
                M.push_back(m + j);
            }
        }

        ll ans = 0;
        if (D.size() < 2) {
            ans = 0;
        } else if (M[0] == M[1]) {
            ans = 0;
        } else {
            double a1 = M[0] * RD[0] / 360.0;
            double a2 = M[0] * RD[0] / 360.0+ M[0];
            double b1 = M[1] * RD[1] / 360.0;
            double b2 = M[1] * RD[1] / 360.0 + M[1];

            if (M[0]*RD[0] + M[0]*360 <= M[1]*RD[1] || M[0]*RD[0] >= M[1]*RD[1] + M[1]*360) {
                ans = 1;
            } else {
                ans = 0;
            }
        }

        printf("Case #%d: %lld\n", t, ans);
    }
}
