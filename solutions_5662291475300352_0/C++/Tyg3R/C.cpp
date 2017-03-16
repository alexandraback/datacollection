#include <algorithm>
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iostream>
#include <sstream>
#include <map>
#include <set>
#include <queue>
#include <vector>

using namespace std;

#define FOR(prom, a, b) for(int prom = (a); prom < (b); prom++)
#define FORD(prom, a, b) for(int prom = (a); prom > (b); prom--)
#define FORDE(prom, a, b) for(int prom = (a); prom >= (b); prom--)

#define DRI(a) int a; scanf("%d ", &a);
#define DRII(a, b) int a, b; scanf("%d %d ", &a, &b);
#define DRIII(a, b, c) int a, b, c; scanf("%d %d %d ", &a, &b, &c);
#define DRIIII(a, b, c, d) int a, b, c, d; scanf("%d %d %d %d ", &a, &b, &c, &d);
#define RI(a) scanf("%d ", &a);
#define RII(a, b) scanf("%d %d ", &a, &b);
#define RIII(a, b, c) scanf("%d %d %d ", &a, &b, &c);
#define RIIII(a, b, c, d) scanf("%d %d %d %d ", &a, &b, &c, &d);

#define PB push_back
#define MP make_pair

#define ll long long
#define ull unsigned long long

#define MM(co, cim) memset((co), (cim), sizeof((co)))

#define DEB(x) cerr << ">>> " << #x << " : " << x << endl;

ll D[7];
ll M[7];

int main ()
{
  DRI(T);
  FOR(t,0,T) {
    DRI(N);
    int hi = 0;
    FOR(n,0,N) {
      DRIII(d,h,m);
      FOR(j,0,h) {
        D[hi] = d;
        M[hi] = m + j;
        hi++;
      }
    }
    int ff = 0;
    if((360LL-D[0])*M[1] < (360LL-D[1])*M[0]) ff = 0;
    else if((360LL-D[0])*M[1] <= (360LL-D[1])*M[0] && M[0] <= M[1]) ff = 0;
    else ff = 1;
    if((360LL-D[1-ff])*M[ff] < (720LL-D[ff])*M[1-ff]) printf("Case #%d: %d\n", t+1, 0);
    else printf("Case #%d: %d\n", t+1, 1);
  }
  return 0;
}
