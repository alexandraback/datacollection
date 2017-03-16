/***************************************
      zzblack                         **
      2016-05-01                      **
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

map<string, int> Hash;
int l[20], r[20];

int vis[2][300];



int main () {
#ifdef LOCAL
	freopen("C:\\Users\\zzblack\\Desktop\\case.in","r",stdin);
      freopen("C:\\Users\\zzblack\\Desktop\\case.out","w",stdout);
#endif

    int T = read(), cas = 1;
    while (T--) {
        int n = read();
        Hash.clear();
        int cnt = 1;
        for (int i = 0; i < n; i++) {
            string s, t;
            cin >> s >> t;
            if (Hash[s] == 0) Hash[s] = cnt++;
            if (Hash[t] == 0) Hash[t] = cnt++;
            l[i] = Hash[s], r[i] = Hash[t];
        }
        int ans = 0;
        for (int i = 0; i < 1 << n; i++) {
            int x = __builtin_popcount(i);
            if (x <= ans) continue;
            bool flag = 1;
            CLR(vis);
            for (int j = 0; j < n; j++) {
                if ((i >> j & 1) == 0)
                    vis[0][l[j]] = 1, vis[1][r[j]] = 1;
            }

            for (int j = 0; j < n; j++) {
                if (i >> j & 1) {
                    if (vis[0][l[j]] == 0) flag = 0;
                    if (vis[1][r[j]] == 0) flag = 0;
                }
            }

            if (flag) ans = x;
        }
        printf("Case #%d: %d\n", cas++, ans);

    }

	return 0;
}
