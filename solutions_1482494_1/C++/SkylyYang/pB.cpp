#include <cstdio>
#include <string>
#include <sstream>
#include <algorithm>
using namespace std;

//by Skyly

typedef long long int64;

#define SIZE(X) ((int)((X).size())) 
#define FOR(IT, X) for (__typeof((X).begin()) IT = (X).begin(); IT != (X).end(); ++IT)

template<typename T> string toStr(const T &x) { ostringstream os; os << x; return os.str(); }
template<typename T> void toMin(T &x, const T &y) { x = min(x, y); }
template<typename T> void toMax(T &x, const T &y) { x = max(x, y); }

const int MAXN = 1005;
const int MAX_NEEDED = 2005;

int N;
int a[MAXN], b[MAXN];
int vis[MAXN];

int main() {
    int t;

    scanf("%d", &t);
    for (int casN = 1; casN <= t; ++casN) {
        scanf("%d", &N);
        for (int i = 1; i <= N; ++i) {
            scanf("%d%d", &a[i], &b[i]);
            vis[i] = -1;
        }
        int cnt = 0;
        int y = 0;
        int ans = 0;
        bool flag = false;
        while (cnt < N) {
            for (int i = 1; i <= N; ++i) {
                if (vis[i] == 2) continue;
                if (y >= b[i]) {
                    y += (vis[i] == -1) ? 2 : 1;
                    vis[i] = 2;
                    ans++;
                    cnt++;
                    flag = true;
                }
            }
            if (flag) {
                flag = false;
                continue;
            }
            int maxB = -1;
            int loc = -1;
            for (int i = 1; i <= N; ++i) {
                if (vis[i] != -1) continue;
                if (y >= a[i]) {
                    if (b[i] > maxB) {
                        maxB = b[i];
                        loc = i;
                    }
                }
            }
            if (loc == -1) break;
            vis[loc] = 1;
            y++;
            ans++;
        }
        printf("Case #%d: ", casN);
        if (cnt < N) puts("Too Bad");
        else printf("%d\n", ans);
    }

    return 0;
}

