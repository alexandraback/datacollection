#include <cstring>
#include <cmath>
#include <cstdio>
#include <algorithm>
#include <iostream>
#include <vector>
#include <string>
#include <map>
#include <set>

using namespace std;

#define pb push_back
#define sz(a) (int)a.size()
#define fs first
#define sc second

typedef long long ll;
typedef pair<int,int> ii;

int c, D, V, a[100];
bool F[35], tong[35];

int main() {
    int t;
    freopen("C-small-attempt2.in","r",stdin);
    freopen("output.txt","w",stdout);
    scanf("%d",&t); int tmp = t;
    while (t--) {
        scanf("%d%d%d",&c,&D,&V);
        memset(F, false, sizeof F);
        memset(tong, false, sizeof tong);
        for (int i = 1; i <= D; ++i)
            scanf("%d",&a[i]);
        F[0] = tong[0] = true;
        for (int i = 1; i <= D; ++i) {
            for (int j = V; j >= a[i]; --j)
                if (tong[j-a[i]]) tong[j] = true;
            F[a[i]] = true;
        }
        int cnt = 0;
        for (int i = 1; i <= V; ++i)
        if (!tong[i]) {
            int tmp = i;
            F[tmp] = true;
            for (int i = V; i >= tmp; --i)
                if (tong[i-tmp]) tong[i] = true;
            cnt++;
        }
        printf("Case #%d: %d\n",tmp-t,cnt);
    }
	return 0;
}
