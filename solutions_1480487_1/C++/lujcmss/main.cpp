#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>
#include <algorithm>
using namespace std;

int a[250], n;

int check(int i, int sum, double mid) {
    double tmp = a[i]+sum*mid;
    double tot = sum*(1-mid);
    for (int j=0; j<n; ++j)
        if (i!=j && a[j] < tmp)
            tot-=tmp-a[j];
    if (tot>-1e-10) return 0;
    return 1;
}
int main()
{
    freopen("A-large.in", "r", stdin);
    freopen("A-large.out", "w", stdout);

    int T;
    scanf("%d", &T);

    for (int kase=1; kase<=T; kase++) {
        int sum=0;
        scanf("%d", &n);
        for (int i=0; i<n; ++i) {
            scanf("%d", a+i);
            sum+=a[i];
        }

        printf("Case #%d:", kase);
        for (int i=0; i<n; ++i) {
            double l=0, r=1;
            while (r-l>1e-10) {
                double mid = (r+l)/2;
                if (check(i,sum,mid)) r=mid;
                else l=mid;
            }
            printf(" %.8f", 100*l);
        }
        printf("\n");
    }
}
