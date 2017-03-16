#include <cstdio>

int main() {
    int _t; scanf("%d", &_t);
    for(int _i=1; _i<=_t; _i++) {
        double c, f, x; scanf("%lf %lf %lf", &c, &f, &x);
        // c is the cost of buying a farm, f is the production of the farm, x is the number of cookies required to finish
        double t=0;
        double r=2;
        double best=x/r + 1;
        while(t + x/r < best) {
            best = t + x/r;
            t += c/r;
            r += f;
        }
        printf("Case #%d: %lf\n", _i, best);
    }
}
