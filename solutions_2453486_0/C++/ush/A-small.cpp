
#include <cstdio>
#include <iostream>
#include <sstream>
#include <string>
#include <cstring>
#include <cctype>
#include <algorithm>
#include <vector>
#include <map>
#include <queue>
#include <set>
#include <list>
#include <cmath>
#include <complex>
#include <numeric>
#include <cassert>
using namespace std;

#define REP(i,n) for(int i = 0; i < (int)(n); ++i)
#define FOR(i,s) for(__typeof((s).begin()) i = (s).begin(); i != (s).end(); ++i)
#define ALLOF(s) ((s).begin()), ((s).end())

typedef long long ll;


char field[10][10];
const char* PLAYER = "XO";
int main(void) {
  int nCases;
  cin >> nCases;
  REP(iCase, nCases) {
    cout << "Case #" << (iCase+1) << ": ";
    REP(i, 4){
      cin >> field[i];
    }

    
    REP(player, 2){
      REP(i, 4){
	bool ok = true;
	REP(j, 4){
	  if(field[i][j] == PLAYER[player] || field[i][j] == 'T'){
	  }else{
	    ok = false;
	    break;
	  }
	}
	if(ok){
	  cout << PLAYER[player] << " won" << endl;
	  goto NEXT;
	}
      }

      REP(j, 4){
	bool ok = true;
	REP(i, 4){
	  if(field[i][j] == PLAYER[player] || field[i][j] == 'T'){
	  }else{
	    ok = false;
	    break;
	  }
	}
	if(ok){
	  cout << PLAYER[player] << " won" << endl;
	  goto NEXT;
	}
      }
      
      {
	bool ok = true;
	REP(i, 4){
	  if(field[i][i] == PLAYER[player] || field[i][i] == 'T'){
	  }else{
	    ok = false;
	    break;
	  }
	}
	if(ok){
	  cout << PLAYER[player] << " won" << endl;
	  goto NEXT;
	}
      }

      {
	bool ok = true;
	REP(i, 4){
	  if(field[i][3-i] == PLAYER[player] || field[i][3-i] == 'T'){
	  }else{
	    ok = false;
	    break;
	  }
	}
	if(ok){
	  cout << PLAYER[player] << " won" << endl;
	  goto NEXT;
	}
      }
    }
    
    {
      bool empty = false;
      REP(i, 4){
	REP(j, 4){
	  empty = empty || (field[i][j] == '.');
	}
      }
      if(empty){
	cout << "Game has not completed" << endl;
      }else{
	cout << "Draw" << endl;
      }
    }
    
  NEXT:
    ;
  }
  
  return 0;
}
