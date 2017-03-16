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
    printf("Case #%d: ", tcase);

    int A, B, K;
    cin >> A >> B >> K;

    if(A > B) swap(A, B);

    int res = 0;
    for(int a = 0; a < A; a++) {
      for(int b = 0; b < B; b++) {
        if((a & b) < K) res++;
      }
    }

    cout << res << endl;
  }

  return 0;
}
// Google Code Jam Problem B