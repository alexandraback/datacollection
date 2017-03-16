#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <string>
#include <vector>
#include <iostream>
#include <map>
#include <set>
#include <algorithm>
#include <queue>
#include <sstream>
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
#define SZ(x) (int)(x.size())
#define F0(i,n) for(int i=0;i<n;i++)
#define F1(i,n) for(int i=1;i<=n;i++)
const int MOD = 1000002013;
const double pi = atan(1.0)*4.0;
const double eps = 1e-8;
ll gcd(ll x, ll y) { return y ? gcd(y, x%y) : x; }
int bc(int n) { return n ? bc((n-1)&n)+1 : 0; }

int i, j, k, m, n, l, p, s;
int a[1005], v[1005], d[1005];
int jp[11][11], ps[11][11], js[11][11];


int main() {

    int tt, tn; cin >> tn;

    F1(tt,tn) {
        int J, P, S, K;
        cin >> J >> P >> S >> K;
        //cerr << tt << endl;
        //cerr << J << P << S << K << endl;
        ll count = 0;
        F1(i,10) F1(j,10) {jp[i][j] = 0;js[i][j]=0;ps[i][j]=0;}
        F1(j,J) F1(p,P) F1(s,S) {
            if (jp[j][p] < K && js[j][s] < K && ps[p][s] < K) {
                jp[j][p]++;
                js[j][s]++;
                ps[p][s]++;
                count++;
                //cerr << j << ' ' <<  p << ' ' << s << endl;
            }
        }
        printf("Case #%d: ", tt);
        cout << count << endl;
        F1(i,10) F1(j,10) {jp[i][j] = 0;js[i][j]=0;ps[i][j]=0;}
        F1(j,J) F1(p,P) F1(s,S) {
            if (jp[j][p] < K && js[j][s] < K && ps[p][s] < K) {
                jp[j][p]++;
                js[j][s]++;
                ps[p][s]++;
                cout << j << ' ' <<  p << ' ' << s << endl;
            }
        }
    }
    return 0;
}
