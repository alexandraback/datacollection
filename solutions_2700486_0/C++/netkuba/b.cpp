#include <cstdio>
#include <cmath>

using namespace std;

const int M = 2000;

long double p[M][M];

void prep() {
    p[0][0] = 1;
    for (int i=1; i<M; ++i) {
        p[i][0] = p[i-1][0] / 2;
        p[i][i] = p[i-1][i-1] / 2;
        for (int j=1; j<i; ++j) {
            p[i][j] = (p[i-1][j-1] + p[i-1][j]) / 2;
        }
    }
}

int tri(int a) {
    return (a*2)*(a*2-1)/2;
}

int counter = 0;
void make() {
    printf("Case #%d: ", ++counter);
    int x, y, n; scanf("%d %d %d", &n, &x, &y);

    int layer = (abs(x) + y) / 2;
    int mmin = tri(layer);
    int mmax = tri(layer+1);

    if (mmin >= n) {
//        printf("X");
        printf("0.0\n");
        return;
    }
    if (n >= mmax) {
//        printf("Y");
        printf("1.0\n");
        return;
    }

    if (x == 0) {
//        printf("O");
        printf("0.0\n");
        return;
    }

    n -= mmin;
    
    layer *= 2;
    y += 1;

//    printf("%d %d %d ", layer, y, n);

    if (n >= layer + y) {
//        printf("Z");
        printf("1.0\n");
        return;
    }
    if (n < y) {
//        printf("T");
        printf("0.0\n");
        return;
    }
    long double res = 0;
    for (int i = y; i <= n; ++i) {
//        printf("(%d %d) ", n, i);
        res += p[n][i];
    }
    printf("%.7Lf\n", res);
}

int main() {
    prep();
    int t; scanf("%d", &t);
    while(t--) make();
    return 0;
}
