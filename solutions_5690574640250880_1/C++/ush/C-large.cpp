
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

char buf[55][55];

bool solve(int nRow, int nCol, int nBomb) {
  cerr << "solve(" << nRow << " " << nCol << " " << nBomb << ")" << endl;
  if(nRow > nCol){
    bool res = solve(nCol, nRow, nBomb);
    REP(i, 52) REP(j, i)
      swap(buf[i][j], buf[j][i]);
    return res;
  }
  memset(buf, 0, sizeof buf);

  if(nBomb == 0){
    REP(i, nRow) REP(j, nCol)
      buf[i][j] = '.';
    buf[0][0] = 'c';
//     cerr << "TRUE 1"<< endl;
    return true;
  }

  int nSpace = nRow * nCol - nBomb;
  
  REP(i, nRow) REP(j, nCol)
    buf[i][j] = '*';

  if(nRow == 1){
    REP(j, nSpace){
      buf[0][j] = '.';
    }
    buf[0][0] = 'c';
//     cerr << "TRUE 2"<< endl;
    return true;
  }
  
  if(nSpace == 1){
    buf[0][0] = 'c';
//     cerr << "TRUE 3"<< endl;
    return true;
  }

  if(nSpace % 2 == 0){
    // base is 2*2 space
    if(nSpace < 4){
//       cerr << "FALSE 4"<< endl;
      return false;
    }
    REP(i, 2) REP(j, 2)
      buf[i][j] = '.';
    nSpace -= 4;
  }else{
    // base is 3*3 space
    if(nSpace < 9 || nRow < 3){
//       cerr << "FALSE 5"<< endl;
      return false;
    }
    REP(i, 3) REP(j, 3)
      buf[i][j] = '.';
    nSpace -= 9;
  }

  if(nBomb == 1){ // (example) nRow == 4, nCol == 4, nBomb == 1
    REP(i, nRow) REP(j, nCol)
      buf[i][j] = '.';
    buf[nRow-1][nCol-1] = '*';
    buf[0][0] = 'c';
    return true;
  }
  
  while(nSpace > 0){
    REP(i, nRow) REP(j, nCol){
      if(nSpace > 0 && buf[i][j] == '*' &&
	 j+1 < nCol && buf[i][j+1] == '*' &&
	 i-1 >= 0 && buf[i-1][j] == '.' && buf[i-1][j+1] == '.' &&
	 (j == 0 || buf[i][j-1] == '.')) {
	// add horizontal two space
	nSpace -= 2;
	buf[i][j] = buf[i][j+1] = '.';
	
      }else if(nSpace > 0 && buf[i][j] == '*' &&
	 i+1 < nRow && buf[i+1][j] == '*' &&
	 j-1 >= 0 && buf[i][j-1] == '.' && buf[i+1][j-1] == '.' &&
	 (i == 0 || buf[i-1][j] == '.')) {
	// add vertical two space
	nSpace -= 2;
	buf[i][j] = buf[i+1][j] = '.';
	
      }

    }
  }
  
  buf[0][0] = 'c';
//   cerr << "TRUE 6" << endl;
  return true;
}


int main(void) {
  int nCases;
  cin >> nCases;
  REP(iCase, nCases) {
    printf("Case #%d:\n", iCase+1);
    
    int nRow, nCol, nBomb;
    cin >> nRow >> nCol >> nBomb;
    if(solve(nRow, nCol, nBomb)){
      REP(i, nRow){
	puts(buf[i]);
      }
    }else{
      puts("Impossible");
    }
  }
  
  return 0;
}
