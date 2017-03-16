#include<stdio.h>
#include<algorithm>
#define N 1010
using namespace std;

int a[N];

int main(){
    int T;
    scanf("%d", &T);
    for(int kase=1; kase<=T; kase++){
        int n;
        scanf("%d", &n);
        for(int i=1; i<=n; i++) scanf("%d", a+i);
        int M = 0;
        for(int i=1; i<=n; i++) M = max(M, a[i]);
        int ans = M;
        for(int i=1; i<=M; i++){
            int temp = i;
            for(int j=1; j<=n; j++) temp += (a[j]-1) / i;
            ans = min(ans, temp);
        }
        printf("Case #%d: %d\n", kase, ans);
    }
    return 0;
}
