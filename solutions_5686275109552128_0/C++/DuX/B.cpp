#include<stdio.h>
#include<vector>
#include<string>
#include<math.h>
#include<algorithm>
#include<cstring>
using namespace std;

#define sz size()
#define pb push_back
#define len length()
#define clr clear()

#define eps 0.0000001
#define PI  3.14159265359

int main() {

    FILE *ff=fopen("B-small-attempt1.in", "r"), *gg=fopen("B-small-attempt1.out", "w");

    int n,m,i,t,p1,p2,tt,res,ttt,x[5555],cnt[5555];

    fscanf(ff,"%d", &ttt);
    for(tt=1;tt<=ttt;tt++) {
        fprintf(gg,"Case #%d: ", tt);

        memset(cnt,0,sizeof(cnt));

        res = 0;

        fscanf(ff,"%d", &n);
        for(i=0; i<n; i++) {
            fscanf(ff,"%d", &x[i]);
            if (x[i] > res) res = x[i];
        }

        for(m=1; m<=1000; m++) {
            t = 0;
            for(i=0; i<n; i++) {
                t += (x[i]-1) / m;
            }
            if (t+m < res) res = t+m;
        }

        fprintf(gg, "%d\n", res);
    }

    fclose(ff); fclose(gg);

    return 0;
}
