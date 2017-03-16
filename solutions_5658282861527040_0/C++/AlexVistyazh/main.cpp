#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <vector>
#include <map>
#include <algorithm>

using namespace std;

typedef unsigned long long ull;

const int INF = int(1e9 + 5);

int aa[33], bb[33], cc[33], aalen, bblen, cclen;
long long f[35][8];

int gb(int x, int i) {
    return ((x&(1<<i))>0);
}

bool check(int k, int nowC, int nxtC) {
    if (k==0) return true;
    if (k==1) return nxtC<=nowC;
    return false;
}

int nxtK(int k, int nowC, int nxtC) {
    if (k==0) return 0;
    if (k==1) {
        if (nxtC==nowC) return 1;
        return 0;
    }
    return 0;
}

int nxtK(int k1, int c1, int nc1, int k2, int c2, int nc2, int k3, int c3, int nc3) {
    return nxtK(k1,c1,nc1) | (nxtK(k2,c2,nc2)<<1) | (nxtK(k3,c3,nc3)<<2);
}

long long calcF(int a, int b, int c) {
    memset(f, 0, sizeof(f));
    aalen = bblen = cclen = 0;
    while (aalen<33) {
        aa[aalen++]=a%2;
        a/=2;

        bb[bblen++]=b%2;
        b/=2;

        cc[cclen++]=c%2;
        c/=2;
    }
    reverse(aa,aa+aalen);
    reverse(bb,bb+bblen);
    reverse(cc,cc+cclen);
    f[0][7]=1LL;
    for (int len = 0; len < 33; len++) {
        for (int k = 0; k < 8; k++) {
            if (!f[len][k]) continue;
            for (int ab = 0; ab < 4; ab++) {
                if (check(gb(k,0),aa[len],gb(ab,0)) && check(gb(k,1),bb[len],gb(ab,1)) && check(gb(k,2),cc[len],gb(ab,0)&gb(ab,1))) {
                        f[len+1][nxtK(gb(k,0),aa[len],gb(ab,0),
                                      gb(k,1),bb[len],gb(ab,1),
                                      gb(k,2),cc[len],gb(ab,0)&gb(ab,1))]+=f[len][k];
                    }
            }
        }
    }
    long long res = 0;
    for (int k = 0; k < 8; k++) res += f[33][k];
    return res;
}

void solve() {
    int a, b, k;
    cin >> a >> b >> k;
    a--, b--, k--;
    cout << calcF(a, b, k) << '\n';
}

int main()
{
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    ios_base::sync_with_stdio(0);
    int t;
    cin >> t;
    int c = 0;
    while (t--) {
        ++c;
        cout << "Case #" << c << ": ";
        solve();
    }
    return 0;
}
