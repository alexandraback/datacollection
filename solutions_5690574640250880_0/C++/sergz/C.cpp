#include <iostream>

using namespace std;

void
print_field(int* field, int R, int C, int rc, int cc) {
  for(int r = 1; r < R-1; r++) {
    for(int c = 1; c < C-1; c++) {
      if((r == rc) && (c == cc)) {
	cout << 'c';
      } else {
	if(field[r*C+c] == 0) {
	  cout << '*';
	} else {
	  cout << '.';
	}
      }
    }
    cout << endl;
  }
}

bool
open(int* field, int R, int C, int M, int r, int c, int m) {
  bool result = false;

  for(int i = -1; i <=1; i++) {
    for(int j = -1; j <=1; j++) {
      field[(r+i)*C+(c+j)]++;
      if(field[(r+i)*C+(c+j)] == 1) {
	m--;
      }
    }
  }
  if(m == M) {
    result = true;
  } else if(m > M) {
    for(int i = -1; !result && (i <=1); i++) {
      for(int j = -1; !result && (j <=1); j++) {
	if(field[(r+i)*C+(c+j)] == 1) {
	  result = open(field, R, C, M, r+i, c+j, m);
	}
      }
    }
  }

  if(!result) {
    for(int i = -1; i <=1; i++) {
      for(int j = -1; j <=1; j++) {
	field[(r+i)*C+(c+j)]--;
      }
    }
  }

  return result;
}

bool
solve(int* field, int R, int C, int M, int& rc, int& cc) {
  bool result = false;

  if(M == 0) {
    result = true;
    rc = 1;
    cc = 1;
    for(int r = 0; r < R; r++) {
      for(int c = 0; c < C; c++) {
	field[r*C+c] = 1;
      }
    }
  } else if((M+1) == (R-2)*(C-2)) {
    result = true;
    rc = 1;
    cc = 1;
    for(int r = 0; r < R; r++) {
      for(int c = 0; c < C; c++) {
	field[r*C+c] = 0;
      }
    }
  } else {
    for(int r = 1; !result && (r < R-1); r++) {
      for(int c = 1; !result && (c < C-1); c++) {
	rc = r;
	cc = c;
	result = open(field, R, C, M, r, c, (R-2)*(C-2));
      }
    }
  }

  return result;
}

int
main() {
  int T;

  cin >> T;

  for(int i = 1; i <= T; i++) {
    int R, C, M;

    cin >> R >> C >> M;

    R += 2;
    C += 2;
    int* field = new int[R*C];
    for(int r = 0; r < R; r++) {
      for(int c = 0; c < C; c++) {
	field[r*C+c] = 0;
      }
    }
    for(int c = 0; c < C; c++) {
      field[c] = 9;
      field[(R-1)*C+c] = 9;
    }
    for(int r = 0; r < R; r++) {
      field[r*C] = 9;
      field[r*C+(C-1)] = 9;
    }

    cout << "Case #" << i << ": " << endl;
//    cout << "R: " << (R-2) << "; C: " << (C-2) << "; M: " << M << endl;

    int r=5, c=6;
    if(solve(field, R, C, M, r, c)) {
      print_field(field, R, C, r, c);
    } else {
      cout << "Impossible" << endl;
    }

    delete[] field;
  }

  return 0;
}

