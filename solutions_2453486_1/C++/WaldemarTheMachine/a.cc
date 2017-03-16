#include <string> 
#include <cmath>  
#include <cstdlib>  
#include <algorithm>  
#include <vector>  
#include <string.h>  
#include <utility>  
#include <queue>
#include <stack>
#include <iostream>  
#include <iomanip>  
#include <ctype.h>  
#include <sstream>  
#include <map> 
#include <set> 
#include <stdio.h>  
#include <ctype.h>  

using namespace std;

#define INF = 2000000000
#define FOR(i,n) for(int i = 0;i < n;i++)
#define CLEAR(x) memset((x),0,sizeof(x))
#define REP(i,a,b) for(int i = (a);i<(b);++i)
#define MP make_pair
#define ALL(a) (a).begin(),(a).end()
#define PB push_back
#define PII pair<int,int>
#define sz(a) (int)(a).size()

typedef long long LL;

void solve(int tt){
  cout << "Case #" << tt << ": ";

  string f[4];
  FOR(i,4){
    cin >> f[i];
  }

  FOR(i,4){
    int cx = 0,cy = 0;
    FOR(j,4){
      if (f[i][j] == 'O' || f[i][j] == 'T'){
        cx++;
      }
      if (f[i][j] == 'X' || f[i][j] == 'T'){
        cy++;
      }
    }
    if (cx == 4){
      cout << "O won\n";
      return;
    }
    if (cy == 4){
      cout << "X won\n";
      return;
    }
  }

  FOR(j,4){
    int cx = 0,cy = 0;
    FOR(i,4){
      if (f[i][j] == 'O' || f[i][j] == 'T'){
        cx++;
      }
      if (f[i][j] == 'X' || f[i][j] == 'T'){
        cy++;
      }
    }
    if (cx == 4){
        cout << "O won\n";
        return;
    }
    if (cy == 4){
      cout << "X won\n";
      return;
    }
  }

  int cx = 0,cy = 0;

  FOR(i,4){
    if (f[i][i] == 'O' || f[i][i] == 'T'){
      cx++;
    }
    if (f[i][i] == 'X' || f[i][i] == 'T'){
      cy++;
    }
  }
  if (cx == 4){
      cout << "O won\n";
      return;
  }
  if (cy == 4){
    cout << "X won\n";
    return;
  }

  cx=0;
  cy=0;

  FOR(i,4){
    if (f[i][3-i] == 'O' || f[i][3-i] == 'T'){
      cx++;
    }
    if (f[i][3-i] == 'X' || f[i][3-i] == 'T'){
      cy++;
    }
  }
  if (cx == 4){
      cout << "O won\n";
      return;
  }
  if (cy == 4){
    cout << "X won\n";
    return;
  }

  FOR(i,4){
    FOR(j,4){
      if (f[i][j] == '.'){
        cout << "Game has not completed\n";
        return;
      }
    }
  }

  cout << "Draw\n";
}

int main() {
  int n;cin >> n;
  FOR(i,n){
    solve(i+1);
  }
  return 0;
}
