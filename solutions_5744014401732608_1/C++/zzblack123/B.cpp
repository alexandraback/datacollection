/***************************************
      zzblack                         **
      2016-05-08                      **
      Orz                             **
****************************************/
#include <set>
#include <map>
#include <queue>
#include <stack>
#include <cmath>
#include <string>
#include <cctype>
#include <cstdio>
#include <vector>
#include <cstdlib>
#include <cstring>
#include <iomanip>
#include <sstream>
#include <iostream>
#include <algorithm>
using namespace std;
#define ls id<<1,l,mid
#define rs id<<1|1,mid+1,r
#define OFF(x) memset(x,-1,sizeof x)
#define CLR(x) memset(x,0,sizeof x)
#define MEM(x) memset(x,0x3f,sizeof x)
typedef long long ll ;
typedef pair<int,int> pii ;
const int maxn = 1e5 + 50 ;
const int maxm = 1e6 + 50;
const double eps = 1e-10;
const int max_index = 62;
const int inf = 0x3f3f3f3f ;
const int MOD = 1e9+7 ;

inline int read(){
    char c = getchar();
    while (!isdigit(c)) c = getchar();
    int x = 0;
    while (isdigit(c)) {
        x = x * 10 + c - '0';
        c = getchar();
    }
    return x;
}

int ans[55][55];

int main () {
#ifdef LOCAL
	freopen("C:\\Users\\zzblack\\Desktop\\case.in","r",stdin);
      freopen("C:\\Users\\zzblack\\Desktop\\case.out","w",stdout);
#endif
    int T = read(), cas = 1;
    while (T--) {
        CLR(ans);
        int n = read();
        ll m;
        scanf("%lld", &m);
//        cout << "m = " << m << "\n";
        printf("Case #%d: ", cas++);
        if (1LL << n - 2 < m) {
            puts("IMPOSSIBLE");
            continue;
        } else puts("POSSIBLE");
        ans[1][n] = 1;
        m--;
        for (int i = 1; i < n; i++) {
            for (int j = i + 1; j < n; j++) ans[i][j] = 1;
        }
        for (int i = 0; i < n-2; i++) {
            if (m >> i & 1) ans[i+2][n] = 1;
        }
//        if(m == (1LL << n-2)) ans[1][n] = 1;

        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= n; j++)
                printf("%d", ans[i][j]);
            puts("");
        }
    }



	return 0;
}
