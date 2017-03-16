#include <bits/stdc++.h>
#define FOR(i,a,b) for(int i=(a);i<(b);++i)
#define FORD(i, a, b) for(int i = (a); i >= (b); --i)
#define VAR(v, i) __typeof(i) v=(i)
#define FORE(i, c) for(VAR(i, (c).begin()); i != (c).end(); ++i)
#define all(v) (v).begin(),(v).end()
 
#define VI vector<int>
#define PII pair<int,int>
#define st first
#define nd second
#define mp make_pair
#define pb push_back
#define lint long long int
 
#define debug(x) {cerr <<#x <<" = " <<x <<endl; }
#define debug2(x,y) {cerr <<#x <<" = " <<x << ", "<<#y<<" = "<< y <<endl; } 
#define debug3(x,y,z) {cerr <<#x <<" = " <<x << ", "<<#y<<" = "<< y << ", " << #z << " = " << z <<endl; } 
#define debugv(x) {{cerr <<#x <<" = "; FORE(itt, (x)) cerr <<*itt <<", "; cerr <<endl; }}
#define debugt(t,n) {{cerr <<#t <<" = "; FOR(it,0,(n)) cerr <<t[it] <<", "; cerr <<endl; }}
 
#define make( x) int (x); scanf("%d",&(x));
#define make2( x, y) int (x), (y); scanf("%d%d",&(x),&(y));
#define make3(x, y, z) int (x), (y), (z); scanf("%d%d%d",&(x),&(y),&(z));
#define make4(x, y, z, t) int (x), (y), (z), (t); scanf("%d%d%d%d",&(x),&(y),&(z),&(t));
#define makev(v,n) VI (v); FOR(i,0,(n)) { make(a); (v).pb(a);} 
#define IOS ios_base::sync_with_stdio(0)
#define HEAP priority_queue
 
#define read( x) scanf("%d",&(x));
#define read2( x, y) scanf("%d%d",&(x),&(y));
#define read3(x, y, z) scanf("%d%d%d",&(x),&(y),&(z));
#define read4(x, y, z, t) scanf("%d%d%d%d",&(x),&(y),&(z),&(t));
#define readv(v,n) FOR(i,0,(n)) { make(a); (v).pb(a);}

#define REP(i,n) FOR(i,0,(n))
 
using namespace std;

const int max_n = 1005;

int n;
int parent[max_n];
int numer[max_n];

int testuj(int v) {
	FOR(i,0,n) {
		numer[i] = -1;
	}
	numer[v] = 0;
	int nr = 1;
	int w = parent[v];
	while (numer[w]==-1) {
		numer[w] = nr;
		nr++;
		w = parent[w];
	}
	return nr-numer[w];
}

VI g[max_n];
int kolor[max_n];

int dfs(int v) {
	FORE(i,g[v]) {
		int w = *i;
		if (kolor[w] == -1) {
			kolor[w] = kolor[v] + 1;
			dfs(w);
		}
	}
}

void solve() {
	read(n);
	FOR(i,0,n) {
		make(a); a--; 
		parent[i] = a;
		g[i].clear();
	}
	FOR(i,0,n) g[parent[i]].pb(i);
	int ans = 0;
	FOR(i,0,n) ans = max(ans, testuj(i));
  int ans2 = 0;
  FOR(i,0,n) {
		int w = parent[i];
    if (w < i) continue;
		if (parent[w] == i) {
			int loc = 2;
			FOR(j,0,n) kolor[j] = -1;
			kolor[i] = kolor[w] = 0;
			dfs(i); 
			int myns = 0;
			FOR(j,0,n) myns = max(myns, kolor[j]);
			loc += myns;

			FOR(j,0,n) kolor[j] = -1;
			kolor[i] = kolor[w] = 0;
			dfs(w);
			myns = 0;
			FOR(j,0,n) myns = max(myns, kolor[j]);
			loc += myns;
			ans2 += loc;
		}
	}
  
	printf("%d\n", max(ans,ans2));
}

int main() {
	make(tt);
	FOR(test,1,tt+1) {
		printf("Case #%d: ",test);
		solve();
	}
}
