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

double resolve(int n, int x, int y) {
  if (x < 0) x = -x;
  int k = (x + y) / 2;
  int det = 2 * (k-1)*k + k;
  if (n <= det) return 0;
  n -= det;
  if (x == 0) {
    if (n > k * 4) return 1;
    return 0;
  }
  // x != 0
  if (n >= k * 2 + y + 1) return 1;
  double a[10010];
  mset(a, 0);
  a[0] = 1;
  for (int i = 0; i < n; ++i) {
    for (int j = i; j >= 0; --j) {
      a[j+1] = (a[j+1] + a[j]) / 2;
    }
    a[0] /= 2;
  }
  double sum = 0;
  for (int i = y + 1; i <= n; ++i) sum += a[i];
  return sum;
}

int main()
{
	int tcase = 0;
	ifstream fin("z.in");
	ofstream fout("z.out");
	fin >> tcase;
	for (int tind = 1; tind <= tcase; tind++)
	{
          int n, x, y;
          fin >> n >> x >> y;
          fout << "Case #" << tind << ": " << resolve(n, x, y) << endl;
	}
	return 0;
}
