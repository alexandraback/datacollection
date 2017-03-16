#include <cstdio>
#include <algorithm>
using namespace std;

int a[101];
int main () {
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    int T=1;
    scanf("%d",&T);
    for (int z=1;z<=T;++z) {
        int A,N,cost;
        scanf("%d %d",&A,&N);
        for (int i=1;i<=N;++i) scanf("%d",&a[i]);
        sort(a+1,a+N+1);
        int best=N;
        for (int i=1;i<=N+1;++i) {
            cost=N+1-i;
            long long cur=A;
            for (int j=1;j<i;++j) {
                if (cur>a[j]) cur+=a[j];
                else {
                    if (cur==1) {
                        cost=N;
                        break;
                    }
                    while (cur<=a[j]) ++cost,cur+=cur-1;
                    --j;
                }
            }
            if (cost<best) {
                best=cost;
            }
        }
        printf("Case #%d: %d\n",z,best);
    }
    return 0;
}
