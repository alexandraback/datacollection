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
#define F0(i,n) for(i=0;i<n;i++)
#define F1(i,n) for(i=1;i<=n;i++)
#define CL(a,x) memset(x, a, sizeof(x))
const int inf = 1000000009;
const double pi = atan(1.0)*4.0;
const double eps = 1e-8;
ll gcd(ll x, ll y) { return y ? gcd(y, x%y) : x; }
int bc(int n) { return n ? bc((n-1)&n)+1 : 0; }

int i, j, k, m, n, l, ans;
char ss[1000002], c[100][100];

int main() {
  //  freopen("c.in", "r", stdin);

//    freopen("C-small-attempt1.in", "r", stdin);
//    freopen("C-small-attempt1.out", "w", stdout);

    freopen("C-large.in", "r", stdin);
    freopen("C-large.out", "w", stdout);

	int tt, tn; cin >> tn;
	F1(tt,tn) {
        //cerr << tt << endl;
        cerr << tt << endl;
        cin >> m >> n >> k;
        l = m * n - k - 1;
        printf("Case #%d:\n", tt);
        bool flip = false, solved = false;
        if (m > n) { swap(m, n); flip = true; }
        F0(i,m) F0(j,n) c[i][j] = '*';
        if (m == 1) {
            c[0][0] = 'c';
            F1(i,l) c[0][i] = '.';
            solved = true;
        } else if (m == 2) {
            if (l == 0) {
                c[0][0] = 'c';
                solved = true;
            }
            else if (l >= 3 && l % 2 == 1) {
                c[0][0] = 'c';
                c[1][0] = '.';
                F1(i,l/2) c[0][i] = c[1][i] = '.';
                solved = true;
            }
        } else {
            if (l == 0) {
                c[0][0] = 'c';
                solved = true;
            } else if (l == 3) {
                c[0][0] = 'c';
                c[1][0] = c[0][1] = c[1][1] = '.';
                solved = true;
            } else if (l == 5) {
                c[0][0] = 'c';
                c[0][1] = c[0][2] = '.';
                c[1][0] = c[1][1] = c[1][2] = '.';
                solved = true;
            } else if (l >= 7) {
                c[0][0] = 'c';
                int ci, cj, ck, cl, cx, cy;
                for (ci = 2; ci <= m; ci++)
                    for (cj = 2; cj <= n; cj++) if (!solved) {
                        if (ci*cj == l+1) {
                            F0(i,ci) F0(j,cj) if (i != 0 || j != 0) c[i][j] = '.';
                            solved = true;
                        } else if (ci * cj < l+1) {
                            for (ck = 2; ck < ci; ck++)
                                for (cl = cj+1; cl <= n; cl++) if (!solved)
                                if (ci*cj + ck*(cl-cj) == l+1) {
                                F0(i,ci) F0(j,cj) if (i != 0 || j != 0) c[i][j] = '.';
                                F0(i,ck) for (j=cj; j<cl; j++) c[i][j] = '.';
                                solved = true;
                            } else
                            if (ci*cj + ck*(cl-cj) < l+1)
                                for (cx = 2; cx < ck; cx++)
                                for (cy = cl+1; cy <= n; cy++)
                                    if (ci*cj + ck*(cl-cj)+cx*(cy-cl) == l+1 && !solved) {
                                    F0(i,ci) F0(j,cj) if (i != 0 || j != 0) c[i][j] = '.';
                                    F0(i,ck) for (j=cj; j<cl; j++) c[i][j] = '.';
                                    F0(i,cx) for (j=cl; j<cy; j++) c[i][j] = '.';
                                    solved = true;
                                }

                        }
                    }
                if (!solved) {
                    cout << m << " " << n << " " << k << endl;
                    throw 12;
                }
                solved = true;
            }
        }
        if (solved) {
            if (flip) { swap(m,n); }
            F0(i,m) {
                F0(j,n) cout << (char)(flip ? c[j][i] : c[i][j]);
                cout << endl;
            }
        } else
            cout << "Impossible" << endl;
	}
	return 0;
}
