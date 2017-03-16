#include <stdio.h>
#include <math.h>
#include <algorithm>

using namespace std;

int n, A[1024], sum;

bool judge(int index, double p) {
    double value = A[index] + sum * p;
    double left = 1 - p;
    for (int j = 0; j < n ; j++){
        if (j == index) continue;
        if (A[j] > value) continue;
        left = left - (value - A[j]) / sum;
    }
   if (left < -1e-8) return true;
   else return false;
}

double solve(int index) { 
    double begin = 0.0, end = 1.0;
    while(fabs(end - begin) > 1e-8) {
        double mid = (begin + end) / 2;
        if (judge(index, mid)) {
             end = mid; 
        } else {
            begin = mid;
        }
    }
    return begin * 100;
}

int main() {
    int T;
    scanf("%d", &T);
    for(int cases = 1; cases <= T; cases++) {
        scanf("%d",&n);
        sum = 0;
        for(int i = 0;i < n; i++){
            scanf("%d", &A[i]);
            sum += A[i];
        }
        printf("Case #%d:", cases);
        for(int i = 0; i < n; i++){
            printf(" %.6lf", solve(i));
        }
        printf("\n");
    }
    return 0;
}
