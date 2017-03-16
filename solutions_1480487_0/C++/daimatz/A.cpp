#include <iostream>
#include <cstdio>
#include <vector>
#include <algorithm>
#include <list>
#include <stack>
#include <queue>
#include <map>
#include <string>
#include <cctype>
#include <cmath>
#include <cstring>
#include <climits>
#include <complex>
#include <set>
#define DEBUG(x) cout<<"line:"<<__LINE__<<", "<<#x" == "<<(x)<<endl;
#define REP(i,n) for(int i=0;i<(int)(n);i++)
#define FOR(it,s) for(__typeof(s.begin()) it=s.begin();it!=s.end();it++)
#define ALLOF(a) a.begin(),a.end()
using namespace std;

typedef long long ll;
typedef unsigned int uint;
typedef unsigned long long ull;

#define INF (INT_MAX/10-1)
#define EPS 1.0e-8

vector<double> solve(vector<int> s) {
  int sum = 0, asum;
  for (uint i = 0; i < s.size(); i++)
    sum += s[i];
  asum = sum;
  double required = (double)(sum + asum) / (double)s.size();
  //DEBUG(required);
  vector<double> ret;
  int k = 0;
  for (uint i = 0; i < s.size(); i++) {
    if ((double)s[i] - EPS >= required) {
      sum -= s[i];
      k++;
    }
  }
  required = (double)(sum + asum) / (double)(s.size() - k);
  //DEBUG(required);
  for (uint i = 0; i < s.size(); i++) {
    if ((double)s[i] - EPS >= required) {
      ret.push_back(0.0);
    } else {
      ret.push_back(100*(required-s[i])/asum);
    }
  }
  return ret;
}

int main(int argc, char *argv[]) {
  int T;
  scanf("%d\n", &T);
  for (int t = 1; t <= T; t++) {
    int N;
    scanf("%d", &N);
    vector<int> s;
    for (int i = 0; i < N; i++) {
      int tmp;
      scanf("%d", &tmp);
      s.push_back(tmp);
    }
    vector<double> m = solve(s);
    printf("Case #%d: ", t);
    for (uint i = 0; i < m.size(); i++) {
      printf("%6f ", m[i]);
    }
    puts("");
  }

  return 0;
}
