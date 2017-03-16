#include <vector>
#include <list>
#include <map>
#include <set>
#include <deque>
#include <queue>
#include <stack>
#include <bitset>
#include <algorithm>
#include <functional>
#include <utility>
#include <sstream>
#include <iostream>
#include <iomanip>
#include <cstdio>
#include <cmath>
#include <fstream>
#include <cstdlib>
#include <ctime>
#include <cstring>
using namespace std;

int f[200];
int s, n;
bool can(double r, int k) {
    double mi = f[k] + s*r/100;
    double rem = 100-r;
    for (int i=0; i<n; i++) {
        if (i==k) continue;
        double need = mi-f[i]>=0?(mi-f[i])*100/s+1e-10:0;
        rem -= need;
        if (rem<0) return true;
    }
    return false;
}

int main() {
    freopen("/Users/fengyelei/Desktop/in.in", "r", stdin);
    freopen("/Users/fengyelei/Desktop/out", "w", stdout);
    int T;cin>>T;
    for (int c=1; c<=T; c++) {
        cin>>n;
        s = 0;
        for (int i=0; i<n; i++) {
            scanf("%d", &f[i]);
            s += f[i];
        }
        printf("Case #%d: ", c);
        for (int i=0; i<n; i++) {
            double l = 0, r = 100, mid;
            while (fabs(r-l)>1e-10) {
                mid = l + (r-l)/2;
                if (can(mid, i)) r=mid;
                else l=mid;
            }
            printf("%.8lf ", mid);
        }
        printf("\n");
    }
}