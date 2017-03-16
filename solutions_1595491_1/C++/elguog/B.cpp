#include <vector>
#include <list>
#include <map>
#include <set>
#include <deque>
#include <stack>
#include <bitset>
#include <algorithm>
#include <functional>
#include <numeric>
#include <utility>
#include <sstream>
#include <iostream>
#include <iomanip>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <ctime>
#include <cstring>
#include <ctype.h>
#include <assert.h>

using namespace std;

typedef long long i64;
typedef vector<int> VI;
typedef vector<string> VS;
#define REP(i,n) for(int _n=n, i=0;i<_n;i++)
#define FOR(i,a,b) for(int i=(a),_b=(b);i<=_b;i++)
#define ALL(x)   (x).begin(),(x).end()
#define SORT(x) sort(ALL(x))
#define PB push_back

int N, S, p, x;

int main() {
  int T;
  cin>>T;
  FOR(cs, 1, T) {
    cin>>N>>S>>p;
    int res = 0;
    REP(i, N) {
      cin>>x;
      if (x >= 3*p-2) res++;
      else if (x >= 3*p-4 && 2 <= x && x <= 28) {
	if(S) {
	  S--;
	  res++;
	}
      }
    }
    cout<<"Case #"<<cs<<": "<<res<<endl;
  }
  return 0;
}
