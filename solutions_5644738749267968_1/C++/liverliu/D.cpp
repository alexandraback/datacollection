#include<cstdio>
#include<cstring>
#include<cstdlib>
#include<cmath>
#include<iostream>
#include<algorithm>
using namespace std;
double a[1005],b[1005];
int n;
bool cmp(double a,double b) {
    return a>b;
}
int calc(double a[],double b[]) {
    int id1 = 0, id2 = 0, ans = 0;
    while(id1<n && id2<n) {
        if(a[id1]>b[id2]) {
            id1++;
            id2++;
            ans++;
        } else {
            id2++;
        }
    }
    return ans;
}
int main() {
    freopen("/Users/liverliu/Documents/codejam/D-large.in","r",stdin);
    freopen("/Users/liverliu/Documents/codejam/D-large.out","w",stdout);
    int T,cas=0;
    scanf("%d",&T);
    while(T--) {
        scanf("%d",&n);
        for(int i=0;i<n;i++) {
            scanf("%lf",a+i);
        }
        for(int i=0;i<n;i++) {
            scanf("%lf",b+i);
        }
        sort(a,a+n,cmp);
        sort(b,b+n,cmp);
        printf("Case #%d: %d %d\n",++cas, calc(a,b),n-calc(b,a));
    }
}
