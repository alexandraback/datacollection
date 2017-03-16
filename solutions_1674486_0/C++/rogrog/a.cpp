// Marek Rogala; Code Jam 2012
#include <algorithm>
#include <cstdio>
#include <cstdlib>
#include <cctype>
#include <cmath>
#include <iostream>
#include <sstream>
#include <string>
#include <utility>
#include <vector>
#include <map>
#include <queue>
#include <set>

using namespace std;
#define VAR(a,b) typeof(b) a=(b)
#define REP(i,n) for(int _n=n, i=0;i<_n;++i)
#define FOR(i,a,b) for(int i=(a),_b=(b);i<=_b;++i)
#define FORD(i,a,b) for(int i=(a),_b=(b);i>=_b;--i)
#define FOREACH(it,c) for(VAR(it,(c).begin());it!=(c).end();++it)
#define ALL(x) x.begin(),x.end()
#define PB push_back
#define ST first
#define ND second
#define MP make_pair
#define SIZE(x) ((int)x.size())
int COND = 1;
#define DB(x) { if (COND > 0) { COND--; REP (xxx, 1) cerr << __LINE__ << " " << #x << " " << x << endl; cerr.flush(); } }
typedef long long LL;
const int INF = 1000000000;
typedef vector<int> VI;
typedef pair<int,int> PII;
typedef vector<PII> VPII;

int const MAXN=1009;

int n,m;
VI Adj[MAXN];
bool inh[MAXN][MAXN];
bool visited[MAXN];

bool calc(int v){
  if(visited[v]) return false;
  visited[v]=true;
  
  REP(i,SIZE(Adj[v])){
    int u=Adj[v][i];
    if(calc(u)) return true;
    if(inh[v][u]) return true;
    
    inh[v][u] = true;
    //cout << v << " << " << u << endl;
    
    FOR(j,1,n){
      if(inh[u][j]){
//        cout << v << " <<< " << j << endl;
        if(inh[v][j]) return true;
        inh[v][j]=true;
      }
    }
  }
  return false;
}


void zrob(int testcase){
  cin >> n;
  FOR(i,1,n){
    cin >> m;
    Adj[i].clear();
    REP(j,m){
      int v;
      cin >> v;
      Adj[i].PB(v);
    }
    visited[i]=false;
    FOR(j,1,n) inh[i][j] = false;
  }
  bool diamond = false;
  FOR(i,1,n){
    if(calc(i)) { diamond = true; break; };
  }
	cout << "Case #"<<testcase<<": "<< (diamond ? "Yes" : "No") << endl;
}

int main() {
	int T; cin >> T;
	for(int i=1;i<=T;i++) zrob(i);
	return 0;
}

