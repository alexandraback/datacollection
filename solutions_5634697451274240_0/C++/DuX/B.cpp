#include<bits/stdc++.h>
using namespace std;

#define sz size()
#define pb push_back
#define len length()
#define clr clear()

#define eps 0.0000001
#define PI  3.14159265359

int main() {

    FILE *ff=fopen("B-small-attempt0.in", "r"), *gg=fopen("B-small-attempt0.out", "w");

    int n,i,tt,res,ttt;
    char s[555];

    fscanf(ff,"%d", &ttt);
    for(tt=1;tt<=ttt;tt++) {
        fprintf(gg,"Case #%d: ", tt);

        fscanf(ff,"%s", &s);
        n = strlen(s);
        s[n] = '+';
        res = 0;
        for(i=1; i<=n; i++) res += (s[i] != s[i-1]);

        fprintf(gg, "%d\n", res);
    }

    fclose(ff); fclose(gg);

    return 0;
}
