#include <cstdio>
#include <stack>
#include <vector>
#include <algorithm>
using namespace std;

const int MAX_N = 10005;

typedef long long ll;

ll E, R;
int N;
ll vals[MAX_N];
int next[MAX_N];

int main() {
    int T;
    scanf("%d",&T);

    for(int z=1;z<=T;z++) {
        printf("Case #%d: ",z);

        scanf("%lld %lld %d",&E,&R,&N);

        for(int i=0;i<N;i++) {
            scanf("%lld",&vals[i]);
        }

        stack<int> S;

        for(int i=N-1;i>=0;i--) {
            ll me = vals[i];
            while(!S.empty() && vals[S.top()] <= me) {
                S.pop();
            }

            if(S.empty()) {
                next[i] = N;
            } else {
                next[i] = S.top();
            }

            S.push(i);
        }

        ll curEnergy = E;
        ll tot = 0ll;
        for(int i=0;i<N;i++) {
            if(next[i] == N) {
                tot += curEnergy * vals[i];
                curEnergy = 0ll;
            } else {
                ll steps = next[i] - i;
                ll takeUpto = min(curEnergy,max(0ll, E - (R*steps)));
                tot += (curEnergy - takeUpto) * vals[i];
                curEnergy = takeUpto;
            }

            curEnergy = min(E, curEnergy + R);
        }

        printf("%lld\n",tot);
    }

    return 0;
}
