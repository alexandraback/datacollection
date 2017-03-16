#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
#define N 10004
typedef long long ll;
int e, r, n;
int v[N], right_max[N];
int find_bigger(int i) {
    if (right_max[i]<=v[i]) return -1;
    for(int j=i+1;j<n;j++) if (v[j]>v[i]) return j;
}
ll sol() {
    scanf("%d%d%d",&e,&r,&n);
    for(int i=0;i<n;i++) scanf("%d", v+i);
    int last = -1;
    for(int i=n-1;i>=0;i--) {
        right_max[i] = last;
        last = max(last, v[i]);
    }
    r = min(e, r);
    ll res = 0;
    int now = e;
    for(int i=0;i<n;i++) {
        int next_pos = find_bigger(i);
        if(next_pos == -1) {
            res += 1ll*v[i]*now;
            now = r;
        } else {
            int tmp = max(0, min(now, now-e+(next_pos-i)*r));
            now = now-tmp+r;
            res += 1ll*tmp*v[i];
        }
    }
    return res;
}
int main() {
    int T;
    freopen("sbin.in", "r", stdin);
    freopen("sbout.out", "w", stdout);
    scanf("%d", &T);
    for (int t=1;t<=T;t++) {
        ll res = sol();
        printf("Case #%d: %lld\n", t, res);
    }
}
