#include <string>
#include <vector>
#include <iostream>
#include <set>
#include <cstdio>

using namespace std;

vector < vector <int> > transpose( vector < vector <int> > A) {
  int n, m, i, j;
  vector < vector <int> > nil, B;
  n = A.size();
  if (n == 0) {
    return nil;
  }
  m = A[0].size();

  for (j = 0; j < m; j++) {
    vector <int> v;
    for (i = 0; i < n; i++) {
      v.push_back(A[i][j]);
    }
    B.push_back(v);
  }
  return B;
}

vector < vector <int> > arrange(int R, int C, int M) {
  vector < vector <int> > nil, sol;
  int i, j, k, n, m;
  int flipped;

  if (R > C) {
    sol = arrange(C, R, M);
    sol = transpose(sol);
    return sol;
  }

  for (i = 0; i < R; i++) {
    vector <int> v;
    for (j = 0; j < C; j++) {
      v.push_back('.');
    }
    sol.push_back(v);
  }

  if (R == 1) {
    for (j = C - M; j < C; j++) {
      sol[0][j] = '*';
    }
    sol[0][0] = 'c';
    return sol;
  } else if (R == 2) {
    if (R * C - M == 1) {
      for (i = 0; i < R; i++) {
	for (j = 0; j < C; j++) {
	  sol[i][j] = '*';
	}
      }
      sol[0][0] = 'c';
      return sol;
    } else if (R * C - M == 2 || (R * C - M) % 2 == 1) {
      return nil;
    } else {
      for (i = 0; i < R; i++) {
	for (j = C - M/2; j < C; j++) {
	  sol[i][j] = '*';
	}
      }
      sol[0][0] = 'c';
      return sol;
    }
  } else {
    if (R * C - M == 1) {
      for (i = 0; i < R; i++) {
	for (j = 0; j < C; j++) {
	  sol[i][j] = '*';
	}
      }
      sol[0][0] = 'c';
      return sol;
    } else if (R * C - M == 2 ||
	       R * C - M == 3 ||
	       R * C - M == 5 || 
	       R * C - M == 7) {
      return nil;
    } else {
      sol[0][0] = 'c';
      m = M;
      for (i = R - 1; i >= 2; i--) {
	for (j = C - 1; j >= 2; j--) {
	  if (m > 0) {
	    sol[i][j] = '*';
	    m--;
	  }
	}
      }
      if (m == 0) {
	return sol;
      }

      if ((R * C - M) % 2) {
	sol[2][2] = '.';
	m++;
      }

      for (j = C - 1; j > 2; j--) {
	  if (m > 0) {
	    sol[0][j] = sol[1][j] = '*';
	    m -= 2;
	  }
      }
      if (m == 0) {
	return sol;
      }

      for (i = R - 1; i > 2; i--) {
	  if (m > 0) {
	    sol[i][0] = sol[i][1] = '*';
	    m -= 2;
	  }
      }
      if (m == 0) {
	return sol;
      }

      if (m == 4) {
	if (sol[2][2] == '*') {
	  sol[2][0] = sol[2][1] = sol[0][2] = sol[1][2] = '*';
	  return sol;
	}
      } else if (m == 2) {
	if (sol[2][2] == '*') {
	  sol[2][0] = sol[2][1] = '*';
	  return sol;
	}
      }
    }
  }
  return nil;

}


int main(void) {
  int T, t;
  int R, C, M, m;
  int i, j;
  vector < vector <int> > res;
  cin >> T;

  for (t = 1; t <= T; t++) {
    cin >> R;
    cin >> C;
    cin >> M;

    cout << "Case #" << t << ": " << endl;

    res = arrange(R, C, M);

    if (res.size() == 0) {
      cout << "Impossible" << endl;
    } else {
      for (i = 0; i < R; i++) {
	for (j = 0; j < C; j++) {
	  putchar(res[i][j]);
	}
	putchar('\n');
      }
    }
  }
  return 0;
}
