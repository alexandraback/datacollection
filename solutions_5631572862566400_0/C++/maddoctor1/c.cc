#include <iostream>
#include <algorithm>
#include <cstdio>
#include <string>
#include <cstring>
#include <vector>
#include <queue>
using namespace std;
int g[1111];
int in[1111];
int  v[1111];
int num[1111];
int q[1111];
int main() {
    int T, cas = 0,  x, n;
    scanf("%d", &T);
    while(T--) {
        scanf("%d", &n); 
        memset(in, 0, sizeof(in));
        for(int i = 0; i < n; i++) {
            scanf("%d", &x);
            g[i] = x - 1;
            in[x - 1] ++;
        }
        vector<int>tmp;
        memset(num, 0, sizeof(num));
        for(int i = 0; i < n; i++) {
            if(in[i] == 0) {
                memset(v, 0, sizeof(v));
                int now = i;
                int cnt = 0;
                int len = -1;
                v[now] = ++ cnt;
                while(true) {
                    if(v[g[now]]) {
                        len = v[now] - v[g[now]] + 1;
                        break;
                    }
                    now = g[now];
                    v[now] = ++ cnt;
                }
                if(len == 2) {
                    num[g[now]] = max(num[g[now]], v[g[now]] - 1);
                }
            }
        }
        int ans = 0;
        int res = 0;
        memset(q, 0, sizeof(q));
        for(int i = 0; i < n; i++) {
            if(q[i]) continue;
            memset(v, 0, sizeof(v));
            int now = i;
            int cnt = 0;
            int len = -1;
            
            v[now] = ++ cnt;
            while(true) {
                if(v[g[now]]) {
                    len = v[now] - v[g[now]] + 1;
                    break;
                }
                now = g[now];
                v[now] = ++ cnt;
            }
            if(g[now] == i) {
                while(!q[now]) {
                    q[now] = 1;
                    now = g[now];
                }
                if(len == 2) ans += len; 
                else res = max(res, len);
            }
        }
        for(int i = 0; i < n; i++) ans += num[i];
        printf("Case #%d: %d\n", ++ cas, max(ans, res));
    }
    return 0;
}
