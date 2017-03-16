#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;

const double eps = 1e-10;

int judge[210];
bool vis[210];

int dblcmp(double x)
{
    if(x > -eps && x < eps)
        return 0;
    return x > 0 ? 1 : -1;
}

int main()
{
    //freopen("input.txt", "r", stdin);
    freopen("A-large.in", "r", stdin);
    freopen("A-large.out", "w", stdout);
    int X;
    int n, m, T;
    int cnt = 1;
    scanf("%d", &T);
    while(T--){
        scanf("%d", &n);
        X = 0;
        for(int i = 0; i < n; i++){
            scanf("%d", &judge[i]);
            X += judge[i];
        }
        printf("Case #%d: ", cnt++);
        if(X == 0){
            for(int i = 0; i < n; i++)
                printf("0.000000%c", i == n - 1 ? '\n' : ' ');
        }else {
            memset(vis, false, sizeof(vis));
            int j, x = 0;
            m = n;
            while(m){
                double avg = (double)2.0 * X / m;
                bool flag = true;
                for(j = 0; j < n; j++){
                    if(!vis[j] && dblcmp(judge[j] - avg) > 0){
                        x += judge[j];
                        vis[j] = true;
                        m--;
                        flag = false;
                    }
                }
                if(flag) break;
            }
            for(int i = 0; i < n; i++){
                if(vis[i]){
                    printf("0.000000");
                }else{
                    double v = (double)(2 * X - m * judge[i] - x) / (double)(m * X) * 100;
                    printf("%lf", v);
                }
                printf("%c", i == n - 1 ? '\n' : ' ');
            }
        }
    }
    return 0;
}
