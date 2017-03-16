#include <algorithm>
#include <cmath>
#include <cstdlib>
#include <cstring>
#include <ctime>
#include <cstdio>
#include <deque>
#include <functional>
#include <iomanip>
#include <iostream>
#include <map>
#include <queue>
#include <set>
#include <sstream>
#include <string>
#include <utility>
#include <vector>

using namespace std;

#define REP(i,n) for(int (i)=0;(i)<(int)(n);(i)++)
#define OINT(i,b,e) for(int (i)=(b);(i)<(int)(e);(i)++)
#define CINT(i,b,e) for(int (i)=(b);(i)<=(int)(e);(i)++)
#define FOREACH(c,itr) for(__typeof((c).begin()) itr=(c).begin();itr!=(c).end();itr++)
#define PI 3.1415926535897932384626433832795
#define INF 0x7FFFFFFF

int T;
int X, R, C;

bool solve()
{
  if (X >= 7) {
    return true;
  }

  if ((R * C) % X) {
    return true;
  }

  if ((X + 1) / 2 > min(R, C)) {
    return true;
  }

  if (X >= 3 && min(R, C) <= 2) {
    return true;
  }

  return false;
}

int main(int argc, char **argv)
{
  cin >> T;
  for (int t = 0;t < T;t++) {
    cin >> X >> R >> C;
    bool res = solve();

    cout << "Case #" << t + 1 << ": ";
    cout << (res ? "RICHARD" : "GABRIEL");
    cout << endl;
  }

  return 0;
}
