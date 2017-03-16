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

int mulop[4][4] = {
    {1, 2, 3, 4},
    {2,-1, 4,-3},
    {3,-4,-1, 2},
    {4, 3,-2,-1}
};

int mul(int x, int y) {
    if ((x>0 && y>0) || (x<0 && y<0)) return mulop[abs(x)-1][abs(y)-1];
    else return -mulop[abs(x)-1][abs(y)-1];
}

int a[33555],suff[33555];
char s[33555];

int main() {

    FILE *ff=fopen("C-small-attempt0.in", "r"), *gg=fopen("C-small-attempt0.out", "w");

    int l,x,n,i,t,tt,ttt;
    bool imaI;
    string res;

    fscanf(ff,"%d", &ttt);
    for(tt=1;tt<=ttt;tt++) {
        fprintf(gg,"Case #%d: ", tt);

        fscanf(ff,"%d%d", &l, &x);
        fscanf(ff,"%s", &s);
        n = l*x;
        for(i=l; i<n; i++) s[i] = s[i%l];

        for(i=0; i<n; i++) {
            a[i] = s[i] - 'i' + 2;
        }

        suff[n] = 1;
        for(i=n-1; i>=0; i--) {
            suff[i] = mul(a[i],suff[i+1]);
        }

        res = "NO";
        t = 1;
        imaI = false;
        for(i=0; i<n-1; i++) {
            t = mul(t,a[i]);
            if (t == 2) imaI = true;
            if (imaI && t == 4 && suff[i+1] == 4) {
                res = "YES";
            }
        }

        fprintf(gg, "%s\n", res.c_str());
    }

    fclose(ff); fclose(gg);

    return 0;
}
