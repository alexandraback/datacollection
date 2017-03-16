#include <cstdio>
#include <algorithm>
using namespace std;

int r,c,w,a[105];

int solve(){
    scanf("%d %d",&r,&c);
    scanf("%d",&a[c]);
    a[c]++;
    for (int i=0; i<c; i++) {
        scanf("%d",&a[i]);
    }
    int ret = 0;
    long long sum = 0;
    for (int i=0; i<=c; i++) {
        while (sum * r < 1ll * a[i] - 1) {
            sum += sum + 1;
          //  printf("%lld\n",sum);
            ret++;
        }
        sum += a[i];
        //printf("%lld\n",sum);
    }
    return ret;
}

int main(){
    freopen("C-small-attempt3.in","r",stdin);
    freopen("output.txt","w",stdout);
    int t;
    scanf("%d",&t);
    for (int i=1; i<=t; i++) {
        printf("Case #%d: %d\n",i,solve());
    }
}