
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
#define rep2d(i,a,b) for(long i=(a); i>=(b); i--)
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
#define M1 105
bool abTaken[2][M1]; // [row/column][i] taken
int an0[M1][M1];

main ()
{
  cin.sync_with_stdio(false);
  cout.sync_with_stdio(false);
  
  int cTest; cin >> cTest;
  rep(iTest, cTest) {
    zeroMem(abTaken);
    zeroMem(an0);
    int cy; cin >> cy;
    int cx; cin >> cx;
    if (bDebug) cerr << (iTest+1) << deb(cy) << deb(cx) << endl;
    bool bOk = true;
    rep(y, cy) rep(x, cx) {
      cin >> an0[y][x];
      // if (bDebug) cerr << deb(y) << deb(x) << deb(an0[y][x]) << endl;
    }
    rep2d(h, 100, 0) {
      // This time the lawnmower will run at height h
      // Every square that should be higher already marked its
      //   row and column as taken.
      // For any square that must be of height h,
      // it's sufficient to have either row or column not taken
      rep(y, cy) rep(x, cx) {
        if (an0[y][x] == h) {
          if (abTaken[0][y] && abTaken[1][x]) {
            bOk = false;
            if (bDebug) cerr << deb(y) << deb(x) << deb(h) << endl;
          }
        }
      }

      // So mark the taken rows now
      rep(y, cy) rep(x, cx) {
        if (an0[y][x] >= h) {
          abTaken[0][y] = true;
          abTaken[1][x] = true;
        }
      }
    }
    cout << "Case #" << (iTest+1) << ": " << (bOk ? "YES" : "NO") << endl;
  }
}

// :collapseFolds=1:folding=explicit:
