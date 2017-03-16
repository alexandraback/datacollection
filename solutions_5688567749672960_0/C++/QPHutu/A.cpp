#pragma comment(linker, "/STACK:102400000,102400000")
#include <iostream>
#include <cstdio>
#include <cstring>
#include <sstream>
#include <algorithm>
#include <cmath>
#include <map>
#include <functional>
#include <queue>
#include <vector>
#include <cstdlib>
#include <string>
#include <set>
#include <ctime>
using namespace std;

#define PII pair<int,int> 
#define MP make_pair
#define FI first
#define SE second
#define PB push_back
#define lid (id << 1)
#define rid (id << 1 | 1)
#define MID(a, b) ((a + b) >> 1)

const int N = 2000100;
const int NN = 25;
const int INF = 1000000000;
const int Mod = 1000000007;
const int maxn = 10;
const double PI = acos(-1.0);
const double eps = 1e-6;


vector<int> edge[N];
int dist[N], inq[N], n;
queue<int > q;
char s[100];

int main() {
    freopen("A1.in", "r", stdin);
    freopen("A1.out", "w", stdout);
    for(int i = 1; i < N; i++) {
        if(i + 1 < N) {
            edge[i].push_back(i + 1);
            // printf("%d -> %d\n", i, i + 1);
        }

        sprintf(s, "%d", i);
        int len = strlen(s);
        int now = 0;
        for(int j = 0; j < len; j++) {
            now = now * 10 + s[len - 1 - j] - '0';
        }
        if(now < N) {
            edge[i].push_back(now);
            // printf("%d -> %d\n", i, now);
        }

    }
    for(int i = 1; i < N; i++) {
        dist[i] = INF; inq[i] = 0;
    }
    dist[1] = 1; inq[1] = 1; q.push(1);
    while(!q.empty()) {
        int u = q.front(); q.pop();
        for(int i = 0; i < edge[u].size(); i++) {
            int v = edge[u][i];
            if(!inq[v]) {
                dist[v] = dist[u] + 1;
                inq[v] = 1; q.push(v);
            }
        }
    }
    int t;
    scanf("%d", &t);
    for(int i = 1; i <= t; i++) {
        int n;
        scanf("%d", &n);
        printf("Case #%d: %d\n", i, dist[n]);
    }
    return 0;
}