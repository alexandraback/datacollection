#include <cstdio>
#include <iostream>
#include <vector>

using namespace std;

int N, X, Y;

double solve() {
    int layer = (X+Y) / 2;
    int used = layer > 0 ? (1 + 1+(layer-1)*2) * ((layer-1)*2+1) / 2 : 0;
    int rest = N - used;
    // cout << rest << endl;
    if (rest <= Y)
        return 0.;

    int overflow = 0;
    if (rest >= layer*2+1)
        overflow = rest - (layer*2);
    if (overflow > Y)
        return 1.;

    if (X == 0)
        return 0.;

    // cout << rest << ' ' << Y << ' ' << overflow << endl;
    double x = 0.;
    double curr = 1;
    for (int i = 0; i <= Y; i++) {
        x += curr;
            curr = curr * (rest - i) / (i + 1);
    }

    for (int i = 0; i < rest; i++)
        x /= 2;

    return 1 - x;
}

int main() {
    int T;
    scanf("%d", &T);
    for (int testcase = 1; testcase <= T; testcase++) {
        scanf("%d%d%d", &N, &X, &Y);
        if (X < 0)
            X = -X;

        printf("Case #%d: %lf\n", testcase, solve());
    }
    return 0;
}
