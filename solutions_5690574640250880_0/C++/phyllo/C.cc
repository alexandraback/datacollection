#include <algorithm>
#include <cstdio>
#include <cstdlib>
#include <cctype>
#include <cmath>
#include <iostream>
#include <queue>
#include <list>
#include <map>
#include <numeric>
#include <set>
#include <sstream>
#include <string>
#include <vector>
using namespace std;
#define REP(i,a,n) for(int i=(a); i<(int)(n); i++)
#define rep(i,n) REP(i,0,n)
#define FOR(it,c) for(__typeof((c).begin()) it=(c).begin(); it!=(c).end(); ++it)
#define ALLOF(c) (c).begin(), (c).end()
typedef long long ll;

void solve(int R, int C, int M){
  if(R*C-1 == M){
    rep(i,R){
      rep(j,C){
        if(i==0 && j==0) cout << "c";
        else cout << "*";
      }
      cout << endl;
    }
    return;
  }
  if(R == 1){
    if(C == 1){
      cout << "c" << endl;
      return;
    }
    else if(C-2 >= M){
      cout << "c.";
      rep(i,C-2-M) cout << ".";
      rep(i,M) cout << "*";
      cout << endl;
      return;
    }else{
      cout << "Impossible" << endl;
      return;
    }
  }
  else if(R == 2){
    if(C == 1 && M == 0){
      cout << "c" << endl;
      cout << "." << endl;
      return;
    }
    else if(2*C-4 >= M && M%2==0){
      cout << "c.";
      rep(i,C-2-M/2) cout << ".";
      rep(i,M/2) cout << "*";
      cout << endl;

      cout << "..";
      rep(i,C-2-M/2) cout << ".";
      rep(i,M/2) cout << "*";
      cout << endl;
      return;      
    }else{
      cout << "Impossible" << endl;
      return;
    }
  }
  else {

    if(C == 1){
      if(R-2 >= M){
        cout << "c" << endl;
        cout << "." << endl;
        rep(i,R-2-M) cout << "." << endl;
        rep(i,M) cout << "*" << endl;
        return;
      }else{
        cout << "Impossible" << endl;
        return;
      }
    }
    else if(C == 2){
      if(2*R-4 >= M && M%2==0){
        cout << "c." << endl;
        cout << ".." << endl;
        rep(i,R-2-M/2) cout << ".." << endl;
        rep(i,M/2) cout << "**" << endl;
        return;
      }else{
        cout << "Impossible" << endl;
        return;
      }
    }
    else{
      int field[55][55];      
      rep(i,R) rep(j,C) field[i][j] = -1;
      
      if(R*C-M == 4){
        rep(i,2) rep(j,2) field[i][j] = 1;
        field[0][0] = 0;
        rep(i,R){
          rep(j,C){
            if(field[i][j] == -1) cout << "*";
            else if(field[i][j] == 0) cout << "c";
            else if(field[i][j] == 1) cout << ".";
          }
          cout << endl;
        }
        return;
      }
      else if(R*C-M == 6){
        rep(i,3) rep(j,2) field[i][j] = 1;
        field[0][0] = 0;
        rep(i,R){
          rep(j,C){
            if(field[i][j] == -1) cout << "*";
            else if(field[i][j] == 0) cout << "c";
            else if(field[i][j] == 1) cout << ".";
          }
          cout << endl;
        }
        return;
      }
      else if(R*C-M >= 8){
        rep(i,3) rep(j,3) field[i][j] = 1;
        field[0][0] = 0;
        field[2][2] = -1;

        int rev = R*C-8-M;
        int xrev = C-3;
        int yrev = R-3;
        rep(i,xrev){
          if(rev >= 2){
            field[0][3+i] = 1;
            field[1][3+i] = 1;
            rev-=2;
          }
        }
        rep(i,yrev){
          if(rev >= 2){
            field[3+i][0] = 1;
            field[3+i][1] = 1;            
            rev-=2;
          }
        }
        if(rev >= 1){
          REP(i,2,R){
            REP(j,2,C){
              if(rev>0){
                field[i][j] = 1;
                rev--;
              }
            }
          }
        }

        rep(i,R){
          rep(j,C){
            if(field[i][j] == -1) cout << "*";
            else if(field[i][j] == 0) cout << "c";
            else if(field[i][j] == 1) cout << ".";
          }
          cout << endl;
        }
        return;

      }
      else{
        cout << "Impossible" << endl;
        return;
      }
    }
  }
}

int main(){
  int T;
  cin >> T;

  for(int t=0; t<T; t++){
    int R, C, M;
    cin >> R >> C >> M;
    cout << "Case #" << t+1 << ":" << endl;
    //cout << R << " " << C << " " << M << endl;
    solve(R, C, M);
  }
  
  return 0;
}
