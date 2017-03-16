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

const int MAX_L = 1005;

int L;
char buf[MAX_L];

int main() {
    int T;
    scanf("%d",&T);

    for(int z=1;z<=T;z++) {
        printf("Case #%d: ",z);
        scanf(" %s ",buf);
        L = strlen(buf);

        deque<char> blah;

        char sofar = 'A'-1;
        for(int i=0;i<L;i++) {
            if(buf[i] >= sofar) {
                sofar = buf[i];
                blah.push_front(buf[i]);
            } else {
                blah.push_back(buf[i]);
            }
        }

        while(!blah.empty()) {
            putchar(blah.front());
            blah.pop_front();
        }
        putchar('\n');
    }

    return 0;
}
