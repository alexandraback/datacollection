#include <cstdio>
#include <deque>
#include <map>
#include <algorithm>

using namespace std;

struct point {
  int x,y;
  point(int _x, int _y) {
    x = _x; y = _y;
  }
  bool operator < (const point b) const {
    bool out = true;
    if ( x == b.x ){
      out = y < b.y;
    } else out = x < b.x;
    return out;
  }
  bool operator != (const point b) const {
    return (x != b.x || y != b.y);
  }
};

deque<pair<point, int> > q;
char S[1111111];
map<point, bool> u;
map<point, point> pa;

int main(void)
{
  int T;
  freopen("input.txt", "rt", stdin);
  freopen("output.txt", "wt", stdout);
  scanf("%d",&T);
  for (int t = 0; t < T; t++) {
    long long res = 0;
    int x,y;
    scanf("%d%d",&x,&y);
    q.clear();
    u.clear();
    pa.clear();
    u[point(0,0)] = true;
    q.push_front(make_pair(point(0,0),1));
    while (!q.empty()) {
      point p = q.front().first, pp(0,0);
      int n = q.front().second;
      int dx[4] = {0,0,n,-n};
      int dy[4] = {n,-n,0,0};
      q.pop_front();
      res = max(res, (long long)n);
      if (p.x == x && p.y == y) break;
      for (int i = 0; i < 4; i++) {
        pp = p;
        pp.x += dx[i];
        pp.y += dy[i];
        if (u.find(pp) == u.end()) {
          u[pp] = true;
          pa.insert(pair<point,point>(pp, p));
          q.push_back(make_pair(pp, n+1));
        }
      }
    }
    int len = 0;
    point prev(x,y);
    for (point i = (*pa.find(prev)).second; prev != point(0,0); i = (*pa.find(i)).second) {
      if (prev.x == i.x) {
        if (prev.y > i.y) {
          S[len++] = 'N';
        } else {
          S[len++] = 'S';
        }
      } else {
        if (prev.x > i.x) {
          S[len++] = 'E';
        } else {
          S[len++] = 'W';
        }
      }
      //cout << prev.x << " " << prev.y << endl;
      prev = i;
    }
    S[len] = 0;
    reverse(S,S+len);
    printf("Case #%d: %s\n", t+1, S);
  }
  return 0;
}
