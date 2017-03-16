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

const int MAX_N = 1111;
ld a[MAX_N], b[MAX_N];
int N, ai[MAX_N], bi[MAX_N];

int main() {
  ios_base::sync_with_stdio(0);

  int T; cin >> T;
  for(int tests = 1; tests <= T; ++tests) {
    memset(a, 0, sizeof(a)); memset(b, 0, sizeof(b));
    memset(ai, 0, sizeof(ai)); memset(bi, 0, sizeof(bi));
    cin >> N;
    for(int i = 0; i < N; ++i) {cin >> a[i]; ai[i] = ((a[i] * 1000000)+1)/10;}
    for(int i = 0; i < N; ++i) {cin >> b[i]; bi[i] = ((b[i] * 1000000)+1)/10;}
    sort(ai, ai+N);
    sort(bi, bi+N);

    int f = 0, s = 0, ap = 0, bp = 0;
    while(ap < N && bp < N) {
      if(ai[ap] > bi[bp]) {
	f++;
	ap++; bp++;
      } else {
	ap++;
      }
    }

    ap = 0, bp = 0;
    while(ap < N && bp < N) {
      if(bi[bp] > ai[ap]) {
	s++;
	ap++, bp++;
      } else {
	bp++;
      }
    }

    cout << "Case #" << tests << ": ";
    cout << f << ' ' << N-s << '\n';
  }

  return 0;
}
