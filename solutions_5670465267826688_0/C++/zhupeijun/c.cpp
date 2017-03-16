#include <iostream>
#include <cstdio>
#include <cstring>
#include <string>
#include <vector>
#include <algorithm>
#include <cmath>
#include <cstdlib>
#include <queue>
#include <stack>
#include <map>
#include <utility>
#include <set>

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;

char str[10005];
int v[10005];

int mat[5][5] = {
    {0, 0, 0, 0, 0},
    {0, 1, 2, 3, 4},
    {0, 2,-1, 4,-3},
    {0, 3,-4,-1, 2},
    {0, 4, 3,-2,-1}
};

int idx(char c) {
    if(c == 'i') return 2;
    else if(c == 'j') return 3;
    else return 4;
}

int mul(int i, int j) {
    if(i > 0 && j > 0) return mat[i][j];
    else if(i < 0 && j > 0) return -mat[-i][j];
    else if(i > 0 && j < 0) return -mat[i][-j];
    else return mat[-i][-j];
}

int times(int x, int n) {
    int cur = 1;
    for(int i = 0; i < n; i++) cur = mul(cur, x);
    return cur;
}

int main() {
    int cn;
    scanf("%d", &cn);
    for(int ci = 1; ci <= cn; ci++) {
        ll L, X;
        scanf("%lld %lld", &L, &X);
        scanf("%s", str);

        v[0] = idx(str[0]);
        for(int i = 1; i < L; i++) {
            int k = idx(str[i]);
            v[i] = mul(v[i - 1], k);
        }
        printf("Case #%d: ", ci);
        ll tot = times(v[L - 1], X % 4);
        if(tot != -1) { printf("NO\n"); continue; }
        ll all = L * X;
        ll mini = all;
        bool ans = false;
        for(int i = 0; i < L; i++) {
            for(int j = 0; j < 4; j++) {
                ll cur = mul(times(v[L - 1], j), v[i]);
                ll cnt = i + L * j;
                if(cur == 2 && cnt < all - 2 && cnt < mini)
                    mini = cnt;
            }
        }
        for(int i = 0; i < L; i++) {
            for(int j = 0; j < 4; j++) {
                ll cur = mul(times(v[L - 1], j), v[i]);
                ll cnt = i + L * j;
                ll left = max(0LL, X - (j + 1));
                ll use = left / 4 * 4;
                if (cnt + use * L < all - 1) cnt += use * L;
                else {
                    use --;
                    if (use >= 0) cnt += use * L;
                }
                if(cur == 4 && cnt < all - 1 && cnt > mini)
                    ans = true;
            }
        }
        if(ans) printf("YES\n");
        else printf("NO\n");
    }
    return 0;
}

