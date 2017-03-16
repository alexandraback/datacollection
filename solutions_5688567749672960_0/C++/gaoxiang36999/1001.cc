#include <iostream>
#include <cstdio>
#include <cstring>
#include <string>
#include <map>
#include <set>
#include <queue>
#include <stack>
#include <cmath>
#include <vector>
#include <algorithm>
using namespace std;
typedef long long LL;
typedef double DB;
#define MAXN 20
using namespace std;
int vis[1000005];
int n, t;
struct node {
    int u, step;
};
int ans = 0;
void BFS() {
    queue <node> Q;
    while(!Q.empty()) Q.pop();
    node now, next;
    now.u = 1;
    now.step = 1;
    vis[1] = 1;
    Q.push(now);
    while(!Q.empty()) {
        now = Q.front();
        Q.pop();
        if(now.u == n) {
            ans = now.step;
            break;
        }
        for(int i = 0; i < 2; i++) {
            if(i == 0) {
                next.u = now.u + 1;
                next.step = now.step + 1;
                if(!vis[next.u] && next.u <= n) {
                    Q.push(next);
                    vis[next.u] = 1;
                }
            } else {
                int temp = now.u;
                int nn[20];
                int nnm = 0;
                while(temp) {
                    nn[nnm++] = temp % 10;
                    temp /= 10;
                }
                if(nn[nnm - 1] == 0) continue;
                next.u = 0;
                for(int j = 0; j < nnm; j++) {
                    next.u *= 10;
                    next.u += nn[j];
                }
                next.step = now.step + 1;
                if(!vis[next.u] && next.u <= n) {
                    Q.push(next);
                    vis[next.u] = 1;
                }
            }
        }
    }
}
int main() {
    freopen("A-small-attempt0.in", "r", stdin);
    freopen("outA.out", "w", stdout);
    scanf("%d", &t);
    for(int ii = 1; ii <= t; ii++) {
        memset(vis, 0, sizeof(vis));
        scanf("%d", &n);
        BFS();
        printf("Case #%d: %d\n", ii , ans);
    }
    return 0;
}

