#include<cstdio>
#include<algorithm>
#include<utility>
#include<string>
#include<vector>
#include<map>
#include<set>
#include<queue>
#include<stack>
#include<cmath>
#include<iostream>

#define SC(a) scanf("%d", &a)
#define SCC(a) scanf("%c", &a)
#define SC2(a, b) scanf("%d%d", &a, &b)
#define SC3(a, b, c) scanf("%d%d%d", &a, &b, &c)
#define PR(a) printf("%d\n", a)
#define FORE(a, b, c) for(int c=int(a); c<= int(b); ++c)
#define FORD(a, b, c) for(int c=int(a); c>= int(b); --c)
#define FORIT(cont_t, cont, it) for(cont_t::iterator it = cont.begin(); it != cont.end(); ++it) 
#define ALL(a) a.begin(), a.end()

#define xx first
#define yy second
#define pb push_back
#define mp make_pair
#define itr iterator

#define dbg if(0) 
#define prd dbg printf
#define koniec dbg {SCC(c);SCC(c);} return 0;

using namespace std;

typedef vector<int> vi;
typedef set<int> si;
typedef map<int, int> mi;
typedef pair<int, int> pi;
typedef vector<pi> vii;
typedef long long ll;
typedef double ld;
typedef unsigned int uint;

char c;
int n, tn, sum, a, j[300];
const ld eps = 1e-8;

bool can_i_get(int i, ld x) {
  ld my_score = j[i] + sum * x;
  ld rest = 1 - x;
  
  FORE(0, n-1, i2) if(i != i2)
    rest -= max(0.0, (my_score - j[i2]) / sum);

  dbg cout << i << " " << x << " " << my_score << " : " << rest << endl;
  return (rest < 0.0) ;
}
  
void compute(int ti) {
  sum = 0;
  SC(n);
  FORE(0, n-1, i) {
    SC(a);
    j[i] = a;
    sum += a;
  }
  cout << "Case #" << ti << ": ";
  //fprintf(stderr, "Case #%d:\n", ti);
  FORE(0, n-1, i) {
    ld l = 0, r = 1;
    FORE(1, 200, ri) {
      ld mid = (l+r)/2;
      if (can_i_get(i, mid))
        r = mid;
      else
        l = mid;
    }
    if (l < eps) l = 0;
    cout << l*100 << " ";
  }
  cout << endl; 
}

int main() {
  SC(tn);
  FORE(1, tn, ti)
    compute(ti);
  return 0;
}

