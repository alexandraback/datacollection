#include <algorithm>
#include <climits>
#include <cmath>
#include <cstdio>
#include <cstring>
#include <ctime>
#include <deque>
#include <fstream>
#include <iomanip>
#include <iostream>
#include <limits>
#include <map>
#include <queue>
#include <set>
#include <sstream>
#include <stack>
#include <string>
#include <vector>
#define mp make_pair
#define st first
#define nd second
#define FOR(i,n) for(int i=0;i<(n);i++)
#define FORO(i,n) for(int i=1;i<=(n);i++)
#define FORS(i,a,n) for(int i=(a);i<(n);i++)
#define FORB(i,a,n) for(int i=(a);i>=(n);i--)
#define FORE(i,v) for(typeof((v).begin())i=(v).begin();i!=(v).end();i++)
#define INRANGE(a,b,c,d) ((a)>=0&&(b)>=0&&(a)<(c)&&(b)<(d))
#define pf printf
typedef long long ll;
using namespace std;

int x, y;
double prob;
set< pair<int, int> > fallen;

void xtry(int n, int sx, int sy, double prior) {
  //pf("%d %d %d %.6lf\n", n, sx, sy, prior);
  if (n == 0)
    return;
  while (true) {
    if (sy <= 0)
      break;
    if (sy > 1 && !fallen.count(mp(sx, sy-2))) {
      sy -= 2;
      continue;
    }
    bool canleft = !fallen.count(mp(sx-1, sy-1)),
	 canright = !fallen.count(mp(sx+1, sy-1));
    if (!canleft && !canright)
      break;
    if (canleft && canright) {
      xtry(n, sx-1, sy-1, prior/2);
      xtry(n, sx+1, sy-1, prior/2);
      return;
    }
    if (canleft)
      sx -= 1, sy -= 1;
    else if (canright)
      sx += 1, sy -= 1;
  }
  if (sx == x && sy == y)
    prob += prior;
  else {
    fallen.insert(mp(sx, sy));
    xtry(n-1, 0, 100, prior);
    fallen.erase(mp(sx, sy));
  }
}

void go() {
  int n;
  scanf("%d%d%d", &n, &x, &y);
  prob = 0;
  fallen.clear();
  xtry(n, 0, 100, 1);
  printf("%.6lf\n", prob);
}


int main() {
	//freopen(".in", "r", stdin); freopen(".out", "w", stdout);
	int t;
	scanf("%d", &t);
	FORO(i, t) {
	  printf("Case #%d: ", i);
	  go();
	}
}


