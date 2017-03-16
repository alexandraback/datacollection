#include <stdio.h>
#include <cstdlib>
#include <queue>
#include <algorithm>
#include <cmath>
#include <string>
#include <iostream>
#include <algorithm>
#include <vector>
#define M 9973
using namespace std;

int main() {
    freopen("A-small-attempt0.in", "r", stdin);
    freopen("out.txt", "w", stdout);
    int cas;
    scanf("%d", &cas);
    for (int i = 0; i < cas; i++) {
        int n;
        scanf("%d", &n);
        int num[1000];
        int N[1000];
        double total = 0;
        double sum = 0;
        for (int i = 0; i < n; i++) {
            scanf("%d", &num[i]);
            N[i] = num[i];
            total += num[i];
        }
        sort(N, N + n);
        N[n] = 1000;
        int e = n;
        for (int i = 0; i < n; i++) {
            sum += N[i];
            if ((sum + total) / (i + 1) < N[i + 1]) {
                e = i + 1;
                break;
            }
        }
        printf("Case #%d:", i + 1);
        for (int i = 0; i < n; i++) {
            if (num[i] < N[e]) printf(" %.6lf", ((total + sum) / e - num[i]) / total * 100);
            else printf(" 0.000000");
        }
        printf("\n");
    }
    return 0;
}