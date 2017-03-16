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

const int MAX_N = 25;
const int MAX_D = 680000;
const int MAX_L = 1000;
const int BP = 200;
const int INF = 1 << 28;
const double EPS = 1e-9;
const double PI = 3.14159265358979;

struct Nomadic{
  int d, n, w, e, s, delta_d, delta_p, delta_s;
};

struct Attack{
  int l, r, s;
};

int n;
Nomadic a[MAX_N];
vector<Attack> d[MAX_D];
int w[MAX_L];


int solve(){
  memset(w, 0, sizeof(w));
  REP(i, MAX_D) d[i].clear();
  REP(i, n){
	REP(j, a[i].n){
	  Attack at = {a[i].w + a[i].delta_p * j + BP,
				   a[i].e + a[i].delta_p * j + BP,
				   a[i].s + a[i].delta_s * j};
	  d[a[i].d + a[i].delta_d * j].push_back(at);
	}
  }
  int r = 0;
  REP(i, MAX_D){
	REP(j, SIZE(d[i])){
	  Attack &at = d[i][j];
	  FOR(k, at.l, at.r){
		if(w[k] < at.s){
		  r++;
		  break;
		}
	  }
	}
	REP(j, SIZE(d[i])){
	  Attack &at = d[i][j];
	  FOR(k, at.l, at.r){
		w[k] = max(w[k], at.s);
	  }
	}
  }
  return r;
}

int main(){
  int T;
  cin >> T;
  REP(t, T){
	cin >> n;
	REP(i, n) cin >> a[i].d
				  >> a[i].n 
				  >> a[i].w
				  >> a[i].e
				  >> a[i].s
				  >> a[i].delta_d
				  >> a[i].delta_p
				  >> a[i].delta_s;
	printf("Case #%d: %d\n", t + 1, solve());
  }
  return 0;
}
