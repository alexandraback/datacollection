#include <iostream>
#include <cstdio>

using namespace std;

int n;
double sum, toAssign;
const double EPS = 1e-7;
int points[300];

double binarySearch(int contestant) {

    double begin = 0.0, end = 100.0;

    while (end - begin > EPS) {

        double middle = (begin + end) / 2.0;
        toAssign = sum * (100.0 - middle) / 100.0;

        double deficit = 0.0;

        for (int i = 0; i < n; i++) {

            if (i != contestant && double(points[i]) < double(points[contestant]) 
                + (middle / 100.0) * sum) {
                deficit += double(points[contestant]) + (middle / 100.0) * sum - double(points[i]);
            }
        }

        if (deficit >= toAssign) {
            end = middle;
        } else {
            begin = middle;
        }
    }

    return begin;
}

int main() {

    int t;

    scanf("%d", &t);

    for (int i = 1; i <= t; i++) {

        scanf("%d", &n);

        for (int j = 0; j < n; j++)
            scanf("%d", &points[j]);

        sum = 0.0;

        for (int j = 0; j < n; j++)
            sum += double(points[j]);

//         cout << "suma: " << sum << '\n';

        printf("Case #%d: ", i);

        for (int j = 0; j < n; j++) {
            printf("%.5lf ", binarySearch(j));
        }

        printf("\n");
    }

    return 0;
}
