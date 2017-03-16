#include <cstdio>
#include <algorithm>
#include <string>
#include <map>

using namespace std;

const int MAXN = 1010;
const int MAXL = 22;

const int MAXV = MAXN*2;
const int MAXE = MAXN * 4;
const int INF = 1 << 28;

// nxt: adj list head
struct Edge {
    int s, t, w, n;
} E[MAXE]; int lE;

int nxt[MAXV];

void add_edge(int s, int t) {
    E[lE] = {s, t, 1, nxt[s]}; nxt[s] = lE++;
    E[lE] = {t, s, 0, nxt[t]}; nxt[t] = lE++;
}


int v;

int lvl[MAXV];
int flowv, flows, flowt;
bool make_level() {
    int Q[flowv];
    for (int i = 1; i < flowv; ++i) lvl[i] = -1;
    lvl[Q[0] = flows] = 0;
    for (int i = 0, lQ = 1; i < lQ; ++i)
        for (int s = Q[i], j = nxt[s]; j != -1; j = E[j].n)
            if (E[j].w != 0 && lvl[E[j].t] == -1)
                lvl[Q[lQ++] = E[j].t] = lvl[s] + 1;
    return lvl[flowt] != -1;
}

int extend(int s, int cap) {
    if (s == flowt) return cap;
    int acc = 0, aug;
    for (int j = nxt[s]; j != -1 && acc < cap; j = E[j].n)
        if (E[j].w != 0 && lvl[E[j].t] == lvl[s] + 1)
            acc += (aug = extend(E[j].t, min(E[j].w, cap - acc))),
                E[j].w -= aug, E[j^1].w += aug;
    if (acc == 0) lvl[s] = -1;
    return acc;
}

int dinic(int v) {
    int acc = 0;
    flows=0, flowt=1, flowv=v;
    while (make_level()) for (int t; (t = extend(flows, INF)) != 0; ) acc += t;
    return acc;
}


int jizz() {
    int n; scanf("%d", &n);

    lE = 0;
    for (int i = 0; i < n*2+4; ++i) nxt[i] = -1;

    map<string, int> idx[2];
    int v = 2;
    int arr[MAXN][2];
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < 2; ++j) {
            char str[MAXL];
            scanf("%s", str);
            string s = str;

            if (idx[j].count(s) == 0) {
                int id = v++;
                arr[i][j] = idx[j][s] = id;

                if (j==0)
                    add_edge(0, id);
                else
                    add_edge(id, 1);
            } else {
                arr[i][j] = idx[j][s];
            }
        }

        add_edge(arr[i][0], arr[i][1]);
    }

    dinic(v);

    bool used[MAXN] = {};
    for (int i = 0; i < lE; i += 2) {
        const auto &e = E[i];
        if (e.s != 0 and e.t != 1 and e.w == 0)
            used[e.s] = used[e.t] = true;
    }

    int ans = 0;
    for (int i = 0; i < lE; i += 2) {
        const auto &e = E[i];
        if (e.s != 0 and e.t != 1 and e.w == 1) {
            if (used[e.s] and used[e.t]) ans += 1;
            used[e.s] = used[e.t] = true;
        }
    }

    return ans;
}

int main() {
    int T; scanf("%d", &T);
    for (int t = 1; t <= T; ++t) {
        printf("Case #%d: %d\n", t, jizz());
    }

    return 0;
}
