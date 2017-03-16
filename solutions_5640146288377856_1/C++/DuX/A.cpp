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

    FILE *ff=fopen("A-large.in", "r"), *gg=fopen("A-large.out", "w");

    int r,c,w,tt,res,ttt;

    fscanf(ff,"%d", &ttt);
    for(tt=1;tt<=ttt;tt++) {
        fprintf(gg,"Case #%d: ", tt);

        fscanf(ff,"%d%d%d", &r, &c, &w);

        res = r*(c/w) + w - ((c%w) == 0);

        fprintf(gg, "%d\n", res);
    }

    fclose(ff); fclose(gg);

    return 0;
}
