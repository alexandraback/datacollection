#include <cstdio>
#include <vector>
#include <algorithm>
#include <utility>
using namespace std;

#ifdef DEBUG
#define D(x...) fprintf(stderr,x)
#else
#define D(x...)
#endif

typedef long long ll;

// <sum, nummasks>
typedef pair<ll,ll> pll;

const int NUM_CONFIG = 19000;

int R, N, M, K;

ll fact[15];

int depth[15];

int C;
vector<int> configs[NUM_CONFIG];
ll configWays[NUM_CONFIG];

vector<ll> prods[NUM_CONFIG];

int target[15];

void gen(int ply, int upto) {
    if(ply == N) {
        for(int i=0;i<N;i++) {
            configs[C].push_back(depth[i]);
        }
        C++;
    } else {
        for(int i=upto;i<=M;i++) {
            depth[ply] = i;
            gen(ply+1, i);
        }
    }
}

void getWays(int num) {
    ll tot = fact[N];

    int cur = 1;
    for(int i=1;i<N;i++) {
        if(configs[num][i] == configs[num][i-1]) {
            cur++;
        } else {
            tot /= fact[cur];
            cur = 1;
        }
    }

    tot /= fact[cur];
    configWays[num] = tot;
}

ll totWays(int num) {
    ll tot = 1ll;
    for(int i=0;i<K && tot > 0ll;i++) {
        vector<ll>::iterator lo = lower_bound(prods[num].begin(), prods[num].end(), target[i]);
        vector<ll>::iterator hi = upper_bound(prods[num].begin(), prods[num].end(), target[i]);
        tot *= ((ll)(hi - lo) * configWays[num]);
    }
    return tot;
}

int main() {
    // factorial
    fact[0] = 1ll;
    for(ll i=1ll;i<15ll;i++) {
        fact[i] = fact[i-1] * i;
    }

    // input and precomp
    int T;
    scanf("%d",&T);

    printf("Case #1:\n");

    scanf("%d %d %d %d",&R,&N,&M,&K);

    // generate
    gen(0, 2);

    D("* C = %d\n",C);

    // find num ways to get each config
    for(int i=0;i<C;i++) {
        getWays(i);

        // find all the sums
        for(int m=0;m<(1<<N);m++) {
            ll tot = 1ll;
            for(int j=0;j<N;j++) {
                if(m & (1 << j)) {
                    tot *= configs[i][j];
                }
            }

            prods[i].push_back(tot);
        }

        sort(prods[i].begin(), prods[i].end());
    }

    for(int i=0;i<R;i++) {
        for(int j=0;j<K;j++) {
            scanf("%d",&target[j]);
        }

        int best = 0;
        ll bestWays = 0ll;

        for(int j=0;j<C;j++) {
            ll t = totWays(j);
            if(t > bestWays) {
                bestWays = t;
                best = j;
            }
        }

        for(int j=0;j<N;j++) {
            printf("%d",configs[best][j]);
        }
        printf("\n");
    }

    return 0;
}
