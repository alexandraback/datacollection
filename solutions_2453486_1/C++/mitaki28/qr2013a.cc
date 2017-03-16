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

const string XWON = "X won";
const string OWON = "O won";
const string DRAW = "Draw";
const string NEXT = "Game has not completed";
const int L = 4;
const int INF = 1 << 28;
const int EPS = 1e-9;

char a[L][L];

bool check(char c){

  {
	REP(i, L){
	  bool ok = true;
	  REP(j, L) if(!(a[i][j] == c || a[i][j] == 'T')){
		ok = false;
		break;
	  }
	  if(ok) return true;
	}
  }

  {
	REP(i, L){
	  bool ok = true;
	  REP(j, L) if(!(a[j][i] == c || a[j][i] == 'T')){
		ok = false;
		break;
	  }
	  if(ok) return true;
	}
  }

  {
	bool ok = true;
	REP(i, L) if(!(a[i][i] == c || a[i][i] == 'T')){
	  ok = false;
	  break;
	}
	if(ok) return true;
  }

  {
	bool ok = true;
	REP(i, L) if(!(a[i][L - 1 - i] == c || a[i][L - 1 - i] == 'T')){
	  ok = false;
	  break;
	}
	if(ok) return true;
  }
  return false;
}

string solve(){
  int empty = 0;
  REP(i, L) REP(j, L) if(a[i][j] == '.') empty++;
  if(check('O')) return OWON;
  if(check('X')) return XWON;
  if(empty == 0) return DRAW;
  return NEXT;
}

int main(){
  int T;
  cin >> T;
  REP(t, T){
	REP(i, L) REP(j, L) cin >> a[i][j];
	printf("Case #%d: %s\n", t + 1, solve().c_str());
  }
  return 0;
}
