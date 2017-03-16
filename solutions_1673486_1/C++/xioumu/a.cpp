/*
 * Author:  xioumu
 * Created Time:  2012-4-28 9:52:12
 * File Name: a.cpp
 * solve: a.cpp
 */
#include<cstdio>
#include<cstring>
#include<cstdlib>
#include<cmath>
#include<algorithm>
#include<string>
#include<map>
#include<set>
using namespace std;
const double esp = 1e-8;
const int maxn = 100007;
typedef long long ll;
double p[maxn];
int n, m;
int main(){
    int t;
    freopen("a.out","w",stdout);
    scanf("%d",&t);
    for(int ti = 1; ti <= t; ti++){
        scanf("%d %d",&n,&m);
        for(int i = 1; i <= n; i++)
            scanf("%lf",&p[i]);
        double ans1, ans2, ans3;
        ans1 = ans2 = ans3 = 0;
        double sump = 1, sump2 = 1;
        double ans = 0;
        for(int i = 1; i <= n; i++)
            sump *= p[i];
        ans1 = (m - n + 1) + (1 - sump) * (m + 1);
        ans = ans1;
        
        sump2 = 1;
        for(int i = 1, sump = 0; i < n; i++){
            sump2 *= p[i];
            ans = min(ans, (n - i) * 2.0 + (m - n + 1) + 
                           (1 - sump2) * (m + 1));
            
            //printf("%f\n", (n - i) * 2.0 + (m - n + 1) + 
                           //(1 - sump2) *  (m + 1));
        }
        //ans2 += m - n + 1;
        
        ans3 = m + 2;

        ans = min(ans, ans3);
        //printf("%f %f %f\n",ans1, ans, ans3);
        printf("Case #%d: %f\n", ti, ans);
    }
    return 0;
}
