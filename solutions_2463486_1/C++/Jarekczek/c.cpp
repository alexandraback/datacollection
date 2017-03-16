
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
#define rep(i,n) for(long long i=0; i<(n); i++)
#define rep2(i,a,b) for(long long i=(a); i<=(b); i++)
#define rep2d(i,a,b) for(long long i=(a); i>=(b); i--)
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
#define M1 1005
#define M2 (((Int)1e7)+5)
Int anSquare[M1*M1];
vector<Int> vOk;

bool isPali(Int a) //{{{
{
  vector<int> vDig;
  int cDig = 0;
  Int b = a;
  while (b) {
    vDig.push_back(b % 10);
    cDig++, b /= 10;
  }
  assert(cDig == vDig.size());
  bool bOk = true;
  rep(i, cDig) {
    if (vDig[i] != vDig[cDig-i-1]) {
      if (bDebug) cerr << deb(a) << deb(i) << deb(vDig[i]) << deb(vDig[cDig-1-i]) << endl;
      bOk = false;
      break;
    }
  }
  if (bDebug) if (bOk) cerr << deb(a) << "ok" << endl;
  return bOk;
} //}}}

main ()
{
  cin.sync_with_stdio(false);
  cout.sync_with_stdio(false);
  
  zeroMem(anSquare);
  rep(i, M1) anSquare[i*i] = i;
  rep(i, M2) {
    if (isPali(i) && isPali(i*i)) vOk.push_back(i*i);
  }
  cerr << deb(vOk.size()) << endl;
  
  int cTest; cin >> cTest;
  rep(iTest, cTest) {
    Int a; cin >> a;
    Int b; cin >> b;
    Int cOk = 0;
    rep(j, vOk.size()) {
      if (vOk[j] >= a && vOk[j] <= b) cOk++;
    }
    if (bDebug) cerr << (iTest+1) << endl;
    cout << "Case #" << (iTest+1) << ": " << cOk << endl;
  }
}

// :collapseFolds=1:folding=explicit:
