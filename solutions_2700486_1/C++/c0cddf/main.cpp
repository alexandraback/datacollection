#include <cstdio>
#include <iostream>
#include <string>
#include <map>
#include <cassert>
#include <vector>
#include <set>
#include <algorithm>
#include <cstring>
#include <cmath>

using namespace std;

#define ll long long
#define point pair<double, double>
#define pb push_back
#define mp make_pair
#define x first
#define y second
#define uint unsigned int
//#define double long double
#define merge botva
#define M_PI 3.14159265358979323846

const int maxn = 5000000, maxt = 100020, INF = 1200000000;

#define big pair<int, string>
#define mp make_pair
#define y second

int n, m;
int a[maxn];

int main() {
        //freopen("ellipse.in", "r", stdin);
        //freopen("ellipse.out", "w", stdout);
       
        int t;
        cin >> t;
        for (int gi = 0; gi < t; ++gi) {
                int n, X, Y;
                cin >> n >> X >> Y;
                int level = (abs(X) + abs(Y)) / 2;
                int numb = Y;
                int ost = n;
                int lev;
                for (lev = 0; ; ++lev) {
                        if (1 + lev * 4 <= ost) ost -= 1 + lev * 4;
                        else break;
                }
                //lev skolko zel
                if (level < lev)
                        printf("Case #%d: 1\n", gi + 1);
                else if (level > lev)
                        printf("Case #%d: 0\n", gi + 1);
                else {
                        if (numb == 2 * level) printf("Case #%d: 0\n", gi + 1);
                        else {
                                long double res = 0.0l;
                                long double now = 1.0l;
                                //cout << "level is " << level << " need is " << numb << endl;
                                for (int i = min(ost, numb); i >= 0; --i) {
                                        if (i + max(ost - i - (2 * lev), 0) <= numb) {
                                                //cout << "can " << i << endl;
                                                int ozt = ost;
                                                now = 1;//
                                                res = 1;
                                                for (int j = 1; j <= i; ++j) {
                                                        now = now * (ost - j + 1.0l) / j;
                                                        while (now > 2 && ozt > 0) --ozt, now /= 2, res /= 2;
                                                        res = res + now;
                                                }
                                                while (ozt) res /= 2, --ozt;
                                                break;
                                        }
                                }
                                res = 1 - res;
                                printf("Case #%d: ", gi + 1);
                                cout.precision(20);
                                cout << res << endl;
                        }
                }
        }
}
