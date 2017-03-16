#include <vector>
#include <list>
#include <map>
#include <set>
#include <deque>
#include <stack>
#include <bitset>
#include <algorithm>
#include <functional>
#include <numeric>
#include <utility>
#include <sstream>
#include <iostream>
#include <iomanip>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <cctype>
#include <string>
#include <cstring>
#include <ctime>
using namespace std;
typedef long long ll;
const double PI = acos(-1.0);

int main()
{
  int t;
  cin >> t;
  
  for(int tcase = 1; tcase <= t; tcase++) {
    double c, f, x, a = 2.0;
    cin >> c >> f >> x;
    double opt = x / a, pre = 0.0, tm;
    while(1) {
      tm = (pre += c / a) + x / (a += f);
      if(opt >= tm) opt = tm;
      else break;
    }
    printf("Case #%d: ", tcase);
    printf("%.7f\n", opt);
  }

  return 0;
}
// Google Code Jam