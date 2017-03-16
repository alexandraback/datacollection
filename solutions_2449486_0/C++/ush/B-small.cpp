
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


int field[200][200];
bool chk[200][200];
const char* PLAYER = "XO";
int main(void) {
  int nCases;
  cin >> nCases;
  REP(iCase, nCases) {
    int nRows, nCols;
    cin >> nRows >> nCols;
    REP(i, nRows){
      REP(j, nCols){
	cin >> field[i][j];
	chk[i][j] = false;
      }
    }
    
    REP(i, nRows){
      int maxi = -100;
      REP(j, nCols){
	maxi = max(maxi, field[i][j]);
      }
      REP(j, nCols){
	if(field[i][j] == maxi)
	  chk[i][j] = true;
      }
    }

    REP(j, nCols){
      int maxi = -100;
      REP(i, nRows){
	maxi = max(maxi, field[i][j]);
      }
      REP(i, nRows){
	if(field[i][j] == maxi)
	  chk[i][j] = true;
      }
    }
    
    bool res = true;
    REP(i, nRows){
      REP(j, nCols){
	if(chk[i][j] == false){
	  res = false;
	  break;
	}
      }
    }
    
    cout << "Case #" << (iCase+1) << ": " << (res ? "YES" : "NO") << endl;
  }
  
  return 0;
}
