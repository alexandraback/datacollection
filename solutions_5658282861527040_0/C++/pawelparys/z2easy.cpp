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

int A, B, K;
LL res;

void licz() {
  res = 0;
  REP(a, A)
    REP(b, B)
      if ((a&b)<K)
        ++res;
}

int main() {
  int TT;
  scanf("%d", &TT);
  REP(tt, TT) {
    scanf("%d%d%d", &A, &B, &K);
    licz();
    printf("Case #%d: %lld\n", tt+1, res);
  }
}


