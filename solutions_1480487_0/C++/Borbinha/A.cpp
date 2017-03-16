#include <iostream>
#include <vector>
#include <algorithm>
#include <list>
#include <string>
#include <map>
#include <set>
#include <cmath>
#include <iomanip>
using namespace std;

int main()
{

  int nc;
  cin >> nc;

  for (int c=0;c<nc;c++) {
    cout << "Case #" << c+1 << ":";
    int n;
    cin >> n;
    vector<int> v;
    int sum = 0;
    for (int i=0;i<n;i++) {
      int k;
      cin >> k;
      v.push_back(k);
      sum += k;
    }

    int s = sum;
    int ns;
    int x = n;
    int nprev = x+1;
    vector<bool> t(n,false);
    while (nprev != x) {
      nprev = x;
      ns = s;
      for (int i=0;i<n;i++) {
        if (t[i]) continue;
        if (((s + sum) - (nprev*v[i])) < 0) {
          x--;
          ns -= v[i];
          t[i] = true;
        }
      }
      s = ns;
    }

    for (int i=0;i<n;i++) {
      if (t[i]) {
        cout << " 0";
      } else {
        cout << " " << setprecision (10) <<  ((double) ( 100 *((s + sum) - (x*v[i])))) / ((double) sum * x);
      }
    }
    cout << endl;

  }

  return 0;
}
