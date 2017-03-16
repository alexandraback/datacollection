#include <iostream>
#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <cmath>
#include <utility>
#include <vector>
#include <stack>
#include <queue>
#include <map>
#include <set>
#include <algorithm>

using namespace std;

#define pb push_back
#define mp make_pair

typedef long long           LL;
typedef unsigned long long  ULL;
typedef unsigned int        uint;
typedef pair<int, int>      pii;
typedef pair<LL, LL>        pll;

const int INF = 0x3f3f3f3f;
const int MAXN = 110;

char s[MAXN];
int n, ans;

int main() {
    freopen("b_in.txt", "r", stdin);
    freopen("b_out.txt", "w", stdout);
    int T;
    scanf("%d", &T);
    for (int t = 1; t <= T; t++) {
        scanf("%s", s);
        n = strlen(s);
        ans = 0;
        int ptrl = 0, ptrr = 0;
        while (ptrr < n) {
            if (s[ptrr] == '+') {
                ptrl = ptrr;
                ptrr++;
            } else {
                ptrl = ptrr;
                while (ptrr < n && s[ptrr] != '+') {
                    ptrr++;
                }
                if (ptrl == 0) {
                    ans++;
                } else {
                    ans += 2;
                }
            }
        }

        printf("Case #%d: %d\n", t, ans);
    }
    return 0;
}
