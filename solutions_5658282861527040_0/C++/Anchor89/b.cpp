#include<iostream>
#include<cstdio>
#include<cmath>
#include<vector>
#include<unordered_map>
#include<unordered_set>
#include<queue>
#include<string>
#include<algorithm>
using namespace std;

inline int lessThan(int A, int K) {
  int res = 0;
  for (int i=0; i<A; i++) {
    if ( (A&K) == K) res++;
  }
  return res;
}
int main() {
  int T,t;
  int A, B ,K;
  int res;
  cin >> T;
  t = 0;
  while(t++<T) {
    cin >> A >> B >> K;
    res = 0;
    for (int i=0; i<A; i++) {
      for (int j=0; j<B; j++) {
	if ( (i&j) < K) {
	  res++;
	}
      }
    }
    printf("Case #%d: %d\n", t, res);
  }
  return 0;
}
