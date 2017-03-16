#include <iostream>
#include <stdio.h>
using namespace std;

int T, A, B;
double p[100005], P[100005];
double a, b, c;

int main()
{
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    cin >> T;
    for(int t = 1; t <= T; t++)
    {
        cin >> A >> B;
        for(int i = 0; i < A; i++) cin >> p[i];
        P[0] = p[0];
        for(int i = 1; i < A; i++) P[i] = P[i - 1] * p[i];
        double ans;
        ans = (B - A + 1) * P[A - 1] + (B - A + 1 + B + 1) * (1.0 - P[A - 1]);
        if (B + 2 < ans) ans = B + 2;
        for(int i = 1; i <= A; i++)
        {
            double cur = P[A - 1] * (i + B - A + i + 1);
            for(int j = 0; j < A; j++)
            {
                double curP;
                if (j > 0) curP = P[j - 1] * (1.0 - p[j]);
                else curP = 1.0 - p[j];
                if (A - i <= j) cur += curP * (i + B - A + i + 1);
                else cur += curP * (i + B - A + i + 1 + B + 1);
                if (cur > ans) break;
            }
            if (cur < ans) ans = cur;
        }
        printf("Case #%d: %.6lf\n", t, ans);
    }
    return 0;
}
