#include <iostream>
#include <sstream>
#include <string>
#include <vector>
#include <stack>
#include <queue>
#include <set>
#include <map>
#include <algorithm>
#include <iterator>
#include <utility>
#include <cmath>
#include <climits>
#include <stdio.h>
#include <string.h>

using namespace std;

typedef vector<int> vi;
typedef vector<string> vs;
typedef long long ll;
typedef pair<int, int> pii;


std::map<pair<int,int>, std::vector< std::vector<char> >> memo;

bool solve_helper(int r, int c, int m, std::vector< std::vector<char> > &vv) {
  switch (m) {
  case 1:
    if (r == 1) {
      vv[0][0] = 'c';
      vv[0][c-1] = '*';
      return true;
    } else if (c == 1) {
      vv[0][0] = 'c';
      vv[r-1][0] = '*';
      return true;
    } else if (r == 3 && c == 3) {
      vv[0][0] = 'c';
      vv[r-1][c-1] = '*';
      return true;
    } else {
      return false;
    }
  case 2:
    if (r == 1 && c == 3) {
      vv[0][0] = 'c';
      vv[0][1] = '*';
      vv[0][2] = '*';
      return true;
    } else if (r == 3 && c == 1) {
      vv[0][0] = 'c';
      vv[1][0] = '*';
      vv[2][0] = '*';
      return true;
    } else if (r == 2 && c == 3) {
      vv[0][0] = 'c';

      vv[0][2] = '*';
      vv[1][2] = '*';
      return true;
    } else if (r == 3 && c == 2) {
      vv[0][0] = 'c';

      vv[2][0] = '*';
      vv[2][1] = '*';
      return true;
    } else 
      return false;

  case 3:
    if (r == 2 && c == 2) {
      vv[0][0] = 'c';
      vv[0][1] = '*';
      vv[1][0] = '*';
      vv[1][1] = '*';
      return true;
    } else if (r == 3 && c == 3) {
      vv[0][0] = 'c';
      vv[2][0] = '*';
      vv[2][1] = '*';
      vv[2][2] = '*';
      return true;
    } else
      return false; // impossible

  case 4:
    return false;

  case 5:
    if (r == 2 && c == 3) {
      vv[0][0] = 'c';
      vv[0][1] = '*';
      vv[0][2] = '*';
      vv[1][0] = '*';
      vv[1][1] = '*';
      vv[1][2] = '*';
      return true;
    } else if (r == 3 && c == 2) {
      vv[0][0] = 'c';
      vv[1][0] = '*';
      vv[2][0] = '*';
      vv[0][1] = '*';
      vv[1][1] = '*';
      vv[2][1] = '*';
      return true;
    } else if (r == 3 && c == 3) {
      vv[0][0] = 'c';

      vv[0][2] = '*';
      vv[1][2] = '*';
      vv[2][0] = '*';
      vv[2][1] = '*';
      vv[2][2] = '*';
      return true;
    } else {
      cerr << "should not reach here : " << "r = " << r << ", c = " << c << endl;
    }
  case 6:
    return false; // must be 3x3

  case 7:
    return false; // impossible

  case 8:
	if (r == 3 && c == 3) {
	  vv[0][0] = 'c';
	  vv[0][1] = '*';
	  vv[0][2] = '*';
	  vv[1][0] = '*';
	  vv[1][1] = '*';
	  vv[1][2] = '*';
	  vv[2][0] = '*';
	  vv[2][1] = '*';
	  vv[2][2] = '*';
	  return true;
	} else
	  return false; // impossible
  case 9:
	return false;  // impossible
  }

  cerr << "should not reach here : " << "r = " << r << ", c = " << c << endl;
  return false;  // never reach here
}


void solve() {
  int i, j;
  
  int T;
  cin >> T;
  for (int t = 0; t < T; t++) {
    int R, C, M;
    cin >> R >> C >> M;
    
    std::vector< std::vector<char> > vv(R, std::vector<char>(C));
    for (int _vi = 0; _vi < R; _vi++) {
      for (int _vj = 0; _vj < C; _vj++) {
	vv[_vi][_vj] = '.';
      }
    }
    
    int solvable = true;

    int r = R;
    int c = C;
    int m = M;

    if (M == 0) {
      vv[0][0] = 'c';
    }

    while (true) {
      if (m == 0) break;
      if (c <= 3 && r <= 3) break;

      bool row_is_bigger = r >= c;
      if (row_is_bigger) {
	if (m > c) {
	  for (i = 0; i < c; i++) {
	    vv[r-1][i] = '*';
	  }
	  m -= c;
	  r--;
	} else if (m == 1 && c == 2) {
	  solvable = false; break;
	} else if (m == c-1) {
	  for (i = 0; i < m-1; i++) { 
	    vv[r-1][c-1-i] = '*';
	  }
	  vv[r-2][c-1] = '*';
	  vv[0][0] = 'c';
	  m = 0; break;
	} else {
	  for (i = 0; i < m; i++) { 
	    vv[r-1][c-1-i] = '*';
	  }
	  vv[0][0] = 'c';
	  m = 0; break;
	}
      } else {
	if (m > r) {
	  for (i = 0; i < r; i++) {
	    vv[i][c-1] = '*';
	  }
	  m -= r;
	  c--;
	} else if (m == 1 && r == 2) {
	  solvable = false; break;
	} else if (m == r-1) {
	  for (i = 0; i < m-1; i++) { 
	    vv[r-1-i][c-1] = '*';
	  }
	  vv[r-1][c-2] = '*';
	  vv[0][0] = 'c';
	  m = 0; break;
	} else {
	  for (i = 0; i < m; i++) { 
	    vv[r-1-i][c-1] = '*';
	  }
	  vv[0][0] = 'c';
	  m = 0; break;
	}
      }
    }

    if (m != 0 && solvable) {
      solvable = solve_helper(r, c, m, vv);
    }
    
    std::cout << "Case #" << (t+1) << ": " << std::endl;
    if (solvable) {
      for (int _vi = 0; _vi < R; _vi++) {
      	for (int _vj = 0; _vj < C; _vj++) {
      	  cout << vv[_vi][_vj];
      	}
      	cout << endl;
      }
    } else {
      std::cout << "Impossible" << std::endl;
    }
  }
}

int main(int argc, char *argv[])
{
  solve();
  return 0;
}
