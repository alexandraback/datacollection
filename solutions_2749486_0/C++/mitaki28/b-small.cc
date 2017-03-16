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

const int INF = 1 << 28;
const double EPS = 1e-9;
const double PI = 3.14159265358979;

int X, Y;

string solve(){
  string s;
  int dx = -1, dy = -1;
  if(X < 0) dx *= -1;
  if(Y < 0) dy *= -1;
  int x = 0, y = 0;
  int d = 1;
  while(x != X){
	x += d * dx;
	if(dx < 0){
	  s.push_back('W');
	}else{
	  s.push_back('E');
	}
	dx *= -1;
	d++;
  }
  while(y != Y){
	y += d * dy;
	if(dy < 0){
	  s.push_back('S');
	}else{
	  s.push_back('N');
	}
	dy*= -1;
	d++;
  }
  return s;
}

int main(){
  int T;
  cin >> T;
  REP(t, T){
	cin >> X >> Y;
	printf("Case #%d: %s\n", t + 1, solve().c_str());
  }
  return 0;
}
