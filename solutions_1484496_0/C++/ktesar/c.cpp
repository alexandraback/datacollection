#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <cctype>
#include <cstring>
#include <string>
#include <climits>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <queue>
#include <stack>
#include <list>
#include <ctime>

#define FOR(i, m, n) for (int i=m; i<n; i++)

using namespace std;

struct Res {
  int x; int y;
};

int N;
vector<int> vec;
vector<int> moznost;

bool zkus_vse(int i) {
  if (i<N) {
    FOR (k, 0, 3) {
      moznost[i] = k;
      if (zkus_vse(i+1)==true) return true;
    }
    return false;
  }
  else {
    int a = 0, b = 0;
    FOR (k, 0, N) {
      if (moznost[k]==1) a += vec[k];
      else if (moznost[k]==2) b += vec[k];
    }
    if (a==b && a!=0) {
      FOR (k, 0, N) {
        if (moznost[k]==1) printf("%d ", vec[k]);
      }
      printf("\n");
      FOR (k, 0, N) {
        if (moznost[k]==2) printf("%d ", vec[k]);
      }
      printf("\n");
      return true;
    }
    else return false;
  }
}

void solve() {
  vec.clear();
  moznost.clear();
  scanf("%d", &N);
  FOR (i, 0, N) {
    int x; scanf("%d", &x);
    vec.push_back(x);
    moznost.push_back(0);
  }
  zkus_vse(0);
}

int main()
{
  int t; scanf("%d", &t);
  FOR (i, 0, t) {
    printf("Case #%d:\n", i+1);
    solve();
  }
  return 0;
}
