#include<stdio.h>
#include<algorithm>
#define eps 1e-10
using namespace std;

int d[2], h[2], m[2];
double v[2];

int main(){
    int T;
    scanf("%d", &T);
    for(int kase=1; kase<=T; kase++){
        int n;
        scanf("%d", &n);
        for(int i=0; i<=n-1; i++) scanf("%d%d%d", d+i, h+i, m+i);
        if(n == 1){
            if(h[0] == 1){
                printf("Case #%d: 0\n", kase);
                continue;
            }
            else d[1] = d[0], m[1] = m[0] + 1;
        }
        if(m[0] == m[1]){
            printf("Case #%d: 0\n", kase);
            continue;
        }
        if(m[0] > m[1]) swap(d[0], d[1]), swap(m[0], m[1]);
        v[0] = 360. / m[0], v[1] = 360. / m[1];
        int ans;
        if(d[0] == d[1]){
            double t = 360. / (v[0] - v[1]);
            double theta = d[1] + t * v[1];
            ans = (theta < 360 + eps);
        }
        else if(d[0] > d[1]){
            double t = (360. - (d[0] - d[1])) / (v[0] - v[1]);
            double theta = d[1] + t * v[1];
            ans = (theta < 360 + eps);
        }
        else{
            double t1 = (d[1] - d[0]) / (v[0] - v[1]);
            double theta1 = d[1] + t1 * v[1];
            if(theta1 > 360 - eps) ans = 0;
            else{
                double t2 = t1 + 360. / (v[0] - v[1]);
                double theta2 = d[1] + t2 * v[1];
                ans = (theta2 < 360 + eps);
            }
        }
        printf("Case #%d: %d\n", kase, ans);
    }
    return 0;
}
