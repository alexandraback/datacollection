#include<bits/stdc++.h>
using namespace std;

typedef long long LL;

const int maxn = 20;
LL T,n,ans;
int b[maxn],c[maxn];
bool flag;

int main() {
    freopen("A1.in","r",stdin);
    freopen("B.out","w",stdout);
    scanf("%lld",&T);
    for (int kase=1; kase<=T; kase++) {
        scanf("%lld",&n);
        flag = false;
        if (n%10==0) n--,flag = true;
        ans = n;
        int l = 0;
        LL t = n;
        while (t) {
             b[++l] = t%10;
              t/=10;
        }
        reverse(b+1,b+l+1);
        for (int i=2; i<l; i++) {
            c[1] = 1;
            for (int j=2; j<=i/2; j++) c[j] = 0;
            for (int j=i/2+1; j<=i; j++) c[j] = 9;
            LL t1 = 0,t2 = 0;
            for (int j=1; j<=i; j++) t1 = t1*10 + c[j];
            for (int j=i; j>=1; j--) t2 = t2*10 + c[j];
            if (t2 > t1) ans -= t2-t1-1;
        }
        c[1] = 1;
        for (int j=2; j<=l/2; j++) c[j] = 0;
        for (int j=l/2+1; j<=l; ++j) c[j] = b[l-j+1];
        LL t1 = 0,t2 = 0;
        for (int j=1; j<=l; j++) t1 = t1*10 + c[j];
        for (int j=l; j>=1; j--) t2 = t2*10 + c[j];
        if (t2>t1) ans -= t2-t1-1;
        if (flag) ++ans;
        printf("Case #%lld: %lld\n",kase,ans);
    }

    return 0;
}
