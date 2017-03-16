#include <vector>
#include <list>
#include <map>
#include <set>
#include <queue>
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
#include <string>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <ctime>
#include <cstring>
 
using namespace std; 

int t, n, m, c, in[105][105], mx[105][2];
string res;

int main() {
	freopen("input.in", "r", stdin);
	freopen("output.out", "w", stdout);
  scanf ("%d", &t);
  for (int c = 0; c < t; c++) {
    scanf ("%d%d", &n, &m);
    res = "YES\n";
    memset(mx, 0, sizeof(mx));
    for (int i = 0; i < n; i++) for (int j = 0; j < m; j++) scanf ("%d", &in[i][j]);
    for (int i = 0; i < n; i++) {
      for (int j = 0; j < m; j++) {
        if (in[i][j] > mx[i][0]) mx[i][0] = in[i][j];
        if (in[i][j] > mx[j][1]) mx[j][1] = in[i][j];
      }
    }
    for (int i = 0; i < n; i++) for (int j = 0; j < m; j++) if (mx[i][0] > in[i][j] && mx[j][1] > in[i][j]) res = "NO\n";
    printf ("Case #%d: ", c + 1);
    cout << res;
  }
	return 0;
}