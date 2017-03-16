#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <algorithm>
#include <vector>
#include <queue>
#include <map>
#include <set>

using namespace std;

#define For(i,a,b) for(int i=a;i<=b;i++)
#define Ford(i,a,b) for(int i=a;i>=b;i--)
#define OUT(x) {cout << #x << " = " << x << endl;}
#define FOUT(x,a,b) {cout << #x << " = "; For(_,a,b) cout << x[_] << ' '; cout << endl;}
#define FOUT2(x,a,b,c,d) {cout << #x << " = " << endl; For(_,a,b){For(__,c,d) cout << x[_][__] << " "; cout << endl;}}
#define fi first
#define se second
#define mp make_pair
#define sz(x) (int)x.size()
#define BIT(s,i) ((s&(1<<i))>0)

typedef long long ll;

long long f[33][2][2][2];
int A, B, K;

long long rec(int i, int eqA, int eqB, int eqK) {
    //OUT(i); //OUT(eqA); OUT(eqB); OUT(eqK);
    if (i == -1) return 1;
    if (f[i][eqA][eqB][eqK] != -1) return f[i][eqA][eqB][eqK];
    long long &ret = f[i][eqA][eqB][eqK];
    ret = 0;
    int nA, nB, nK;
    if (eqA) nA = BIT(A, i); else nA = 1;
    if (eqB) nB = BIT(B, i); else nB = 1;
    if (eqK) nK = BIT(K, i); else nK = 1;
    //OUT(nA); OUT(nB); OUT(nK);
    For(bK, 0, nK) For(bA, 0, nA) For(bB, 0, nB)
        if ((bA & bB) == bK) {
            //OUT(i); OUT(bA); OUT(bB); OUT(bK);
            //cout << endl;
            ret += rec(i - 1, eqA && bA == nA, eqB && bB == nB, eqK && bK == nK);
            //OUT(i); OUT(ret);
            //cout << endl;
        }
    return ret;
}

void solve() {
    cin >> A >> B >> K;
    if (A == 1 && B == 1 && K == 1) {
        cout << 1;
        return;
    }
    K--; A--; B--;
    int msb = 30;
    while (BIT(A, msb) == 0 && BIT(B, msb) == 0 && BIT(K, msb) == 0) --msb;
    For(i1, 0, 32) For(i2, 0, 1) For(i3, 0, 1) For(i4, 0, 1) f[i1][i2][i3][i4] = -1;
    long long res = rec(msb, 1, 1, 1);
    cout << res;
}

int main() {

#ifndef ONLINE_JUDGE
    freopen("B-small-1.in", "r", stdin);
    freopen("B.out", "w", stdout);
#endif

    int T;
    cin >> T;
    For(i, 1, T) {
        cout << "Case #" << i << ": ";
        solve();
        cout << endl;
    }
}
