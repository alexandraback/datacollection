#include<cstdio>
#include<cmath>
#include<cstring>
#include<iostream>
#include<algorithm>
#include<utility>
#include<vector>
#include<string>
#include<functional>
#include<queue>

#define FOR(i, a, n) for(int i = (a); i < (n); i++)
#define FORN(i, a, n) for(int i = (a); i <= (n);i++)
#define REP(i, n) FOR(i, 0, n)
#define REPN(i, n) FORN(i, 1, n)
#define ABS(x) (x) > 0 ? (x) : -(x)
#define SIZE(vec) (int)vec.size()

using namespace std;

typedef long long ll;
typedef pair<int, int> P;

const int MAX_N = 100;
const int MAX_M = 100;
const int INF = 1 << 28;
const int EPS = 1e-9;

int n, m;
int rmax[MAX_N], cmax[MAX_M];
int a[MAX_N][MAX_M];
int b[MAX_N][MAX_M];
int al[MAX_N * MAX_M];

int solve(){
  REP(i, n) REP(j, m) b[i][j] = 100;
  sort(al, al + n * m, greater<int>() );
  REP(k, n * m){
	int v = al[k];
	REP(i, n) if(rmax[i] <= v){
	  REP(j, m) b[i][j] = v;
	}
	REP(i, m) if(cmax[i] <= v){
	  REP(j, n) b[j][i] = v;
	}
  }
  bool ok = true;
  REP(i, n){
	REP(j, m){
	  if(b[i][j] != a[i][j]){
		ok = false;
		break;
	  }
	}
	if(!ok) break;
  }
  if(ok) return true;
  else return false;
}

int main(){
  int T;
  cin >> T;
  REP(t, T){
	cin >> n >> m;
	memset(rmax, 0, sizeof(rmax));
	memset(cmax, 0, sizeof(cmax));
	REP(i, n) REP(j, m){
	  cin >> a[i][j];
	  rmax[i] = max(rmax[i], a[i][j]);
	  cmax[j] = max(cmax[j], a[i][j]);
	  al[i * m + j] = a[i][j];
	}
	printf("Case #%d: %s\n", t + 1, (solve() ? "YES" : "NO"));
  }
  return 0;
}
