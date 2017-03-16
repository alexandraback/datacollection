#include <iostream>
#include <cstring>
#include <algorithm>
using namespace std;

int a[201];
int f[200];
int vis[200];
int mark[200];

int c, v;
void fillV(int d){
    int i, j;
    memset(f, 0, sizeof(f));
    f[0] = 1;
    for (i = 1; i <= d; i++){
        for (j = v; j > 0; j--){
            if (j >= a[i - 1]) f[j] |= f[j - a[i - 1]];
        }
    }
}

int combine(int d, int n, int cnt){
//    cerr << d << ", " << n << ", " << cnt << endl;
    if (d == cnt){
        fillV(d);
//        for (int i = 0; i < d; i++)
//            cerr << a[i] << ", ";
//        cerr << endl;
        for (int i = 1; i <= v; i++)
            if (!f[i]) return 0;
        return 1;
    }
    for (int i = 0; i < n; i++){
        if (vis[i] != -1){
            int k = vis[i];
            a[d] = k;
            vis[i] = -1;
            int res = combine(d + 1, n, cnt);
            vis[i] = k;
            if (res) return 1;
        }
    }
    return 0;
}

int main(){
    int t, T;
    int d, ans;
    int i, j, k;


    freopen("C-small-attempt1.in", "r", stdin);
    freopen("c.out", "w", stdout);

    cin >> T;
    for (t = 1; t <= T; t++){
        cin >> c >> d >> v;
        for (i = 0; i < d; i++) cin >> a[i];

//        cerr << "finish read" << endl;

        fillV(d);
        k = 0;
        for (i = 1; i <= v; i++) if (!f[i]) k++;
//        cerr << "k = " << k << endl;
        if (k > 0){
            memset(vis, 0, sizeof(vis));
            memset(mark, 0, sizeof(mark));
            int cnt[200];
            for (i = 0; i < d; i++) mark[a[i]] = 1;
            for (i = 1; i <= v; i++){
                if (!f[i]){
                    for (j = i - 1; j >= 0; j--)
                        if (f[j] && !mark[i - j]){
                            vis[i - j]++;
                            cnt[i] = i - j;
                            break;
                        }
                }
            }
            for (i = v; i > 0; i--){
                if (vis[i] == 0) continue;
                for (j = 1; j <= v; j++){
                    if (f[j]) continue;
                    if (j >= i && f[j - i]){
                        k = cnt[j];
                        vis[k]--;
                        vis[i]++;
                        cnt[j] = i;
//                        cerr << "dec " << k << ", inc " << i << ", at " << j << endl;
                    }
                }
            }
            for (k = 0, i = 1; i <= v; i++)
                if (vis[i]) vis[k++] = i;
            for (i = k; i <= v; i++) vis[i] = 0;
//            for (i = 0; i < k; i++)
//                cerr << "vis " << vis[i] << endl;
//            cerr << "vis size = " << k << endl;
            for (i = 1; i <= k; i++){
                if (combine(d, k, i + d)) break;
            }
            ans = i;
        }else ans = 0;
        cerr << t << endl;
        printf("Case #%d: %d\n", t, ans);
    }
    return 0;
}
