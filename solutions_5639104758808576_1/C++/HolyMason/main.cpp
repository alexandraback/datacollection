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
char s[1005];

int main() {
    freopen("1.in", "r", stdin);
    freopen("1.out", "w", stdout);
    int T, ca = 1;
    scanf("%d", &T);
    while(T--) {
        int Smax;
        scanf("%d%s", &Smax, s);
        int cnt = 0, ans = 0;
        for(int i = 0; i <= Smax; ++i) {
            if(s[i] != '0' && cnt < i) ans += i - cnt, cnt = i;
            cnt += s[i] - '0';
        }
        printf("Case #%d: %d\n", ca++, ans);
    }
    return 0;
}
