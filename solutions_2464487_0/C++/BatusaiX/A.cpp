#include <algorithm>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>
#include <queue>
#include <stack>
#include <set>
#include <map>
#include <list>
#include <bitset>
#include <deque>
#include <numeric>
#include <iterator>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cctype>
#include <cmath>
#include <climits>
#include <sys/time.h>

using namespace std;

#define DEBUG(x) cout << #x << ": " << x << endl
#define sz(a) int((a).size())
#define all(x) (x).begin(),(x).end()
#define foreach(it,c) for(typeof((c).begin()) it=(c).begin();it!=(c).end();++it)
template <typename T> string tostr(const T& t) { ostringstream os; os<<t; return os.str(); }

typedef long long llong;


#define _USE_MATH_DEFINES

double area(double r) {
   //  r^2 * π
   return r * r * M_PI;
}

// One millilitre of paint is required to cover area π cm^2
int main(int argc, char *argv[]) { 
   int TC; 
   double r, paint;
   scanf("%d",&TC);
   for(int tc = 1; tc <= TC; ++tc) {
      scanf("%lf%lf",&r,&paint);
      int res = 0;
      double p = 0.0;
      //fprintf(stderr, "paint: %lf\n",paint);
      for(int rad = r + 1; true; rad += 2) {
         res++;  
         p += (area(rad) - area(rad-1)) - p;
         //fprintf(stderr, "rad=%d p=%lf\n",rad,p);
         if(p > paint) break; 
         
         
      }
      printf("Case #%d: %d\n",tc,res);
      //fprintf(stderr, "\n");
   }
   return 0;
}
