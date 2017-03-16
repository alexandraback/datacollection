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

int a[555],d[555];

int main() {

    FILE *ff=fopen("C-small-attempt0.in", "r"), *gg=fopen("C-small-attempt0.out", "w");

    int n,v,c,i,j,br,tt,ttt,res;

    fscanf(ff,"%d", &ttt);
    for(tt=1;tt<=ttt;tt++) {
        fprintf(gg,"Case #%d: ", tt);

        fscanf(ff,"%d%d%d", &c, &n, &v);

        for(i=0; i<n; i++) fscanf(ff,"%d", &a[i]);

        res = 0;
        while(true) {

            for(i=0; i<=v; i++) d[i] = 0;
            d[0] = 1;

            for(i=0; i<n; i++) {
                for(j=v; j>=a[i]; j--) {
                    if (d[j-a[i]] == 1) d[j] = 1;
                }
            }

            br = -1;
            for(i=1; i<=v; i++) {
                if (d[i] == 0) {
                    br = i;
                    break;
                }
            }

            if (br == -1) break;

            res++;
            a[n++] = br;
        }

        fprintf(gg, "%d\n", res);
    }

    fclose(ff); fclose(gg);

    return 0;
}
