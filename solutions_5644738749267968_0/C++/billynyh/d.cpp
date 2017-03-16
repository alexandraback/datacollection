#include <stdio.h>
#include <string.h>
#include <algorithm>
#include <math.h>
#include <vector>
#include <string>
#include <queue>
#include <iostream>
using namespace std;

bool fless(double a,double b){ return b-a>1e-6; }
bool fequal(double a,double b){ return fabs(b-a)<=1e-6; }

int main(){
    int tt; scanf("%d",&tt);
    for (int ti=1;ti<=tt;ti++){
        int n; scanf("%d", &n);
        double a[n], b[n];
        for (int i=0;i<n;i++) scanf("%lf", &a[i]);
        for (int i=0;i<n;i++) scanf("%lf", &b[i]);

        sort(a, a+n);
        sort(b, b+n);

        /*
        for (int i=0;i<n;i++) printf("%.5lf ", a[i]); puts("");
        for (int i=0;i<n;i++) printf("%.5lf ", b[i]); puts("");
*/
        int ans1 = 0, ans2 = 0;

        // standard war
        int p = 0;
        for (int i=0;i<n;i++) {
            while (p<n && fless(b[p], a[i])) p++;
            if (p == n) {
                ans2 ++;
            } else {
                p ++;
            }
        }

        // Deceitful war
        p = 0;
        ans1 = n;
        for (int i=0;i<n;i++) {
            while (p<n && fless(a[p], b[i])) p++;
            if (p == n) {
                ans1 --;
            } else {
                p ++;
            }
        }

        printf("Case #%d: %d %d\n",ti,ans1, ans2);
    }
    return 0;
}

