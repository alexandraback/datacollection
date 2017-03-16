#include <queue>
#include <cstdio>
#include <cstring>

using namespace std;

const int MAXN = 1005;
const int MAXM = 15;

int n;
int f[MAXN][MAXN];
//int lnk[MAXN][MAXM];
//int ind[MAXN];
//int d[MAXN];
//int cnt[MAXN];

//bool check(int x){
//    memset(cnt, 0, sizeof(cnt));
//    memcpy(d, ind, sizeof(d));
//    queue<int> q;
//    q.push(x);
//    cnt[x] = 1;
//    while (!q.empty()){
//        int cur = q.front();
//        q.pop();
//        printf("%d\n", cur);
//        for (int i = 1;i <= lnk[cur][0];i++){
//            int nxt = lnk[cur][i];
//            d[nxt] -= 1;
//            cnt[nxt] += cnt[cur];
//            if (cnt[nxt] > 1) return true;
//            if (d[nxt] == 0){
//                q.push(nxt);
//            }
//        }
//    }
//    return false;
//}

bool floyd(){
    for (int k = 1;k <= n;k++)
        for (int i = 1;i <= n;i++)
            for (int j = 1;j <= n;j++)
                if (f[i][k] > 0 && f[k][j] > 0){
                    f[i][j] += f[i][k] * f[k][j];
                    if (f[i][j] > 1) return true;
                }
    return false;
}

int main(){
#ifdef ILOAHZ
    //freopen("a.in", "r", stdin);
    //freopen("A-small-attempt0.in", "r", stdin);
    //freopen("A-small-attempt0.out", "w", stdout);
    freopen("A-small-attempt1.in", "r", stdin);
    freopen("A-small-attempt1.out", "w", stdout);
#endif
    int T, t = 0;
    scanf("%d", &T);
    while (T--){
        scanf("%d", &n);
        //memset(ind, 0, sizeof(ind));
        memset(f, 0, sizeof(f));
        for (int i = 1;i <= n;i++){
            int m;
            scanf("%d", &m);
            for (int j = 1;j <= m;j++){
                int k;
                scanf("%d", &k);
                f[i][k] = 1;
                //ind[lnk[i][j]] += 1;
            }
        }
        bool flag = false;
        flag = floyd();
//        for (int i = 1;i <= n;i++){
//            if (ind[i] == 0 && check(i)){
//                flag = true;
//                break;
//            }
//        }
        printf("Case #%d: %s\n", ++t, flag ? "Yes" : "No");
    }
    return 0;
}
