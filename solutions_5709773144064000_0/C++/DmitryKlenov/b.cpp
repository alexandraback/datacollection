#define _CRT_SECURE_NO_DEPRECATE
#include <iostream>
using namespace std;

double const EPS = 1E-10;

double solveCase() {
    double C, F, X;
    cin >> C >> F >> X;

    double curF = 2, curT = 0;

    while (curF * (C / F + C / curF) < X - EPS) {
        curT += C / curF;
        curF += F;
    }
    return curT + X / curF;

}

int main() {
    freopen("input.txt", "rt", stdin);
    freopen("output.txt", "wt", stdout);

    int tk;
    scanf("%d", &tk);
    for(int tc = 1; tc <= tk; ++tc) {
        printf("Case #%d: %.10lf\n", tc, solveCase());
        cerr << "Case #" << tc << " is solved." << endl;
    }
    return 0;
}