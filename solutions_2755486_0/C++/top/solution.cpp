#include <cstdio>
#include <algorithm>

using namespace std;

int n,h[1000];
struct xxx {
  int d,w,e,s;
} wall[1000010];

inline void add (int d, int w, int e, int s) {
  wall[n].d = d;
  wall[n].w = w*2+500;
  wall[n].e = e*2+500;
  wall[n].s = s;
  n ++;
}

inline bool comp (xxx a, xxx b) {
  return a.d < b.d;
}

inline int solve () {
  int nn;
  n = 0;
  scanf ("%d", &nn);

  for (int i = 0;i < nn;i ++) {
    int d,_n,w,e,s,dd,dp,ds;
    scanf ("%d %d %d %d %d %d %d %d", &d, &_n, &w, &e, &s, &dd, &dp, &ds);

    for (int j = 0;j < _n;j ++) {
      add (d, w, e, s);
      d += dd;
      w += dp;
      e += dp;
      s += ds;
    }
  }

  sort (wall, wall+n, comp);

  for (int i = 0;i < 1000;i ++) {
    h[i] = 0;
  }

  int cnt = 0;
  for (int i = 0;i < n;) {
    int j;
    for (j = i+1;j < n and wall[j].d == wall[i].d;j ++) ;

    for (int k = i;k < j;k ++) {
      for (int z = wall[k].w;z <= wall[k].e;z ++) {
	if (h[z] < wall[k].s) {
	  cnt ++;
	  break;
	}
      }
    }

    for (int k = i;k < j;k ++) {
      for (int z = wall[k].w;z <= wall[k].e;z ++) {
	if (h[z] < wall[k].s) {
	  h[z] = wall[k].s;
	}
      }
    }

    i = j;
  }
  return cnt;
}

int main () {
  int test;
  scanf ("%d", &test);

  for (int Case = 1;Case <= test;Case ++) {
    printf ("Case #%d: %d\n", Case, solve ());
  }
}
