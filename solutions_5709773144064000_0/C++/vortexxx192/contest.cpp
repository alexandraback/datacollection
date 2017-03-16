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
typedef pair<int,pair<int,int> > piii;
const ld EPS = 1e-7;
const ld PI  = 3.141592653589793;

int main() {
  ios_base::sync_with_stdio(0);

  int T; cin >> T;
  for(int tests = 1; tests <= T; ++tests) {
    ld C, F, X; cin >> C >> F >> X;
    ld timer = 0;

    ld V = 2;
    for(;;) {
      ld end = X/V;
      ld build = C/V + X/(F+V);
      if(end <= build) {
	timer += end;
	break;
      } else {
	timer += C/V;
	V += F;
      }
    }
    
    cout << "Case #" << tests << ": ";
    cout << fixed << setprecision(8) << timer << '\n';
  }

  return 0;
}
