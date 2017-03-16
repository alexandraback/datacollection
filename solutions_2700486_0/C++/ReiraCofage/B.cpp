#include <cstdio>
#include <cstring>

using namespace std;

bool M[128][64];
int tot, conta[128][64], C=1, T;
double resp[24][128][64];

void poe(int n, int x, int y) {
    if (n==0) {
        for (int i=0;i<128;i++) for (int j=0;j<64;j++)
            if (M[i][j]) conta[i][j]++;
        tot++;
        return;
    }
    if (y==0) {
        M[x][y]= true;
        poe(n-1,60,60);
        M[x][y]=false;
        return;
    }
    int x1,y1,x2,y2,x3,y3;
    x1=x-1; y1=y-1;
    x2=x+1; y2=y-1;
    x3=x;   y3=y-2;
    if (M[x1][y1] and M[x2][y2]) {
        M[x][y] = true;
        poe(n-1,60,60);
        M[x][y] = false;
        return;
    }
    if (M[x1][y1]) {
        poe(n,x2,y2);
        return;
    }
    if (M[x2][y2]) {
        poe(n,x1,y1);
        return;
    }
    if (!M[x3][y3]) {
        poe(n,x3,y3);
        return;
    }
    poe(n,x1,y1);
    poe(n,x2,y2);
}

int main() {

    for (int d=1;d<=20;d++) {
        memset(M,false,sizeof(M));
        memset(conta,0,sizeof(conta));
        tot=0;
        poe(d,60,60);
        for (int i=0;i<128;i++)
            for (int j=0;j<64;j++)
                resp[d][i][j] = (double)conta[i][j]/(double)tot;
    }

    for(scanf("%d",&T);T--;) {
        int n, x, y;
        scanf("%d %d %d",&n,&x,&y);
        x += 60;
        double r;
        if (!(0 <= x and x < 128 and 0 <= y and y < 64))
            r = 0.0;
        else
            r = resp[n][x][y];
        printf("Case #%d: %.12lf\n",C++,r);
    }

    return 0;
}
