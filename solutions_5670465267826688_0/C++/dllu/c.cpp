#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <queue>
#include <cmath>
#include <cstdio>
#include <string>
#include <complex>
#include <stack>
#include <iomanip>
#include <map>

using namespace std;
typedef long double ld;
typedef complex<ld> pt;
typedef vector<pt> pol;

#define I 2
#define J 3
#define K 4

const long long qwer = 1e18;

int quatmul[4][4] = {
    {1, I, J, K},
    {I, -1, K, -J},
    {J, -K, -1, I},
    {K, J, -I, -1}};

int qm(int a, int b) {
    int ans = 1;
    if(a<0) ans *= -1;
    if(b<0) ans *= -1;
    return ans * quatmul[abs(a)-1][abs(b)-1];
}

int qp(int a, long long p) {
    int b = a;
    int ans = 1;
    for(long long i=1; i<=p; i<<=1) {
        if(i&p) {
            ans = qm(ans, b);
        }
        b = qm(b,b);
    }
    return ans;
}

int main() {
    int zxcv[255];
    zxcv[1] = 1;
    zxcv['i'] = I;
    zxcv['j'] = J;
    zxcv['k'] = K;
    int N;
    cin >> N;
    for(int kase=1; kase<=N; kase++) {
        cout << "Case #" << kase << ": ";
        long long l, x;
        cin >> l >> x;
        string s;
        cin >> s;
        long long f[9] = {qwer,qwer,qwer,qwer,qwer,qwer,qwer,qwer,qwer};
        long long f2[9];
        long long e[9] = {qwer,qwer,qwer,qwer,qwer,qwer,qwer,qwer,qwer};
        long long e2[9];
        int a = 1;
        int a2 = 1;
        for(long long i=0; i<l; i++) {
            e[a2+4] = min(e[a2+4], i);
            f[a+4] = min(f[a+4], i);
            a = qm(a,zxcv[s[i]]);
            a2 = qm(zxcv[s[l-i-1]],a2);
        }
        if(qp(a, x) != -1) {
            cout << "NO" << endl;
            continue;
        }
        for(int i=0; i<9; i++) {
            f2[i] = f[i];
            e2[i] = e[i];
        }
        int b = a;
        int b2 = a2;
        for(long long i=1; i<x && i<10000; i++) {
            for(int j=0; j<9; j++) {
                if(j == 4) continue;
                int c = qm(b,j-4);
                f2[c+4] = min(f2[c+4], i*l + f[j]);
                c = qm(j-4, b2);
                e2[c+4] = min(e2[c+4], i*l + e[j]);
            }
            b = qm(b, a);
            b2 = qm(a2, b);
        }
        //cerr << endl;
        for(int i=0; i<9; i++) {
            //cerr << "       " << i << " " << f2[i] <<  ", " << e2[i] << endl;
        }
        if(f2[I+4] + e2[K+4] < x*l) {
            cout << "YES" << endl;
        } else {
            cout << "NO" << endl;
        }
    }
    return 0;    
}
