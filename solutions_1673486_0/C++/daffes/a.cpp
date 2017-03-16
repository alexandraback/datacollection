#include <iostream>
#include <sstream>
#include <string>
#include <vector>
#include <deque>
#include <queue>
#include <stack>
#include <map>
#include <algorithm>
#include <set>
#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <cmath>
#include <ctime>
#include <fstream>
#include <numeric>
#include <limits.h>
#include <iomanip>

using namespace std;

typedef vector<int> vi;
typedef vector<string> vs;
typedef pair<int,int> ii;
typedef long long ll;

#define ITE(v) typeof(v.begin())
#define FOR(i,n) for(int i = 0; i < n; i++)
#define FORIT(it,v) for(ITE(v) it = v.begin(); it != v.end(); it++)
#define ALL(v) v.begin(), v.end()
#define SZ(v) int(v.size())
#define pb push_back
#define SQR(a) ((a)*(a))

#define INF 0x3f3f3f3f
#define EPS (1e-9)

inline int cmp(double a, double b = 0.0) {
  if (fabs(a-b) <= EPS) return 0;
  if (a < b) return -1;
  return 1;
}

double p[100001];
int a,b;

int main(int argc, char **argv) {
  int ncases;
  cin >> ncases;
  FOR(kk, ncases) {
    printf("Case #%d: ", kk+1);
    cin >> a >> b;
    FOR(i,a) cin >> p[i];
    double pm = 1.;
    double res = 1e100;
    for (int j = 1; j <= a; j++) {
      pm = pm*p[j-1];
      double cost = (a-j) + b-j + 1;
      double cost1 = cost+b+1;
      double exp = pm*cost + (1-pm)*cost1;
      res = min(res, exp);
    }
    res = min(res, pm*(b-a+1) + (1-pm)*(b-a+1+b+1));
    res = min(res, (double)1+b+1);
    printf("%.7lf\n", res);
  }
  return 0;
}
