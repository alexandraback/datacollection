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

char s[110];

int main () {
#ifdef LOCAL
	freopen("C:\\Users\\zzblack\\Desktop\\B-small-attempt0.in","r",stdin);
      freopen("C:\\Users\\zzblack\\Desktop\\out.txt","w",stdout);
#endif
    int T = read(), cas = 1;
    while (T--) {
        scanf("%s", s);
        int ans = 0;
        char last = s[0];
        for (int i = 1; s[i]; i++) {
            if (s[i] == last) continue;
            ans++;
            last = s[i];
        }
        if (last == '-') ans++;
        printf("Case #%d: %d\n", cas++, ans);
    }


	return 0;
}
