#include <stdio.h>
#include <string>
#include <cstring>
#include <algorithm>
#include <memory.h>
#include <vector>
#include <math.h>
#include <set>
#include <map>
#include <iostream>
using namespace std;

#define PI 3.141592653589793
#define INF 2123456789
#define NUL 0.000000001

#define SZ size()
#define CS c_str()
#define PB push_back
#define INS insert
#define EMP empty()
#define CLR clear()
#define LEN length()
#define ull unsigned long long

void swap(int &a, int &b){
    int c = a; a = b; b = c;
}

double sol[205];

int main(){
    freopen("A-small.in", "r", stdin);
    freopen("A-small.out", "w", stdout);
int t; scanf("%d", &t);
for (int tt = 1; tt <= t; tt++){
    int n; scanf("%d", &n);
    int a[205], idx[205], s = 0;
    for (int i = 1; i <= n; i++){
        scanf("%d", a+i);
        s += a[i];
    }

    for (int i = 1; i <= n; i++){
        double l = 0.0, r = 1.0;
        while (fabs(l - r) > NUL){
            double mid = (l + r) / 2.0;

            double xd = 0.0;
            for (int j = 1; j <= n; j++) if (j != i){
                double p = double(double(a[i]-a[j]) + mid * double(s)) / double(s);
                if (p > NUL) xd += p;
            }

            if (xd + mid < 1.0)
                l = mid + NUL;
            else
                r = mid - NUL;
        }

        sol[i] = l;
    }

    printf("Case #%d:", tt);
    for (int i = 1; i <= n; i++) printf(" %.7lf", sol[i] * 100.0); printf("\n");
}
    return 0;
}
