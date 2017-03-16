#include <cassert>
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <algorithm>
#include <bitset>
#include <complex>
#include <deque>
#include <functional>
#include <iostream>
#include <iterator>
#include <limits>
#include <list>
#include <map>
#include <numeric>
#include <queue>
#include <set>
#include <sstream>
#include <string>
#include <utility>
#include <valarray>
#include <vector>
#include <ext/algorithm>
#include <ext/hash_map>
#include <ext/hash_set>
#include <ext/numeric>
using namespace std;
using namespace __gnu_cxx;

#define F(i,a,b)for(int i=a;i<b;++i)
#define rep(i,n)F(i,0,n)
#define all(a)a.begin(),a.end()
template<class T>vector<T>&operator<<(vector<T>& v,T t){v.push_back(t);return v;} 


int _heights[20004];
int *heights = _heights + 10001;


pair<int, int> place(int left) {
  if (heights[0] == -1) {
    heights[0] = 1;
    heights[-1] = 0;
    heights[1] = 0;
    return make_pair(0,0);
  }

  if (heights[0] == heights[-1] - 1 && heights[-1] == heights[1]) {
    heights[0] += 2;
    return make_pair(0, heights[0] - 1);
  }
  int curY = heights[0];
  int curX = 0;

  if (heights[-1] < heights[1]) {
    left = 1;
  } else if (heights[1] < heights[-1]) {
    left = 0;
  }

  int dx = left ? -1 : 1;

  
  curX += dx;
  while (curY >= 0) {
    curY = max(heights[curX], heights[curX + 1] - 1);
    curY = max(heights[curX-1] - 1, curY);


    if (heights[curX + dx] >= curY) break;
    curX += dx; 
  }

  heights[curX] = curY + 2;
  heights[curX - 1] = curY + 1;
  heights[curX + 1] = curY + 1;
  return make_pair(curX, curY + 1);
}

int main() {
  int T;
  cin >> T;
  rep(t, T) {
    int N, X, Y;
    cin >> N >> X >> Y;
    pair<int, int> target(X,Y);


    int hits = 0;
    rep(i, (1 << N)) {
      memset(_heights, -1, sizeof(_heights));
      rep(j, N) {
        int left = (i & (1 << j));
        pair<int, int> res = place(left);
        if (res == target) ++hits;
      }
    }
    printf("Case #%d: %.7f\n", t + 1, (double) hits / (1 << N));
  }
}
