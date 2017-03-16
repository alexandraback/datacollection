/*
ID: wuqi9395@126.com
PROG:
LANG: C++
*/
#include<map>
#include<set>
#include<queue>
#include<stack>
#include<cmath>
#include<cstdio>
#include<vector>
#include<string>
#include<fstream>
#include<cstring>
#include<ctype.h>
#include<iostream>
#include<algorithm>
using namespace std;
#define INF (1 << 30)
#define LINF (1LL << 60)
#define PI acos(-1.0)
#define mem(a, b) memset(a, b, sizeof(a))
#define rep(i, a, n) for (int i = a; i < n; i++)
#define per(i, a, n) for (int i = n - 1; i >= a; i--)
#define eps 1e-6
#define debug puts("===============")
#define pb push_back
#define mkp make_pair
#define all(x) (x).begin(),(x).end()
#define fi first
#define se second
#define SZ(x) ((int)(x).size())
#define POSIN(x,y) (0 <= (x) && (x) < n && 0 <= (y) && (y) < m)
typedef long long ll;
typedef unsigned long long ULL;
const int N = 1e7 + 10;
const int M = 1e6;
int n, t, f[N];
int change(int x) {
    int cnt = 0;
    while(x) {
        int k = x % 10;
        cnt = cnt * 10 + k;
        x /= 10;
    }
    return cnt;
}
queue<int> q;
void init() {
    int cnt = 1;
    f[1] = 1;
    q.push(1);
    while(!q.empty()) {
        int now = q.front();
        q.pop();
        if (f[now + 1] == 0) {
            f[now + 1] = f[now] + 1;
            q.push(now + 1);
            if (now + 1 <= M) cnt++;
        }
        int x = change(now);
        if (f[x] == 0) {
            f[x] = f[now] + 1;
            if (now + 1 <= M) cnt++;
            q.push(x);
        }
        if (cnt == M) break;
    }
}
int main () {
    init();
    freopen("A-small-attempt0.in", "r", stdin);
    freopen("1.out", "w", stdout);
    cin>>t;
    for (int cas = 1; cas <= t; cas++) {
        scanf("%d", &n);
        printf("Case #%d: %d\n", cas, f[n]);
    }
    return 0;
}
