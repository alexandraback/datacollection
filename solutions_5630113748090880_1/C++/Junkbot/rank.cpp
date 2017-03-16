#include <bits/stdc++.h>
using namespace std;

#ifdef DEBUG
#define D(x...) fprintf(stderr,x)
#else
#define D(x...)
#endif

#define M(x) (((x%MOD)+MOD)%MOD)

typedef long long ll;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;

const ll MOD = (ll)(1e9)+7ll;

int main() {
    int T;
    scanf("%d",&T);

    for(int z=1;z<=T;z++) {
        printf("Case #%d:",z);

        map<int,int> num;

        int N;
        scanf("%d",&N);

        for(int i=0;i<2*N-1;i++) {
            for(int j=0;j<N;j++) {
                int a;
                scanf("%d",&a);
                if(num.count(a) == 0) {
                    num[a] = 0;
                }
                num[a]++;
            }
        }

        for(auto a: num) {
            if(a.second % 2 == 1) {
                printf(" %d",a.first);
            }
        }
        printf("\n");
    }

    return 0;
}
