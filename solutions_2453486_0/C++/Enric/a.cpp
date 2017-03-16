#include <iostream>
#include <vector>
#include <string>
#include <cmath>
using namespace std;
#define REP(i,n) for (int i=0;i<int(n);++i) 
int main() {
  int t; cin >> t;
  REP(cas,t) {
    vector<vector<char> > v(4,vector<char>(4,'.'));
    REP(i,4) REP(j,4) cin >> v[i][j];
    int wino=0,winx=0,full=1;
    int nx=0,no=0,nt=0;
    REP(i,4) REP(j,4) if(v[i][j]=='.') full=0;
    //valid state = both cant have won
    REP(i,4) {
      nx=no=nt=0;
      REP(j,4) {
        if (v[i][j]=='X') ++nx;
        else if(v[i][j]=='O') ++no;
        else if(v[i][j]=='T') ++nt;
      }
      if (no+nt==4) wino=1;
      else if(nx+nt==4) winx=1;
    }
    REP(j,4) {
      nx=no=nt=0;
      REP(i,4) {
        if (v[i][j]=='X') ++nx;
        else if(v[i][j]=='O') ++no;
        else if(v[i][j]=='T') ++nt;
      }
      if (no+nt==4) wino=1;
      else if(nx+nt==4) winx=1;
    }
    nx=no=nt=0;
    REP(i,4) {
      if (v[i][i]=='X') ++nx;
      else if(v[i][i]=='O') ++no;
      else if(v[i][i]=='T') ++nt;
    }
    if (no+nt==4) wino=1;
    else if(nx+nt==4) winx=1;
    nx=no=nt=0;
    REP(i,4) {
      if (v[i][3-i]=='X') ++nx;
      else if(v[i][3-i]=='O') ++no;
      else if(v[i][3-i]=='T') ++nt;
    }
    if (no+nt==4) wino=1;
    else if(nx+nt==4) winx=1;
    cout << "Case #" << cas+1 << ": ";
    if (wino) cout << "O won" << endl;
    else if (winx) cout << "X won" << endl;
    else if(full) cout << "Draw" << endl;
    else cout << "Game has not completed" << endl;
  }
}
