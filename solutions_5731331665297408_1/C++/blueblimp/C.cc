#include <algorithm>
#include <cassert>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <map>
#include <queue>
#include <set>
#include <sstream>
#include <vector>
using namespace std;

#define FR(i,a,b) for(int i=(a);i<(b);++i)
#define FOR(i,n) FR(i,0,n)
#define CLR(x,a) memset(x,a,sizeof(x))
#define setmin(a,b) a = min(a,b)
#define PB push_back
#define FORALL(i,v) for(typeof((v).end())i=(v).begin();i!=(v).end();++i)
#define MP make_pair
#define A first
#define B second
#define RF(i,a,b) for(int i=(a)-1;i>=(b);--i)
#define BEND(v) (v).begin(),(v).end()
#define SZ(v) int((v).size())
#define FORI(i,v) FOR(i,SZ(v))
typedef long double ld;
typedef long long ll;

#define dlog printf
//#define dlog(...)

int const maxN = 64;
int const maxZip = 8;

int N,M;
string zip[maxN];

// order of zip -> index in input
vector<int> pi;
vector<int> invpi;

bool adj[maxN][maxN];
bool mark[maxN];
vector<size_t> entry[maxN];

string ret;

bool inconn[maxN];
int parent[maxN];
int setrank[maxN];
void initconn() {
  memset(inconn,0,sizeof(inconn));
  FOR(v,N) parent[v] = v;
  memset(setrank,0,sizeof(setrank));
}
int lookup(int v) {
  if (parent[v] == v) return v;
  return parent[v] = lookup(parent[v]);
}
void unify(int v, int w) {
  v = lookup(v); w = lookup(w);
  if (setrank[w] > setrank[v]) swap(v,w);
  parent[w] = v;
  if (setrank[v] == setrank[w]) ++setrank[v];
}
void putconn(int v) {
  inconn[v] = true;
  FOR(w,N) if (adj[v][w] && inconn[w]) {
    unify(v,w);
  }
}
bool isconn() {
  int node = -1;
  FOR(v,N) if (inconn[v]) {
    if (node == -1) node = lookup(v);
    else if (node != lookup(v)) return false;
  }
  return true;
}

vector<int> stack;
void push(int v) {
  assert(!mark[v]);
  ret += zip[ pi[v] ];
  mark[v] = true;
  int idx = stack.size();
  stack.push_back(v);
  FOR(w,N) if (adj[v][w]) {
    entry[w].push_back(idx);
  }
}
void pop() {
  assert( stack.size() > 0 );
  int v = stack.back();
  stack.pop_back();
  int idx = stack.size();
  FOR(w,N) if (adj[v][w]) {
    assert(entry[w].back() == idx);
    entry[w].pop_back();
  }
}

void doit(int cas)
{
  scanf(" %d %d", &N, &M);

  FOR(i,N) {
    char buf[maxZip];
    scanf(" %s", buf);
    zip[i] = string(buf);
    assert(zip[i].size() == 5);
  }
  pi.clear();
  FOR(i,N) pi.push_back(i);
  sort(BEND(pi), [&](int i, int j) {
    return zip[i] < zip[j];
  });
  invpi.assign(N, -1);
  FOR(i,N) invpi[pi[i]] = i;
  FOR(i,N) assert(invpi[i] != -1);
  ret.clear();

  memset(adj, 0, sizeof(adj));
  FOR(e,M) {
    int x,y;
    scanf(" %d %d", &x, &y);
    assert( 1 <= x && x < y && y <= N );
    int v = invpi.at(x-1), w = invpi.at(y-1);
    adj[v][w] = adj[w][v] = true;
  }

  memset(mark, 0, sizeof(mark));
  FOR(v,N) entry[v].clear();
  stack.clear();
  push(0);
  int remain = N-1;
  while (remain) {
    initconn();
    FOR(v,N) if (!mark[v]) putconn(v);
    int s;
    for (s = 0; s < stack.size(); ++s) {
      putconn(stack[s]);
      if (isconn()) break;
    }
    assert( isconn() );

    int next = -1;
    FOR(v,N) if (!mark[v]) {
      if (entry[v].size() && entry[v].back() >= s) {
        next = v; break;
      }
    }
    assert(next != -1);
    while (entry[next].back()+1 < stack.size()) pop();
    push(next);
    --remain;
  }

  printf("Case #%d: %s\n", cas, ret.c_str());
}

int T;
int main() {
  scanf(" %d", &T);
  assert(1 <= T && T <= 100);
  FOR(cas,T) doit(cas+1);
  return 0;
}
