#include <cstdio>
#include <algorithm>
#include <queue>
#include <map>
using namespace std;

#define pii pair<int, int>
#define piii pair<pii, int>
#define __x first.first
#define __y first.second
#define __z second

#define mk make_pair
#define mk3(x, y, z) mk(mk(x, y), z)

const int LIM = 605;

int n;
queue<piii> q;
map<piii, piii> m;
map<pii, int> ss;

int dir[4][2] = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};

inline void bfs() {
  q.push(mk3(0, 0, 1));
  m[mk3(0, 0, 1)] = mk3(0, 0, -1);
  while(not q.empty()) {
    int x = q.front().__x;
    int y = q.front().__y;
    int z = q.front().__z;
    q.pop();
    if(abs(x) <= 100 and abs(y) <= 100 and not ss.count(mk(x, y))) {
      ss[mk(x, y)] = z;
      if(ss.size() == 201*201) {
	break;
      }
    }
    if(z > 500) continue;
    for(int dd = 0; dd < 4; dd++) {
      int xx = x + dir[dd][0]*z, yy = y + dir[dd][1]*z;
      if(abs(xx) <= LIM and abs(yy) <= LIM and not m.count(mk3(xx, yy, z+1))) {
	m[mk3(xx, yy, z+1)] = mk3(x, y, z);
	q.push(mk3(xx, yy, z+1));
      }
    }
  }
}

inline void print(int x, int y, int z) {
  int xx = m[mk3(x, y, z)].__x;
  int yy = m[mk3(x, y, z)].__y;
  int zz = m[mk3(x, y, z)].__z;
  if(zz == -1) return;
  print(xx, yy, zz);
  if(xx < x) {
    printf("E");
  } else if(xx > x) {
    printf("W");
  } else if(yy < y) {
    printf("N");
  } else {
    printf("S");
  }
}

int main() {
  bfs();
  int T;
  scanf("%d", &T);
  for(int __ = 1; __ <= T; __++) {
    int x, y;
    scanf("%d %d", &x, &y);
    printf("Case #%d: ", __);
    for(int z = 1; z <= 500; z++) {
      if(m.count(mk3(x, y, z))) {
	print(x, y, z);
	break;
      }
    }
    printf("\n");
  }
}
