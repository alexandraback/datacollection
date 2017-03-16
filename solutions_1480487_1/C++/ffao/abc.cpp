#include<iostream>
#include <cstdio>

using namespace std;

int N, T;

int scores[200];
int S, teste;

#define ITER 20000

bool possible(double mid) {
    double remaining = S;
    for (int i = 0; i < N; i++) {
        if (scores[i] > mid) continue;
        else remaining -= mid-scores[i];
    }
    
    if (remaining > 0) return false;
    return true;
}

int main () {
    for (scanf("%d", &T); T; T--) {
        scanf("%d", &N);
        
        S = 0;
        for (int i = 0; i < N; i++) {
            scanf("%d", &scores[i]);
            S += scores[i];
        }
        
        double st = 0, end = 100000;
        for (int i = 0; i < ITER; i++) {
            double mid = (st+end)/2;
            if (possible(mid)) {
                end = mid;
            }
            else st = mid;
        }
        
        printf("Case #%d:", ++teste);
        for (int i = 0; i < N; i++) {
            if (scores[i] > st) printf(" 0.00");
            else printf(" %.10lf", (st-scores[i])/S*100);
        }
        printf("\n");
    }   
}
