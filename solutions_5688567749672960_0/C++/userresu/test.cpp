#include <cstdio>
#include <map>
using namespace std;
typedef long long ll;

int mp[1000001];
ll rev (ll t) {
    ll sum = 0;
    while (t) {
        sum = sum * 10 + t % 10;
        t/= 10;
    }
    return sum;
}
ll target;
ll go (ll t) {
    if (t == target) {
        return 1;
    }
    int z = mp[t];
    if (z) return z;
    if (t > 1000000) return mp[t] = -2;
    ll ret = go(t+1) + 1;
    if (ret == 0) ret = 2000000000;
    if (rev(t) > t) {
        ll ret2 = go(rev(t))+1;
        if (ret2  > 0) ret = min(ret,ret2);
    }
    return mp[t] = ret;
}

int main () {
    freopen("input.txt","r",stdin);
    freopen("output2.txt","w",stdout);
    int T;
    scanf("%d",&T);
    for (int z=1;z<=T;++z) {
        int i;
        for (int j=0;j<=1000000;++j) mp[j] = 0;
        scanf("%d",&i);
        target = i;
        printf("Case #%d: %lld\n",z,go(1));
    }
    return 0;
}
