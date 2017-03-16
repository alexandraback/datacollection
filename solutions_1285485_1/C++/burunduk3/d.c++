#include <cassert>
#include <cstdio>
#include <algorithm>

int gcd( int a, int b ) {
  return b ? gcd(b, a % b) : a;
}
int sgn( int x ) {
  return x > 0 ? 1 : x < 0 ? -1 : 0;
}

using namespace std;

int main() {
  int tn;
  assert(scanf("%d", &tn) == 1);
  for (int tt = 1; tt <= tn; tt++) {
    int wy, wx, dist;
    assert(scanf("%d%d%d", &wy, &wx, &dist) == 3);
    char map[wy][wx];
    int sx = -1, sy = -1;
    for (int y = 0; y < wy; y++)
      for (int x = 0; x < wx; x++) {
        assert(scanf(" %c", &map[y][x]) == 1);
        if (map[y][x] == 'X')
          sx = x, sy = y;
      }
    assert(sx != -1 && sy != -1);
    int ans = 0;
    for (int dx = -dist; dx <= dist; dx++)
      for (int dy = -dist; dy <= dist; dy++) {
        if (gcd(abs(dx), abs(dy)) != 1 || (dx == 0 && dy == 0))
          continue;
        // fprintf(stderr, "D = (%d, %d)\n", dx, dy);
        // if (dx * dx + dy * dy > dist * dist || (dx == 0 && dy == 0))
        //   continue;
        // fprintf(stderr, "dd = %d\n", dd);
        // assert(dd);
        int dd = 1, d2 = dist * dist / (dx * dx + dy * dy);
        while (dd * dd <= 4 * d2)
          dd++;
        // fprintf(stderr, "steps: %d\n", dd - 1);
        if (--dd == 0)
          continue;
        int mx = max(abs(dy), 1);
        int my = max(abs(dx), 1);
        // fprintf(stderr, "m = (%d, %d)\n", mx, my);
        int cx = sx * mx * 2 + mx;
        int cy = sy * my * 2 + my;
        int vx = sgn(dx), vy = sgn(dy);
        // int step = 0;
        while (dd > 0) {
          // assert(++step < 100);
          // fprintf(stderr, "c,v = (%d, %d) (%d, %d)\n", cx, cy, vx, vy);
          int rx = vx > 0 ? mx - cx % mx : cx % mx;
          if (rx == 0) rx = mx;
          int ry = vy > 0 ? my - cy % my : cy % my;
          if (ry == 0) ry = my;
          // fprintf(stderr, "r = (%d, %d)\n", rx, ry);
          assert(rx && ry);
          int ta, tb; // T = ta / tb;
          if (rx * abs(vy) < ry * abs(vx))
            ta = rx, tb = abs(vx);
          else
            ta = ry, tb = abs(vy);
          // fprintf(stderr, "T = %d/%d\n", ta, tb);
          assert(ta != 0 && tb != 0);
          assert(vx * ta % tb == 0 && vy * ta % tb == 0);
          int nx = cx + vx * ta / tb;
          int ny = cy + vy * ta / tb;
          // fprintf(stderr, "n = (%d, %d)\n", nx, ny);
          assert(nx >= 2 * mx && nx <= 2 * mx * (wx - 1));
          assert(ny >= 2 * my && ny <= 2 * my * (wy - 1));
          if (nx == sx * mx * 2 + mx && ny == sy * my * 2 + my) {
            ans++;
            break;
          }
          int color[2][2];
          for (int px = -1; px <= 0; px++)
            for (int py = -1; py <= 0; py++) {
              int ox = (nx + px) / (2 * mx);
              int oy = (ny + py) / (2 * my);
              // fprintf(stderr, "  p = (%d, %d)  o = (%d, %d)  map=%c\n", px, py, ox, oy, map[oy][ox]);
              color[px + 1][py + 1] = map[oy][ox] == '#';
            }
          /*
          for (int py = 0; py < 2; py++) {
            fprintf(stderr, "color: ");
            for (int px = 0; px < 2; px++)
              fprintf(stderr, "%c", color[px][py] ? '#' : '.');
            fprintf(stderr, "\n");
          }
          */
          int fx = vx < 0, fy = vy < 0;
          /*
          for (int py = 0; py < 2; py++) {
            fprintf(stderr, "color(flipped): ");
            for (int px = 0; px < 2; px++)
              fprintf(stderr, "%c", color[px ^ fx][py ^ fy] ? '#' : '.');
            fprintf(stderr, "\n");
          }
          */
          assert(!color[fx][fy]); // =^_^=
          if (color[fx ^ 1][fy ^ 1]) {
            if (color[fx ^ 1][fy] && !color[fx][fy ^ 1])
              vx = -vx;
            if (!color[fx ^ 1][fy] && color[fx][fy ^ 1])
              vy = -vy;
            if (color[fx ^ 1][fy] && color[fx][fy ^ 1])
              vx = -vx, vy = -vy;
            if (!color[fx ^ 1][fy] && !color[fx][fy ^ 1])
              break;
          }
          cx = nx, cy = ny;
          if (abs(cx) % mx == 0 && abs(cy) % my == 0)
            dd--;
        }
      }
    printf("Case #%d: %d\n", tt, ans);
  }
  return 0;
}

