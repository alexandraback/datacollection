#include <iostream>
#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <cmath>
#include <algorithm>
#include <queue>
#include <map>
#include <set>
#include <vector>
#include <string>
#include <stack>
#include <bitset>
#define INF 0x3f3f3f3f
#define eps 1e-8
#define FI first
#define SE second
using namespace std;
typedef long long LL;
const int N = 10005;
char s[N];
int pre[N], suf[N];
int tab[][4] = {
    {1, 2, 3, 4},
    {2, -1, 4, -3},
    {3, -4, -1, 2},
    {4, 3, -2, -1}
};

inline int key(char ch) {
    if(ch == 'i') return 2;
    if(ch == 'j') return 3;
    return 4;
}

inline int mul(int x, int y) {
    int v = tab[abs(x) - 1][abs(y) - 1];
    if(x * y < 0) v *= -1;
    return v;
}

int main() {
    freopen("1.in", "r", stdin);
    freopen("1.out", "w", stdout);
    int T;
    scanf("%d", &T);
    for(int ca = 1; ca <= T; ++ca) {
        int L, X;
        scanf("%d%d", &L, &X);
        scanf("%s", s + 1);
        int n = L;
        for(int i = 1; i < X; ++i) {
            for(int j = 1; j <= L; ++j) {
                s[++n] = s[j];
            }
        }
        pre[0] = 1;
        for(int i = 1; i <= n; ++i) pre[i] = mul(pre[i - 1], key(s[i]));
        suf[n + 1] = 1;
        for(int i = n; i >= 1; --i) suf[i] = mul(key(s[i]), suf[i + 1]);
        int cnt = pre[1] == 2;
        bool Find = 0;
        for(int i = 2; i < n; ++i) {
            if(suf[i + 1] == 4) {
                if(pre[i] == 4 && cnt) {
                    Find = 1;
                    break;
                }
            }
            cnt += pre[i] == 2;
        }
        printf("Case #%d: ", ca);
        puts(Find ? "YES" : "NO");
    }
    return 0;
}
