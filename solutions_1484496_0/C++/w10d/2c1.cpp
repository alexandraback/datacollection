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

#define dbg if(1) 
#define prd dbg printf
#define koniec dbg {SCC(c);SCC(c);} return 0;

using namespace std;

typedef vector<int> vi;
typedef set<int> si;
typedef map<int, int> mi;
typedef pair<int, int> pi;
typedef vector<pi> vii;
typedef long long ll;
typedef long double ld;
typedef unsigned int uint;

const int sto = 103;

char c;
int n, tn, num[1000], sum, ans1, ans2;
mi mem;

void compute(int ti) {
  SC(n);
  FORE(0, n-1, i)
    SC(num[i]);
    
  mem.clear();
  ans1 = ans2 = 0;
  
  FORE(1, (1<<n)-1, m) {
    sum = 0;
    FORE(0, n-1, i) if((1<<i) & m) sum += num[i];
    if(mem[sum] > 0) {
      ans1 = mem[sum];
      ans2 = m;
      break;
    }
    else
      mem[sum] = m;
  }
  
  printf("Case #%d:\n", ti);
  fprintf(stderr, "Case #%d:\n", ti);
  if(!ans1)
    printf("Impossible\n");
  else {
    FORE(0, n-1, i) if((1<<i) & ans1) printf("%d ", num[i]);
    printf("\n");
    FORE(0, n-1, i) if((1<<i) & ans2) printf("%d ", num[i]);
    printf("\n");
  }
}

int main() {
  SC(tn);
  FORE(1, tn, ti)
    compute(ti);
  return 0;
}

