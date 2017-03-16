/**
 * Copyright © 2016 Authors. All rights reserved.
 * 
 * FileName: C.cpp
 * Author: Beiyu Li <sysulby@gmail.com>
 * Date: 2016-05-01
 */
#include <bits/stdc++.h>

using namespace std;

#define rep(i,n) for (int i = 0; i < (n); ++i)
#define For(i,s,t) for (int i = (s); i <= (t); ++i)
#define foreach(i,c) for (__typeof(c.begin()) i = c.begin(); i != c.end(); ++i)

typedef long long LL;
typedef pair<int, int> Pii;

const int inf = 0x3f3f3f3f;
const LL infLL = 0x3f3f3f3f3f3f3f3fLL;

const int maxn = 10000 + 5;
const int maxe = 1000000 + 5;

class BoundedFlow {
        int psz, s, t;
        struct Edge {
                int v, r;
                Edge *next, *cp;
        } pool[maxe], *e[maxn], *cur[maxn];
        int dlt[maxn], dis[maxn];

        bool bfs()
        {
                queue<int> que;
                memset(dis, 0x3f, sizeof(dis));
                dis[s] = 0; que.push(s);
                while (!que.empty()) {
                        int u = que.front(); que.pop();
                        for (Edge *i = e[u]; i; i = i->next) {
                                int v = i->v;
                                if (i->r && dis[v] == inf) {
                                        dis[v] = dis[u] + 1; que.push(v);
                                        if (v == t) return true;
                                }
                        }
                }
                return false;
        }

        int aug(int u, int m)
        {
                if (u == t) return m;
                int l = m;
                for (Edge* &i = cur[u]; i; i = i->next)
                        if (l && i->r && dis[i->v] == dis[u] + 1) {
                                int f = aug(i->v, min(i->r, l));
                                i->r -= f, i->cp->r += f, l -= f;
                        }
                if (l == m) dis[u] = -1;
                return m - l;
        }

        void add_edge(int u, int v, int w)
        {
                Edge *i = pool + psz;
                i->v = v, i->r = w, i->next = e[u]; e[u] = i;
                i->cp = pool + (psz++ ^ 1);
                if (psz & 1) add_edge(v, u, 0);
        }

        int max_flow()
        {
                int flow = 0;
                while (bfs()) {
                        memcpy(cur, e, sizeof(cur));
                        flow += aug(s, inf);
                }
                return flow;
        }

        public:
        void init(int n)
        {
                psz = 0, s = n, t = n + 1;
                memset(e, 0, sizeof(e));
                memset(dlt, 0, sizeof(dlt));
        }

        void add_edge(int u, int v, int b, int c)
        {
                add_edge(u, v, c - b);
                dlt[u] -= b, dlt[v] += b;
        }

        int min_flow(int src, int trg)
        {
                for (int u = 0; u < s; ++u) {
                        if (dlt[u] > 0) add_edge(s, u, dlt[u]);
                        if (dlt[u] < 0) add_edge(u, t, -dlt[u]);
                }
                max_flow();
                add_edge(trg, src, inf);
                max_flow();
                return (pool + psz - 1)->r;
        }
} grp;

int n;
int s[maxn], t[maxn];
map<string, int> lf, rt;

int get_id(string s, map<string, int> &mp)
{
        if (mp.count(s)) return mp[s];
        return mp[s] = mp.size();
}

int main()
{
        ios::sync_with_stdio(false);

        int T, cas = 0;
        cin >> T;

        while (T--) {
                lf.clear(), rt.clear();
                cin >> n;
                rep(i,n) {
                        string str;
                        cin >> str;
                        s[i] = get_id(str, lf);
                        cin >> str;
                        t[i] = get_id(str, rt);
                }
                int src = 0, trg = lf.size() + rt.size() + 1;
                grp.init(trg + 1);
                foreach(it,lf) grp.add_edge(src, 1 + it->second, 1, n);
                foreach(it,rt) grp.add_edge(1 + lf.size() + it->second, trg, 1, n);
                rep(i,n) grp.add_edge(1 + s[i], 1 + lf.size() + t[i], 0, 1);
                printf("Case #%d: %d\n", ++cas, n - grp.min_flow(src, trg));
        }

        return 0;
}
