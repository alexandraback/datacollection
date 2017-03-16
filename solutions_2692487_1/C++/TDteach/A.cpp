#include<iostream>
#include<algorithm>
#include<cstring>
#include<cstdio>
using namespace std;

#define maxn 107

int ans;
int n, m;
int a[maxn];
int f[maxn];

int main()
{
    freopen("A1.in","r",stdin);
    freopen("A.out","w",stdout);
    
    int cases, k, i;
    scanf("%d",&cases);
    for (k = 1; k <= cases; ++k) {
        scanf("%d%d",&m,&n);
        for (i = 0; i < n; ++i)
            scanf("%d",&a[i]);
        if (m == 1) ans = n;
        else {
        
        sort(a,a+n);
        ans = 0;
        
        for (i = 0; i < n; ++i) {
            while (m <= a[i]) {
                m += m-1;
                ++ans;
            }
            f[i] = ans;
            m += a[i];
        }
        
        ans = n;
        for (i = 0; i < n; ++i) {
            if (f[i]+n-i-1 < ans)
                ans = f[i]+n-i-1;
        }
    }
        printf("Case #%d: %d\n",k,ans);
    }
    
    return 0;
}
