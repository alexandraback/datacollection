#include<cstdio>
#include<cstring>
#include<cstdlib>
#include<cmath>
using namespace std;

int s[400];

int main()
{
    int i, j, T, N;
    int sum = 0;
    int sum2 = 0;
    double ans = 0;
    int cnt = 0;
    scanf("%d", &T);
    for(i=1;i<=T;i++){
        sum = 0;
        cnt = 0;
        scanf("%d", &N);
        for(j=1;j<=N;j++){
            scanf("%d", &s[j]);
            sum += s[j];
        }
        sum2 = sum;
        for(j=1;j<=N;j++){
            if(s[j]>=(2.0*sum/N)){
                sum2 -= s[j];
                cnt++;
            }
        }
         
        printf("Case #%d: ", i);
        for(j=1;j<N;j++){
            ans = (double)(sum2 + sum - s[j]*(N-cnt))/(double)((N-cnt)*sum)*100;
            if(ans < 0.0) ans = 0;
            printf("%.6lf ", ans);
        }
        ans = (double)(sum2 +sum - s[j]*(N-cnt))/(double)((N-cnt)*sum)*100;
        if(ans < 0.0) ans = 0;
        printf("%.6lf\n", ans);
    }
    return 0;
}
