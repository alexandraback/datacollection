#include <cstdio>
#include <cstring>
#include <algorithm>

using namespace std;

const int MAXN = 205;
const double EPS = 1e-8;

int n;
int s[MAXN];

int main(){
#ifdef ILOAHZ
    //freopen("a.in", "r", stdin);
    freopen("A-small-attempt1.in", "r", stdin);
    freopen("A-small-attempt1.out", "w", stdout);
#endif
    int T, t = 0;
    scanf("%d", &T);
    while (T--){
        scanf("%d", &n);
        for (int i = 0;i < n;i++) scanf("%d", &s[i]);
        int x = 0;
        for (int i = 0;i < n;i++) x += s[i];
        double k = 2.0 * x / n;
        bool flag = true;
        int lst = n;
        while (flag){
            flag = false;
            int cnt = n;
            int sy = 0;
            for (int i = 0;i < n;i++)
                if (s[i] - EPS > k){
                    cnt -= 1;
                    flag = true;
                }
                else{
                    sy += s[i];
                }
            if (cnt == lst) break;
            k = (x + sy) * 1.0 / cnt;
            lst = cnt;
        }
        //printf("%d\n", lst);
        printf("Case #%d:", ++t);
        for (int i = 0;i < n;i++) printf(" %.7f", max((k - s[i]) * 100 / x, 0.0));
        //for (int i = 0;i < n;i++) printf(" %.7f", max((k - s[i]) * 100 / x, 0.0));
        printf("\n");
    }
    return 0;
}
