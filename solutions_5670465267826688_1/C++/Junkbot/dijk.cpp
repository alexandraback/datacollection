#include <cstdio>
#include <algorithm>
using namespace std;

#ifdef DEBUG
#define D(x...) fprintf(stderr,x)
#else
#define D(x...)
#endif

typedef long long ll;
const int MAX_N = 11005;
const ll INF = (1ll << 60ll); 

int mul[4][4] = {
    {0, 1, 2, 3},
    {1, 0, 3, 2},
    {2, 3, 0, 1},
    {3, 2, 1, 0}
};

int neg[4][4] = {
    {0, 0, 0, 0},
    {0, 1, 0, 1},
    {0, 1, 1, 0},
    {0, 0, 1, 1}
};

ll L, X;
char word[MAX_N];
int vals[MAX_N];
int pw[MAX_N];

int prod(int a, int b) {
    int aa = a%4;
    int bb = b%4;
    int p = mul[aa][bb];
    int nega = neg[aa][bb];
    if(a >= 4) {
        nega++;
    }
    if(b >= 4) {
        nega++;
    }
    p = (p+(4*nega))%8;
    return p;
}

int main() {
    int T;
    scanf("%d",&T);

    int target = prod(1, prod(2, 3));
    D("target = %d\n",target);
    for(int i=0;i<8;i++) {
        for(int j=0;j<8;j++) {
            D("%d ",prod(i,j));
        }
        D("\n");
    }

    for(int z=1;z<=T;z++) {
        printf("Case #%d: ",z);

        scanf("%lld %lld",&L,&X);
        scanf(" %s ",word);
        for(int i=0;i<L;i++) {
            vals[i] = word[i]-'i'+1;
        }

        int all = 0;
        for(int i=0;i<L;i++) {
            all = prod(all, vals[i]);
        }

        pw[0] = all;
        for(int i=1;i<MAX_N;i++) {
            pw[i] = prod(pw[i-1], pw[i-1]);
        }

        int grand = 0;
        for(int i=60;i>=0;i--) {
            ll h = (1ll << (ll)(i));
            if(X & h) {
                grand = prod(grand, pw[i]);
            }
        }
        if(grand != target) {
            D("overall product bad: all=%d, grand=%d\n",all,grand);
            printf("NO\n");
            continue;
        }

        ll firstI = INF;
        int tot = 0;
        for(int i=0;i<=L;i++) {
            int cur = 0;
            for(ll j=0ll;j<=8ll;j++) {
                if(prod(cur, tot) == 1) {
                    firstI = min(firstI, ((ll)(i)) + j*L);
                }
                cur = prod(cur, all);
            }
            tot = prod(tot, vals[i]);
        }

        ll lastK = -1ll;
        tot = 0;
        for(int i=0;i<L;i++) {
            int cur = 0;
            for(ll j=0ll;j<=8ll;j++) {
                if(prod(tot, cur) == 3) {
                    lastK = max(lastK, L*X - (((ll)(i)) + j*L));
                }
                cur = prod(all, cur);
            }
            tot = prod(vals[L-i-1], tot);
        }

        D("firstI = %lld, lastK = %lld\n",firstI,lastK);

        if(firstI < lastK) {
            printf("YES\n");
        } else {
            printf("NO\n");
        }
    }

    return 0;
}
