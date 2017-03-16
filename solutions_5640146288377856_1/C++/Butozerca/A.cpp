#include<cstdio>
using namespace std;


int solve(int r, int thisc, int c, int w) {
    if(r == 1) {
        if(thisc == w) return w;

        if(thisc <= 2*w-1)
            return w+1;

        return 1+solve(r, thisc-w, c, w);
    } else {
        if(thisc <= 2*w-1)
            return 1+solve(r-1, c, c, w);
        return 1+solve(r, thisc-w, c, w);
    }
}

int main() {
    int Z;
    scanf("%d", &Z);
    for(int zz = 1; zz <= Z; ++zz) {
        int r, c, w;
        scanf("%d %d %d", &r, &c, &w);
        printf("Case #%d: %d\n", zz, solve(r, c, c, w));
    }
    return 0;
}
