#include <string>
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
#define INIT(a,v) __typeof(v) a = (v)
#define FOREACH(a,v) for(INIT(a, (v).begin()); a!=(v).end(); ++a)

#define INF 1000000000

#define PB push_back
#define MP make_pair

typedef long long LL;
typedef vector<string> vs;
typedef vector<int> vi;
typedef pair<int, int> pii;
 
template<class T>
inline int size(const T&t){return t.size();}
 
//////////////////////////////////////////

double pr;
long double wyn;
long double ilo;

int main() {
  int TT, A, B;
  scanf("%d ", &TT);
  REP(tt, TT) {
    scanf("%d%d", &A, &B);
    ilo = 1;
    wyn = 2+B;
    FOR(a, 1, A) {
      scanf("%lf", &pr);
      ilo *= pr;
      wyn = min(wyn, ilo*(A-a+B-a+1)+(1-ilo)*(A-a+B-a+1+B+1));
//      fprintf(stderr, "%Lf\n",ilo*(A-a+B-a+1)+(1-ilo)*(A-a+B-a+1+B+1));
    }
    printf("Case #%d: %Lf\n", tt+1, wyn);
  }
}
