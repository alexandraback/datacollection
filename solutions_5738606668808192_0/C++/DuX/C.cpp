#include<bits/stdc++.h>
using namespace std;

#define sz size()
#define pb push_back
#define len length()
#define clr clear()

#define eps 0.0000001
#define PI  3.14159265359

const int BRC = 16;

long long del[11],res[55555][11];

long long prost(long long x) {

    long long i;

    if (x%2LL == 0) return 2LL;

    for(i=3; i*i<=x; i++) {
        if (x%i == 0) return i;
    }

    return 0;
}


bool c[55];
bool ok(int x) {

    long long t,p,i,j;

    del[2] = prost(x);
    if (del[2] == 0) {
        return false;
    } else {

        for(i=0; i<BRC; i++) {
            if (x & (1<<i)) {
                c[i] = true;
            } else {
                c[i] = false;
            }
        }

        for(i=3; i<=10; i++) {
            t = 0;
            p = 1;
            for(j=0; j<BRC; j++) {
                if (c[j]) t += p;
                p*=i;
            }
            del[i] = prost(t);
            if (del[i] == 0) return false;
        }

        return true;
    }
}

int main() {

    long long i,t,q,br,gr,poc,maxbr;

    poc = (1<<(BRC-1));

    br = 0;
    maxbr = 50;

    gr = poc/2;
    for(q=0; q<gr; q++) {
        t = poc + 2*q + 1;

        if (ok(t) && del[8] == 3 && del[6] == 7 && del[10] == 3) {
            br++;
            for(i=BRC-1; i>=0; i--) printf("%d", c[i]);
            printf(" ");
            for(i=2; i<=10; i++) {
                //res[br][i] = del[i];
                printf("%lld ", del[i]);
            }
            printf("\n");
        }
    }

    printf("-> %lld\n", br);

//    FILE *ff=fopen("A-small-attempt0.in", "r"), *gg=fopen("A-small-attempt0.out", "w");
//
//    fscanf(ff,"%d", &ttt);
//    for(tt=1;tt<=ttt;tt++) {
//        fprintf(gg,"Case #%d: ", tt);
//
//        fprintf(gg, "%d\n", res);
//    }
//
//    fclose(ff); fclose(gg);

    return 0;
}
