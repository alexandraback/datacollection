#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>
#include <cmath>
using namespace std;
const int maxn = 100010;
double p[maxn];
int main()
{
    //freopen("A-large.in","r",stdin);
    //freopen("A-large.out","w",stdout);
    int T,A,B;
    double ans;
    cin>>T;
    for(int cas=0;cas<T;cas++){
        cin >> A >> B;
        for(int i=0 ; i < A ; i++)
            scanf("%lf", p+i);
        for(int i = 1 ; i < A ; i++)
            p[i]=p[i-1]*p[i];
        int n=A;
        ans = B + 2;
        while(n--){
            ans = min(ans, p[n] * (B - n) +(1 - p[n])*(B - n + B + 1) + A - n - 1);
            //cout << ans <<endl;
        }
        printf("Case #%d: %.6f\n", cas+1, ans);
    }
    return 0;
}
