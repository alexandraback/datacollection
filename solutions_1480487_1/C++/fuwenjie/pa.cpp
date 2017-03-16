#include <iostream>
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
  cin >> tcase;
  for (int tind = 1; tind <= tcase; tind++) {
    int i,j;
    //istringstream strin();
    int s[300];
    vector<int> a;
    int n;
    int sum = 0;
    cin >> n;
    for (i = 0; i < n; ++i) {
      cin >> s[i];
      sum += s[i];
      a.push_back(s[i]);
    }
    a.push_back(0);
    sort(a.begin(), a.end());
    cout << "Case #" << tind << ":";
    int allsum = sum;
    for (i = 0; i < n; ++i) {
      sum = allsum;
      int p = 0;
      int k = 1;
      while (k < a.size() && a[k] <= s[i]) {
        p += s[i] - a[k];
        k++;
      }
      double ans = 0;
      if (sum > p) {
        sum -= p;
        while (sum > 0 && k < a.size()) {
          int q = (a[k] - a[k-1]) * (k - 1);
          if (q <= sum) {
            ans += a[k] - a[k-1];
            sum -= q;
          } else {
            ans += sum * 1.0 / (k - 1);
            sum = 0;
          }
          k++;
        }
        if (sum > 0) {
          ans += sum * 1.0 / n;
        }
      }
      cout << ' ' << ans * 100 / allsum;
    }
    cout << endl;
  }
  return 0;
}
