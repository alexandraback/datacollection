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

    int br,tt,ttt;
    long long p,n,i,res;
    bool mark[55];

    fscanf(ff,"%d", &ttt);
    for(tt=1;tt<=ttt;tt++) {
        fprintf(gg,"Case #%d: ", tt);

        for(i=0; i<10; i++) mark[i] = false;
        br = 10;
        res = -1;

        fscanf(ff, "%lld", &n);
        for(i=1; i<=1000; i++) {
            p = n*i;
            while(p) {
                if (!mark[p%10]) {
                    br--;
                    mark[p%10] = true;
                }
                p/=10;
            }
            if (br == 0) {
                res = i*n;
                break;
            }
        }

        if (res == -1) {
            fprintf(gg, "INSOMNIA\n");
        } else {
            fprintf(gg, "%lld\n", res);
        }
    }

    fclose(ff); fclose(gg);

    return 0;
}
