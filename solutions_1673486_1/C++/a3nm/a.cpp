#include<algorithm>
#include<bitset>
#include<cmath>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<deque>
#include<functional>
#include<iostream>
#include<limits>
#include<map>
#include<queue>
#include<set>
#include<stack>
#include<string>
#include<vector>
#include<numeric>
#include<ext/numeric>  // iota
//#include<ext/hash_set>
//#include<ext/hash_map>

using namespace std;
using namespace __gnu_cxx; // Pour utiliser les ext/...

typedef long long ll;
typedef unsigned long long ull;
typedef vector<int> vi;
typedef pair<int, int> pii;
//typedef int int128 __attribute__ ((mode(TI)));
//typedef unsigned int uint128 __attribute__ ((mode(TI)));

#define MAX 100000
int infty = numeric_limits<int>::max();

int main(int argc, char **argv) {
  int T, i, A, B, j;
  long double p[MAX];
  scanf("%d", &T);
  for (i=0; i<T; i++) {
    scanf("%d %d", &A, &B);
    p[0] = 1;
    for (j=1; j<=A; j++) {
      scanf("%llf", &(p[j]));
      p[j] *= p[j-1];
      //printf("%d: %llf\n", j, p[j]);
    }
//long double best = 2*B + 1;
    long double best = 2 + B;
    for (j=0; j<=A; j++) {
      long double val = (2*j+B-A+1)*p[A-j] + (2*j+B-A+1+B+1)*(1-p[A-j]);
      if (val < best) {
        best = val;
        //printf("got %llf at %d\n", val, j);
      }
    }
    printf("Case #%d: %llf\n", i+1, best);
  }
  return 0;
}
