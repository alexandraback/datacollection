#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <string>
#include <cstring>
#include <cmath>
#include <algorithm>
#include <set>
#include <map>
#include <vector>

using namespace std;

struct tCell {
  int x;
  int y;
  int adjacent_unopens;

  tCell(int my_x, int my_y, int my_adjacent_unopens) : 
    x(my_x), y(my_y), adjacent_unopens(my_adjacent_unopens) {
  }

  bool operator<(const tCell& rhs) const {
    return adjacent_unopens < rhs.adjacent_unopens;
  }
};

int main() {
  int n_tests;
  cin >> n_tests;
  for (int i_test = 0; i_test < n_tests; i_test++) {
    int r, c, m;
    cin >> r >> c >> m;

    bool open[r][c];
    int start_x, start_y;
    bool found_answer = false;
    vector<tCell> edges;

    // Check start points for a quarter of the grid
    for (start_y = 0; start_y < (r + 1) / 2; start_y++) {
      for (start_x = 0; start_x < (c + 1) / 2; start_x++) {
        // Reset variables
        int remaining_opens = r * c - m - 1;
        //cout << "Remaining opens: " << remaining_opens << endl;

        for (int y = 0; y < r; y++) { 
          for (int x = 0; x < c; x++) {
            if (start_y == y && x == start_x) {
              open[y][x] = true;
            } else {
              open[y][x] = false;
            }
          }
        }

        if (remaining_opens == 0) {
          found_answer = true;
          break;
        }

        edges.clear();
        tCell start_cell(start_x, start_y, 0);
        edges.push_back(start_cell);

        while (true) {
          // Compute adjacent_unopens
          vector<tCell>::iterator it = edges.begin();
          for (; it != edges.end(); it++) {

            int my_x = it->x;
            int my_y = it->y;

            int adjacent_unopens = 0;
            for (int y = my_y - 1; y <= my_y + 1; y++) {
              for (int x = my_x - 1; x <= my_x + 1; x++) {
                if (y < 0 || y >= r || x < 0 || x >= c) { continue; }
                if (!open[y][x]) { adjacent_unopens++; }
              }
            }
            it->adjacent_unopens = adjacent_unopens;

            if (remaining_opens == adjacent_unopens) { break; }
          }

          // If it is not end, then we have a finisher
          if (it != edges.end()) {
            int my_x = it->x;
            int my_y = it->y;

            for (int y = my_y - 1; y <= my_y + 1; y++) {
              for (int x = my_x - 1; x <= my_x + 1; x++) {
                if (y < 0 || y >= r || x < 0 || x >= c) { continue; }
                open[y][x] = true;
              }
            }

            found_answer = true;
            break;
          }

          // If it is not end, then we have a finisher
          if (it != edges.end()) {
            int my_x = it->x;
            int my_y = it->y;

            for (int y = my_y - 1; y <= my_y + 1; y++) {
              for (int x = my_x - 1; x <= my_x + 1; x++) {
                if (y < 0 || y >= r || x < 0 || x >= c) { continue; }
                open[y][x] = true;
              }
            }

            found_answer = true;
            break;
          }

          sort(edges.begin(), edges.end());
          while (edges.begin() != edges.end() && 
                 edges.begin()->adjacent_unopens == 0) {
            edges.erase(edges.begin());
          }

          // No possible solutions
          if (edges.begin() == edges.end()) { break; }

          // Add the first one to the list
          it = edges.begin();
          remaining_opens -= it->adjacent_unopens;
          
          // No possible solutions
          if (remaining_opens < 0) { break; }

          int my_x = it->x;
          int my_y = it->y;
          //printf("Adding: %d %d\n", my_x, my_y);

          for (int y = my_y - 1; y <= my_y + 1; y++) {
            for (int x = my_x - 1; x <= my_x + 1; x++) {
              if (y < 0 || y >= r || x < 0 || x >= c) { continue; }
              open[y][x] = true;
              tCell cell(x, y, 0);
              edges.push_back(cell);
            }
          }
          edges.erase(edges.begin());
        }

        if (found_answer) { break; }
      }
      if (found_answer) { break; }
    }

    printf("Case #%d:\n", i_test+1);
    if (found_answer) {
      for (int y = 0; y < r; y++) {
        for (int x = 0; x < c; x++) {
          if (open[y][x]) {
            if (x == start_x && y == start_y) {
              cout << 'c';
            } else {
              cout << '.';
            }
          } else {
            cout << '*';
          }
        }
        cout << endl;
      }
    } else {
      cout << "Impossible" << endl;
    }
  }
}
