#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cmath>
#include <algorithm>
#include <string>
#include <vector>
#include <stack>
#include <queue>
#include <set>
#include <map>
#include <time.h>
#include <cctype>
#include <functional>
#include <deque>
#include <iomanip>
#include <bitset>
#include <assert.h>
#include <numeric>
#include <sstream>
#include <utility>

#define pb push_back
#define mp make_pair
#define fi first
#define se second
#define all(a) (a).begin(),(a).end()
#define FOR(i,a,b) for (int i=(a);i<(b);i++)
#define FORD(i,a,b) for (int i=(a); i>=(b); i--)
#define REP(i,b) FOR(i,0,b)
#define ll long long
#define sf scanf
#define pf printf
using namespace std;
const int maxint = -1u>>1;
const double pi = 3.14159265358979323;
const double eps = 1e-8;
typedef pair<int,int> pii;
typedef vector<int> vi;
typedef vector<int>::iterator vit;

int n, x, y;
int ans6[][2] = {{0,0}, {2,0}, {-2, 0}, {-1, 1}, {1, 1}, {0, 2}};
int ans15[][2] = {{-4, 0}, {-3, 1}, {-2, 2}, {-1, 3}, {0, 4}, {4, 0}, {3, 1}, {2, 2}, {1, 3}};

double c[23][23];
void init() {
    c[1][1] = c[1][0] = 1;
    for (int i = 2; i <= 20; i++) {
        c[i][0] = c[i][i] = 1.0;
        for (int j = 1; j < i; j++) 
            c[i][j] = c[i-1][j] + c[i-1][j-1];
    }
}
int main() {
    freopen("B-small-attempt0.in", "r", stdin);
    freopen("B-small-attempt0.out", "w", stdout);
    int T, ca = 0;
    init();
    //cout <<c[2][1] <<endl;
    cin >>T;
    while (T--) {
        cin >>n >>x >>y;
        pf("Case #%d: ", ++ca);
        if (n == 1) {
            if (x == 0 && y == 0) pf("1.00\n");
            else pf("0.00\n");
        }
        else if (n > 1 && n < 6) {
            if (x == 0 && y == 0) pf("1.00\n");
            else {
                if (x >= -2 && x <= 2 && y <= 2) {
                    int need = abs(abs(x) - 2) + 1;
                    n--;
                    if (x == 0 && y == 2) need = 5;
                    if (n < need) puts("0.00");
                    else {
                        double ans = 0;
                        for (int i = need; i <= n; i++) ans += c[n][i];
                        //cout <<ans <<" "<<need <<" "<<n <<endl;
                        ans /= pow(2.0, 1.0*n);
                        pf("%.8f\n", ans);
                    }
                }
                else puts("0.000");
            }
        }
        else if (n == 6) {
            bool flag = false;
            REP(i, 6) {
                if (x == ans6[i][0] && y == ans6[i][1]) {
                    flag = true;
                    pf("1.00\n");
                }
            }
            if (!flag) puts("0.00");
        }
        else if (n > 6 && n < 15) {
            bool flag = false;
            REP(i, 6) {
                if (x == ans6[i][0] && y == ans6[i][1]) {
                    flag = true;
                    pf("1.00\n");
                }
            }
            if (!flag) {
                if (x >= -4 && x <= 4 && y <= 4) {
                    int need = abs(abs(x) - 4) + 1;
                    n -= 6;
                    if (x == 0 && y == 4) need = 9;
                    if (n < need) puts("0.00");
                    else {
                        double ans = 0;
                        for (int i = need; i <= n; i++) ans += c[n][i];
                        ans /= pow(2.0, 1.0*n);
                        pf("%.8f\n", ans);
                    }
                }
                else puts("0.000");
            }
        }
        else if (n == 15) {
           bool flag = false;
             REP(i, 6) {
                if (x == ans6[i][0] && y == ans6[i][1]) {
                    flag = true;
                    pf("1.00\n");
                }
             }
             REP(i, 9) {
                 if (x == ans15[i][0] && y == ans15[i][1]) {
                     flag = true;
                     pf("1.00\n");
                 }
             }
             if (!flag) puts("0.000"); 
        }
        else {
             bool flag = false;
             REP(i, 6) {
                if (x == ans6[i][0] && y == ans6[i][1]) {
                    flag = true;
                    pf("1.00\n");
                }
             }
             REP(i, 9) {
                 if (x == ans15[i][0] && y == ans15[i][1]) {
                     flag = true;
                     pf("1.00\n");
                 }
             }
             if (!flag) {
                  if (x >= -6 && x <= 6 && y <= 6) {
                    int need = abs(abs(x) - 6) + 1;
                    n -= 15;
                    if (x == 0 && y == 6) need = 100;
                    if (n < need) puts("0.00");
                    else {
                        double ans = 0;
                        for (int i = need; i <= n; i++) ans += c[n][i];
                        ans /= pow(2.0, 1.0*n);
                        pf("%.8f\n", ans);
                    }
                }
                else puts("0.000");
             }
        }
    }
    return 0;
}

