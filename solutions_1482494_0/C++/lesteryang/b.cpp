#include "iostream"
#include "cstdio"
#include "cstring"
#include "algorithm"
#include "vector"
#include "queue"
#include "cmath"
#include "string"
#include "cctype"
#include "map"
#include "iomanip"
using namespace std;
#define pb push_back
#define mp make_pair
#define fi first
#define se second
#define sof(x) sizeof(x)
#define lc(x) (x << 1)
#define rc(x) (x << 1 | 1)
#define lowbit(x) (x & (-x))
#define ll long long
#define maxn 1010
int a[maxn], b[maxn];
bool visita[maxn], visitb[maxn];
int n;
int main() {
    freopen("B-small-attempt0.in", "r", stdin);
    freopen("out.txt", "w", stdout);
    int T, Case = 1;
    cin >> T;
    while(T--) {
        cin >> n;
        for(int i = 1; i <= n; i++) cin >> a[i] >> b[i];
        int sum = 0;
        int ans = 0;
        memset(visita, false, sof(visita));
        memset(visitb, false, sof(visitb));
        for(int i = 0; i < 2 * n; i++) {
            bool flag = false;
            for(int j = 1; j <= n; j++) {
                if(!visitb[j] && sum >= b[j]) {
                    flag = true;
                    ans++;
                    if(visita[j]) sum += 1;
                    else visita[j] = true, sum += 2;
                    visitb[j] = true;
                }
            }
            if(flag) continue;
            int idx = -1;
            for(int j = 1; j <= n; j++) {
                if(!visita[j] && sum >= a[j] && (idx == -1 || b[idx] < b[j])) idx = j;
            }
            if(idx == -1) break;
            visita[idx] = true, sum += 1;
            ans++;
        }
        printf("Case #%d: ", Case++);
        if(sum == 2 * n) cout << ans << endl;
        else cout << "Too Bad" << endl;
    }
    return 0;
}
