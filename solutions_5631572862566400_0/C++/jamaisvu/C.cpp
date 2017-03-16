#include <algorithm>
#include <cmath>
#include <cstdio>
#include <cstring>
#include <iomanip>
#include <iostream>
#include <list>
#include <map>
#include <queue>
#include <set>
#include <sstream>
#include <stack>
#include <string>
#include <vector>

using namespace std;
typedef pair<int,int> ii;
typedef vector<int> vi;
typedef vector<ii> vii;
#define MP make_pair
#define PB push_back
#define ff first
#define ss second
#define TR(it,c) for( typeof(c.begin()) it = c.begin(); it != c.end(); ++it )
#define TRR(it,c) for( typeof(c.rbegin()) it = c.rbegin(); it != c.rend(); ++it
#define REP(i,a) for (int i = 0; i < (a); i++)
#define FOR(i,a,b) for (int i = (a); i <= (b); i++)
#define FORD(i,a,b) for (int i = (a); i >= (b); i--)

#define DRI(a) int a; scanf("%d", &a);
#define DRII(a, b) int a, b; scanf("%d %d", &a, &b);
#define DRIII(a, b, c) int a, b, c; scanf("%d %d %d", &a, &b, &c);
#define RI(a) scanf("%d", &a);
#define RII(a, b) scanf("%d %d", &a, &b);
#define RIII(a, b, c) scanf("%d %d %d", &a, &b, &c);
#define MM(arr, num) memset((arr), (num), sizeof((arr)))
#define DEB(x) cerr << ">>> " << (#x) << " -> " << (x) << endl;
#define DEBA(x,n) cerr << (#x) << " "; deba((x),(n));
void deba(int * a, int n){ cerr << "| "; REP(i,n) cerr << a[i] << " "; cerr << "|" << endl;}


inline bool EQ(double a, double b) { return fabs(a-b) < 1e-9; }

const int INF = 1<<30;
typedef long long ll;
typedef unsigned long long ull;
/*******************************************************/
int a[1234];
vi gn[1005];
int n;

int vis[1005];
int dfs(int u, int h, int f){
        int mx = 0;
        REP(i, gn[u].size() ){
            if ( gn[u][i] == f) return h;
            if ( !vis[gn[u][i]] ){ vis[gn[u][i]] = 1;  mx = max(  mx, dfs( gn[u][i], h+1, f  ) ); }
        }
        return mx;
    }


int dfs2(int u){
        int mx = 1;
        REP(i, gn[u].size() ){
            if ( !vis[gn[u][i]] ){ vis[gn[u][i]] = 1;  mx = max( mx , 1 + dfs2( gn[u][i] ) ); }
        }
        return mx;

    }



int len(int i){
  MM(vis,0);
  vis[i] = 1;
  return dfs(i,1,i);
}

int bc(){
  int mx = 0;
  REP(i,n){
      mx = max( mx, len(i) );

  }
  return mx;

}

int rec(){
  //int k = 0;
  int d = 0;

  REP(i,n){
    if ( i == a[ a[i] ]  ) {
      //DEB(i)
      //k++;

      MM(vis,0);
      vis[i] = 1;
      vis[a[i] ] = 1;
      d+= dfs2(i);

    }
    //DEB(k)
    //DEB(d)
  }
  return d;

}






int main() {
//    freopen("C.in","r",stdin);
  freopen("C-small-attempt0.in","r",stdin);freopen("C-small-attempt0.out","w",stdout);
//	freopen("C-small-attempt1.in","r",stdin);freopen("C-small-attempt1.out","w",stdout);
//	freopen("C-small-attempt2.in","r",stdin);freopen("C-small-attempt2.out","w",stdout);
//	freopen("C-large.in","r",stdin);freopen("C-large.out","w",stdout);

  DRI(cs);
  FOR(ci,1,cs){
    RI(n);
    REP(i,1004) gn[i].clear();
    REP(i,n){
      RI(a[i]); a[i]--;
      gn[a[i]].PB(i);
    }

    //DEB(bc());DEB(rec())

    printf("Case #%d: %d\n",ci, max(bc(),rec() ));
  }
  return 0;
}
