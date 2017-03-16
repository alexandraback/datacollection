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

int solve(vector<double> a, vector<double> b) {
  sort(a.begin(), a.end());
  sort(b.begin(), b.end());
  int ans = 0;
  int i = 0, j = 0;
  while (i < a.size()) {
    while (j < b.size() && b[j] < a[i]) j++;
    if (j >= b.size()) break;
    ans++;
    i++;
    j++;
  }
  return ans;
}

int main()
{
	int tcase = 0;
	ifstream fin("z.in");
	ofstream fout("z.out");
	fin >> tcase;
	for (int tind = 1; tind <= tcase; tind++)
	{
          int n;
          vector<double> a, b;
          fin >> n;
          double j;
          for (int i = 0; i < n; ++i) {
            fin >> j;
            a.push_back(j);
          }
          for (int i = 0; i < n; ++i) {
            fin >> j;
            b.push_back(j);
          }
          fout << "Case #" << tind << ": " << solve(b, a)
               << ' ' << n - solve(a, b) << endl;
	}
	return 0;
}
