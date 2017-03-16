/*
 * Author: Lixiang Liu
 * Created Time:  2012/4/28 9:04:55
 * File Name: \TopCoder\gcj2012\R1A\A.cpp
 */
#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;

int main() {
    FILE *fin, *fout;    
    fin = fopen("D:\\TopCoder\\gcj2012\\R1A\\A-small-attempt0.in", "r");
    fout = fopen("D:\\TopCoder\\gcj2012\\R1A\\A.out", "w");
    int T;
    fscanf(fin, "%d\n", &T);
    for (int ca = 1; ca <= T; ca++) {
        int A, B;
        fscanf(fin, "%d %d", &A, &B);
        double pro[A];
        for (int i = 0; i < A; i++) {
            fscanf(fin, "%lf", &pro[i]);
        }
        double ans = B*2 + 2, p = 1;
        ans = A + B+1;
        //cout << "== " << ans << endl;///
        if (A < B) {
            int tmp = 1 + B+1;
            if (ans > tmp) ans = tmp;
            //cout << "give " << ans << endl;///
        }
        for (int i = 0; i < A; i++) {
            p *= pro[i];
            int cnt1 = A-i-1  + (B-i);
            int cnt2 = cnt1 + B+1;
            double exp = cnt1 * p + cnt2 * (1-p);
            if (ans > exp) ans = exp;
            //cout << i << " " << exp << endl;///
        }
        if (A == B) {
            double exp = 1*p + (B+1) * (1-p);
            if (ans > exp) ans = exp;
        }
        fprintf(fout, "Case #%d: %.6lf\n", ca, ans);
    }
    
    fclose(fin);
    fclose(fout);
    return 0;
}

