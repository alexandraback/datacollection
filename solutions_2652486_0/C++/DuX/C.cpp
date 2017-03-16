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

    FILE *ff=fopen("C-small-1-attempt0.in", "r"), *gg=fopen("C-small-1-attempt0.out", "w");

    int i,r,k,n,m,t,q,p,w,pw,br,a1,a2,a3,r1,r2,r3,tt,ttt,pr[555];

    fscanf(ff,"%d", &ttt);
    for(tt=1;tt<=ttt;tt++) {

        fprintf(gg,"Case #%d:\n", tt);

        //scanf("%d", &r);
        //r = 100; k = 7; m = 5;
        //r = 3; k = 4; m = 4;

        fscanf(ff, "%d%d%d%d", &r, &n, &m, &k);

        //printf("%d %d %d\n", r, k, m);

        for(t=0; t<r; t++) {

            for(i=0; i<535; i++) pr[i] = 0;

            //printf("ok\n");

            for(i=0; i<k; i++) {
                fscanf(ff, "%d", &p);
                //printf("-> %d\n", p);
                pr[p]++;
            }

            //printf("ok\n");

            r1=2; r2=2; r3=2;
            q = 0; w = 0;
            for(a1=2; a1<=m; a1++) {
                for(a2=a1; a2<=m; a2++) {
                    for(a3=a2; a3<=m; a3++) {

                        br = (pr[a1] + pr[a2] + pr[a3] + pr[a1*a2] + pr[a1*a3] + pr[a2*a3] + pr[a1*a2*a3]);
                        pw = (a1!=a2) + (a1!=a3) + (a2!=a3);

                        //printf("%d %d %d ~ %d\n", a1, a2, a3, br);
                        //if (a1 == 3 && a2==3 && a3 == 4) printf("%d\n", br);

                        if (br > q || (br == q && pw > w)) {
                            q=br;
                            w = pw;
                            //printf("-> %d %d %d\n", a1, a2, a3);
                            r1 = a1; r2 = a2; r3 = a3;
                        }

                    }
                }
            }

            fprintf(gg, "%d%d%d\n", r1, r2, r3);
        }

    }

    fclose(ff); fclose(gg);

    return 0;
}
