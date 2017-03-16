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

#define MAX_GROWTH 20

template<class T>vector<T>&operator<<(vector<T>& v,T t){v.push_back(t);return v;} 

int sizes[101];
int A, N;

int f(int size, int i) {
  if (i == N) return 0;
  if (size > sizes[i]) {
    return f(size + sizes[i], i + 1);
  }

  if (size == 1) return N - i;
  int res = f(size + (size - 1), i) + 1;
  if (res < N - i) return res;
  return N - i;
}

int main() {
  int T;
  cin >> T;
  rep(t, T) {
    cin >> A;
    cin >> N;
    rep(n, N) {
      cin >> sizes[n];
    }

    sort(sizes, sizes + N);

    printf("Case #%d: %d\n", t + 1, f(A, 0));
  }
}
