#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include <string>
#include <algorithm>
#include <cmath>
//#include <utility>
//#include <set>
//#include <map>
//#include <queue>
#include <iomanip>
using namespace std;

#define mset(A,B) memset(A,B,sizeof(A));
#define mcpy(A,B) memcpy(A,B,sizeof(B));
typedef long long ll;
typedef long double ld;
typedef vector<int> vint;
//typedef vector<string> vstr;
#define FI(I,L,U) for (int I=L;I<U;I++)
#define sqr(x) ((x)*(x))

vector<vector<char> > a;

void init(int r, int c, char ch) {
  a.clear();
  FI(i, 0, r) {
    a.push_back(vector<char>(c, ch));
  }
}

bool solve(int r, int c, int m) {
  init(r, c, '.');
  if (r == 1) {
    FI(i, 0, m) a[0][i] = '*';
    return true;
  }
  if (c == 1) {
    return false;
  }
  if (m == 0) return true;
  if (m <= r * (c-2)) {
    FI(i, 0, r) FI(j, 0, c)
      if (j * r + i < m) a[i][j] = '*';
    if ((m+1) % r == 0) {
      int k = m / r;
      swap(a[r-2][k], a[0][k+1]);
      if (m == r*(c-2) - 1) {
        if (r == 2) return false;
        swap(a[r-3][k], a[0][k+2]);
      }
    }
    return true;
  }
  int n = r * c - m;
  init(r, c, '*');
  if (n % 2 == 0) {
    if (n == 2) return false;
    FI(i, 0, n/2) a[r - 1 - i][c - 1] = a[r - 1 - i][c - 2] = '.';
    return true;
  }
  if (n == 1) {
    a[r-1][c-1] = '.';
    return true;
  }
  if (n < 9) return false;
  if (c < 3) return false;
  FI(i, 0, 3) FI (j, 0, 3) a[r-1-i][c-1-j] = '.';
  FI(i, 0, (n-9)/2) a[r-4-i][c-1] = a[r-4-i][c-2] = '.';
  return true;
}

int main()
{
	int tcase = 0;
	ifstream fin("z.in");
	ofstream fout("z.out");
	fin >> tcase;
	for (int tind = 1; tind <= tcase; tind++)
	{
                int r, c, m;
                fin >> r >> c >> m;
		fout << "Case #" << tind << ":" << endl;
                if (solve(r, c, m)) {
                  a[r-1][c-1] = 'c';
                  FI(i, 0, r) {
                    FI(j, 0, c) fout << a[i][j];
                    fout << endl;
                  }
                } else if (solve(c, r, m)) {
                  a[c-1][r-1] = 'c';
                  FI(i, 0, r) {
                    FI(j, 0, c) fout << a[j][i];
                    fout << endl;
                  }
                } else {
                  fout << "Impossible" << endl;
                }
	}
	return 0;
}
