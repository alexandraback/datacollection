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
const int MAX_N = 1005;

int N;
int degree[MAX_N];
vector<int> in[MAX_N];
int out[MAX_N];
int best[MAX_N];
bool seen[MAX_N];

void reset(void) {
    for(int i=0;i<MAX_N;i++) {
        in[i].clear();
        degree[i] = 0;
        best[i] = 1;
        seen[i] = false;
    }
}

int go(int u) {
    if(seen[u]) {
        return 0;
    }
    seen[u] = true;
    return 1 + go(out[u]);
}

int main() {
    int T;
    scanf("%d",&T);

    for(int z=1;z<=T;z++) {
        reset();

        printf("Case #%d: ",z);

        scanf("%d",&N);
        for(int i=0;i<N;i++) {
            scanf("%d",&out[i]);
            out[i]--;
            degree[out[i]]++;
            in[out[i]].push_back(i);
        }

        queue<int> todo;
        for(int i=0;i<N;i++) {
            if(degree[i] == 0) {
                todo.push(i);
            }
        }

        while(!todo.empty()) {
            int u = todo.front();
            todo.pop();
            seen[u] = true;
            degree[out[u]]--;
            best[out[u]] = max(best[out[u]], best[u]+1);
            if(degree[out[u]] == 0) {
                todo.push(out[u]);
            }
        }

        int ans = 0;
        int tt = 0;
        for(int i=0;i<N;i++) {
            int g = go(i);
            ans = max(ans, g);
            if(g == 2) {
                tt += best[i] + best[out[i]];
            }
        }
        ans = max(ans, tt);
        printf("%d\n",ans);
    }

    return 0;
}
