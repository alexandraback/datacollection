#include <cstdio>
#include <algorithm>
#include <vector>
#include <list>

using namespace std;

const int MAX_SIZE = 100;

int main(){
  freopen("B-large.in", "r", stdin);
  freopen("B-large.out", "w", stdout);
  int test_n;
  scanf("%d", &test_n);
  int pattern[MAX_SIZE][MAX_SIZE];
  for (int t = 0; t < test_n; ++t) {
    printf("Case #%d: ", t+1);
    int n, m;
    scanf("%d%d", &n, &m);
    for (int i = 0; i < n; ++i) {
      for (int j = 0; j < m; ++j) {
	scanf("%d", &pattern[i][j]);
      }
    }
    bool valid = true;
    for (int i = 0; i < n; ++i) {
      for (int j = 0; j < m; ++j) {
	// check row
	bool row_valid = true;
	for (int k = 0; k < m; ++k) {
	  if (pattern[i][k] > pattern[i][j]) {
	    row_valid = false;
	    break;
	  }
	}
	// check column
	bool col_valid = true;
	for (int k = 0; k < n; ++k) {
	  if (pattern[k][j] > pattern[i][j]) {
	    col_valid = false;
	    break;
	  }
	}
	if (!row_valid && !col_valid) {
	  valid = false;
	  break;
	}
      }
      if (!valid) {
	break;
      }
    }
    if (valid) {
      printf("YES\n");
    } else {
      printf("NO\n");
    }
	
  }
  return 0;
}
