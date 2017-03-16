#include <cmath>
#include <queue>
#include <vector>
#include <queue>
#include <map>
#include <cstdlib>
#include <cstdio>
#include <fstream>
#include <iomanip>   
#include <iostream>  
#include <sstream>  // istringstream buffer(myString);
#include <stack>
#include <set>
#include <algorithm>
#include <cstring>
#include <limits>

#define INF 1000000000;

using namespace std;

typedef long long ll;
typedef vector<int> vi;
typedef pair<int, int> ii;
typedef vector<ii> vii;


int parent(ll p, ll q) {
  if (p*2 == q || p==q) { return 1;}
  if (q % 2 == 1) return -INF;
  if (p*2 > q) {
    if (parent(p-q/2, q/2) > 0) return 1;
    return -INF;
  }
  return 1 + parent(p, q/2);
}

ll gcd(ll a, ll b) { return !b ? a : gcd(b, a % b); }

int main() {
  
  int TC, CASE=1;
  scanf("%d\n", &TC);
  while(TC--) {
    ll p, q;
    scanf("%lld/%lld", &p, &q);
    ll g = gcd(p,q);
    p = p/g;
    q = q/g;
    int r = parent(p,q);
    if (r<0 || r>40) {
      printf("Case #%d: impossible\n", CASE++);
    } else {
      printf("Case #%d: %d\n", CASE++, parent(p,q));
    }
  }
}
