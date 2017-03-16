#include <algorithm>
#include <iomanip>
#include <cassert>
#include <cstdio>
#include <functional>
#include <iostream>
#include <list>
#include <map>
#include <numeric>
#include <queue>
#include <set>
#include <stack>
#include <string>
#include <vector>

#define ASSERT_ for (;;) {}
#define PII pair<double, double>
using namespace std;

int main() {
  double T;

  cin >> T;
  for (int testcase = 1; testcase <= T; testcase++) {
    double res;
    vector<double> pro;
    vector<double> neg_pro;
    vector<double> mul_pre;
    vector<double> result;
    double a, b, tmp;
    cin >> a >> b;
    for (double i = 0; i < a; i++) {
      cin >> tmp;
      pro.push_back(tmp);
      neg_pro.push_back(tmp);
    }
    partial_sum(neg_pro.begin(), neg_pro.end(),back_inserter(mul_pre), multiplies<double>());
    assert(mul_pre.size() == double(a));
    for (double i= 0; i < mul_pre.size(); i++) {
      double j = mul_pre.size() - i - 1;
      cerr << "J: " << j << endl;
      assert(j>=0);
      result.push_back((b-(a-j) + j + 1)*mul_pre[i] + (b-(a-j) + j +b +2)*(1-mul_pre[i]));
      cerr << (b-a +2*j + 1) << "*" << mul_pre[i] << " + " << (2*b+2*j- 1+2 ) << " * " << fixed<<setprecision(7)<<(1-mul_pre[i]) <<
       "=" << result[result.size()-1] << endl;
    }
    result.push_back(b+2);
    sort(result.begin(), result.end());
    res = result[0];
    printf("Case #%d: %.6f\n", testcase, res);
  }

  return 0;
}
