
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

main ()
{
  cin.sync_with_stdio(false);
  cout.sync_with_stdio(false);
  
  int cTest; cin >> cTest;
  rep2(iTest, 1, cTest) {
    if (bDebug) cerr << deb(iTest) << endl;
    Int a, m; cin >> a >> m;
    Int nRes = m;
    vector<Int> v;
    rep(i, m) {
      int x; cin >> x;
      v.push_back(x);
    }
    if (a != 1) {
      Int cAbs = 0;
      sort(v.begin(), v.end());
      rep(i, v.size()) {
        if (bDebug) cerr << cerr << "I could removes other " << (v.size()-i)
          << " " << deb(cAbs) << deb(a) << " to reach "
          << (cAbs + v.size() - i) << endl;
        setMin(nRes, cAbs + v.size() - i);
        Int b = v[i];
        if (b < a) {
          a += b;
        } else {
          while (b >= a) {
            cAbs++;
            a += (a-1);
            if (bDebug) cerr << "absorbed, now " << deb(a) << deb(cAbs) << endl;
          }
          a += b;
        }
      }
      setMin(nRes, cAbs);
      if (bDebug) cerr << cerr << deb(cAbs) << deb(nRes) << endl;
    }
    cout << "Case #" << iTest << ": " << nRes << endl;
  }
}

// :collapseFolds=1:folding=explicit:
