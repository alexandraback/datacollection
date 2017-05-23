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

int F[1000005], n, t;

int main() {
    freopen("A-small-attempt0.in","r",stdin);
    freopen("output.txt","w",stdout);
    F[1] = 1;
    for (int i = 2; i <= 1000000; ++i)
        F[i] = 1000000000;
    for (int i = 1; i <= 1000000; ++i) {
        F[i+1] = min(F[i+1],F[i]+1);
        int st[10]; st[0] = 0;
        for (int u = i; u; u /= 10)
            st[++st[0]] = u%10;
        int v = 0; for (int i = 1; i <= st[0]; ++i) v = v*10+st[i];
        F[v] = min(F[v],F[i]+1);
    }
    int n; scanf("%d",&n); int t = n;
    while (n--) {
        int x; scanf("%d",&x);
        printf("Case #%d: %d\n",t-n,F[x]);
    }
    return 0;
}
