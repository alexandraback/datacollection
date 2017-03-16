#include <iostream>
#include <sstream>
#include <vector>
#include <string>
#include <algorithm>
#include <cmath>
//#include <utility>
//#include <set>
#include <map>
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

int n;
int a[501];
bool solved;
map<int, int> m;
int index1, index2;

void solve(int k, int index, int sum) {
  if (k >= n) {
    if (index > 0) {
      if (m.find(sum) != m.end()) {
        index1 = m[sum];
        index2 = index;
        solved = true;
      } else {
        m[sum] = index;
      }
    }
    return;
  }
  solve(k + 1, index, sum);
  if (solved) {
    return;
  }
  solve(k + 1, index + (1 << k), sum + a[k]);
}

int main()
{
  int tcase = 0;
  cin >> tcase;
  for (int tind = 1; tind <= tcase; tind++) {
    int i,j;
    cin >> n;
    //istringstream strin();
    for (i = 0; i < n; ++i) {
      cin >> a[i];
    }
    cout << "Case #" << tind << ":" << endl;
    solved = false;
    solve(0, 0, 0);
    if (solved) {
      vector<int> l1, l2;
      for (int i = 0; i < n; ++i) {
        int k1 = index1 & (1 << i);
        int k2 = index2 & (1 << i);
        if (k1 && k2) {
          continue;
        }
        if (k1) {
          l1.push_back(a[i]);
        }
        if (k2) {
          l2.push_back(a[i]);
        }
      }
      cout << l1[0];
      for (int j = 1; j < l1.size(); ++j) {
        cout << ' ' << l1[j];
      }
      cout << endl;
      cout << l2[0];
      for (int j = 1; j < l2.size(); ++j) {
        cout << ' ' << l2[j];
      }
      cout << endl;
    } else {
      cout << "Impossible" << endl;
    }
  }
  return 0;
}
