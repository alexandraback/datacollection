#include <iostream>
#include <cstring>
#include <cstdio>
#include <cmath>
#include <string>
using namespace std;

int max(int a, int b) { return a > b ? a : b; }


int main() {
    freopen("1.in","r",stdin);
    freopen("1.out","w",stdout);
    int tt, n, x[210], sum;
    double ans[210], sumans;
    cin >> tt;
    for (int i = 1; i <= tt; ++i) {
        cin >> n;
        sum = 0;
        for (int j = 0; j < n; ++j) {
            cin >> x[j];
            sum += x[j];
        }
        sumans = 0;
        for (int j = 0; j < n; ++j) {
            ans[j] = (2.0*sum/n - x[j])/sum;
            if (ans[j] < 0) ans[j] = 0;
            sumans += ans[j];
        }
        for (int j = 0; j < n; ++j) ans[j] /= sumans;
        printf("Case #%d:", i);
        for (int j = 0; j < n; ++j) printf(" %.6lf", ans[j]*100);
        printf("\n");
    }
        
    
    return 0;
}
