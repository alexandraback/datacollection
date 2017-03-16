#include<cstdio>
#include<iostream>
#include<cstring>
#include<algorithm>
#include<vector>
#define ll long long
using namespace std;

double a[1010],b[1010];
int main()
{
    freopen("D-small-attempt0.in","r",stdin);
    freopen("D-small-attempt0.out","w",stdout);
    int cas = 1;
    int T;
    scanf("%d",&T);
    double ans,tmp,now;
    while (T--) {
        int n;
        scanf("%d",&n);
        for (int i = 0 ; i< n; i++) {
            scanf("%lf",&a[i]);
        }
        for (int i = 0 ; i< n; i++) {
            scanf("%lf",&b[i]);
        }
        sort(a,a+n);
        sort(b,b+n);
        int ans1,ans2;
        int l = 0,r;
        while (l < n) {
            bool fail = false;
            for (int i = 0; i + l < n; i++) {
                if (a[i + l] < b[i]) fail = true;
            }
            if (!fail) break;
            l++;
        }
        ans1 = n - l;
        l = 0,r = 0;
        while (l < n && r < n) {
            while (r < n && b[r] < a[l]) r++;
            if (r < n) {
                l++;
                r++;
            }
        }


        ans2 = n - l;
        printf("Case #%d: %d %d\n",cas++,ans1,ans2);
    }
}
