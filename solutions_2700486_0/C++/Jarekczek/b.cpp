
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>
#include <time.h>
#include <algorithm>
#include <fstream>
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
#define setMinP(a,b) { typeof(a) rv = (b); if (a < 0 || rv < a) a = rv; }
#define setMax(a,b) { typeof(a) rv = (b); if (rv > a) a = rv; } 
#define swap(a,b) { typeof(a) swapVar = a; a = b; b = swapVar; }
#define Int long long

//*********************** SOLUTION    ******************************


int fact(int n) //{{{
{
  if (n < 2) return 1;
  else return fact(n-1) * n;
} //}}}

Int comb(int n, int k) //{{{
{
  Int nComb = fact(n) / ( fact(k) * fact(n-k) );
  if (bDebug) cerr << "comb: " << deb(n) << deb(k) << deb(nComb) << endl;
  return nComb;
} //}}}

#define M1 1000005

main ()
{
  cin.sync_with_stdio(false);
  cout.sync_with_stdio(false);
  int cTest; cin >> cTest;
  rep2(iTest, 1, cTest) {
    double fProb = 0;
    if (bDebug) cerr << deb(iTest) << endl;
    Int x, y, n; cin >> n >> x >> y;
    if (x < 0) x = -x;
    Int L0 = (x + y) / 2;
    Int cDiam = 0;
    Int L = 0;
    Int p = 0; // the count of diamonds on one side
    while (L < L0) {
      cDiam += 2*p + 1;
      p = p + 2;
      L++;
      if (bDebug) cerr << deb(L) << deb(cDiam) << deb(p) << endl;
    }
    Int a = n - cDiam;
    Int b = y + 1; // b - is our diamond row, counting from 1
    if (bDebug) cerr << deb(L) << deb(cDiam) << deb(p)
      << deb(a) << deb(b) << endl;
    if (a >= p + b) {
      fProb = 1;
    } else if (a < b) {
      fProb = 0;
    } else if (b == p + 1) {
      // reaching the top is a different case, requires filling whole level
      fProb = (a == 2*p+1) ? 1 : 0;
    } else {
      // more than 0, less than 1
      // must accumulate probability of b, b+1, .. successes in "a" tries
      fProb = 0;
      rep2(i, b, a) {
        fProb += comb(a, i);
      }
      rep(j, a) fProb /= 2.0;
      if (bDebug) cerr << deb(a) << deb(b) << deb(fProb) << endl;
    }
    if (((x + y) % 2) != 0) fProb = 0;
    cout << "Case #" << iTest << ": " << fProb << endl;
  }
}

// :collapseFolds=1:folding=explicit:
