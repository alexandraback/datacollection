#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <queue>
#include <iostream>
#include <algorithm>
#include <unordered_map>
using namespace std;

const bool ONE_SIDE = false;

long long rev(long long x)
{
    char temp[20];
    sprintf(temp, "%I64d", x);
    int len = strlen(temp);
    reverse(temp, temp + len);
    sscanf(temp, "%I64d", &x);
    return x;
}

bool add(queue<long long> &q, long long x, unordered_map<long long, bool> &visit, bool side)
{
    if (visit.count(x)) {
        if (visit[x] == side) {
            return false;
        }
        return true;
    }
    q.push(x);
    visit[x] = side;
    return false;
}

int solve(long long n)
{
    if (n == 1) {
        return 0;
    }
    queue<long long> q, q_rev;
    unordered_map<long long, bool> visit;
    int dist = 0, dist_rev = 0;
    q.push(1);
    q_rev.push(n);
    while (true) {
        //cerr << dist + dist_rev << " " << q.size() << " " << q_rev.size() << endl;
        if (ONE_SIDE || (q.size() <= q_rev.size())) {
            ++ dist;
            int steps = q.size();
            while (steps -- > 0) {
                long long x = q.front();
                q.pop();
                if (add(q, x + 1, visit, false)) {
                    return dist + dist_rev;
                }
                if (add(q, rev(x), visit, false)) {
                    return dist + dist_rev;
                }
            }
        } else {
            ++ dist_rev;
            int steps = q_rev.size();
            while (steps -- > 0) {
                long long x = q_rev.front();
                q_rev.pop();
                if (add(q_rev, x - 1, visit, true)) {
                    return dist + dist_rev;
                }
                if (x % 10 != 0 && add(q_rev, rev(x), visit, true)) {
                    return dist + dist_rev;
                }
            }
        }
    }
}

int main()
{
    freopen("A-small.in", "r", stdin);
    freopen("A-small.out", "w", stdout);

    int tests, test = 1;
    for (scanf("%d", &tests); test <= tests; ++ test) {
        long long n;
        scanf("%I64d", &n);
        printf("Case #%d: %d\n", test, solve(n) + 1);
    }
    return 0;
}
