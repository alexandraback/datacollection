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
typedef long long ll;

char s[1005];

int main() {
    freopen("A-small-attempt0.in", "r", stdin);
    freopen("Asmall.out", "w", stdout);
    int T;
    scanf("%d", &T);
    for(int cas = 1; cas <= T; ++ cas) {
        scanf("%s", s);
        printf("Case #%d: ", cas);
        string ans = "";
        for(int i = 0; s[i]; ++ i) {
            string A = ans + s[i], B = s[i] + ans;
            if(A < B) {
                ans = B;
            } else {
                ans = A;
            }
        }
        printf("%s\n", ans.c_str());
    }
    return 0;
}
