#include <bits/stdc++.h>
using namespace std;
#define clc(x) memset(x, 0, sizeof(x))
#define mp(x, y) make_pair(x, y)
#define pb(x) push_back(x)
#define F0(i, n) for (int i = 0; i < n; i++)
#define F1(i, n) for (int i = 1; i <= n; i++)
typedef long long ll;
const ll mxn = 1005;
int T;
int j, p, s, k;
int a1[mxn], a2[mxn], a3[mxn];
int jp[10][10], js[10][10],ps[10][10];

int main() {
    freopen("/Users/akanork/Desktop/1.in", "r", stdin);
    freopen("/Users/akanork/Desktop/1.out", "w", stdout);
    scanf("%d", &T);
    int kase = 1;
    while (T--) {
        clc(a1); clc(a2); clc(a3);
        clc(jp); clc(js); clc(ps);
        scanf("%d%d%d%d", &j, &p, &s, &k);
        int ans = 0;
        int cnt = 0;
        int q = 1;
        if(k >= s) {
            printf("Case #%d: %d\n", kase++, j*p*s);
            F1(x1, j)
            F1(x2, p)
            F1(x3, s){
                printf("%d %d %d\n", x1, x2, x3);  
            }
        }
        else {
            ans = j * p * k;
            printf("Case #%d: %d\n", kase++, ans);
            F1(x1, j) {
                int x3 = q;
                F1(x2, p){
                F1(i, k) {
                    printf("%d %d %d\n", x1, x2, x3);
                    x3 = (x3 + 1 > s ? x3 + 1 - s : x3 + 1);      
                }
                
            }
            q++;

        }
            
            
        }  
    
    }    
    return 0;
}

