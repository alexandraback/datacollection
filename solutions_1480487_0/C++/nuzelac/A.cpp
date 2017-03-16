#include <cstdio>

using namespace std;

int s[300];

int main() {
    int test;
    scanf("%d", &test);
    for(int t = 0; t < test; ++t) {
        int n, sum = 0;
        scanf("%d", &n);
        for(int i = 0; i < n; ++i) {
            scanf("%d", &s[i]); 
            sum += s[i];
        }
        printf("Case #%d: ", t+1);
        double negative = 0;
        int k = 0;
        for(int i = 0; i < n; ++i) {
            double p = (2 * sum / (double)n - s[i]) / (double)sum;
            if(p < 0) {
                negative += p;
            } else {
                ++k;
            }
        }
        for(int i = 0; i < n; ++i) {
            double p = (2 * sum / (double)n - s[i]) / (double)sum;
            if(p < 0) {
                p = 0;
            } else {
                p += negative / k;
            }
            printf("%lf ", p * 100.0);
        }
        printf("\n");
    }
    return 0;
}
