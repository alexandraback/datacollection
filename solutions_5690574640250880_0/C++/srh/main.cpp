#include <iostream>
#include <vector>

int main() {
  int T;
  std::cin >> T;
  for (int casenum = 1; casenum <= T; ++casenum) {
    int R, C, M;
    std::cin >> R >> C >> M;

    std::vector<std::string> field(R, std::string(C, '*'));
    int N = R * C - M;
    bool possible = true;
    if (N == 1) {
      field[0][0] = 'c';
    } else if (R == 1) {
      for (int i = 0; i < N; ++i) {
	field[0][i] = '.';
      }
      field[0][0] = 'c';
    } else if (C == 1) {
      for (int i = 0; i < N; ++i) {
	field[i][0] = '.';
      }
      field[0][0] = 'c';
    } else if (R == 2) {
      if (N % 2 == 0 && N >= 4) {
	for (int i = 0; i < N / 2; ++i) {
	  field[0][i] = '.';
	  field[1][i] = '.';
	}
	field[0][0] = 'c';
      } else {
	possible = false;
      }
    } else if (C == 2) {
      if (N % 2 == 0 && N >= 4) {
	for (int i = 0; i < N / 2; ++i) {
	  field[i][0] = '.';
	  field[i][1] = '.';
	}
	field[0][0] = 'c';
      } else {
	possible = false;
      }
    } else {
      if (N == 4 || N == 6) {
	for (int i = 0; i < N / 2; ++i) {
	  field[i][0] = '.';
	  field[i][1] = '.';
	}
	field[0][0] = 'c';
      } else if (N == 8) {
	for (int i = 0; i < 3; ++i) {
	  for (int j = 0; j < 3; ++j) {
	    if (!(i == 3 && j == 3)) {
	      field[i][j] = '.';
	    }
	  }
	}
	field[0][0] = 'c';
      } else if (N > 8) {
	int h = N / C;
	if (h < 2) {
	  h = 2;
	}
	int w = N / h;
	if (w > C) {
	  w = C;
	}

	int r = N - h * w;
	if (h == 2 && r == 1) {
	  --w;
	  r += 2;
	}
	int K = N;
	for (int i = 0; K > 0 && i < R; ++i) {
	  for (int j = 0; K > 0 && j < w; ++j) {
	    if (!(r == 1 && i == h - 1 && j == w - 1)) {
	      field[i][j] = '.';
	      --K;
	    }
	  }
	}
	if (K != 0) {
	  std::cerr << "K is " << K << std::endl;
	  return 1;
	}
	field[0][0] = 'c';
      } else {
	possible = false;
      }
    }

    std::cout << "Case #" << casenum << ":" << std::endl;
    if (!possible) {
      std::cout << "Impossible" << std::endl;
    } else {
      for (int i = 0; i < R; ++i) {
	std::cout << field[i] << std::endl;
      }
    }
  }

}
