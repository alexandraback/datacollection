#include<iostream> 
#include<cstdio> 
#include<algorithm> 
#include<cstring> 
#include<string>
#include<cmath> 
#include<vector> 
#include<queue> 
#include<map>
#include<ctime>
#include<set>
typedef long long lld; 
using namespace std; 
#define debug(x) cout<<#x<<"="<<x<<endl;
#define here cout<<"_______________here "<<endl;
#define clr(NAME,VALUE) memset(NAME,VALUE,sizeof(NAME)) 
#define MAX 0x7f7f7f7f 
#define N 16000010
#define PRIME 999983

int main()
{
    //#ifndef ONLINE_JUDGE
    //freopen("a", "r", stdin);
    //#endif
    int cas = 1;
    int T;
    scanf("%d", &T);
    int n;
    double num[210];
    double num1[210];
    double ans[210];
    int tp;
    double sum;
    double sum1;
    double bjsum;
    double tot;
    int cnt;
    while (T--) {
        sum = 0.0;
        sum1 = 0.0;
        scanf("%d", &n);
        for (int i = 0; i < n; i++) {
            scanf("%d", &tp);
            num[i] = (double)tp;
            sum += num[i];
        }
        bjsum = sum;
        printf("Case #%d:", cas++);
        //printf("tot: %lf", tot);
        sum *= 2;
        sum /= n;
        cnt = 0;
        for (int i = 0; i < n; i++) {
            if (num[i] <= sum) {
                num1[cnt] = num[i];
                sum1 += num[i];
                cnt++;
            }
        }
        if (sum1 == 0.0) {
            for (int i = 0; i < n; i++) {
                if (num[i] > sum) {
                    printf(" 0.000000");
                } else {
                    printf(" %.6lf", 100.0 / cnt);
                }
            }
            printf("\n");
            continue;
        }
        tot = bjsum;
        sum1 = sum1 + bjsum;
        sum1 /= cnt;
            
        //printf("sum: %lf", sum1);
        //printf("cnt: %d", cnt);
        //printf("tot: %lf", tot);
        int bj = 0;
        for (int i = 0; i < n; i++) {
            if (num[i] <= sum) {
                ans[i] = (sum1 - num1[bj]) / tot;
                bj++;
            }
        }
        for (int i = 0; i < n; i++) {
            if (num[i] > sum) {
                printf(" 0.000000");
            } else {
                printf(" %.6lf", ans[i] * 100.0);
            }
        }
        printf("\n");
    }
    return 0;
}
