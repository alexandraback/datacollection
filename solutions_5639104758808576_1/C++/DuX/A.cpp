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

    int n,i,tr,tt,res,ttt;
    char s[5555];

    fscanf(ff,"%d", &ttt);
    for(tt=1;tt<=ttt;tt++) {
        fprintf(gg,"Case #%d: ", tt);

        fscanf(ff,"%d%s", &n, &s);

        res = 0;
        tr = 0;

        for(i=0; i<=n; i++) {
            if (tr < i && s[i] > '0') {
                res += (i-tr);
                tr = i;
            }
            tr += s[i] - '0';
        }

        fprintf(gg, "%d\n", res);
    }

    fclose(ff); fclose(gg);

    return 0;
}
