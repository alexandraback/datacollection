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
    map<int, int> was;
    for (int ti = 1; ti <= t; ++ti) {
        cin >> n;
        //n = 20;
        was.clear();
        for (int i = 0; i < n; ++i)
            scanf("%d", &a[i]);
        printf("Case #%d:\n", ti);
        int sum = 0;
        bool wasu=  0;
        for (int i = 0; i < (1 << n); ++i) {
            sum = 0;
            for (int j = 0; j < n; ++j)
                if (((1 << j) & i) != 0) 
                    sum += a[j];
            if (was.find(sum) != was.end()) {
                for (int j = 0; j < n; ++j)
                    if (((1 << j) & i) != 0)
                        cout << a[j] << " ";
                cout << endl;
                for (int j = 0; j < n; ++j)
                    if (((1 << j) & was[sum]) != 0)
                        cout << a[j] << " ";
                cout << endl;
                wasu = 1;
                break;
            }
            was[sum] = i;
        }
        if (!wasu) printf("Impossible\n");
    }
}
