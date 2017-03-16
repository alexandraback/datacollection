#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
#include <utility>
#include <queue>
#include <map>
#include <sstream>
using namespace std;

typedef long long LL;
typedef unsigned int UINT32;

int str2int(const string &s) {
  stringstream ss(s);
  int a;
  ss >> a;
  return a;
}

string int2str(int a) {
  stringstream ss;
  ss << a;
  return ss.str();
}

int N, M;
bool rowok(vector<vector<int> > &b, int r, int c) {
  for (int i = 0; i < M; ++i) {
    if (b[r][i] > b[r][c]) return false;
  }
  return true;
}
bool colok(vector<vector<int> > &b, int r, int c) {
  for (int i = 0; i < N; ++i) {
    if (b[i][c] > b[r][c]) return false;
  }
  return true;
}

void print(vector<vector<int> > &b) {
  for (int i = 0; i < b.size(); ++i) {
    for (int j = 0; j < b[i].size(); ++j) {
      cout << b[i][j] << ' ';
    }
    cout << endl;
  }
}

string calc()
{
  cin >> N >> M;
  vector<vector<int> > b(N), c;
  int i, j, k;
  int h = 0;
  for (i = 0; i < N; ++i) {
    b[i].resize(M);
    for (j = 0; j < M; ++j) {
      cin >> b[i][j];
      if (b[i][j] > h) h = b[i][j];
    }
  }
 
  c = b;
  for (i = 0; i < N; ++i) {
    for (j = 0; j < M; ++j) {
      c[i][j] = h;
    }
  }

  /*
  for (int m1 = 0; m1 < (1<<N); ++m1) {
    for (int m2 = 0; m2 < (1<<M); ++m2) {
      for (i = 0; i < N; ++i) {
        for (j = 0; j < M; ++j) {
          c[i][j] = 2;
        }
      }

      for (int i = 0; i < N; ++i) {
        if (m1 & (1<<i)) {
          for (int k = 0; k < M; ++k) c[i][k] = 1;
        }
      }
      for (int i = 0; i < M; ++i) {
        if (m2 & (1<<i)) {
          for (int k = 0; k < N; ++k) c[k][i] = 1;
        }
      }

      if (c == b) return "YES";
    }
  }
  return "NO";
  */

  bool found = true;
  while (found) {
  found = false;
  for (i = 0; i < N; i++) {
    for (j = 0; j < M; j++) {
      if ((j == 0 || j==M-1) && rowok(b, i, j)) {
        for (k = 0; k < M; ++k) {
          if (c[i][k] > b[i][j]) {
            c[i][k] = b[i][j];
            found = true;
          }
        }
      }
      if ((i == 0 || i == N-1) && colok(b, i, j)) {
        for (k = 0; k < N; ++k) {
          if (c[k][j] > b[i][j]) {
            c[k][j] = b[i][j];
            found = true;
          }
        }
      }
    }
  }
  }

  /*
  cout << "b:" << endl;
  print(b);
  cout << "c:" << endl;
  print(c);
  */
  return b == c ? "YES" : "NO";
}

int main(void)
{
  // NOTE: if using getline() to read the input, the following two lines should be
  // added to read the line sepeartor in the first line. 
  string line;
  getline(cin, line);
	int N = str2int(line);

	for (int i=1; i<=N; ++i) {
		cout << "Case #" << i << ": " << calc() << endl;
	}

	return 0;
}
