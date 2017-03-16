/***************************************
      zzblack                         **
      2016-04-09                      **
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

ll Pow(int a, int b) {
    ll res = 1;
    while (b--) res *= a;
    return res;
}

int main () {
#ifdef LOCAL
	freopen("C:\\Users\\zzblack\\Desktop\\D-large.in","r",stdin);
      freopen("C:\\Users\\zzblack\\Desktop\\out.txt","w",stdout);
#endif

//    printf("10\n");
//    for (int i = 1; i <= 10; i++) {
//        int k = rand() % 100 + 1;
//        ll cnt = 1, t = k;
//        while (t < 1e18) cnt++, t *= k;
//        int c = rand() % cnt + 1;
//        int s = (k - 1) / c + 1;
//        printf("%d %d %d\n", k, c, s);
//
//    }


    int cas = 1, T = read();
    while (T--) {
        int K = read(), C = read(), S = read();
        printf("Case #%d: ",cas++);
        if ((K - 1) / C + 1 > S) puts("IMPOSSIBLE");
        else {
            int cur = 1, out = 0;
            while (cur <= K) {
                int ti = 1;
                ll id = 1;
                while (ti <= C) {
                    id += (cur - 1) * Pow(K, ti - 1);
                    if (cur == K) out = 1;
                    if (cur < K) cur++;
                    ti++;
                }
                printf("%I64d%c", id, out ? '\n' : ' ');
                if (out) break;
            }
        }
    }


	return 0;
}
