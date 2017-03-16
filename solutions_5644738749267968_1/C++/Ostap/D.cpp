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

double A[1010];
double B[1010];

int main()
{
  int T;
  scanf("%d", &T);
  for (int t = 0; t < T; ++t) {
    int N;
    scanf("%d", &N);
    for (int i = 0; i < N; ++i)
      scanf("%lf", &A[i]);
    for (int i = 0; i < N; ++i)
      scanf("%lf", &B[i]);
    sort(A, A+N);
    sort(B, B+N);

    int rd = 0;
    int b, e;
    b = 0;
    e = N;
    for (int i = 0; i < N; ++i) {
      if (A[i] < B[b]) {
	e--;
      } else {
	++rd;
	++b;
      }
    }

    int rw = N;
    for (int i = 0; i < N; ++i) {
      for (int j = 0; j < N; ++j)
	if (B[j] > A[i]) {
	  B[j] = -1;
	  --rw;
	  break;
	}
    }

    printf("Case #%d: %d %d\n", t+1, rd, rw);
  }

  return 0;
};
