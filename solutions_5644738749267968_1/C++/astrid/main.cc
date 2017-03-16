#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <string.h>
#include <strings.h>
#include <string>
#include <algorithm>
#include <vector>
#include <set>
#include <iostream>
#include <sstream>
#include <iomanip>
#include <math.h>
#include <cmath>
#include <map>
#include <list>
#include <queue>
#include <deque>
#include <stack>
#include <bitset>
#include <functional>
#include <numeric>
#include <utility>
#include <iomanip>
#include <cmath>
#include <ctime>
#include <climits>
#include <assert.h>

using namespace std;

#define all(c) (c).begin(),(c).end() 
#define FOR(i,a,b) for(int i=int(a); i<int(b); ++i)

int main() {
  int T, n;
  scanf("%d", &T);
  FOR(test,1,T+1) {
    scanf("%d", &n);
    vector<double> noe(n);
    vector<double> ken(n);
    FOR(i,0,n) scanf("%lf",&noe[i]);
    FOR(i,0,n) scanf("%lf",&ken[i]);
    sort(all(noe));
    sort(all(ken));
 
    int j = 0, i = 0;
    while (j < n) {
      while ((i < n) && (noe[i] < ken[j]))
	i ++;
      if (i == n) break;
      i ++, j++;
    }
    int sol1 = j;
    i = 0, j = 0;
    while (i < n) {
      while ((j < n) && (ken[j] < noe[i]))
	j ++;
      if (j == n) break;
      i ++, j ++;
    }
    assert (j == n);
    int sol2 = n - i;
    printf("CASE #%d: %d %d\n", test, sol1, sol2);
  }
  return 0;
}
