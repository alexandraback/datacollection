#include <string>
#include <cstring>
#include <vector>
#include <cmath> 
#include <cstdio>
#include <vector>
#include <set>
#include <map>
#include <queue>
#include <algorithm>
#include <utility>
#include <sstream>
#include <iostream>
 
using namespace std;
 
#define REP(a,n) for(int a=0; a<(n); ++a)
#define FOR(a,b,c) for(int a=(b); a<=(c); ++a)
#define FORD(a,b,c) for(int a=(b); a>=(c); --a)
#define INIT(i,v) __typeof(v) i = (v)
#define FOREACH(i,v) for(INIT(i, (v).begin()); i!=(v).end(); ++i)
#define MP make_pair
#define PB push_back
 
typedef pair<int, int> pii;
typedef vector<int> vi;
typedef vector<string> vs;
typedef long long LL;
 
template<class T>
inline int size(const T&t){return t.size();}

#define INF 1000000000
 
//////////////////////////////////////////

LL res;
#define C 31

inline bool daj_bit(int X, int bit) {
  return (X&(1<<bit)) ? 1 : 0;
}

inline int ustaw(int X, int bit) {
  return X|(1<<bit);
}

inline int zeruj(int X, int bit) {
  return X&(~(1<<bit));
}

inline int ustaw_na(int X, int bit, bool czy) {
  return czy ? ustaw(X, bit) : zeruj(X, bit);
}

LL pot3(int bit) {
  LL res2 = 1;
  REP(a, bit)
    res2 *= 3;
  return res2;
}

int find(int A) {
  REP(a, C)
    if (A&(1<<a))
      return a;
  return -1;
}

void licz_fabk(int A, int B, int K) {
  if (A<=K || B<=K) {
    res += A*(LL)B;
    return;
  }
  if (A<B) swap(A, B);
  int bitA = find(A);
  int bitB = find(B);
  int bitK = find(K);
  res += (1<<bitK)*(LL)(1<<(bitA-bitB))*(LL)(1<<bitK)*(LL)pot3(bitB-bitK);
}

int ma_bit0(int A, int bit) {
  --A;
  if (A&(1<<bit)) {
    A = zeruj(A, bit);
    REP(b, bit)
      A = ustaw(A, b);
  }
  int Ad = A&((1<<bit)-1);
  int Ag = A-Ad;
  Ag = Ag>>1;
  A = Ag+Ad;
  ++A;
  return A;
}

void licz_fbk(int A, int B, int K) { // K oraz B jest potega 2
  if (A<=K) {
    res += A*(LL)B;
    return;
  }
  FORD(bit, C-1, 0) 
    if (A&(1<<bit)) {
      licz_fabk(1<<bit, B, K);
      licz_fbk(A-(1<<bit), ma_bit0(B, bit), K);
      return;
    }
}

void licz_fk(int A, int B, int K) { // tutaj K jest potega 2
  if (A<=K) {
    res += A*(LL)B;
    return;
  }
  FORD(bit, C-1, 0) 
    if (A&(1<<bit)) {
      licz_fbk(B, 1<<bit, K);
      licz_fk(A-(1<<bit), ma_bit0(B, bit), K);
      return;
    }
}

int ma_bit1(int A, int bit) {
//printf("%d %d--> ", A, bit);
  --A;
  if (!(A&(1<<bit))) {
    if (A<(1<<bit))
      return 0;
    int b2 = bit;
    while (!(A&(1<<b2)))
      ++b2;
    A = zeruj(A, b2);
    REP(b, b2)
      A = ustaw(A, b);
  }
  A = zeruj(A, bit);
  int Ad = A&((1<<bit)-1);
  int Ag = A-Ad;
  Ag = Ag>>1;
  A = Ag+Ad;
  ++A;
//printf("%d\n", A);
  return A;
}

void licz(int A, int B, int K) {
//printf("%d %d %d\n", A, B, K);
  FORD(bit, C-1, 0)
    if (K & (1<<bit)) {
      licz_fk(A, B, 1<<bit);
      licz(ma_bit1(A, bit), ma_bit1(B, bit), K-(1<<bit));
      return;
    }
  // jak nie znajdzie to K jest 0, czyli wynik = 0
}

int main() {
  int TT;
  scanf("%d", &TT);
  REP(tt, TT) {
    int A, B, K;
    scanf("%d%d%d", &A, &B, &K);
    res = 0;
    licz(A, B, K);
    printf("Case #%d: %lld\n", tt+1, res);
  }
}


