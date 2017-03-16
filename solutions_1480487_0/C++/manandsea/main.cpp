#include <iostream>
#include <cmath>
#include <cstring>
#include <string>
#include <vector>
#include <cstdio>
#include <set>

using namespace std;

int s[256];
const double eps = 1e-8;
int main()
{
    freopen("A-small-attempt0.in", "r", stdin);
    freopen("A-small-attempt0.out", "w", stdout);
    int T, N;
    cin >> T;
    for (int ca = 1; ca <= T; ++ ca) {
        int sum = 0;

        cin >> N;
        for (int i = 0; i < N; ++ i) {
            cin >> s[i];
            sum += s[i];
        }

        printf("Case #%d:", ca);
        for (int i= 0; i < N; ++ i) {
            double low = 0, high = 100.0;
            while (low + eps < high) {
                double mid = (low + high) / 2;
                double score = s[i] + mid / 100 * sum;
                double cost = mid;
                for (int j = 0; j < N; ++ j) if (j != i) {
                    if (s[j] < score) {
                        cost += (score - s[j]) / sum * 100;
                    }
                }
                if (cost > 100.0) {
                    high = mid;
                } else low = mid;
            }
            printf(" %.6lf", low);
        }
        puts("");
    }
}
