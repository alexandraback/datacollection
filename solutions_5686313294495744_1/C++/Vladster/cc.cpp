#define _CRT_SECURE_NO_DEPRECATE
#include <algorithm>
#include <cmath>
#include <cstring>
#include <iostream>
#include <map>
#include <queue>
#include <set>
#include <string>
#include <vector>
#include <utility>
using namespace std;

#define fi(i,a,b) for(int i=(a);i<(b); ++i)
#define fd(i,a,b) for(int i=(a);i>(b); --i)
#define fie(i,a,b) for(int i=(a);i<=(b); ++i)
#define fde(i,a,b) for(int i=(a);i>=(b); --i)
#define mp(a,b) make_pair(a,b)
#define pb(x) push_back(x)
#define all(x) x.begin(), x.end()
#define rall(s) (s).rbegin(),(s).rend()
#define C(u) memset((u),0,sizeof((u)))
#define x first
#define y second
#define inf 1000000000
typedef unsigned int uint;
typedef long long ll;
typedef unsigned long long ull;
typedef vector<int> vi;
typedef vector<vi > vvi;
typedef pair<int, int> pii;

#define INP_FILE "C-large.in"
#define OUT_FILE "output.txt"

int index(map<string, int> &w, string &s) {
    if (w.find(s) == w.end()) {
        int m = w.size();
        w[s] = m;
    }
    return w[s];
}

int NODES;
#define MIN(X,Y) ((X) < (Y) ? (X) : (Y))
#define INFINITE 10000000

void push(const int * const * C, int ** F, int *excess, int u, int v) {
    int send = MIN(excess[u], C[u][v] - F[u][v]);
    F[u][v] += send;
    F[v][u] -= send;
    excess[u] -= send;
    excess[v] += send;
}

void relabel(const int * const * C, const int * const * F, int *height, int u) {
    int v;
    int min_height = INFINITE;
    for (v = 0; v < NODES; v++) {
        if (C[u][v] - F[u][v] > 0) {
            min_height = MIN(min_height, height[v]);
            height[u] = min_height + 1;
        }
    }
};

void discharge(const int * const * C, int ** F, int *excess, int *height, int *seen, int u) {
    while (excess[u] > 0) {
        if (seen[u] < NODES) {
            int v = seen[u];
            if ((C[u][v] - F[u][v] > 0) && (height[u] > height[v])) {
                push(C, F, excess, u, v);
            }
            else
                seen[u] += 1;
        }
        else {
            relabel(C, F, height, u);
            seen[u] = 0;
        }
    }
}

void moveToFront(int i, int *A) {
    int temp = A[i];
    int n;
    for (n = i; n > 0; n--) {
        A[n] = A[n - 1];
    }
    A[0] = temp;
}

int pushRelabel(const int * const * C, int ** F, int source, int sink) {
    int *excess, *height, *list, *seen, i, p;

    excess = (int *)calloc(NODES, sizeof(int));
    height = (int *)calloc(NODES, sizeof(int));
    seen = (int *)calloc(NODES, sizeof(int));

    list = (int *)calloc((NODES - 2), sizeof(int));

    for (i = 0, p = 0; i < NODES; i++) {
        if ((i != source) && (i != sink)) {
            list[p] = i;
            p++;
        }
    }

    height[source] = NODES;
    excess[source] = INFINITE;
    for (i = 0; i < NODES; i++)
        push(C, F, excess, source, i);

    p = 0;
    while (p < NODES - 2) {
        int u = list[p];
        int old_height = height[u];
        discharge(C, F, excess, height, seen, u);
        if (height[u] > old_height) {
            moveToFront(p, list);
            p = 0;
        }
        else
            p += 1;
    }
    int maxflow = 0;
    for (i = 0; i < NODES; i++)
        maxflow += F[source][i];

    free(list);

    free(seen);
    free(height);
    free(excess);

    return maxflow;
}

void printMatrix(const int * const * M) {
    int i, j;
    for (i = 0; i < NODES; i++) {
        for (j = 0; j < NODES; j++)
            printf("%d\t", M[i][j]);
        printf("\n");
    }
}


int main()
{
    NODES = 2020;
    int **flow, **capacities, i;
    flow = (int **)calloc(NODES, sizeof(int*));
    capacities = (int **)calloc(NODES, sizeof(int*));
    for (i = 0; i < NODES; i++) {
        flow[i] = (int *)calloc(NODES, sizeof(int));
        capacities[i] = (int *)calloc(NODES, sizeof(int));
    }

    freopen(INP_FILE, "r", stdin);
    freopen(OUT_FILE, "w", stdout);
    int tstCnt; cin >> tstCnt;
    for (int tst = 1; tst <= tstCnt; tst++)
    {
        int n; cin >> n;
        map<string, int> w1, w2;
        vector<pii> edges;
        fi(i, 0, n) {
            string s1, s2; cin >> s1 >> s2;
            edges.push_back(make_pair(index(w1, s1), index(w2, s2)));
        }
        int f1 = 1; int f2 = f1 + w1.size();
        NODES = w1.size() + w2.size() + 2;
        fi(i, 0, NODES) fi(j, 0, NODES) flow[i][j] = capacities[i][j] = 0;
        int st = 0, fin = NODES-1;
        fi(i, 0, w1.size()) capacities[st][f1 + i] = 1;
        fi(i, 0, w2.size()) capacities[f2 + i][fin] = 1;
        fi(i, 0, edges.size()) capacities[f1 + edges[i].first][f2 + edges[i].second] = 1;
        int ans = pushRelabel(capacities, flow, st, fin);
        int d1 = w1.size() - ans;
        int d2 = w2.size() - ans;
        ans = edges.size() - (ans +d1 +d2);

        printf("Case #%d: %d\n",tst, ans);
    }

    return 0;
}