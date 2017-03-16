#include <cmath>
#include <cstdio>
#include <string>
#include <string.h>
#include <vector>
#include <algorithm>
#include <cassert>
#include <map>
#include <memory>

#define sz(a) ((int)(a).size())
#define fori(i,b,e) for(int i = (b); i < (e); ++i)
#define pb push_back
#define mp make_pair

using namespace std;

typedef long double ldb;

const int maxn = 2000;
double ti[maxn], xi[maxn], as[maxn];
ldb t[maxn], x[maxn];
double di;
ldb d;
int n, ac;
const double eps = 1e-8;

int main() {
    freopen("in.txt", "rt", stdin);
    freopen("out.txt", "wt", stdout);
    int TT;
    scanf ("%d\n", &TT);
    for (int tt = 1; tt <= TT; ++tt) {
        printf("Case #%d:\n", tt);
        scanf ("%lf%d%d", &di, &n, &ac);
        d = di;
        fori(i,0,n) {
            scanf ("%lf%lf", ti+i, xi+i);
            t[i] = ti[i];
            x[i] = xi[i];
        }
        while (x[n-1] > d - eps) {
            n--;
        }
        n++;
        if (x[n-1] > d) {
            if (n > 1) {
                t[n-1] = (t[n-1] - t[n-2]) * (ldb)(d - x[n-2]) / (x[n-1] - x[n-2]);
                x[n-1] = d;
            } else {
                x[0] = d;
            }
        }
        fori(i,0,ac) {
            scanf ("%lf", as+i);
        }
        fori(j,0,ac) {
            ldb a = as[j];
            ldb prevx = 0;
            ldb curt = 0;
            ldb v0 = 0;
            /*
            fori(i,1,n) {
                ldb dx = (x[i] - prevx);
                ldb ct = curt + (-v0 + sqrtl(v0*v0 + 2*a*dx)) / a;
                if (ct < t[i]) {
                    curt = t[i];
                    v0 = (ldb)(x[i] - x[i-1]) / (t[i] - t[i-1]);
                    prevx = x[i];
                }
            }
            //ldb dx = (x[n-1] - prevx);
            //ldb ct = curt + (-v0 + sqrtl(v0*v0 + 2*a*dx)) / a;
            */
            ldb dt = 0;
            fori(i,1,n) {
                ldb dx = (x[i] - prevx);
                ldb ct = curt + (-v0 + sqrtl(v0*v0 + 2*a*dx)) / a;
                dt = max(dt, t[i] - ct);
            }
            ldb ct = sqrtl(2*x[n-1]/a);
            printf ("%.10lf\n", double(ct+dt));
        }
    }
}
