#include<stdio.h>
#include<vector>
#include<string>
#include<math.h>
#include<algorithm>
using namespace std;

#define sz size()
#define pb push_back
#define len length()
#define clr clear()

#define eps 0.0000001
#define PI  3.14159265359

int main() {

    FILE *ff=fopen("A-small-attempt0.in", "r"), *gg=fopen("A-small-attempt0.out", "w");

    int tt,ttt;
    long long t,l,r,k,r1,pt,pk,q1,q2,res;

    fscanf(ff,"%d", &ttt);
    for(tt=1;tt<=ttt;tt++) {

        fscanf(ff,"%lld %lld", &r1, &t);

        printf("--- %d ---\n", tt);

        r1++;

        l=1; r=(1LL<<62LL);
        res = 1;
        while( l<=r ) {
            k=(l+r)/2;

            pt = t;

            pk = 2*k;

            //printf("%lld %lld %lld\n", l, r, k);
            //if (k==2) printf("ok\n");

            if (pt/pk < r1) {
                r=k-1;
                continue;
            }

            //printf("~%lld %lld\n", pt, pk);

            pt -= pk*r1;
            pt += k;

            //q1 = 2*(k-1);
            //q2 = q1 + 1;

            q1 = pk;
            q2 = k-1;

            //printf("~%lld %lld %lld\n", pt, q1, q2);

            if (q1!= 0 && (pt / q1 < q2)) {
                r=k-1;
                continue;
            }

            if (pt >= q1*q2) {
                res = k;
                l = k+1;
                continue;
            }
        }

        fprintf(gg,"Case #%d: %lld\n", tt, res);
    }

    fclose(ff); fclose(gg);

    return 0;
}
