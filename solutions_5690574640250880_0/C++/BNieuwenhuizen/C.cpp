#include <iostream>

#include <vector>
#include <algorithm>
#include <set>
#include <string>
#include <cstdlib>
using namespace std;

int R, C , M;
bool transposed, possible;
char matrix[50][50];
unsigned spread[50][50];
int dx[] = {0,1,1,1,0,-1,-1,-1};
int dy[] = {-1,-1,0,1,1,1,0,-1};
bool check() {
  for(int r = 0; r < R; ++r) {
    for(int c = 0; c < C; ++c) {
      spread[r][c] = 1;
      for(int i = 0; i < 8; ++i) {
	int r2 = r + dx[i];
	int c2 = c + dy[i];
	if(r2 >= 0 && r2 < R && c2 >= 0 && c2 < C && matrix[r2][c2] == '*')
	  spread[r][c] = 0;
      }
    }
  }
  unsigned cnt = 0;
  unsigned ccnt = 0;
  for(int r = 0; r < R; ++r) {
    for(int c = 0; c < C; ++c) {
      if(matrix[r][c] == '*')
	++cnt;
      else if(matrix[r][c] == 'c') 
	++ccnt;
      else {
	bool n = false;
	for(int i = 0; i < 8; ++i) {
	  int r2 = r + dx[i];
	  int c2 = c + dy[i];
	  if(r2 >= 0 && r2 < R && c2 >= 0 && c2 < C && (matrix[r2][c2] == 'c' || spread[r2][c2]))
	    n = true;
	}
	if(!n)
	  return false;
      }
    }
  }
  return cnt == M && ccnt == 1;
}

void testCase(unsigned id) {
  cin >> R >> C >> M;
  if(R > C) {
    swap(R,C);
    transposed = true;
  } else
    transposed = false;
  cout << "Case #" << id << ":\n";
  for(unsigned r = 0; r < R; ++r)
    for(unsigned c = 0; c < C; ++c)
      matrix[r][c] = '.';
  matrix[R-1][C-1] = 'c';
  //std::cerr << R << "  "<< C << " " << M << "\n";
  if(R == 1) {
    // cerr << "c0\n";
    possible = true;
    for(unsigned i = 0; i < M; ++i)
      matrix[0][i] = '*';
  } else if(M + 1 == R * C) {
    // cerr << "c1\n";
    possible = true;
    for(unsigned r = 0; r < R; ++r)
      for(unsigned c = 0; c < C; ++c)
	if(matrix[r][c] != 'c')
	  matrix[r][c] = '*';
  } else if(R >= 3 && M <= C && M != C - 1) {
    possible = true;
    for(unsigned c = 0; c < M; ++c)
      matrix[0][c] = '*';
  }/*else if(R % 2 == 0 && M % 2 == 0 && R * C - M ) {
    possible = true;
    unsigned cnt = 0;
    for(unsigned c = 0; c < C; ++c)
	for(unsigned r = 0; r < R; ++r)
	  if(cnt++ < M)
	    matrix[r][c] = '*';
  }*/ else if(R >= 4 &&  M <= (R-2) * C) {
    // cerr << "c2\n";
    possible = true;
    unsigned cnt = 0;
    for(unsigned r = 0; r < R; ++r)
      for(unsigned c = 0; c < C; ++c)
	if(cnt++ < M)
	  matrix[r][c] = '*';
    if(M % C == C - 1) {
      if(M >= (R-3)*C) {
	matrix[M/C][C-2] = '.';
	matrix[M/C][C-3] = '.';
	matrix[M/C+1][0] = '*';
	matrix[M/C+2][0] = '*';
      } else {
	matrix[M/C][C-2] = '.';
	matrix[M/C+1][0] = '*';
      }
    }
  }else if(C >= 4 &&  M <= (C-2) * R && M % R != R - 1) {
    //cerr << "c2c\n";
    possible = true;
    unsigned cnt = 0;
    for(unsigned c = 0; c < C; ++c)
      for(unsigned r = 0; r < R; ++r)
	if(cnt++ < M)
	  matrix[r][c] = '*';
    if(M % R == R - 1) {
      if(M >= (C-3)*R) { /// TODO
	matrix[R-2][M/R] = '.';
	matrix[R-3][M/R] = '.';
	matrix[0][M/R+1] = '*';
	matrix[0][M/R+2] = '*';
      } else {
	matrix[R-2][M/R] = '.';
	matrix[0][M/R+1] = '*';
      }
    }
  }  else if(R >= 3 &&  M > (R-2) * C && (R * C - M >= 9 || ((R * C - M) % 2 == 0 && R * C - M >= 4))) {
  // cerr << "c3\n";
  possible = true;
    unsigned cnt = 0;
    for(int r = 0; r < R-3; ++r)
      for(unsigned c = 0; c < C; ++c)
	if(cnt++ < M)
	  matrix[r][c] = '*';
    unsigned c;
    for(c = 0; c < C && cnt + 3 <= M; ++c) {
      matrix[R-3][c] = '*';
      matrix[R-2][c] = '*';
      matrix[R-1][c] = '*';
      cnt += 3;
    }
    for(; cnt < M; ++cnt, ++c)
      matrix[R-3][c] = '*';
} else if(R == 2 && M % 2 == 0 && M + 2 < R * C) {
    possible = true;
    for(unsigned c = 0; c * 2 < M; ++c) {
      matrix[0][c] = matrix[1][c] = '*';
    }
 }else if(C >= 3 && (R*C-M) % 2 == 0 && (M % C) != C-2 && (R % 2 == 0 || M >= C)) {

    possible = true;
    unsigned cnt = 0;
    if(R % 2)
       for(unsigned c = 0; c < C; ++c)
	 if(cnt++ < M)
	   matrix[0][c] = '*';
    for(unsigned r = (R % 2); r + 1 < R; r += 2)
      for(unsigned c = 0; c < C; ++c)
	for(unsigned r2 = 0; r2 < 2; ++r2)
	  if(cnt++ < M)
	    matrix[r+r2][c] = '*';
  } else if(R ==2 && M + 1 != R * C && M % 2) {
    //std::cerr << "uneven on size 2!\n";
    possible = false;
  } else if(R >= 2 && (M + 2 == R * C || M + 3 == R * C || M + 5 == R * C || M + 7 == R * C)) {
    //std::cerr << "free space too small: " << ( R * C - M) << "\n";
    possible = false;
  } else {
    std::abort();
    possible = false;
  }
  if(possible) {
    if(transposed) {
      for(unsigned c = 0; c < C; ++c) {
	for(unsigned r = 0; r < R; ++r)
	  cout << matrix[r][c];
	cout << "\n";
      }
    } else {
      for(unsigned r = 0; r < R; ++r) {
	for(unsigned c = 0; c < C; ++c)
	  cout << matrix[r][c];
	cout << "\n";
      }
    }
    if(!check())
      std::abort();
  } else {
    cout << "Impossible\n";
  }
}


int main() {
  int T;
  cin >> T;
  for(int i = 1; i <= T; ++i)
    testCase(i);
  return 0;
}
