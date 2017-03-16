#include <iostream>
#include <sstream>
#include <cstdlib>
#include <cmath>
#include <map>
#include <set>
#include <queue>
#include <string>
#include <vector>
#include <algorithm>
#include <functional>
#include <cstdio>
#include <numeric>
#include <bitset>
#include <stack>
using namespace std;

const int INF = 1 << 30;

int main()
{
  int T;
  cin >> T;
  for (int Testcase = 1; Testcase <= T; ++Testcase) {
    int A, B;
    cin >> A >> B;
    vector<double> p(A);
    for (int i = 0; i < A; ++i)
      cin >> p[i];
    p.push_back(1.0);

    double ans = B + 2.0, sum = p[0];
    for (int i = 1; i <= A; ++i) {
      int backspace = A - i;
      int press = 2 * backspace + B - A + 1;
      ans = min(ans, sum*(press)+(1.0-sum)*(press+B+1));
      sum *= p[i];
    }

    printf("Case #%d: %.6f\n", Testcase, ans);
  }
  return 0;
}
