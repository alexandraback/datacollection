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

const int MAX_N = 10;
const int MAX_M = 10;
const int INF = 1 << 28;
const int EPS = 1e-9;

int n, m;
int a[MAX_N][MAX_M];
int b[MAX_N][MAX_M];

int solve(){
  REP(pat, 1 << (n + m)){
	REP(i, n) REP(j, m) b[i][j] = 2;
	REP(i, n){
	  if(pat & (1 << i)){
		REP(j, m) b[i][j] = 1;
	  }
	}
	REP(i, m){
	  if(pat & (1 << (n + i))){
		REP(j, n) b[j][i] = 1;
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
  }
  return false;
}

int main(){
  int T;
  cin >> T;
  REP(t, T){
	cin >> n >> m;
	REP(i, n) REP(j, m) cin >> a[i][j];
	printf("Case #%d: %s\n", t + 1, (solve() ? "YES" : "NO"));
  }
  return 0;
}
