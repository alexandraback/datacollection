/*
 * Author: code6
 * Created Time:  2012/5/6 1:05:27
 * File Name: B.cpp
 */
#include <iostream>
#include <cstdio>
#include <cstring>
#include <cmath>
#include <cstdlib>
#include <algorithm>
#include <vector>
#include <list>
#include <map>
#include <set>
#include <deque>
#include <stack>
#include <queue>
#include <bitset>
#include <functional>
#include <numeric>
#include <utility>
#include <sstream>
#include <iostream>
#include <iomanip>
#include <cstdio>
#include <ctime>
#include <string>

using namespace std;
#define out(v) cerr << #v << ": " << (v) << endl
#define SZ(v) ((int)(v).size())
const int maxint = -1u>>1;
template <class T> bool get_max(T& a, const T &b) {return b > a? a = b, 1: 0;}
template <class T> bool get_min(T& a, const T &b) {return b < a? a = b, 1: 0;}
typedef long long ll;
const double PI=acos(-1.0);
const double eps=1e-11;

const int dir[][2] = {
    {0, 1},
    {0, -1},
    {1, 0},
    {-1, 0}
};

const int INF = 100000000;

int h, n, m;
int f[200][200], c[200][200];
int dp[200][200];

struct Node
{
    int x, y;
    int v;
    Node(int x1, int y1, int v1) : x(x1), y(y1), v(v1){}
    bool operator<(const Node & rhs) const
    {
        return  v < rhs.v;
    }
    void print()
    {
        printf("at(%d, %d) height = %d\n", x, y, v);
    }
};

bool isIn(Node cur)
{
    return 0 <= cur.x && cur.x < n && 0 <= cur.y && cur.y < m;
}

int calc(Node from, Node to)
{
    int curH = from.v;
    int f1 = f[from.x][from.y];
    int c1 = c[from.x][from.y];
    int f2 = f[to.x][to.y];
    int c2 = c[to.x][to.y];
    int i;
    
    bool flag = (c2 < 50) || (f1 + 50 > c2) || (f2 + 50 > c2) || (f2 + 50 > c1);
    
    if (flag) {
        return -INF;
    }
    
    i = min(c2 - 50, curH);
    
    int cost = (i - f1 >= 20) ? 10 : 100;
    if (i == h) {
        cost = 0;
    }
    return i - cost;
}

int main() {
    freopen("B-small-attempt0.in", "r", stdin);
    freopen("B-small-attempt0.out", "w", stdout);
    //freopen("B-large.in", "r", stdin);
    //freopen("B-large.out", "w", stdout);
    int t, cas = 0;
    int i, j;
    scanf("%d", &t);
    while (t--) {
        cas ++;
        cin >> h >> n >> m;
        for (i = 0; i < n; i++) {
            for (j = 0; j < m; j++) {
                cin >> c[i][j];
            }
        }
        for (i = 0; i < n; i++) {
            for (j = 0; j < m; j++) {
                cin >> f[i][j];
            }
        }
        
        for (i = 0; i < n; i++) {
            for (j = 0; j < m; j++) {
                dp[i][j] = - INF;
            }
        }
        
        dp[0][0] = h;
        
        priority_queue<Node> Q;
        Q.push(Node(0, 0, h));
        while (!Q.empty()) {
            Node cur = Q.top();
            Q.pop();
            for (i = 0; i < 4; i++) {
                Node next = cur;
                next.x += dir[i][0];
                next.y += dir[i][1];
                if (!isIn(next)) {
                    continue;
                }
                next.v = calc(cur, next);
                if (next.v > dp[next.x][next.y]) {
                    //cur.print(); next.print();
                    dp[next.x][next.y] = next.v;
                    Q.push(next);
                }
            }
        }
        
        double ans = (h - dp[n - 1][ m - 1]) / 10.0;
        
        printf("Case #%d: %.7lf\n", cas, ans);
    }
    return 0;
}

