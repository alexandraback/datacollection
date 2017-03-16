#include <iostream>
#include <vector>
#include <set>
#include <queue>
#include <algorithm>
using namespace std;

#define rep(i, n) for (int i = 0; i < int(n); ++i)
#define all(c) (c).begin(), (c).end()

void solve(const int testcaseIndex) {

  // Alla platser närliggande en mina öppnas inte
  // Men de platserna vara i kontakt med 0-rutor

  int R, C, M;

  cin >> R >> C >> M;

  // cout << "R, C, M: " << R << ", " << C << ", " << M << endl;

  bool isMine[8][8];
  bool isZero[8][8];    

  const int numberOfCells = R * C;
  const int numberOfCases = 1 << numberOfCells;
  // cout << "number... " << numberOfCells << ", " << numberOfCases << endl;

  rep(i, numberOfCases) {
    //    cout << i << ", " << __builtin_popcount(i) << endl;

    if (__builtin_popcount(i) != M) {
      continue;
    }

    int tmp = i;
    rep(y, R) {
      rep(x, C) {
	isMine[y][x] = (tmp & 1) == 1;
	tmp >>= 1;
      }
    }

    rep(y, R) {
      rep(x, C) {
	isZero[y][x] = true;
      }
    }
    
    // mark all non-zero cells:
    rep(y, R) {
      rep(x, C) {
	if (isMine[y][x]) {
	  for (int dy = -1; dy <= 1; ++dy) {
	    for (int dx = -1; dx <= 1; ++dx) {
	      const int y2 = y + dy;
	      const int x2 = x + dx;

	      if (0 <= y2 && y2 < R && 0 <= x2 && x2 < C) {
		isZero[y2][x2] = false;
	      }
	    }
	  }
	}
      }
    }

    typedef pair<int, int> pii;
    vector<pii> V;

    rep(y, R) {
      rep(x, C) {
	if (isZero[y][x]) {
	  V.push_back( pii(x, y) );
	}
      }
    }


    pii startCell;
    bool isPossible = false;
    if (V.empty()) {
      
      // click on a non-zero cell:
      if (numberOfCells == M + 1) {
	isPossible = true;

	rep(y, R) {
	  rep(x, C) {
	    if (!isMine[y][x]) {
	      startCell = pii(x, y);
	    }
	  }
	}
      }

    }
    else {
      startCell = V.front();

      queue<pii> Q;
      Q.push( startCell );
      
      set<pii> setRevealed;
      setRevealed.insert( startCell );
      
      while (!Q.empty()) {
	const int x = Q.front().first;
	const int y = Q.front().second;
	Q.pop();
	
	for (int dy = -1; dy <= 1; ++dy) {
	  for (int dx = -1; dx <= 1; ++dx) {
	    const int y2 = y + dy;
	    const int x2 = x + dx;
	    
	    if (0 <= y2 && y2 < R && 0 <= x2 && x2 < C) {
	      const pii p(x2, y2);
	      
	      if (setRevealed.count(p) == 0) {
		setRevealed.insert(p);
		if (isZero[y2][x2]) {
		  Q.push(p);
		}
	      }
	      
	    }
	  }
	}
	
      }
      
      // cout << "revealed size: " << setRevealed.size() << endl;

      if ((int)setRevealed.size() + M == numberOfCells) {
	isPossible = true;
      }
    }

    if (isPossible) {
      // Found solution

      rep(y, R) {
	rep(x, C) {
	  if (pii(x, y) == startCell) {
	    cout << 'c';
	  }
	  else if (isMine[y][x]) {
	    cout << '*';
	  }
	  else {
	    cout << '.';
	  }
	}
	cout << endl;
      }

      return;
    }

  }

  cout << "Impossible" << endl;

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
