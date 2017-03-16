#include<bits/stdc++.h>
using namespace std;
#define FZ(n) memset((n),0,sizeof(n))
#define FMO(n) memset((n),-1,sizeof(n))
#define MC(n,m) memcpy((n),(m),sizeof(n))
#define F first
#define S second
#define MP make_pair
#define PB push_back
#define FOR(x,y) for(__typeof(y.begin())x=y.begin();x!=y.end();x++)
#define ALL(x) x.begin(),x.end()
#define IOS ios_base::sync_with_stdio(0);cin.tie(0)
typedef long long i64;
const int MX = 10101;
const int table[5][5] = {
    { 0, 0, 0, 0, 0 },
    { 0, 1, 2, 3, 4 },
    { 0, 2,-1, 4,-3 },
    { 0, 3,-4,-1, 2 },
    { 0, 4, 3,-2,-1 },
};
int T;
int L;
i64 X;
string S;
int cum[MX];
int recum[MX];

int mul(int a, int b) {
    if(a < 0) return -mul(-a, b);
    if(b < 0) return -mul(a, -b);

    return table[a][b];
}

int fastpow(int a, i64 b) {
    if(b == 0) return 1;
    if(b == 1) return a;
    int res = fastpow(a, b>>1); 
    res = mul(res, res);
    if(b & 1LL) res = mul(res, a);
    return res;
}

void printAns(int t, bool ans) {
    cout << "Case #" << t << ": " << (ans ? "YES" : "NO") << endl;
}

int main() {

    IOS;
    cin >> T;
    for(int _t=1; _t<=T; _t++) {
        
        cin >> L >> X >> S;
        int tt = 1;
        cum[0] = recum[0] = 1;
        for(int i=0; i<L; i++) {
            tt = mul(tt, S[i] - 'i' + 2);
            cum[i+1] = tt;
        }
        for(int i=0; i<L; i++) {
            recum[i+1] = mul(S[L-i-1] - 'i' + 2, recum[i]);
        }
        if(fastpow(tt, X) != -1) {
            printAns(_t, false); continue;
        }
        i64 mi = 1LL * X * L, Mj = -1;
        for(int i=0; i<L; i++) {
            if(cum[i+1] == 2) mi = min(mi, 0LL+i);
            else {
                int x = cum[i+1];
                for(int z=1; z<=min(10LL, X); z++) {
                    x = mul(tt, x);
                    if(x == 2) {
                        mi = min(mi, 0LL + i + z * L);
                        break;
                    }
                }
            }
        }
        //cout << tt << ' ' << mi << endl;
        i64 len = 1LL * L * X;
        for(int i=0; i<L; i++) {
            if(recum[i+1] == 4) Mj = max(Mj, len - i - 1);
            else {
                int x = recum[i+1];
                for(int z=1; z<=min(10LL, X); z++) {
                    x = mul(x, tt);
                    if(x == 4) {
                        Mj = max(Mj, len - i - L*z - 1);
                        break;
                    }
                }
            }
        }
        if(Mj < 0 || mi >= len || Mj <= mi) {
            printAns(_t, false);
        } else printAns(_t, true);

    }
	return 0;
}

