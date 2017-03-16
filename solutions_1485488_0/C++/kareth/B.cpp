#include<iostream>
#include<set>
#include<algorithm>
#include<cstdio>
#include<vector>
#include<cmath>
#include<cstring>
#define INF 2000000000
#define REP(i,n) for(int i = 0; i < (n); i++)
#define FOR(i, a, b) for(int i = (a); i < (b); i++)
#define FORD(i, a, b) for(int i = (a); i >= (b); i--)
#define PI pair<int, int>
#define ST first
#define ND second
#define CLR(a, b) memset(a, b, sizeof(a))
#ifdef DEBUG
  #define DBG printf
#else
  #define DBG
#endif
using namespace std;

vector<int> len;

struct cmp{
  bool operator() (const int &a, const int &b){
    if (len[a] < len[b]) return true;
    if (len[a] > len[b]) return false;
    return a<b;
  }
};

int n,m;
set<int, cmp> st;
PI E[100009][4];

void dfs(int v){
  if( len[v] == 0) return;
  len[v] = 0;
  if( E[v][0].ST == 0 ) dfs( v+m);
  if( E[v][1].ST == 0 ) dfs( v-m);
  if( E[v][2].ST == 0 ) dfs( v-1);
  if( E[v][3].ST == 0 ) dfs( v+1);
}

void dij(){
  int v, u, c;
  len.clear();
  len.resize(n*m, INF);

  dfs(0);
  st.clear();
  REP(i, n*m) st.insert(i);

  //printf("FINISH, %d %d\n", len[0], len[1]);

  while(!st.empty()){
    u = *(st.begin());
    st.erase(st.begin());
    //printf("%d\n", u);

    REP(i, 4){
      if( E[u][i] == PI(-1, -1)) continue;
      if( i == 0) v = u+m;
      if( i == 1) v = u-m;
      if( i == 2) v = u-1;
      if( i == 3) v = u+1;
      if( len[u] > E[u][i].ND ) c = 100;
      else if( E[u][i].ST == E[u][i].ND) c = 100 + max(E[u][i].ST - len[u], 0);
      else c = 10 + max(E[u][i].ST - len[u], 0);
      //printf("c: %d, (%d)\n",c, E[u][i].ND);

      if (len[u]+c < len[v]){
        //printf("move: (%d %d) -> (%d %d)  in %d\n", u/m, u%m, v/m, v%m,len[u]+c);
        st.erase(st.find(v));
        len[v] = len[u]+c;
        st.insert(v);
      }
    }
  }
  return;
}

int c[100009], f[100009], h;

PI times(int f1, int c1, int f2, int c2){
  if( c2 - f2 < 50 || c2 - f1 < 50 || c1 - f2 < 50) return PI(-1, -1);
  int t1 = 50 - (c2 - h), x, y;

  x = max(0, t1);
  y = max(h - f1 - 20, x);

  //printf("%d %d\n", x, y);
  return PI(x, y);
}

int main(){
    int t;
    scanf("%d",&t);
    int casenum = 0;
    while(t--){
      casenum++;

      scanf("%d %d %d", &h, &n, &m);
      REP(i, n) REP(j, m) scanf("%d",&c[i*m + j]);
      REP(i, n) REP(j, m) scanf("%d",&f[i*m + j]);

      REP(i, n*m){
        if( i/m < n-1) E[i][0] = times(f[i], c[i], f[i+m], c[i+m]);
        else E[i][0] = PI(-1, -1);

        if( i/m > 0) E[i][1] = times(f[i], c[i], f[i-m], c[i-m]);
        else E[i][1] = PI(-1, -1);

        if( i%m > 0) E[i][2] = times(f[i], c[i], f[i-1], c[i-1]);
        else E[i][2] = PI(-1, -1);

        if( i%m < m-1) E[i][3] = times(f[i], c[i], f[i+1], c[i+1]);
        else E[i][3] = PI(-1, -1);
      }

      dij();
      printf("Case #%d: %d.%d\n",casenum, len[n*m-1]/10, len[n*m-1]%10);
    }
    return 0;
}


