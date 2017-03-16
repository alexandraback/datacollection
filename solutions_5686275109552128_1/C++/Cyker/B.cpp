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
int D;
vector<int> P;

int main(int argc, char **argv)
{
  cin >> T;
  for (int t = 0;t < T;t++) {
    cin >> D;
    P.clear();
    REP(i, D) {
      int temp;
      cin >> temp;
      P.push_back(temp);
    }

    int Pmax = *max_element(P.begin(), P.end());

    int cnt = INF;
    CINT(k, 1, Pmax) {
      int cnt_k = 0;
      REP(i, D) {
        cnt_k += (P[i] + k - 1) / k - 1;
      }
      cnt_k += k;
      if (cnt_k < cnt) {
        cnt = cnt_k;
      }
    }

    cout << "Case #" << t + 1 << ": ";
    cout << cnt;
    cout << endl;
  }

  return 0;
}
