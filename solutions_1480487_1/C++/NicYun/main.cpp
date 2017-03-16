#include <iostream>
#include <vector>
#include <sstream>
#include <queue>
#include <set>
#include <map>
#include <algorithm>

#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <cmath>

using namespace std;

#define REP(i, n) for(int i = 0; i < (n); ++i)

const int N = 256;
const double EPS = 1e-12;

int T, n, a[N], sum;

bool test(int p, double per)
{
    per /= 100.0;
    double now = a[p] + sum * per;
    double left = sum * (1 - per);
    REP(i, n) if(i != p){
        left -= max(0.0, now - a[i]);
    }
    return left < 1e-10;
}

int main()
{
    freopen("in", "r", stdin);
    freopen("out", "w", stdout);
    double res[N];
    scanf("%d", &T);
    REP(t, T){
        scanf("%d", &n);
        sum = 0;
        REP(i, n) {
            scanf("%d", &a[i]);
            sum += a[i];
        }
        REP(i, n){
            double l = 0.0, h = 100.0;
            while(l <= h){
                double d = (l + h) / 2;
                if(test(i, d)) {
                    res[i] = d;
                    h = d - EPS;
                }
                else l = d + EPS;
            }
        }
        printf("Case #%d:", t + 1);
        REP(i, n) printf(" %.8lf", res[i]);
        putchar('\n');
    }
    return 0;
}
