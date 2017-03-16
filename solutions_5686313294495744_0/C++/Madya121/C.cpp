// Adjacency list implementation of 
// Dinic's blocking flow algorithm.
// This is very fast in practice, 
// and only loses to push-relabel flow.
// Running time:
//     O(|V|^2 |E|)
// INPUT: 
//     - graph, constructed 
//       using AddEdge()
//     - source
//     - sink
// OUTPUT:
//     - maximum flow value
//     - To obtain the actual 
//       flow values, look at all edges with
//       capacity > 0 (zero capacity 
//       edges are residual edges).
#include <cstdio>
#include <bitset>
#include <iostream>
#include <queue>
#include <stack>
#include <string>
#include <cstring>
#include <algorithm>
#include <map>
#include <set>
#include <list>
#include <vector>
#include <cstdlib>
#include <cctype>
#include <cmath>
using namespace std;

// DEFINE LIST
#define REP(_I, _J, _K) for(_I = (_J) ; _I < (_K) ; _I++)
#define input(_A)       freopen(_A, "r", stdin);
#define output(_A)      freopen(_A, "w", stdout);
#define INPUT           input("in.txt");
#define OUTPUT          output("out.txt");
#define CASE_LEFT(_A)   fprintf(stderr, "Cases left: %d\n", _A);
#define hold            {fflush(stdin); getchar();}
#define reset(_A, _B)   memset((_A), (_B), sizeof (_A));
#define debug           printf("<<TEST>>\n");
#define eps             1e-11
#define f_cmp(_A, _B)   (fabs((_A) - (_B)) < eps)
#define phi             acos(-1)
#define pb              push_back
#define value(_A)       cout << "Variabel -> " << #_A << " -> " << _A << endl;
#define st              first
#define nd              second

const int INF = 2000000000;

struct Edge {
  int from, to, cap, flow, index;
  Edge(int from, int to, int cap, int flow, int index) :
    from(from), to(to), cap(cap), flow(flow), index(index) {}
};

struct Dinic {
  int N;
  vector<vector<Edge> > G;
  vector<Edge *> dad;
  vector<int> Q;
  
  Dinic(int N) : N(N), G(N), dad(N), Q(N) {}
  
  void AddEdge(int from, int to, int cap) {
    G[from].push_back(Edge(from, to, cap, 0, G[to].size()));
    if (from == to) G[from].back().index++;
    G[to].push_back(Edge(to, from, 0, 0, G[from].size() - 1));
  }

  long long BlockingFlow(int s, int t) {
    fill(dad.begin(), dad.end(), (Edge *) NULL);
    dad[s] = &G[0][0] - 1;
    
    int head = 0, tail = 0;
    Q[tail++] = s;
    while (head < tail) {
      int x = Q[head++];
      for (int i = 0; i < G[x].size(); i++) {
        Edge &e = G[x][i];
        if (!dad[e.to] && e.cap - e.flow > 0) {
          dad[e.to] = &G[x][i];
          Q[tail++] = e.to;
        }
      }
    }
    if (!dad[t]) return 0;

    long long totflow = 0;
    for (int i = 0; i < G[t].size(); i++) {
      Edge *start = &G[G[t][i].to][G[t][i].index];
      int amt = INF;
      for (Edge *e = start; amt && e != dad[s]; e = dad[e->from]) {
      	if (!e) {
          amt = 0;
          break;
        }
      	amt = min(amt, e->cap - e->flow);
      }
      if (amt == 0) continue;
      for (Edge *e = start; amt && e != dad[s]; e = dad[e->from]) {
      	e->flow += amt;
      	G[e->to][e->index].flow -= amt;
      }
      totflow += amt;
    }
    return totflow;
  }

  long long GetMaxFlow(int s, int t) {
    long long totflow = 0;
    while (long long flow = BlockingFlow(s, t))
      totflow += flow;
    return totflow;
  }
};

string a[1010], b[1010];
vector<string> A, B;
int n, t, kasus;
map<string, int> mapIndexA, mapIndexB;

void clearAll() {
  A.clear();
  B.clear();
  mapIndexA.clear();
  mapIndexB.clear();
}

void normalize() {
  int indxA = 1, indxB = 1;
  for (int i = 0; i < n; i++) {
    if (mapIndexA[a[i]] == 0)
      mapIndexA[a[i]] = indxA++;
    if (mapIndexB[b[i]] == 0)
      mapIndexB[b[i]] = indxB++;
  }
}

int main() {
  input("C-small-attempt1.in");
  output("out.txt");
  cin >> t;
  while (t--) {
    clearAll();
    
    cin >> n;
    Dinic d(3000);
    for (int i = 0; i < n; i++) {
      cin >> a[i] >> b[i];
    }
    normalize();
    
    int maxA = 0, maxB = 0;
    int sumA[10010], sumB[10010];
    int ans = 0;
    reset(sumA, 0);
    reset(sumB, 0);
    for (int i = 0; i < n; i++) {
      //cout << mapIndexA[a[i]] << " " << mapIndexB[b[i]] << endl;
      //d.AddEdge(mapIndexA[a[i]], mapIndexB[b[i]], 1);
      sumA[mapIndexA[a[i]]]++;
      sumB[mapIndexB[b[i]]]++;
      maxA = max(maxA, mapIndexA[a[i]]);
      maxB = max(maxB, mapIndexB[b[i]]);
    }
    
    for (int i = 0; i < n; i++) {
      if (sumA[mapIndexA[a[i]]] > 1 && sumB[mapIndexB[b[i]]] > 1)
        ans++;
    }
    
    /*bool udah[10010];
    memset(udah, false, sizeof udah);
    for (int i = 0; i < n; i++) {
      if (!udah[mapIndexA[a[i]]]) {
        d.AddEdge(1500, mapIndexA[a[i]], 1);
        udah[mapIndexA[a[i]]] = true;
      }
    }
    
    memset(udah, false, sizeof udah);
    for (int i = 0; i < n; i++) {
      if (!udah[mapIndexB[b[i]]]) {
        d.AddEdge(mapIndexB[b[i]], 2000, 1);
        udah[mapIndexB[b[i]]] = true;
      }
    }*/
    
    //int maxFlow = d.GetMaxFlow(1500, 2000);
    cout << "Case #" << ++kasus << ": " << ans << endl;
  }
  return 0;
}
