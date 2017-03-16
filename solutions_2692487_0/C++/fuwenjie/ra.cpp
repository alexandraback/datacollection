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

int main()
{
	int tcase = 0;
	ifstream fin("z.in");
	ofstream fout("z.out");
	fin >> tcase;
	for (int tind = 1; tind <= tcase; tind++)
	{
          int A, n;
          fin >> A >> n;
          int m[101];
          int i,j;
          for (i = 0; i < n; ++i) fin >> m[i];
          sort(m, m + n);
          int ans = n;
          int mv = 0;
          if (A > 1) {
            for (i = 0; i < n; ++i) {
              while (A <= m[i]) {
                mv++;
                A += A - 1;
              }
              A += m[i];
              if (mv+n-i-1 <= ans) ans = mv+n-i-1;
            }
          }
          fout << "Case #" << tind << ": " << ans << endl;
	}
	return 0;
}
