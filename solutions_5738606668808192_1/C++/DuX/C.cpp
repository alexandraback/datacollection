#include<bits/stdc++.h>
using namespace std;

#define sz size()
#define pb push_back
#define len length()
#define clr clear()

#define eps 0.0000001
#define PI  3.14159265359

const int BRC = 32;

long long del[11],res[55555][11];

int mod[] = {1, 3, 3, 7, 3, 3};
int tr[55],dod[55][55];

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

FILE *gg;

int i,j,bb,br;

void idar(int x) {

    if (x == 0) {
        bb = true;
        for(j=1; j<=5; j++) if (tr[j] % mod[j] != 0) bb = false;

        if (bb) {
            br++;
            printf("-> %d\n", br);

            for(i=BRC-1; i>=0; i--) printf("%d", c[i]);
            printf("\n");

            for(i=BRC-1; i>=0; i--) fprintf(gg, "%d", c[i]);
            fprintf(gg, " ");
            for(i=2; i<=10; i++) fprintf(gg, "%d ", (i%2) ? 2 : mod[i/2]);
            fprintf(gg, "\n");

            if (br == 500) {
                fclose(gg);
                exit(0);
            }
        }

        return;
    }

    c[x] = 0;
    idar(x-1);

    c[x] = 1;
    for(j=1; j<=5; j++) tr[j] += dod[x][j];
    idar(x-1);
    for(j=1; j<=5; j++) tr[j] -= dod[x][j];
}

int main() {

    int i,j,p,q;

    gg=fopen("C-large.out", "w");

    for(j=1; j<=5; j++) dod[0][j] = 1;

    for(i=1; i<BRC; i++) {
        for(j=1; j<=5; j++) {
            p = (j*2) % mod[j];
            dod[i][j] = 1;
            for(q=0; q<i; q++) dod[i][j] = (dod[i][j] * p) % mod[j];
        }
    }

    for(j=1; j<=5; j++) {
        tr[j] = dod[0][j] + dod[BRC-1][j];
    }

    c[0] = 1;
    c[BRC-1] = 1;

    br = 0;
    idar(BRC-2);

    return 0;
}
