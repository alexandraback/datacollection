#include <iostream>
#include <vector>
#include <boost/math/common_factor.hpp>
#include <algorithm>

using namespace std;

typedef vector<vector<char> > room_t;

int main()
{
  int T;
  cin >> T;
  for (int cas = 1; cas <= T; cas++) {
    int H, W, D;
    cin >> H >> W >> D;
    room_t room;

    int col_X = 0, row_X = 0;
    for (int y = 0; y < H; y++) {
      room.push_back(vector<char>());
      for (int x = 0; x < W; x++) {
        char ch;
        cin >> ch;
        room.back().push_back(ch);
        if (ch == 'X') {
          col_X = x;
          row_X = y;
        }
      }
    }

    int res = 0;
    for (int dy = -D; dy <= D; dy++) {
      for (int dx = -D; dx <= D; dx++) {
        if (dx * dx + dy * dy > D * D) continue;
        if (boost::math::gcd(dx, dy) != 1) continue;

        int scale_x = abs(dy);
        int scale_y = abs(dx);
        if (scale_x == 0) scale_x = 1;
        if (scale_y == 0) scale_y = 1;
        int step_x = dx ? dx < 0 ? -1 : 1 : 0;
        int step_y = dy ? dy < 0 ? -1 : 1 : 0;

        if (scale_x % 2 || scale_y % 2) {
          scale_x *= 2;
          scale_y *= 2;
        }

        int cur_col = col_X;
        int cur_row = row_X;
        int cur_x = scale_x / 2;
        int cur_y = scale_y / 2;

        int max_step2;
        if (dx && dy) {
          max_step2 = (long long)D * D * scale_x * scale_x * scale_y * scale_y / (scale_x * scale_x + scale_y * scale_y);
        } else {
          max_step2 = dx ? D * D * scale_x * scale_x : D * D * scale_y * scale_y;
        }

        //cout << "=====" << endl;
        //cout << dx << "," << dy << "," << scale_x << "," << scale_y << "," << step_x << "," << step_y << "," << max_step2 << endl;
        for (int step = 0;;) {
          do {
            cur_x += step_x;
            cur_y += step_y;
            step++;
            if (step * step > max_step2) goto not_found;
            if (cur_x == scale_x / 2 && cur_y == scale_y / 2) {
              if (cur_col == col_X && cur_row == row_X) {
                goto found;
              }
            }
          } while (!(cur_x == 0 || cur_x == scale_x || cur_y == 0 || cur_y == scale_y));
          if (cur_x == scale_x) {
            cur_col++;
            cur_x = 0;
          }
          if (cur_y == scale_y) {
            cur_row++;
            cur_y = 0;
          }
          //cout << step << ": " << cur_col << "," << cur_row << "," << cur_x << "," << cur_y << endl;
          bool failed = false;
          if (cur_x == 0 && cur_y == 0) {
            bool ch0 = room[cur_row-1][cur_col-1] == '#';
            bool ch1 = room[cur_row-1][cur_col] == '#';
            bool ch2 = room[cur_row][cur_col-1] == '#';
            bool ch3 = room[cur_row][cur_col] == '#';
            int n = int(ch0) + int(ch1) + int(ch2) + int(ch3);
            bool from0 = step_x > 0 && step_y > 0;
            bool from1 = step_x < 0 && step_y > 0;
            bool from2 = step_x > 0 && step_y < 0;
            bool from3 = step_x < 0 && step_y < 0;
            switch (n) {
            case 0:
              break;
            case 1:
              if ((ch0 && from3) || (ch1 && from2) || (ch2 && from1) || (ch3 && from0))
                failed = true;
              break;
            case 2:
              if ((ch0 && ch1) || (ch2 && ch3)) step_y = -step_y;
              if ((ch0 && ch2) || (ch1 && ch3)) step_x = -step_x;
              break;
            case 3:
              step_x = -step_x;
              step_y = -step_y;
              break;
            }
          } else if (cur_x == 0) {
            bool ch2 = room[cur_row][cur_col-1] == '#';
            bool ch3 = room[cur_row][cur_col] == '#';
            if (ch2 || ch3) step_x = -step_x;
          } else {
            bool ch1 = room[cur_row-1][cur_col] == '#';
            bool ch3 = room[cur_row][cur_col] == '#';
            if (ch1 || ch3) step_y = -step_y;
          }
          if (failed) goto not_found;
          if (cur_x == 0 && step_x < 0) {
            cur_col--;
            cur_x = scale_x;
          }
          if (cur_y == 0 && step_y < 0) {
            cur_row--;
            cur_y = scale_y;
          }
        }
      found:
        //cout << "found" << endl;
        res++;
      not_found:;
      }
    }

    cout << "Case #" << cas << ": " << res << endl;
  }

  return 0;
}
