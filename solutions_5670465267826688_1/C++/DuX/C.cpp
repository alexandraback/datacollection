#include<stdio.h>
#include<vector>
#include<string>
#include<math.h>
#include<cstring>
#include<algorithm>
using namespace std;

#define sz size()
#define pb push_back
#define clr clear()

#define eps 0.0000001
#define PI  3.14159265359

long long mulop[4][4] = {
    {1, 2, 3, 4},
    {2,-1, 4,-3},
    {3,-4,-1, 2},
    {4, 3,-2,-1}
};

long long mul(long long x, long long y) {
    if ((x>0 && y>0) || (x<0 && y<0)) return mulop[abs(x)-1][abs(y)-1];
    else return -mulop[abs(x)-1][abs(y)-1];
}

long long l,x,n,off,len,d[33555],a[33555],suff[33555];
bool mark[33555];
char s[33555];

long long ostatak(long long p) {

    long long i,t,k,q;

    i = p%l;

    if (i == 0) t = 1; else t = suff[i];

    k = n-p;
    q = k/l;

    if (q <= off) return mul(t,d[q]);

    q = (q-off)%len + off;
    return mul(t,d[q]);

}

int main() {

    FILE *ff=fopen("C-large.in", "r"), *gg=fopen("C-large.out", "w");

    long long i,t,tt,ceo,ttt;
    bool imaI;
    string res;

    fscanf(ff,"%lld", &ttt);
    for(tt=1;tt<=ttt;tt++) {
        fprintf(gg,"Case #%lld: ", tt);

        fscanf(ff,"%lld%lld", &l, &x);
        fscanf(ff,"%s", &s);

        n = l*x;

        ceo = 1;
        for(i=0; i<l; i++) {
            a[i] = s[i] - 'i' + 2;
            ceo = mul(ceo, a[i]);
        }

        memset(mark,0,sizeof(mark));
        d[0] = 1;
        i = 1;
        while(true) {
            d[i] = mul(ceo, d[i-1]);
            if (mark[d[i]+55]) {
                off = mark[d[i]+55];
                len = i-off;
                break;
            }
            mark[d[i]+55] = i;
            i++;
        }

        suff[l] = 1;
        for(i=l-1; i>=0; i--) {
            suff[i] = mul(a[i],suff[i+1]);
        }

        res = "NO";
        t = 1;
        imaI = false;
        for(i=0; i<n-1; i++) {
            t = mul(t,a[i%l]);
            if (t == 2) imaI = true;
            if (imaI && t == 4 && ostatak(i+1) == 4) {
                res = "YES";
            }
            if (i == 1333555) break;
        }

        fprintf(gg, "%s\n", res.c_str());
    }

    fclose(ff); fclose(gg);

    return 0;
}
