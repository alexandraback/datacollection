#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <map>
#include <string>
#include <string.h>
#include <set>
#include <stdio.h>
#include <assert.h>
#include <sstream>
using namespace std;

int want[102][102];

int main(int argc, char* argv[]) {
  int nocases;
  cin >> nocases;
  getchar();
  for (int rr = 1; rr <= nocases; ++rr) {
    int n, m;
    cin >> n >> m;
    int maxrow[n], maxcol[m];
    for (int i = 0; i < n; ++i)
      maxrow[i] = -1;
    for (int i = 0; i < m; ++i)
      maxcol[i] = -1;
    for (int i = 0; i < n; ++i)
      for (int j = 0; j < m; ++j) {
	cin >> want[i][j];
	maxrow[i] = max(maxrow[i], want[i][j]);
	maxcol[j] = max(maxcol[j], want[i][j]);
      }
    char bad = 0;
    for (int i = 0; i < n; ++i)
      for (int j = 0; j < m; ++j)
	if (want[i][j] < maxrow[i] && want[i][j] < maxcol[j])
	  bad = 1;
    printf("Case #%d: %s\n", rr, bad ? "NO" : "YES");
  }
  return 0;
}
