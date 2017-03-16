#define _CRT_SECURE_NO_DEPRECATE
#include <iostream>
#include <sstream>
#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <memory.h>
#include <cctype>
#include <string>
#include <vector>
#include <list>
#include <queue>
#include <deque>
#include <stack>
#include <map>
#include <set>
#include <algorithm>
using namespace std;

typedef long double Double;
typedef vector<int> VInt;
typedef vector< vector<int> > VVInt;
typedef long long Int;
typedef pair<int, int> PII;

#define FOR(i, n, m) for(i = n; i < m; ++i)
#define RFOR(i, n, m) for(i = (n) - 1; i >= (m); --i)
#define CLEAR(x, y) memset(x, y, sizeof(x))
#define COPY(x, y) memcpy(x, y, sizeof(x))
#define PB push_back
#define MP make_pair
#define SIZE(v) ((int)((v).size()))
#define ALL(v) (v).begin(), (v).end()

int A[110][110];

int main()
{
  int T, t;
  scanf("%d", &T);
  for (t = 0; t < T; ++t) {
    int N, M;
    scanf("%d%d", &N, &M);
    for (int i = 0; i < N; ++i)
      for (int j = 0; j < M; ++j)
	scanf("%d", &A[i][j]);

    bool good = true;

    for (int i = 0; i < N && good; ++i)
      for (int j = 0; j < M && good; ++j) {
	bool ok = true;
	for (int k = 0; k < N; ++k)
	  if (A[k][j] > A[i][j]) {
	    ok = false;
	    break;
	  }
	if (ok)
	  continue;
	ok = true;
	for (int k = 0; k < M; ++k)
	  if (A[i][k] > A[i][j]) {
	    ok = false;
	    break;
	  }
	if (ok)
	  continue;
	good = false;
      }
    printf("Case #%d: %s\n", t+1, good ? "YES" : "NO");
  }

  return 0;
};
