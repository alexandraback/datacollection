#include<iostream>
#include<cstdio>
#include<cmath>
#include<cstring>
#include<algorithm>
using namespace std;
int a[200][100];
int b[100];
int sum[100][100];
int c, d;
int main(){
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
    int t, tt, n;
    scanf("%d", &tt);
    for (int t = 0; t < tt; ++t){
        scanf("%d", &n);
        for (int i = 0; i < 2 * n - 1; ++i)
            for (int j = 0; j < n; ++j){
                scanf("%d", &a[i][j]);
            }
        memset(b, 0, sizeof(b));
        memset(sum, 0, sizeof(sum));
        for (int j = 0; j < n; ++j){
            int m = 2500;
            int tmp;
            for (int i = 0; i < 2 * n - 1; ++i){
                if (b[i]) continue;
                m = min(m, a[i][j]);
            }
            int cnt = 0;
            for (int i = 0; i < 2 * n - 1; ++i){
                if (m == a[i][j]){
                    ++cnt;
                    tmp = i;
                    b[i] = 1;
                    for (int k = 0; k < n; ++k){
                        sum[j][k] += a[i][k];
                    }
                }
            }

            if (cnt == 1){
                sum[j][j] *= 2;
                c = tmp;
                d = j;
            }
        }
        //cout<<c<<' '<<d<<endl;
        printf("Case #%d:", t + 1);
        for (int i = 0; i < n; ++i)
            //printf(" %d(%d, %d)", sum[i][d] - a[c][i], sum[i][d], a[c][i]);
            printf(" %d", sum[i][d] - a[c][i]);
        printf("\n");
    }
}
