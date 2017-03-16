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

int cnt(int mask) {
  int k = 0;
  while (mask) {
    ++k;
    mask &= (mask-1);
  }
  return k;
}

int N, M, B;
int P[30];
char A[10][10];
int U[10][10];

inline int pos(int x, int y) {
  return x*M + y;
}

bool F() {
  int mask;
  for (mask = (1<<(N*M)) - 1; mask >= 0; --mask) {
    if (cnt(mask) != B)
      continue;

    for (int x = 0; x < N; ++x)
      for (int y = 0; y < M; ++y) {
	if (mask & (1<<pos(x,y)))
	  A[x][y] = '*';
	else
	  A[x][y] = '.';
      }
    for (int x = 0; x < N; ++x)
      for (int y = 0; y < M; ++y) {
	if (A[x][y] == '*')
	  continue;

	for (int xx = 0; xx < N; ++xx)
	  for (int yy = 0; yy < M; ++yy)
	    U[xx][yy] = 0;
	
	queue<PII> Q;
	Q.push(PII(x, y));
	U[x][y] = 1;
	int cnt = 1;
	while (!Q.empty()) {
	  PII cur = Q.front();
	  Q.pop();
	  int bombs = 0;
	  for (int xx = max(0, cur.first-1); xx < N && xx <= cur.first+1; ++xx)
	    for (int yy = max(0, cur.second-1); yy < M && yy <= cur.second+1; ++yy)
	      if (A[xx][yy] == '*') {
		bombs++;
	      }
	  if (bombs == 0) {
	    for (int xx = max(0, cur.first-1); xx < N && xx <= cur.first+1; ++xx)
	      for (int yy = max(0, cur.second-1); yy < M && yy <= cur.second+1; ++yy)
		if (!U[xx][yy]) {
		  ++cnt;
		  U[xx][yy] = 1;
		  Q.push(PII(xx,yy));
		}
	    }
	  }
	  if (cnt + B == N*M) {
	    A[x][y] = 'c';
	    return true;
	  }
      }
  }

  return false; 
}

int main()
{
  int T;
  scanf("%d", &T);
  for (int t = 0; t < T; ++t) {
    scanf("%d%d%d", &N, &M, &B);

    bool res = F();
    printf("Case #%d:\n", t+1);
    fprintf(stderr, "Case #%d:\n", t+1);
    if (res) {
      for (int x = 0; x < N; ++x) {
	A[x][M] = 0;
	printf("%s\n", A[x]);
      }
    } else {
      printf("Impossible\n");
    }

  }

  return 0;
};
