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

long long a[555];

int main() {

    FILE *ff=fopen("C-large.in", "r"), *gg=fopen("C-large.out", "w");

    long long n,v,c,i,j,br,tr,tt,ttt,res;

    fscanf(ff,"%lld", &ttt);
    for(tt=1;tt<=ttt;tt++) {
        fprintf(gg,"Case #%lld: ", tt);

        fscanf(ff,"%lld%lld%lld", &c, &n, &v);

        for(i=0; i<n; i++) fscanf(ff,"%lld", &a[i]);

        res = 0;
        while(true) {

            sort(a,a+n);

            br = -1;
            tr = 1;
            for(i=0; i<n; i++) {
                if (a[i] > tr) {
                    br = tr;
                    break;
                } else {
                    tr += c*a[i];
                    if (tr > v) break;
                }
            }

            if (tr > v) break;
            if (br == -1) br = tr;

            res++;
            a[n++] = br;
        }

        fprintf(gg, "%lld\n", res);
    }

    fclose(ff); fclose(gg);

    return 0;
}
