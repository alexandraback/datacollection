#include <stdio.h>
#include <vector>

using namespace std;

int main(int argc, const char *argv[]) {
    int T;
    int n = 1;
    scanf("%d", &T);
    while (T--) {
        int N;
        vector<int> v;
        scanf("%d", &N);
        int sum = 0;
        bool hasZero = false;
        int a = N;
        while (a--) {
            int tmp;
            scanf("%d", &tmp);
            v.push_back(tmp);
            sum += tmp;
            if (tmp == 0)
                hasZero = true;
        }
        printf("Case #%d:", n++);
        double neg = 0;
        int negNum = 0;
        for (int i = 0; i < v.size(); i++) {
            double x = (double)2 / N - (double)v[i]/sum;
            if (x < 0) {
                neg -= x;
                negNum++;
            }
        }
//         printf("neg %f\n", neg);
        for (int i = 0; i < v.size(); i++) {
            double x = (double)2 / N - (double)v[i]/sum;
            if (x < 0) {
                x = 0;
            }
            else {
//                 printf("x %f\n", x);
                x -= neg/(N-negNum);
//                 printf("x %f\n", x);
            }
            printf(" %.5f", x*100);
        }
        printf("\n");
    }
    return 0;
}
