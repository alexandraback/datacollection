#include <iostream>
#include <vector>
#include <set>
#include <queue>
#include <algorithm>
#include <cassert>
using namespace std;

#define rep(i, n) for (int i = 0; i < int(n); ++i)
#define all(c) (c).begin(), (c).end()

vector< vector<bool> > transpose(const vector< vector<bool> > &V) {
  if (V.empty()) return V;
  const int R = V.size();
  const int C = V.at(0).size();

  vector< vector<bool> > V2(C, vector<bool>(R));
  
  rep(y, R) {
    rep(x, C) {
      V2.at(x).at(y) = V.at(y).at(x);
    }
  }

  return V2;
}

vector< vector<bool> > rec(const int R, const int C, const int M, const vector< vector<bool> > &V) {
  assert(M >= 0);
  assert(M <= R * C);
  assert(R <= (int)V.size());

  if (R > C) {
    return transpose( rec(C, R, M, transpose(V) ) );
  }
  
  assert(R <= C);

  vector< vector<bool> > V2(V);

  if (R <= M) {
    rep(i, R) {
      V2.at(i).at(C-1) = true;
    }
    if (C == 1) {
      assert(R == 1);
      assert(M == 1);
      return rec(0, 0, 0, V2);
    }
    else {
      return rec(R, C - 1, M - R, V2);
    }
  }

  assert(M < R);

  if (R == 0) {
    assert(C == 0);
    assert(M == 0);
    // completely filled
    return vector< vector<bool> >();  // not possible
  }
  else if (R == 1) {
    assert(M == 0);

    if (V.size() == 1 || V.at(0).size() == 1) {
      // long thin row, empty cells
      return V;  // possible      
    }
    else {
      return vector< vector<bool> >();  // not possible
    }
  }
  else if (R == 2) {
    if (M == 0) {
      return V;  // possible      
    }
    else {
      assert(M == 1);
      return vector< vector<bool> >();  // not possible      
    }
  }
  else if (R == 3) {
    if (C == 3) {
      if (M == 0) {
	return V;  // possible            
      }
      else if (M == 1) {
	V2.at(R-1).at(C-1) = true;
	return V2; // possible            
      }
      else {
	assert(M == 2);
	// not possible ??? 7 empty cells, always impossible, right?
	return vector< vector<bool> >();  // not possible            
      }
    }
    else {
      assert(C >= 4);
      assert(M <= 2);

      rep(i, M) {
	V2.at(R - 1).at(C - 1 - i) = true;
      }
      return V2; // possible            
    }
  }
  else {
    assert(R >= 4);
    assert(C >= 4);

    if (R == M + 1) {
      rep(i, M - 1) {
	V2.at(R - 1).at(C - 1 - i) = true;
      }
      V2.at(R - 2).at(C - 1) = true;
      return V2; // possible            
    }
    else {
      assert(R - M >= 2);
      rep(i, M) {
	V2.at(R - 1).at(C - 1 - i) = true;
      }
      return V2; // possible            
    }
  }

  assert(false);
}


void solve(const int testcaseIndex) {
  int R, C, M;

  cin >> R >> C >> M;

  const vector< vector<bool> > emptyBoard(R, vector<bool>(C, false));

  const vector< vector<bool> > sol = rec(R, C, M, emptyBoard);

  if (sol.empty()) {
    cout << "Impossible" << endl;
  }
  else {
    rep(y, R) {
      rep(x, C) {
	if (y == 0 && x == 0) {
	  cout << 'c';
	}
	else {
	  cout << (sol[y][x] ? '*': '.');
	}
      }
      cout << endl;
    }    
  }
}


int main() {

  int T;
  cin >> T;

  rep(i, T) {
    cout << "Case #" << i + 1 << ":" << endl;
    solve(i);
  }

  return 0;
}
