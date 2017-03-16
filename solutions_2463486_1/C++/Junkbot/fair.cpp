#include <cstdio>
#include <algorithm>
#include <vector>
#include <cstring>
using namespace std;

typedef long long ll;

const int MAX_D = 105;
const ll STOP = 10000000ll;

vector<ll> fair;

char buffer[MAX_D];

bool isPalin(ll a) {
    sprintf(buffer, "%lld", a);

    int L = strlen(buffer);
    for(int i=0;i<L;i++) {
        if(buffer[i] != buffer[L-i-1]) {
            return false;
        }
    }

    return true;
}

int main() {
    for(ll i=1ll;i<=STOP;i++) {
        if(isPalin(i) && isPalin(i*i)) {
            fair.push_back(i*i);
        }
    }

    int T;
    scanf("%d",&T);

    for(int z=1;z<=T;z++) {
        printf("Case #%d: ",z);

        ll A, B;
        scanf("%lld %lld",&A,&B);

        vector<ll>::iterator lo = lower_bound(fair.begin(), fair.end(), A);
        vector<ll>::iterator hi = upper_bound(fair.begin(), fair.end(), B);

        printf("%d\n",hi-lo);
    }

    return 0;
}
