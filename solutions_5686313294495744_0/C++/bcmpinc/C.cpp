#include <cstdlib>
#include <cstdio>
#include <cstring>
#include <cmath>
#include <string>
#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <list>
#include <stack>
#include <map>
#include <set>

using namespace std;

const int MAX_FLOWS = 15000;

struct node;
int flows[MAX_FLOWS];
int flowcnt=0;
int last_tag=0;

struct tube {
    node *next;
    int dir, mx, *flow;
    tube(node*nnext, int ndir, int nmx, int * nflow) 
        : next(nnext), dir(ndir), mx(nmx), flow(nflow) {}
    int free() { return mx - dir**flow; }
    void add(int amount) { *flow+=dir*amount; }
};

struct node {
    vector<tube> tubes;
    int tag;
    node() : tag(0) {}
    void reset() { tubes.clear(); tag=0; }
};

void join(node&a, node&b, int maxtoa, int maxtob) {
    a.tubes.push_back(tube(&b, 1, maxtob, flows+flowcnt));
    b.tubes.push_back(tube(&a,-1, maxtoa, flows+flowcnt));
    flows[flowcnt]=0;
    flowcnt++;                         
}

vector<tube*> path;
node source;
node drain;
int findpath(node * cur) {
    if (cur==&drain) return 0x3fffffff;
    cur->tag=last_tag;
    for (unsigned int i=0; i<cur->tubes.size(); i++) {
        tube * t=&cur->tubes[i];
        if (t->next->tag<last_tag && t->free()) {
            int cap=findpath(t->next);
            if (cap>0) {
                path.push_back(t);
                return min(cap, t->free());
            }
        }
    }
    return 0;
}

int solve() {
    int cap;
    int flow=0;
    last_tag=1;
    while((cap=findpath(&source))) {
        for (unsigned int i=0; i<path.size(); i++) 
            path[i]->add(cap);
        flow+=cap;
        path.clear();
        last_tag++;
    }
    return flow;
}

void reset() {
    source.reset();
    drain.reset();
    flowcnt=0;
}

char ca[32];
char cb[32];
void dostep() {
  reset();
  vector<node> a(1005);
  vector<node> b(1005);
  int n=0;
  int na=0;
  int nb=0;
  map<string, int> ma;
  map<string, int> mb;
  cin >> n;
  for (int i=0; i<n; i++) {
    cin >> ca >> cb;
    int& ia = ma[ca];
    int& ib = mb[cb];
    if (ia==0) ia = ++na;
    if (ib==0) ib = ++nb;
    join(a[ia], b[ib], 0, 1);
  }
  for (int i=0; i<na; i++) {
    join(source, a[i+1], 0, a[i+1].tubes.size()-1);
  }
  for (int i=0; i<nb; i++) {
    join(b[i+1], drain, 0, b[i+1].tubes.size()-1);
  }
  int ans = solve();
  cout << ans << endl;
}

int main() {
  int n;
  cin >> n;
  for(int i=1; i<=n; i++) {
    cout << "Case #" << i << ": ";
    dostep();
  }
  return 0;
}
 
