#include <cstdio>

int space[20005][20005];
int counter;

void rec(int i, int &n, int &x, int &y) {
    if(i==0) {
        counter = 0;
    }
    if(i==n) {
        counter += space[x+10000][y];
        /*
        if(space[x+500][y]) {
            for(int j=490; j<510; j++) {
                for(int k=0; k<6; k++) {
                    printf("%d ", space[j][k]);
                }
                printf("\n");
            }
        }
        printf("\n");
        */
        return;
    }
    int s=10000, t=0;
    while(space[s][t]!=0) t+=2;
    while(t>0 and space[s-1][t-1]==0) {
        s-=1; t-=1;
    }
    while(t>0 and space[s+1][t-1]==0) {
        s+=1; t-=1;
    }
    space[s][t] = 1;
    rec(i+1, n, x, y);
    space[s][t] = 0;
    s=10000; t=0;
    while(space[s][t]!=0) t+=2;
    while(t>0 and space[s+1][t-1]==0) {
        s+=1; t-=1;
    }
    while(t>0 and space[s-1][t-1]==0) {
        s-=1; t-=1;
    }
    space[s][t] = 1;
    rec(i+1, n, x, y);
    space[s][t] = 0;
}

int main() {
int _t; scanf("%d", &_t);
for(int _i=1; _i<=_t; _i++) {
    printf("Case #%d: ", _i);
    int n, x, y; scanf("%d %d %d", &n, &x, &y);
    rec(0, n, x, y);
    double answer=(double)counter;
    for(int i=0; i<n; i++) {
        answer /= 2;
    }
    printf("%lf\n", answer);
}
}
