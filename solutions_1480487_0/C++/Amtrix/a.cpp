#include <iostream>
#include <vector>
#include <string.h>
#include <string>
#include <set>
#include <queue>
#include <map>
#include <algorithm>
#include <queue>
#include <iomanip>
#include <stack>
#include <assert.h>
#include <fstream>
#include <cstdlib>
#include <cstdio>
using namespace std;

#define f first
#define s second
#define mk make_pair
#define pii pair<int,int>
#define all(x) x.begin(),x.end()
#define sz(x) (int)x.size()
#define pb push_back

const double eps = 1e-14;
const int maxn = 255;
int x[maxn];
int n;
int sx;

double tmp[maxn];

double survive(int dx, double p) {
    for (int i = 0; i < n; ++i)
        tmp[i] = x[i];
    tmp[dx] += p * sx;

    double have = 1 - p;
    bool ok = true;
    for (int i = 0; i < n; ++i){
        if (dx == i) continue;
        double diff = tmp[dx] - tmp[i];
        if(diff < eps) continue;
        double pc = diff / sx;
        have -= pc;
        tmp[i] += diff;

        if (have < -eps) return true;
    }
    return false;
}

int main() {
    freopen("Ulaz","r",stdin);
    freopen("Izlaz","w",stdout);

    int tests; scanf("%d",&tests);
    for (int t = 1; t <= tests; ++t) {
        scanf("%d",&n);
        sx = 0;
        for (int i = 0; i < n; ++i) {
            scanf("%d",&x[i]);
            sx += x[i];
        }

        printf("Case #%d: ", t);
        for (int i = 0; i < n; ++i){
            double lo = 0, hi = 1;
            double mid;
            while(hi-lo > eps) {
                mid = (lo+hi)/2;
                bool w = survive(i, mid);
                if(!w) lo = mid + eps;
                else hi = mid - eps;
            }
            printf("%.10lf ",mid*100);
        }
        printf("\n");
    }

    return 0;
}
