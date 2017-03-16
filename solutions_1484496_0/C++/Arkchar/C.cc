#include <cstdlib>
#include <cctype>
#include <cstring>
#include <cstdio>
#include <cmath>
#include <algorithm>
#include <vector>
#include <string>
#include <iostream>
#include <sstream>
#include <map>
#include <set>
#include <queue>
#include <stack>
#include <fstream>
#include <numeric>
#include <iomanip>
#include <bitset>
#include <list>
#include <stdexcept>
#include <functional>
#include <utility>
#include <ctime>
#include <complex>
using namespace std;

// begin insert defines
#define two(x) (1LL<<(x))
#define Rep(i,n) for(int n_ = (n), i = 0; i< n_; ++i)

// end insert defines

const int N = 20;

int n;
int num[N];

int main(int argc, char *argv[])
{
  int T;
  cin >> T;
  Rep(Ca, T) {
    cout << "Case #" << Ca + 1 << ":" << endl;
    cin >> n;
    Rep(i, n) cin >> num[i];
    int lab = 0;
    Rep(a, two(n)) {
      if (!a) continue;
      int s1 = 0;
      Rep(i, n)
        if (two(i) & a)
          s1 += num[i];
      for (int b = (a - 1) & a; b > 0; b = (b - 1) & a) {
        int s2 = 0;
        Rep(i, n)
          if (two(i) & b)
            s2 += num[i];
        if (s1 - s2 == s2) {
          lab = 1;
          Rep(i, n) if ((two(i) & a) && !(two(i) & b))
            cout << num[i] << " ";
          cout << endl;
          Rep(i, n) if (two(i) & b)
            cout << num[i] << " ";
          cout << endl;
          goto LL;
        }
      }
    }
  LL:;
    if (!lab) cout << "Impossible" << endl;
  }
  return 0;
}
