#include <string>
#include <algorithm>
#include <vector>
#include <iostream>
#include <iterator>
#include <numeric>
#include <set>
#include <map>
#include <queue>
#include <stack>
#include <memory>

using namespace std;

#define PROBLEM_NUM "b"
#define ATTEMPT "0"

#if 1
#   define SIZE "small"
#else
#   define SIZE "large"
#endif

#if 1
#   define PATH PROBLEM_NUM "."
#else
#   define PATH "C:/Downloads/" PROBLEM_NUM "-" SIZE "-attempt" ATTEMPT "."
#endif

int cl[50][50], fl[50][50];

struct triple {
    triple(int x, int y, int t)
        : x(x), y(y), t(t)
    {
    }
    int x, y, t;
};

bool operator <(triple a, triple b) {
    return a.t > b.t;
}

bool cmp(triple a, triple b) {
    return make_pair(a.x, make_pair(a.y, a.t)) < make_pair(b.x, make_pair(b.y, b.t));
}

double solve(int num) {
    printf("Case #%d: ", num);
    int h, n, m;
    scanf("%d%d%d", &h, &n, &m);
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) 
            scanf("%d", &cl[j][i]);
    }
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) 
            scanf("%d", &fl[j][i]);
    }
    std::set< triple, bool(*)(triple,triple) > was(&cmp);
    priority_queue< triple > q;
    q.push(triple(0, 0, 0));
    while (!q.empty()) {
        triple cur = q.top();
        q.pop();
        if (was.count(cur))
            continue;
        if (cur.x == m - 1 && cur.y == n - 1)
            return cur.t / 10.;
        was.insert(cur);
        int ht = max(0, h - cur.t);
        for (int dx = -1; dx < 2; ++dx)
            for (int dy = -1; dy < 2; ++dy) 
                if (abs(dx) + abs(dy) == 1) {
                    int newx = cur.x + dx;
                    int newy = cur.y + dy;
                    if (newx < 0 || newx >= m || newy < 0 || newy >= n)
                        continue;
                    if (ht + 50 <= cl[newx][newy]) {
                        if (fl[cur.x][cur.y] + 50 <= cl[newx][newy] 
                            && fl[newx][newy] + 50 <= cl[newx][newy]
                            && fl[newx][newy] + 50 <= cl[cur.x][cur.y]) {
                                int dt = cur.t == 0 ? 0 : ht - fl[cur.x][cur.y] > 10 ? 10 : 100;
                                q.push(triple(newx, newy, cur.t + dt));
                            }
                    } else {
                        int dt = 50 + ht - cl[newx][newy];
                        q.push(triple(cur.x, cur.y, cur.t + dt));
                    }
                }
    }
    return numeric_limits< double >::infinity();
}

int main() {
    freopen(PATH "in", "r", stdin);
    freopen(PATH "out", "w", stdout);
    int t;
    scanf("%d\n", &t);
    for (int i = 0; i < t; ++i) {
        double res = solve(i + 1); 
        printf("%.1lf\n", res);
    }
}
