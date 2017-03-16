#include <cstdio>

double p[100042];
double P[100042];
int A, B;
int T, test;

void solve(int test) {
    int i, j;
    P[1] = p[1];
    for (i = 2; i <= A; ++i)
        P[i] = P[i - 1] * p[i];

    double expected = double(1 + 1 + B);
    
    for (i = A - 1; i >= 1; --i) {
        double ex = P[i] * (2 + B - i) + (1.0 - P[i]) * (2 + B - i + 1 + B);
        if (expected > ex)
            expected = ex;
    }

    double ex = P[A] * (1 + B - A) + (1.0 - P[A]) * (1 + B - A + 1 + B);
    if (expected > ex)
        expected = ex;
   
    ex = A + B + 1;
    if (expected > ex)
        expected = ex;
    printf ("Case #%d: %.7lf\n",test, expected); 
}

int main() {
    freopen ("a.in", "r", stdin);
    freopen ("a.out", "w", stdout);
    scanf("%d\n", &T);
    for (test = 1; test <= T; ++test) {
        scanf ("%d %d\n", &A, &B);
        for (int i = 1; i <= A; ++i)
            scanf("%lf ", &p[i]);
        solve(test);
    }
}
