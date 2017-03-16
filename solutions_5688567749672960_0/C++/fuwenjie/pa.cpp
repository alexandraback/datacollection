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

int rev(int i) {
  int j = 0;
  while (i > 0) {
    j = j * 10 + i % 10;
    i /= 10;
  }
  return j;
}

int main()
{
  vector<int> a(1000001);
  vector<int> q, nq;
  nq.push_back(1);
  a[1] = 1;
  int step = 1;
  while (nq.size()) {
    swap(q, nq);
    step++;
    for (int i = 0; i < q.size(); i++) {
      int j = q[i];
      int k = j + 1;
      if (k <= 1000000 && a[k] == 0) {
        a[k] = step;
        nq.push_back(k);
      }
      k = rev(j);
      if (k <= 1000000 && a[k] == 0) {
        a[k] = step;
        nq.push_back(k);
      }
    }
    q.clear();
  }

  int tcase = 0;
  ifstream fin("z.in");
  ofstream fout("z.out");
  fin >> tcase;
  for (int tind = 1; tind <= tcase; tind++) {
    int i;
    fin >> i;
    fout << "Case #" << tind << ": " << a[i] << endl;
  }
  return 0;
}
