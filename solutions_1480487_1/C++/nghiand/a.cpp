#include <iostream>
#include <cstdio>
#define MAXN 222

using namespace std;

int main(){//
    freopen("A-large.in", "rt", stdin);
    freopen("A-large.out", "wt", stdout);
    int test, n, a[MAXN], s;
    double res[MAXN];
    scanf("%d", &test);
    for (int t = 1; t <= test; t++){
        scanf("%d", &n);
        s = 0;
        for (int i = 1; i <= n; i++){
            scanf("%d", &a[i]);
            s += a[i];
        }
        printf("Case #%d: ", t);
        int cnt = 0;
            double k = 1;
            for (int i = 2; i <= n; i++)
                k = k - double(a[1] - a[i]) / s;
            k = k / n;
            res[1] = k;
            for (int i = 2; i <= n; i++)
                res[i] = (s * k + a[1] - a[i]) / s;
            for (int i = 1; i <= n; i++)
                if (res[i] < 0) cnt++;
            int pos = 0;
            for (pos = 1; pos <= n; pos++)
                if (res[pos] > 0) break;
            k = 1;
            for (int i = 1; i <= n; i++)
                if (i != pos)
                    if (res[i] > 0)
                        k = k - double(a[pos] - a[i]) / s;
            k = k / (n - cnt);
            res[pos] = k;
            for (int i = 1; i <= n; i++){
                res[i] = (s * k + a[pos] - a[i]) / s;
                if (res[i] < 0) res[i] = 0;
            }
                
            for (int i = 1; i <= n; i++)
                printf("%.6f ", 100 * res[i]);
            printf("\n");
    }
        
//    system("pause");    
    return 0;
}
