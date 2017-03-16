
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>
#include <time.h>
#include <algorithm>
#include <iomanip>
#include <iostream>
#include <list>
#include <map>
#include <set>
#include <stack>
#include <vector>

using namespace std;

// debugging stuff {{{
#ifdef DEBUG
  #define bDebug 1
  #define bDebug2 1
#else
  #define bDebug 0
  #define bDebug2 0
#endif
#define deb(a) #a << "=" << (a) << " "
#ifndef HOME
  #define assert(a) {}
#endif

template<class T> ostream& operator<<(ostream& os, vector<T> v) //{{{
{
  for(int i=0; i<v.size(); i++)
    os << v[i] << " ";
  os << endl;
  return os;
}  //}}}
// }}} end of debugging stuff

#define array(a, type, count) type *a = (type*)calloc(sizeof(type), count)
#define eps 1e-9
#define eq(a, b) ( (a) > (b) - eps && (a) < (b) + eps )
#define eraseAll(v) v.erase(v.begin(), v.end())
#define rep(i,n) for(long i=0; i<(n); i++)
#define rep2(i,a,b) for(long i=(a); i<=(b); i++)
#define zeroMem(a) memset(a, 0, sizeof(a))
#define zeroMem2(a, n) memset(a, 0, sizeof(*a) * n)
#define fore(it,L) for(typeof(L.begin()) it=L.begin(); it!=L.end(); it++)
#define eraseAll(v) v.erase(v.begin(), v.end())
#define setMin(a,b) { typeof(a) rv = (b); if (rv < a) a = rv; }
#define setMinP(a,b) { typeof(a) rv = (b); if (a < 0  rv < a) a = rv; }
#define setMax(a,b) { typeof(a) rv = (b); if (rv > a) a = rv; } 
#define swap(a,b) { typeof(a) swapVar = a; a = b; b = swapVar; }
#define Int long long

//*********************** SOLUTION    ******************************
char aCol[2] = {'O', 'X'};
char aBoard[50][50];
// directions: right down right-down right-up
int anStart[4][2] = {  {10, 10}, {10, 10}, {10, 10}, {10, 13} };
int anNextRow[4][2] = { {0,  1}, { 1,  0}, { 0,  1}, { 0,  1} };
int anNextCol[4][2] = { {1,  0}, { 0,  1}, { 1,  1}, { 1, -1} };
char *asRes[4] = { "Game has not completed", "O won", "X won", "Draw" };

main ()
{
  cin.sync_with_stdio(false);
  cout.sync_with_stdio(false);
  
  int cTest; cin >> cTest;
  rep(iTest, cTest) {
    if (bDebug) cerr << deb(iTest+1) << endl;
    string as[5];
    rep(i, 4) {
      cin >> as[i];
    }

    int cDots = 0;
    zeroMem(aBoard);

    rep(i, 4) rep(j, 4) {
      if (as[i][j] == '.') cDots++;
      aBoard[10+i][10+j] = as[i][j];
    }
    
    int nRes = -1; // -1 not finished, 0,1 (winners), 2 draw
    
    rep(iCol, 2) {
      rep(iDir, 4) {
        int x0 = anStart[iDir][0];
        int y0 = anStart[iDir][1];
        rep(iRow, 4) {
          int x = x0 + iRow * anNextRow[iDir][0];
          int y = y0 + iRow * anNextRow[iDir][1];
          int cOk = 0;
          rep(i, 5) {
            if (aBoard[x][y] == aCol[iCol])
              cOk++;
            else if (aBoard[x][y] == 'T') {
              cOk++;
            } else {
              assert(cOk <= 4);
              if (cOk == 4) {
                if (bDebug) cerr << deb(iCol) << deb(aCol[iCol]) << deb(cOk) << deb(x) << deb(y) << endl;
                nRes = iCol;
              }
              cOk = 0;
            }
            x += anNextCol[iDir][0];
            y += anNextCol[iDir][1];
          }
        }
      }
    }
    
    if (nRes < 0) {
      if (!cDots) nRes = 2;
    }
    
    cout << "Case #" << (iTest+1) << ": " << asRes[nRes+1] << endl;
  }
}

// :collapseFolds=1:folding=explicit:
