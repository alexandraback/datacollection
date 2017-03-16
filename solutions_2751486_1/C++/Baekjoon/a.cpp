#include <cstdio>
#include <algorithm>
#include <set>
#include <cstring>
#include <cstdlib>
using namespace std;
char a[1111111];
int l[1111111];
int r[1111111];
int n;
int m;
bool go(char x) {
    if (x == 'a' || x == 'e' || x == 'i' || x == 'o' || x == 'u')
        return false;
    else
        return true;
}
long long calc(long long x, long long last) {
    return (x-last)*((long long)m-(x+(long long)n-1)+1);
}
int main() {
    int t;
    scanf("%d",&t);
    for (int tc=1; tc<=t; tc++) {
        memset(a,0,sizeof(a));
        scanf("%s %d\n",a+1,&n);
        m = strlen(a+1);
        long long ans = 0;
        memset(r,0,sizeof(r));
        for (int i=m; i>=1; i--) {
            if (go(a[i])) r[i]=r[i+1]+1;
            else r[i]=0;
        }
        int last = 0;
        for (int i=1; i<=m-n+1; i++) {
            if (r[i] >= n) {
                ans += calc(i,(long long)last);
                last = i;
            }
        }
        printf("Case #%d: %lld\n",tc,ans);
    }
    return 0;
}

