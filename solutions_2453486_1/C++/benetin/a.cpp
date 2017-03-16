#include <iostream>
#include <sstream>
#include <vector>
#include <string>
#include <map>
#include <set>
#include <algorithm>
#include <cmath>
#include <cstdio>
#include <cstdlib>

using namespace std;

typedef long long i64;
typedef vector<int> VI;
typedef vector<string> VS;
#define REP(i,n) for(int _n=n, i=0;i<_n;i++)
#define FOR(i,a,b) for(int i=(a),_b=(b);i<=_b;i++)
#define ALL(x)   (x).begin(),(x).end()
#define SORT(x) sort(ALL(x))
#define PB push_back

char s[10][10];
char cc;

int play(int x, int y, int dx, int dy) {
  for(int i=0; i<4; ++i,x+=dx,y+=dy) {
    if (s[x][y]!=cc && s[x][y]!='T') return 0;
  }
  return 1;
}

int play(char c) {
  cc=c;
  REP(i,4) if(play(i,0,0,1) || play(0,i,1,0)) return 1;
  return play(0,0,1,1) || play(0,3,1,-1);
}

int main() {
  int Ts;
  cin>>Ts;
  FOR(cs, 1, Ts) {
    string res = "Draw";
    REP(i,4) cin>>s[i];
    if (play('O')) res = "O won";
    else if (play('X')) res = "X won";
    else {
      REP(x,4) REP(y,4) if (s[x][y]=='.') res="Game has not completed";
    } 
    cout << "Case #" << cs << ": " << res << endl;
  }
  return 0;
}
