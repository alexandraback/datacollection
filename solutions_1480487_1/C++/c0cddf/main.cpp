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
#include <cstring>
 
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
#define double long double
#define time botva1

#ifdef ONLINE_JUDGE
#define olo "%I64d\n"
#define jolo "%011I64d"
#else
#define olo "%lld\n"
#define jolo "%011Ld"
#endif

#define satan2 atan2
const int maxn = 420000, maxlen = 502 * 502 + 20, consta = 1050, maxi = consta + 4, big = 10000000,
magic = 239, magic1 = 359;
const long long INF = 1000000000;
const char BLANK = '-', FULL = '#';

int a[maxn];
int n;
long long sum = 0;

bool good(int skip, double w, double wha) {
    //w < a[i] + sum * x
    //(w - a[i]) / sum < x
    double need = 0;
    for (int i = 0; i < n; ++i)
        if (i != skip)
            need += max(0.0l, (w - a[i]) / sum);
    if (wha + need > 1) return 0;
    return 1;
}

int main() {
    //freopen("complexity.in", "r", stdin);
    //freopen("complexity.out", "w", stdout);
   
    int h, m, t;
    cin >> t;
    double eps = 1E-13;
    cout.precision(10);
    for (int ti = 1; ti <= t; ++ti) {
        scanf("%d", &n);
        sum = 0;
        for (int i = 0; i < n; ++i) {
            scanf("%d", &a[i]);
            sum += a[i];
        }
        cout << "Case #" << ti << ": ";
        for (int i = 0; i < n; ++i) {
            double l = 0.0, r = 1.0, m;
            while (r - l > eps) {
                m = (l + r) * 0.5;
                if (!good(i, m * sum + a[i], m))
                    r = m;
                else l = m;
            }
            cout << l * 100 << " ";
        }
        cout << endl;
    }
}
