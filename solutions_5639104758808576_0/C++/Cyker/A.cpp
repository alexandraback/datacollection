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
int Smax;
vector<int> S;

int solve(const vector<int> &vec)
{
  int stand = vec[0];
  int need = 0;
  OINT(i, 1, vec.size()) {
    if (vec[i] > 0) {
      if (stand < i) {
        need += i - stand;
        stand = i;
      }
      stand += vec[i];
    }
  }
  return need;
}

int main(int argc, char **argv)
{
  cin >> T;
  for (int t = 0;t < T;t++) {
    cin >> Smax;
    S.clear();
    string temp;
    cin >> temp;
    FOREACH(temp, it) {
      S.push_back(*it - '0');
    }

    cout << "Case #" << t + 1 << ": ";
    cout << solve(S);
    cout << endl;
  }

  return 0;
}

