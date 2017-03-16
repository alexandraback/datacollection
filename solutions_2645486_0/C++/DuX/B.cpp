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

int e,r,n,res,v[555];

void idar(int t, int x, int k) {

    int i;

    if (x==n) {
        if (k>res) res=k;
        return;
    }

    for(i=0; i<=t; i++) {
        idar(min(t-i+r, e), x+1, k+v[x]*i);
    }

    return;
}

int main() {

    FILE *ff=fopen("B-small-attempt0.in", "r"), *gg=fopen("B-small-attempt0.out", "w");

    int i,tt,ttt;;

    fscanf(ff,"%d", &ttt);
    for(tt=1;tt<=ttt;tt++) {

        fscanf(ff,"%d%d%d", &e, &r, &n);
        for(i=0; i<n; i++) fscanf(ff,"%d", &v[i]);

        res=0;
        idar(e,0,0);

        fprintf(gg,"Case #%d: %d\n", tt, res);
    }

    fclose(ff); fclose(gg);

    return 0;
}
