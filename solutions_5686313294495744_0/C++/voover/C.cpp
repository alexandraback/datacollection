#include <algorithm>
#include <cstdio>
#include <cstdlib>
#include <list>
#include <map>
#include <queue>
#include <set>
#include <stack>
#include <vector>
#include <cmath>
#include <cstring>
#include <string>
#include <iostream>
#include <complex>
#include <sstream>
using namespace std;
 
typedef long long LL;
typedef unsigned long long ULL;
typedef long double LD;
typedef vector<int> VI;
typedef pair<int,int> PII;
 
#define REP(i,n) for(int i=0;i<(n);++i)
#define SIZE(c) ((int)((c).size()))
#define FOR(i,a,b) for (int i=(a); i<(b); ++i)
#define FOREACH(i,x) for (__typeof((x).begin()) i=(x).begin(); i!=(x).end(); ++i)
#define FORD(i,a,b) for (int i=(a)-1; i>=(b); --i)
#define ALL(v) (v).begin(), (v).end()
 
#define pb push_back
#define mp make_pair
#define st first
#define nd second

// MAKSYMALNE SKOJARZENIE w grafie dwudzielnym ("Turbomatching")
// Adam Polak

const int N = 1000;
int n1,n2;          // INPUT
vector<int> g[N];   // INPUT
int m1[N], m2[N];   // OUTPUT
bool c[N];

bool dfs(int u) {
    if (u<0) return true;
    if (c[u]) return false; else c[u]=true;
    FOREACH(v, g[u]) 
        if (dfs(m2[*v])) { m1[u] = *v; m2[*v] = u; return true; }
    return false;
}

int matching() {
    REP(i,n1) m1[i]=-1;
    REP(i,n2) m2[i]=-1;
    bool changed;
    do {
        changed = 0;
        REP(i,n1) c[i]=false;
        REP(i,n1) if (m1[i]<0) changed |= dfs(i);
    } while(changed);
    int siz = 0;
    REP(i,n1) siz += (m1[i]!=-1);
    return siz;
}

char data1[30], data2[30];
void scase() {
  REP(i,1000) g[i].clear();
  int NN;
  scanf("%d", &NN);
  n1 = 0, n2 = 0;
  map<string, int> M1, M2;
  REP(i, NN) {
    scanf("%s%s", data1, data2);
    if (!M1.count(data1)) M1[data1] = n1++;
    if (!M2.count(data2)) M2[data2] = n2++;
    g[M1[data1]].push_back(M2[data2]);
  }
  printf("%d\n", NN - (n1 + n2 - matching()));
}

int main() {
    int C;
    scanf("%d",&C);
    FOR(i,1,C+1) {
        printf("Case #%d: ", i);
        scase();
    }
} 
