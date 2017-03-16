#include <vector>
using namespace std;

int main() {
    int t;

    FILE *in = fopen("input.txt", "r");
    FILE *out = fopen("output.txt", "w");
    fscanf(in, "%d", &t);
    for (int l=1; l<=t; l++) {
        double c, f, x;
        fscanf(in, "%lf %lf %lf\n", &c, &f, &x);
        double cur = 2.0;
        double res = x / cur;

        double tt = c/cur;
        while(tt + x/(cur+f) < res) {
            res = tt + x/(cur+f);

            cur += f;
            tt += c/cur;
        }
        fprintf(out, "Case #%d: %.7lf\n", l, res);
    }
    return 0;
}
