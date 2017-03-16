#include <iostream>
#include <cstdio>
#include <queue>
#include <cstdlib>
#include <cstring>
#include <cmath>
#include <algorithm>
#include <string>
#include <climits>
#include <vector>
#include <deque>
#include <set>
#include <map>
#include <list>
#include <stack>
#include <cctype>
#include <bitset>
#include <ctime>
#include <cassert>
#include <fstream>
#include <complex>
#include <iomanip>
using namespace std;

#define MIN(x,y) (((x)<(y))?(x):(y))
#define MAX(x,y) (((x)>(y))?(x):(y))
#define ABS(x) (((x)<0)?(-(x)):(x))
#define ff first
#define ss second
#define ei else if
#define mp make_pair
#define pb push_back
typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;
typedef pair<int,int> pii;
typedef pair<ull, ull> puu;
typedef pair<int,pair<int,int> > piii;
const ld EPS = 1e-7;
const ld PI  = 3.141592653589793;

ull gcd(ull a, ull b) {
  if(!b) return a;
  return gcd(b, a%b);
}

bool check(ull A, ull B) {
  return A >= B;
}

int main() {
  ios_base::sync_with_stdio(0);
  
  int T; cin >> T;
  for(int t = 1; t <= T; ++t) {
    ull A, B; char c;
    cin >> A >> c >> B;
 
    ull g = gcd(A, B);
    A /= g, B /= g;
    if(B & (B - 1)) {
      cout << "Case #" << t << ": impossible\n";;
      continue;
    }
    
    ull res = 0;
    for(;;) {
      if(B & (B - 1)) {
	cout << "Case #" << t << ": impossible\n";;
	continue;
      }

      bool r = check(A, B);
      if(r) {
	cout << "Case #" << t << ": " << res << '\n';
	break;
      }
    
      ull g = gcd(A, B);
      A /= g, B /= g;
  
      A *= 2;
      res++;
    }
  }

  return 0;
}
