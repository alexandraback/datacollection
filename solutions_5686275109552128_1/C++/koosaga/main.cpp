#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

int n,a[1005],b[1005];

int trial(int x){
    int cnt = 0;
    for (int i=1000; i>x; i--) {
        if(b[i]){
            cnt += b[i];
            b[i-x] += b[i];
            b[x] += b[i];
            b[i] = 0;
        }
    }
    return cnt;
}

void solve(){
    int t;
    memset(a,0,sizeof(b));
    scanf("%d",&n);
    for (int i=0; i<n; i++) {
        scanf("%d",&t);
        a[t]++;
    }
    int ret = 1e9;
    for (int i=1; i<=1000; i++) {
        memcpy(b,a,sizeof(b));
        ret = min(ret,i + trial(i));
    }
    printf("%d\n",ret);
}

int main(){
    freopen("B-small-attempt2.in","r",stdin);
    freopen("output","w",stdout);
    int t;
    scanf("%d",&t);
    for (int i=1; i<=t; i++) {
        printf("Case #%d: ",i);
        solve();
    }
}