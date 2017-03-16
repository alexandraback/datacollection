#include <cstdio>
#include <algorithm>
using namespace std;

const int MAX_N = 1005;

int N;
int num[MAX_N];

int main() {
    int T;
    scanf("%d",&T);

    for(int z=1;z<=T;z++) {
        scanf("%d",&N);

        int mx = -1;
        for(int i=0;i<N;i++) {
            scanf("%d",&num[i]);
            mx = max(mx, num[i]);
        }

        int best = mx;
        for(int i=1;i<=mx;i++) {
            int excess = 0;
            for(int j=0;j<N;j++) {
                if(num[j] > i) {
                    int extra = num[j] - i;
                    excess += (extra / i);
                    if((extra % i) > 0) {
                        excess++;
                    }
                }
            }
            best = min(best, i+excess);
        }
        printf("Case #%d: %d\n",z,best);
    }

    return 0;
}
