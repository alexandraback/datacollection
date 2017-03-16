#include <cstdio>
#include <cstring>
#include <cmath>
#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
#include <map>
#include <sstream>
#include <queue>
using namespace std;
#define out(x) (cout<<#x<<": "<<x<<endl)
const int maxint=0x7FFFFFFF;
typedef long long lint;
template<class T>void show(T a, int n){for(int i=0; i<n; ++i) cout<<a[i]<<' '; cout<<endl;}
template<class T>void show(T a, int r, int l){for(int i=0; i<r; ++i)show(a[i],l);cout<<endl;}

int a, b;
double d[100010];

double solve() {
    double ret = b + 2;
    double right = 1, wrong = 0;
    for (int i=0; i<=a; ++i) {
        double exp = a - i;
        exp += right * (b - i + 1);
        exp += wrong * (b - i + 1 + b + 1);
        if (exp < ret) ret = exp;
        right *= d[i];
        wrong = 1. - right;
    }
    return ret;
}

int main()
{
    int z;
    scanf("%d", &z);
    for (int i=1; i<=z; ++i) {
        scanf("%d %d", &a, &b);
        for (int j=0; j<a; ++j) {
            scanf("%lf", d+j);
        }
        printf("Case #%d: %.10lf\n", i, solve());
    }
    return 0;
}

