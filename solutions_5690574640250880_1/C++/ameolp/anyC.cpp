#include <vector>
#include <list>
#include <map>
#include <set>
#include <deque>
#include <stack>
#include <bitset>
#include <algorithm>
#include <functional>
#include <numeric>
#include <utility>
#include <sstream>
#include <iostream>
#include <iomanip>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <cctype>
#include <string>
#include <cstring>
#include <ctime>
using namespace std;
typedef long long ll;
const double PI = acos(-1.0);

int main()
{
  int t;
  cin >> t;
  
  for(int tcase = 1; tcase <= t; tcase++) {
    printf("Case #%d:\n", tcase);
    int r0, r, c0, c, m, a;
    cin >> r0 >> c0 >> m;
    r = r0; c = c0;
    a = r * c;
    if(r > c) swap(r, c);
    int s = (int)ceil(sqrt((double)m)), l = m - (s - 1) * (s - 1);
    bool impossible = false;
    if(r == 2 && (m % 2 && m != a - 1 || m == a - 2)) impossible = true;
    else if(r > 2 && (m == a - 7 || m == a - 5 || m == a - 3 || m == a - 2)) impossible = true;
    if(impossible) {
      cout << "Impossible" << endl;
      continue;
    }

    vector<string> board(51, string(51, '.'));
    board[r-1][c-1] = 'c';
    if(m == 0) {
      // do nothing
    } else if(m == a - 1) {
      for(int i = 0; i < r; i++) {
        for(int j = 0; j < c; j++) {
          if(i != r-1 || j != c-1) board[i][j] = '*';
        }
      }
    } else if(r == 1) {
      for(int i = 0; i < m; i++) board[0][i] = '*';
    } else if(r == 2) {
      for(int i = 0; i < m/2; i++) {
        board[0][i] = board[1][i] = '*';
      }
    } else {
      if(m <= (r - 2) * (c - 2)) {
        for(int i = 0; m && i < r - 2; i++) {
          for(int j = 0; m && j < c - 2; j++) {
            board[i][j] = '*';
            m--;
          }
        }
      } else {
        int q = m / r, d = m % r;
        vector<int> v(c, 0);
        for(int i = 0; i < q; i++) {
          v[i] = r;
        }
        if(d) v[q] = d;
        if(v[q] == r - 1) {
          if(q == c - 3) {
            v[q] -= 2;
            v[q+1]++; v[q+2]++;
          } else {
            v[q]--;
            v[q+1]++;
          }
        }
        if(v[c-2] != v[c-1]) {
          int sum = v[c-2] + v[c-1];
          if(sum % 2 == 0) {
            v[c-2] = v[c-1] = sum / 2;
          } else {
            if(v[c-3] == r) {
              v[c-3] -= 3;
              v[c-2] = v[c-1] = (sum + 3) / 2;
            } else {
              v[c-3]--;
              v[c-2] = v[c-1] = (sum + 1) / 2;
            }
          }
        }
        for(int i = 0; i < c; i++) {
          for(int j = 0; j < v[i]; j++) {
            board[j][i] = '*';
          }
        }
      }
    }

    if(r == r0) {
      for(int i = 0; i < r; i++) {
        for(int j = 0; j < c; j++) {
          printf("%c", board[i][j]);
        }
        printf("\n");
      }
    } else {
      for(int i = 0; i < c; i++) {
        for(int j = 0; j < r; j++) {
          printf("%c", board[j][i]);
        }
        printf("\n");
      }
    }
  }
  return 0;
}
// Google Code Jam