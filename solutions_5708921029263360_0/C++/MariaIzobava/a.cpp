#include <iostream>
#include <cstdlib>
#include <iomanip>
#include <cstring>
#include <string>
#include <algorithm>
#include <queue>
#include <map>
#include <set>
#include <stack>
#include <vector>
#include <ctime>
#include <fstream>
#include <cmath>
#include <functional>

using namespace std;

#define mp make_pair
#define pb push_back
#define F first
#define S second

const int INF = 1000000000;
const int C = 1000000;
const int mda = 1337 +  14664;
const int MAXN = 60; // число вершин

//struct edge {
//	int a, b, cap, flow;
//};
//
//int n, s, t, d[MAXN], ptr[MAXN], q[MAXN];
//vector<edge> e;
//vector<int> g[MAXN];
//
//void add_edge (int a, int b, int cap) {
//	edge e1 = { a, b, cap, 0 };
//	edge e2 = { b, a, 0, 0 };
//	g[a].push_back ((int) e.size());
//	e.push_back (e1);
//	g[b].push_back ((int) e.size());
//	e.push_back (e2);
//}
//
//bool bfs() {
//	int qh=0, qt=0;
//	q[qt++] = s;
//	memset (d, -1, n * sizeof d[0]);
//	d[s] = 0;
//	while (qh < qt && d[t] == -1) {
//		int v = q[qh++];
//		for (size_t i=0; i<g[v].size(); ++i) {
//			int id = g[v][i],
//				to = e[id].b;
//			if (d[to] == -1 && e[id].flow < e[id].cap) {
//				q[qt++] = to;
//				d[to] = d[v] + 1;
//			}
//		}
//	}
//	return d[t] != -1;
//}
//
//int dfs (int v, int flow) {
//	if (!flow)  return 0;
//	if (v == t)  return flow;
//	for (; ptr[v]<(int)g[v].size(); ++ptr[v]) {
//		int id = g[v][ptr[v]],
//			to = e[id].b;
//		if (d[to] != d[v] + 1)  continue;
//		int pushed = dfs (to, min (flow, e[id].cap - e[id].flow));
//		if (pushed) {
//			e[id].flow += pushed;
//			e[id^1].flow -= pushed;
//			return pushed;
//		}
//	}
//	return 0;
//}
//
//int dinic() {
//	int flow = 0;
//	for (;;) {
//		if (!bfs())  break;
//		memset (ptr, 0, n * sizeof ptr[0]);
//		while (int pushed = dfs (s, INF))
//			flow += pushed;
//	}
//	return flow;
//}

int g[3][50][50];
        int u[50][50][50];

int main()
{
    ios_base::sync_with_stdio(0);
    #ifdef LOCAL
        freopen("input.txt", "r", stdin);
        freopen("output.txt", "w", stdout);
    #else
        //freopen("encryption.in", "r", stdin);
        //freopen("encryption.out", "w", stdout);
    #endif // LOCAL
    int T;
    cin >> T;
    for (int t=1; t<=T; t++){
        int j, p, s, k;
        cin >> j >> p >> s >> k;
        for (int i=0; i<3; i++)
            for (int j=0; j<=20; j++)
            for (int u=0; u<=20; u++)
                g[i][j][u] = 0;
        for (int i=0; i<20; i++)
            for (int j=0; j<=20; j++)
            for (int y=0; y<=20; y++)
                u[i][j][y] = 0;
        vector<pair<pair<int, int>, int> > q;
        for (int J=1; J<=j; J++){
            int x = 1;
            for (int P=1; P<=p; P++){
                for (int y=0; y<k; y++){
                int mx = max(max(g[0][J][P], g[1][P][x]), g[2][J][x]);
                //if (J == 1 && P == 1 && S == 3)
                    //cerr << q.size() << ' '<< mx << endl;
                if (mx < k && !u[J][P][x]){
                    u[J][P][x] = 1;
                    g[0][J][P]++;
                    g[1][P][x]++;
                    g[2][J][x]++;
                    q.pb(mp(mp(J, P), x));
                }
                x++;
                if (x > s) x = 1;
                }
            }
        }

        for (int i=0; i<3; i++)
            for (int j=0; j<=20; j++)
            for (int u=0; u<=20; u++)
                g[i][j][u] = 0;
        for (int i=0; i<20; i++)
            for (int j=0; j<=20; j++)
            for (int y=0; y<=20; y++)
                u[i][j][y] = 0;
        vector<pair<pair<int, int>, int> > q1;
        for (int J=1; J<=j; J++)
        for (int P=1; P<=p; P++)
        for (int S=1; S<=s; S++){
                //cerr << J <<  ' ' << P << ' '<< S << endl;
            if (u[J][P][S]) continue;
            int mx = max(max(g[0][J][P], g[1][P][S]), g[2][J][S]);
            //if (J == 1 && P == 1 && S == 3)
                //cerr << q.size() << ' '<< mx << endl;
            if (mx < k){
                u[J][P][S] = 1;
                g[0][J][P]++;
                g[1][P][S]++;
                g[2][J][S]++;
                q1.pb(mp(mp(J, P), S));
            }
        }
        if (q.size() > q1.size()){
        cout << "Case #" << t << ": " << q.size() << endl;
        for (int i=0; i<q.size(); i++){
            cout << q[i].F.F <<' ' << q[i].F.S << ' '<< q[i].S << endl;
        }
        } else{
        cout << "Case #" << t << ": " << q1.size() << endl;
        for (int i=0; i<q1.size(); i++){
            cout << q1[i].F.F <<' ' << q1[i].F.S << ' '<< q1[i].S << endl;
        }

        }

    }
    return 0;
}
