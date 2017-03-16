#include <iostream>
#include <cstring>
#include <vector>
#include <cassert>
using namespace std;

const int MINE = 1;
const int EMPTY = 0;

#define fill(x, v) memset(x, v, sizeof x)

const int MX = 52;
int R, C, M;
int dp[MX][MX][MX*MX];
int bp[MX][MX][MX*MX];
bool solve(int row, int previous, int left) {
  if (left == 0) return 1;
  if (left < 0 || row == R) return 0;
  int &res = dp[row][previous][left];
  if (~res) return res;
  res = 0;
  for (int x=2; x <= previous; x++) {
    if (solve(row+1, x, left - x)) {
      bp[row][previous][left] = x;
      res = 1;
      return res;
    }
  }
  return res;
}

char sol[MX][MX];
char sol2[MX][MX];
int main() {
    int T; cin>>T;
    for (int t=1; t <= T; t++) {
      cout << "Case #" << t << ": " << endl;
      cin>>R>>C>>M;
      bool rotated = false;
      if (R > C) {
        rotated = true;
        swap(R, C);
      }
      if (M == R * C - 1) {
        for (int x=0; x < R; x++, cout<<endl) {
          for (int y=0; y < C; y++) {
            if (x == 0 && y==0) {
              cout << "c";
            } else {
              cout << "*";
            }
          }
        }
      } else if (R == 1) {
        if (M > C-2) {
          cout << "Impossible!" << endl; // R << " " << C << " " << M << endl;
        } else {
          for (int i=0; i < M; i++)
            cout << "*" << endl;
          for (int i=M; i < C - 1; i++)
            cout << "." << endl;
          cout << "c" << endl;
        }
      } else {
        int totalLeft = R * C - M;
        fill(dp, -1); fill(bp, -1);
        bool found = false;
        for (int first=2; first <= C; first++) {
          if (solve(2, first, totalLeft - 2 * first)) {
            fill(sol, 0);
            vector<int> rows;
            int left = R * C - M;
            // cout <<"left: " << left << endl;
            // cout << "r: " << first << endl; 
            left -= first; rows.push_back(first);
            // cout << "r: " << first << endl; 
            left -= first; rows.push_back(first);
            int row = 2, previous = first;
            
            while (left > 0) {
              int x = bp[row][previous][left];
              assert(x != -1);
              // cout << "r: " << x << endl; 
              previous = x;
              row++;
              left -= x;
              rows.push_back(x);
            }
            for (int x=0; x < R; x++)
            for (int y=0; y < C; y++)
              sol[x][y] = '*';
            for (int x=0; x < (int)rows.size(); x++) {
              for (int y=0; y < rows[x]; y++) {
                sol[x][y] = '.';
              }
            }
            sol[0][0] = 'c';
            if (rotated) {
              memcpy(sol2, sol, sizeof sol);
              fill(sol, 0);
              for (int x=0; x < R; x++)
              for (int y=0; y < C; y++)
                sol[y][x] = sol2[x][y];
              swap(R, C);
            }
            for (int x=0; x < R; x++)
              cout << sol[x] << endl;
            found = true;
            break;
          }
        }
        if (!found) {
          cout << "Impossible!" << endl; // R << " " << C << " " << M << endl;
        }
      }
      
      
    }
}
