#include <cstdio>
#include <cmath>
#include <cstring>
#include <cassert>
#include <cstdlib>
#include <ctime>

#include <algorithm>
#include <iomanip>
#include <iostream>
#include <vector>
#include <set>
#include <queue>
#include <map>

using namespace std;

typedef long long ll;

double C, F, X;

bool check(double t)
{
    double c = 2;
    while (true) {
        if (t * c >= X) return true;
        if (t * c <= C) return false;
        t -= C / c;
        c += F;
    }
}

int main()
{
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    
    int tests;
    scanf("%d", &tests);
    for (int test = 1; test <= tests; ++test) {
        scanf("%lf%lf%lf", &C, &F, &X);
        
        double bl = 0.0, br = X / 2.0;
        for (int itr = 0; itr < 100; ++itr) {
            double bm = (bl + br) / 2.0;
            if (check(bm)) {
                br = bm;
            } else {
                bl = bm;
            }
        }
            
        printf("Case #%d: %.7lf\n", test, bl);
    }

    return 0;
}

