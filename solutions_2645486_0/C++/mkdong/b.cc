#include <iostream>
#include <cstdio>

using namespace std;

typedef long long lld;


lld E, R, N;
lld v[100];
lld f[100][101];

lld max(lld a, lld b) {
    return a > b ? a : b;
}
lld min(lld a, lld b) {
    return a < b ? a : b;
}

lld solve()
{
    for (lld i=0; i<=E; ++i) {
        for (lld j=0; j<N+1; ++j) {
            f[j][i] = -1;
        }
    }
    f[0][E] = 0;
    for (lld i=0; i<N; ++i) {
        for (lld e=0; e<=E; ++e) {
            if (f[i][e] == -1) continue;
            for (lld con=0; con<=e; ++con) {
                if (f[i][e] + con*v[i+1] > f[i+1][min(e-con+R, E)]) {
                    f[i+1][min(e-con+R, E)] = f[i][e] + con*v[i+1];
                }
            }
        }
    }
    lld ret = 0;
    for (lld e=0; e<=E; ++e) {
        ret = max(ret, f[N][e]);
    }
    return ret;
}

int main()
{
    int tc;
    cin >> tc;
    for (int c=1; c<=tc; ++c) {
        cin >> E >> R >> N;
        for (lld i=1; i<=N; ++i) {
            cin >> v[i];
        }
        cout << "Case #" << c << ": " << solve() << endl;
    }
    return 0;
}

