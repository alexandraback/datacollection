#include <cstdio>
#include <iostream>
#include <algorithm>
#include <cstring>
#include <vector>
#include <set>
#include <map>
#include <cmath>
#include <list>
#include <ctime>
#include <sstream>
#include <queue>
#include <stack>
#include <bitset>
using namespace std;
typedef vector<int> VI;
typedef pair<int,int> PII;
typedef long long LL;
#define FOR(x, b, e) for(int x=(b); x<=(e); ++x)
#define FORD(x, b, e) for(int x=((int)(b))-1; x>=(e); --x)
#define REP(x, n) for(int x=0; x<(n); ++x)
#define VAR(v,n) typeof(n) v=(n)
#define ALL(c) c.begin(),c.end()
#define SIZE(x) ((int)((x).size()))
#define FOREACH(i,c) for(VAR(i,(c).begin());i!=(c).end();++i)
#define PB push_back
#define ST first
#define ND second
#define mp(x,y) make_pair(x,y)
#define DEBUG 1
#define debug(x) {if (DEBUG)cerr <<#x <<" = " <<x <<endl; }
#define debugv(x) {if (DEBUG) {cerr <<#x <<" = "; FOREACH(it, (x)) cerr <<*it <<", "; cout <<endl; }}
typedef short int sint;


// MAKSYMALNE SKOJARZENIE w grafie dwudzielnym ("Turbomatching")
// Adam Polak

const int N = 1001;
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

map<string, int> pier, drug;
void solve() {
    int n;
    cin >> n;

    REP(i, n) {
        string x, y;
        cin >> x >> y;
        int x1, y1;
        if (pier.find(x) != pier.end()) {
            x1 = pier[x];
        } else {
            x1 = SIZE(pier);
            pier[x] = x1;
        }
        if (drug.find(y) != drug.end()) {
            y1 = drug[y];
        } else {
            y1 = SIZE(drug);
            drug[y] = y1;
        }
        g[x1].PB(y1);
    }
    n1 = SIZE(pier), n2 = SIZE(drug);
    int c = matching();
    printf("%d\n", n - (n1 + n2 - c));
    pier.clear();
    drug.clear();
    REP(i, n1) g[i].clear();    
}

int main(){
    int t;
    cin >> t;
    FOR(i, 1, t) {
        cout << "Case #" << i << ": ";
        solve();
    }
}
