#include <set>
#include <map>
#include <cmath>
#include <stack>
#include <cstdio>
#include <string>
#include <vector>
#include <cstring>
#include <iostream>
#include <algorithm>
using namespace std;

#define PB push_back
#define MP make_pair

typedef long double DB;
typedef long long LL;
typedef pair <int, int> PI;

const DB eps = 1e-8;
const int N = 1e5 + 7;
const int M = 2e5 + 7;
const int INF = 1e9 + 7;
const int MOD = 1e9 + 7;


int CAS, C, D, V, a[N];
map <int, bool> vis;

int main(){
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
    scanf("%d", &CAS);
    for (int cas = 1; cas <= CAS; cas++){
        scanf("%d%d%d", &C, &D, &V);
        vis.clear();
        for (int i = 0; i < D; i++){
            scanf("%d", &a[i]);
            vis[a[i]] = true;
        }
        sort(a, a + D);
        int res = 0, cur = 0; LL A = 1;
        while (A <= V) {
            if (vis.find(A) == vis.end()) {
                res ++;
            }
            LL t = A;
            A = C * A + A;
            while (a[cur] < A && cur < D) {
                if (a[cur] != t)
                    A += C * a[cur];
                cur ++;
            }
        }
        printf("Case #%d: %d\n", cas, res);
    }
}
