#include <vector>
#include <list>
#include <map>
#include <set>
#include <deque>
#include <stack>
#include <bitset>
#include <queue>
#include <algorithm>
#include <functional>
#include <numeric>
#include <utility>
#include <sstream>
#include <iostream>
#include <iomanip>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <cstring>
#include <ctime>

using namespace std;

const long long ll_inf = 1000000000000000000LL;
const int inf = 1000000000;
const int size = 1000000;

struct node {
    int data, weight, cost;
    node *next, *anti;
} *ge[20001], *path[20001];

int top;

long long dist[20001];
int flow[20001], pre[20001], q[size];

node* addEdge(int a, int b, int w, int c) {
    static node buf[80000];
    node* p = &buf[top ++];
    p->data = b;
    p->weight = w;
    p->cost = c;
    p->next = ge[a];
    ge[a] = p;
    return p;
}

void insertEdge(int a, int b, int w, int c) {
    node* p1 = addEdge(a, b, w, c);
    node* p2 = addEdge(b, a, 0, -c);
    p1->anti = p2;
    p2->anti = p1;
}

void spfa(int s, int n) {
    for (int i = 0; i < n; i ++) {
        dist[i] = ll_inf;
    }
    dist[s] = 0;
    flow[s] = inf;
    int head = 0;
    int tail = 1;
    int tot = 1;
    q[0] = s;
    while (tot > 0) {
        int now = q[head ++];
        tot --;
        if (head == size) head = 0;
        for (node *p = ge[now]; p; p = p->next)
            if (p->weight > 0 && dist[now] + p->cost < dist[p->data]) {
                dist[p->data] = dist[now] + p->cost;
                pre[p->data] = now;
                path[p->data] = p;
                flow[p->data] = min(flow[now], p->weight);
                q[tail] = p->data;
                tail ++;
                if (tail == size) tail = 0;
                tot ++;
            }
    }
}

void work() {
    int e, r, n;
    scanf("%d%d%d", &e, &r, &n);
    top = 0;
    for (int i = 0; i < n * 2 + 1; i ++)
        ge[i] = 0;
    int s = n * 2 - 1;
    int t = n * 2;
    insertEdge(s, 0, e, 0);
    for (int i = 0; i < n; i ++) {
        int x;
        scanf("%d", &x);
        insertEdge(i, t, e, -x);
        if (i + 1 < n) {
            insertEdge(i, n + i, e, 0);
            insertEdge(s, n + i, r, 0);
            insertEdge(n + i, i + 1, e, 0);
        }
    }
    long long ans = 0;
    while (true) {
        spfa(s, n * 2 + 1);
        if (dist[t] >= 0) break;
        ans -= dist[t] * flow[t];
        int i = t;
        while (i != s) {
            path[i]->weight -= flow[t];
            path[i]->anti->weight += flow[t];
            i = pre[i];
        }
    }
    printf("%lld\n", ans);
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    int T;
    scanf("%d", &T);
    for (int test = 0; test < T; test ++) {
        printf("Case #%d: ", test + 1);
        work();
    }

    return 0;
}