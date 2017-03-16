#pragma comment (linker, "/STACK:16777216")
#include <vector>
#include <string>
#include <iostream>
#include <algorithm>
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <fstream>
#include <set>
#include <stack>
#include <queue>

using namespace std;

#define FOR(i,a,b) for(int (i) = (a); (i) <= (b); ++(i))
#define rep(i,n) for (int (i) = 0; (i) < (n); ++(i))
#define repd(i,n) for (int (i) = n; (i)--; )
#define fe(i,a) for (int (i) = 0; (i) < int((a).size()); ++(i))
#define mem(a, val) memset((a),val,sizeof(a))
#define inf 1000000000
#define pb push_back
#define ppb pop_back
#define all(c) (c).begin(), (c).end()
#define pi acos(-1.0)
#define sqr(a) ((a)*(a))
#define mp(a,b) make_pair((a), (b))
#define xx first
#define yy second
#define MOD 1000000007LL

typedef vector<int> vint;
typedef vector< pair<int, int> > vpii;
typedef long long LL;
typedef pair<int, int> pii;

struct cell {
  int C, F, ttw, x, y; // time to wait
} map[105][105];

pii go[] = {mp(-1, 0), mp(1, 0), mp(0, -1), mp(0, 1)};

int intersect(int x1, int x2, int x3, int x4) {
  if (x1 > x2) swap(x1, x2);
  if (x3 > x4) swap(x3, x4);
  if (x1 > x3) {
    swap(x1, x3);
    swap(x2, x4);
  }
  if (x2 <= x3) return 0;
  if (x2 <= x4) return x2 - x3;
  return x4 - x3;
}

int main() {
//  freopen("B-small-attempt0.in", "r", stdin);
//  freopen("input.txt", "r", stdin);
//  freopen("output.txt", "w", stdout);

  int T, n, m, h;
  scanf("%d", &T);
  rep(test, T) {
    scanf("%d%d%d", &h, &n, &m);
    rep(i, n)
      rep(j, m)
        scanf("%d", &map[i][j].C);
    rep(i, n)
      rep(j, m) {
        scanf("%d", &map[i][j].F);
        map[i][j].ttw = inf;
        map[i][j].x = i;
        map[i][j].y = j;
      }

    priority_queue<pii, vpii, greater<pii> > q;
    q.push(mp(0, 0));
    map[0][0].ttw = 0;
    pii cur, next;
    while (!q.empty()) {
      cur = q.top();
      q.pop();
      cell *from = &map[cur.xx][cur.yy];

      int cur_h = h - map[cur.xx][cur.yy].ttw;
      rep(i, 4) {
        next = mp(cur.xx + go[i].xx, cur.yy + go[i].yy);
        if (0 <= next.xx && next.xx < n &&
            0 <= next.yy && next.yy < m) {
              cell *to = &map[next.xx][next.yy];
              if (intersect(from->F, from->C, to->F, to->C) < 50) continue; // впринципі неможливо піти
              if (intersect(max(from->F, cur_h), from->C, max(to->F, cur_h), to->C) >= 50) {// зараз можливо піти
                int left = cur_h - from->F;
                int need;
                if (left >= 20)
                  need = 10;
                else
                  need = 100;

                if (from->ttw == 0) {
                  if (to->ttw > 0) q.push(mp(to->x, to->y));
                  to->ttw = 0;
                } else {
                  if (to->ttw > from->ttw + need) q.push(mp(to->x, to->y));
                  to->ttw = min(to->ttw, from->ttw + need);
                }

                continue;
              }

              int add_time = 0;
              while (intersect(max(from->F, cur_h - add_time), from->C, max(to->F, cur_h - add_time), to->C) < 50) {
                ++add_time;
                if (add_time > 11000) printf("%d\n", add_time);
              }

              int left = cur_h - add_time - from->F;
              int need;
              if (left >= 20)
                need = add_time + 10;
              else
                need = add_time + 100;

              if (to->ttw > from->ttw + need) q.push(mp(to->x, to->y));
              to->ttw = min(to->ttw, from->ttw + need);
            }
      }
    }

    printf("Case #%d: %d.%d\n", test + 1, map[n - 1][m - 1].ttw / 10, map[n - 1][m - 1].ttw % 10);
  }

  return 0;
}
