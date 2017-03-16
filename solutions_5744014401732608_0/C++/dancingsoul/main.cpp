#include <bits/stdc++.h>
using namespace std;



typedef double DB;
typedef long long LL;

const int N = 7;

int f[N], e[N][N];
vector<pair<int, int> > vec;


bool calc(int n, int m) {
    memset(f, 0, sizeof(f));
    f[0] = 1;
    for (int i = 0; i < n; i++)
    for (int j = i + 1; j < n; j++)
    if (e[i][j]) f[j] += f[i];
    if (f[n - 1] == m) {
        puts("POSSIBLE");
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++)
                printf("%d", e[i][j]);
            puts("");
        }
    }
    return f[n - 1] == m;
}

int main(){
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
    int CAS, n, m;
    scanf("%d", &CAS);
    for (int cas = 1; cas <= CAS; cas++) {
        printf("Case #%d: ", cas);
        scanf("%d%d", &n, &m);
        vec.clear();
        for (int i = 0; i < n; i++) {
            for (int j = i + 1; j < n; j++) {
                vec.push_back(make_pair(i, j));
            }
        }
        int tot = 1 << vec.size();
        for (int i = 0; i < tot; i++) {
            memset(e, 0, sizeof(e));
            for (int j = 0; j < vec.size(); j++) {
                if (i >> j & 1) e[vec[j].first][vec[j].second] = 1;
            }
            if (calc(n, m)) break;
            else if (i == tot - 1) puts("IMPOSSIBLE");
        }
    }


}
