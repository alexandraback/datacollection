#include <stdio.h>
#include <algorithm>
using namespace std;
int n;
double a[1111];
double b[1111];

int getDeceitful() {
    int p1 = 0;
    int p2 = 0;
    int score = 0;
    while (p1 < n && p2 < n) {
        if (a[p1] > b[p2]) {
            score++;
            p1++;
            p2++;
        } else {
            p1++;
        }
    }
    return score;
}

int getNormal() {
    int p1 = 0;
    int p2 = 0;
    int score = 0;
    while (p1 < n && p2 < n) {
        if (b[p1] > a[p2]) {
            score++;
            p1++;
            p2++;
        } else {
            p1++;
        }
    }
    return n - score;
}

int main() {
    int tn;
    scanf("%d", &tn);
    for (int cn = 1; cn <= tn; cn++) {
        printf("Case #%d: ", cn);

        scanf("%d", &n);
        for (int i = 0; i < n; i++) {
            scanf("%lf", &a[i]);
        }
        for (int i = 0; i < n; i++) {
            scanf("%lf", &b[i]);
        }
        sort(a, a + n);
        sort(b, b + n);

        printf("%d ", getDeceitful());
        printf("%d\n", getNormal());
    }
    return 0;
}
