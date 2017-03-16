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

int cnt[3000];

int main() {
    freopen("B-large.in", "r", stdin);
    freopen("Blarge.out", "w", stdout);
    int T;
    scanf("%d", &T);
    for(int cas = 1; cas <= T; ++ cas) {
        memset(cnt, 0, sizeof(cnt));
        int n;
        scanf("%d", &n);
        for(int i = 0; i < n + n - 1; ++ i) {
            for(int j = 0; j < n; ++ j) {
                int x;
                scanf("%d", &x);
                ++ cnt[x];
            }
        }
        vector <int> ans;
        for(int i = 1; i <= 2500; ++ i) {
            if(cnt[i] & 1) {
                ans.push_back(i);
            }
        }
        sort(ans.begin(), ans.end());
        printf("Case #%d:", cas);
        for(auto x : ans) {
            printf(" %d", x);
        }
        puts("");
    }
    return 0;
}
