#include <cstdio>
#include <vector>
#include <limits>
using namespace std;




void solve(int tc) {
    int A,B;
    scanf("%d %d", &A, &B);
    vector<double> p(A);
    for (int i = 0; i < A; ++i)
        scanf("%lf", &p[i]);
    
    double prob_correct = 1.;
    for (int i = 0; i < A; ++i)
        prob_correct *= p[i];

    double expect[3] = {numeric_limits<double>::max(),numeric_limits<double>::max(),numeric_limits<double>::max()};
    // strategy 3
    expect[2] = B+2;
    // strategy 1
    expect[0] = (B-A+1) + (1-prob_correct)*(B+1);

    // find the best of the backspace strategies...
    prob_correct = 1.;
    expect[1] = A + B + 1;  // remove all characters
    for (int i = 0; i < A-1; ++i) {
        // backspace to i
        prob_correct *= p[i];
        expect[1] = min(expect[1],
                (A-i-1) + // num of backspaces
                (B-i-1+1) + // num of characters to be retyped
                (1-prob_correct)*(B+1));
    }


    double ans = numeric_limits<double>::max();
    for (int i = 0; i < 3; ++i)
        ans = min(ans, expect[i]);
    printf("Case #%d: %.7lf\n", tc, ans);
}








int main() {
    int T;
    scanf("%d", &T);
    for (int t = 1; t <= T; ++t)
        solve(t);
    return 0;
}
