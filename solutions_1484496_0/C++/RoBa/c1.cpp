#include <cstdio>
#include <vector>
#include <map>
using namespace std;

int a[32];
map<int, vector<int> > mp;

void outv(vector<int> &v) {
    for (int i = 0 ; i < v.size() ; ++i) {
        if (i) printf(" ");
        printf("%d",v[i]);
    }
    printf("\n");
}

int main() {
    freopen("C-small.in","r",stdin);
    freopen("C-small.out","w",stdout);
    int T, ca, i, n;
    scanf("%d",&T);
    for (ca = 1 ; ca <= T ; ++ca) {
        scanf("%d",&n);
        for (i = 0 ; i < n ; i++)
            scanf("%d",&a[i]);
        mp.clear();
        printf("Case #%d:\n", ca);
        int flg = 0;
        for (int mask = 1 ; mask < (1<<n) ; ++mask) {
            int tot = 0;
            vector<int> v;
            for (i = 0 ; i < n ; i++) {
                if (mask&(1<<i)) {
                    tot += a[i];
                    v.push_back(a[i]);
                }
            }
            if (mp.count(tot) == 0) {
                mp[tot] = v;
            } else {
                outv(v);
                outv(mp[tot]);
                flg = 1;
                break;
            }
        }
        if (!flg) printf("Impossible\n");
    }
    return 0;
}
