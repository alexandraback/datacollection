#include <bits/stdc++.h>
using namespace std;

typedef long long        ll;
typedef long double      ld;
typedef double           dbl;

#define mp               make_pair
#define pb               push_back
#define sz(x)            (int)(x).size()
#define X                first
#define Y                second
#define all(x)           x.begin(),x.end()
#define y1               y11

#ifdef ROMCHELA
    #define dout(x)        {cout<<#x<<" = ";cout<<(x)<<'\n';}
    #define darr(a, s, n)  {cout<<#a<<" = ";for(int _=s;_<=n;_++)cout<<a[_]<<' ';cout<<'\n';}
    #define dspace()       {for(int _=0;_<10;_++)cout<<'-';cout<<'\n';}
#else
    #define dout(x)        (void)42
    #define darr(a, s, n)  (void)42
    #define dspace()       (void)42
#endif

const int maxn = 100 * 2000 + 10;

dbl a[maxn], b[maxn];
dbl c[maxn], d[maxn];
bool used_d[maxn];
set<int> s;

int main() {
#ifdef ROMCHELA
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    
    int n;
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        int m;
        scanf("%d", &m);
        for (int j = 0; j < m; j++) scanf("%lf", &c[j]);
        for (int j = 0; j < m; j++) scanf("%lf", &d[j]);
        sort(c, c + m);
        sort(d, d + m);
        //darr(c, 0, m - 1);
        //darr(d, 0, m - 1);
        int cntNaomi = 0;
        for (int j = 0; j < 10; j++) used_d[j] = false;
        for (int j = 0; j < m; j++) {
            dbl curNaomi = c[j];
            //printf("Naomi: %lf; ", curNaomi);
            int pos = -1;
            for (int p = m - 1; p >= 0; p--) {
                if (!used_d[p]) {
                    if (curNaomi > d[p]) break;
                    else pos = p;
                }
            }

            if (pos == -1) {
                cntNaomi++;
                for (int p = 0; p < m; p++) {
                    if (!used_d[p]) {
                        used_d[p] = true;
                        //printf("Ken: %lf\n", d[p]);
                        break;
                    }
                }
            } else {
                used_d[pos] = true;
                //printf("Ken: %lf\n", d[pos]);
            }
        }

        int cntCheat = 0;
        int l = 0;
        for (int j = 0; j < m; j++) {
            while (l < m && c[l] < d[j]) l++;
            if (l < m) cntCheat++;
            l++;
        }
        printf("Case #%d: %d %d\n", i + 1, cntCheat, cntNaomi);
    }
    
    return 0;
}
