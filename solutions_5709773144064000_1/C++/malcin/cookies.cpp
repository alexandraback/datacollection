#include <cstdio>
#include <iostream>
#include <algorithm>
#include <set>
#include <map>
#include <stack>
#include <list>
#include <queue>
#include <deque>
#include <cctype>
#include <string>
#include <vector>
#include <sstream>
#include <iterator>
#include <numeric>
#include <cmath>
using namespace std;

typedef vector <int > VI;
typedef vector < VI > VVI;
typedef long long LL;
typedef vector < LL > VLL;
typedef vector < double > VD;
typedef vector < string > VS;
typedef pair<int,int> PII;
typedef vector <PII> VPII;
typedef istringstream ISS;

#define ALL(x) x.begin(),x.end()
#define REP(i,n) for (int i=0; i<(n); ++i)
#define FOR(var,pocz,koniec) for (int var=(pocz); var<=(koniec); ++var)
#define FORD(var,pocz,koniec) for (int var=(pocz); var>=(koniec); --var)
#define FOREACH(it, X) for(__typeof((X).begin()) it = (X).begin(); it != (X).end(); ++it)
#define PB push_back
#define PF push_front
#define MP(a,b) make_pair(a,b)
#define ST first
#define ND second
#define SIZE(x) (int)x.size()


int main(){
  int te;
  scanf("%d", &te);
  FOR(ii, 1, te){
    printf("Case #%d: ", ii);
    double c, f, x;
    scanf("%lf%lf%lf", &c, &f, &x);
    double speed = (double)2;
    double czas = (double)0;
    double besciak = x/speed;
    while(true){
      double nf = c/speed;
      double win = x/speed;
      if (czas + win > besciak)
        break;
      besciak = czas + win;
      czas += nf;
      speed += f;
    }
    printf("%.09lf\n", besciak);
  }
	return 0;
}
