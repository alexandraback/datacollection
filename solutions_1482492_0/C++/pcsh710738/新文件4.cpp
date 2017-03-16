#include<iostream>
#include<stdio.h>
#include<string.h>
#include<vector>
#include<math.h>
using namespace std;

int main() {
    FILE* f;
    f = fopen("PB.txt", "w");
    int T, Count = 1;
    int i, j;
    int N, A;
    double t[2000], x[2000];
    double a, D;
    double total;
    double nowX, nowV;
    double tt, v;
    cin >> T;
    while(T--) {
        cin >> D >> N >> A;
        fprintf(f, "Case #%d:\n", Count++);
        for(i = 0;i < N;i++) {
            cin >> t[i] >> x[i];
        }

        for(i = 0;i < A;i++) {
            cin >> a;
            total = 0;
            nowX = nowV = 0;
            if(N == 1) {
                total += (sqrt(nowV*nowV+2*a*(D - nowX))-nowV)/a;
            }
            else {
            for(j = 0;j < N-1;j++) {
                if(x[j] > D && j == 0) {
                    total += (sqrt(nowV*nowV+2*a*(D - nowX))-nowV)/a;
                    break;
                }
                if(x[j + 1] >= D) {
                    tt = (D - x[j]) / ((x[j + 1] - x[j]) / (t[j + 1] - t[j]));
                    total += tt;
                    nowV = nowV + a*tt;
                    nowX += 0.5*a*tt*tt;
                    if(nowX < D) {
                        total += (sqrt(nowV*nowV+2*a*(D - nowX))-nowV)/a;
                    }
                }
            } }

            fprintf(f, "%f\n", total);
        }
    }
}
