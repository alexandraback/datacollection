#include <cstdio>
#include <cassert>
#include <cmath>
#include <cstdlib>
#include <cstring>
#include <cctype>
#include <algorithm>
#include <vector>
#include <iostream>
#include <string>
#include <map>
#include <set>
#include <utility>
#include <sstream>
using namespace std;
typedef long long ll;

ll ai[100], bi[100];
ll Ai[100], Bi[100];
ll memo[105][105];
int N, M;

ll rec(int a, int b) {
  if (a == N || b == M) return 0;
  ll& res = memo[a][b];
  
  if (res != -1) return res;
  res = 0;

  if (Ai[a] != Bi[b]) {
    res = max(rec(a+1,b), rec(a, b+1));
    return res;
  }


  ll aa = ai[a], bb = bi[b];
  ll sum = 0;
    bool f = false;
  for (;;) {
    //cout << a << " " << aa << " " << b << " " << bb << endl;

    if (Ai[a] == Bi[b]) {
      ll minv = min(aa, bb);
      aa -= minv;
      bb -= minv;
      sum += minv;
      res = max(res, sum);
      if (aa == 0) {
	f = true;
	a++;
	if (a >= N) {
	  return res;
	}
	aa = ai[a];
      } else {
	f = false;
	b++;
	if (b >= M) {
	  return res;
	}
	bb = bi[b];
      }
    } else if (Ai[a] != Bi[b]) {
      if (f) {
	res = max(res, sum + rec(a, b+1));	
	a++;
	if (a >= N) {
	  return res;
	}
	aa = ai[a];
      } else {
	res = max(res, sum + rec(a+1, b));
	b++;
	if (b >= M) {
	  return res;
	}
	bb = bi[b];
      }
    }
  }
}

int main() {

  int T;
  scanf(" %d", &T);

  for (int ii = 0; ii < T; ii++) {

    cin >> N >> M;
    for (int i = 0; i < N; ++i) {
      cin >> ai[i] >> Ai[i];
    }
    for (int i = 0; i < M; ++i) {
      cin >> bi[i] >> Bi[i];
    }
    memset(memo, -1, sizeof(memo));
    ll ans = rec(0,0);
    printf("Case #%d: ", ii + 1);
    cout << ans << endl;
  }
}
