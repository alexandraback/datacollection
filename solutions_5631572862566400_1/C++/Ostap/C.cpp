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

int E[1010];
VInt Rev[1010];
int U[1010];
int Pos[1010];

int maxLink(int x, int ex) {
  queue<PII> Q;
  Q.push(PII(x, 0));
  int res = 0;
  while (!Q.empty()) {
    PII cur = Q.front();
    Q.pop();
    res = max(res, cur.second);
    for (int i = 0; i < Rev[cur.first].size(); ++i) {
      if (Rev[cur.first][i] != ex)
	Q.push(PII(Rev[cur.first][i], cur.second+1));
    }
  }
  return res;
}

int main()
{
  int T, t;
  scanf("%d", &T);
  for (t = 0; t < T; ++t) {
    int N;
    scanf("%d", &N);
    for (int i = 0; i < N; ++i)
      Rev[i].clear();
    for (int i = 0; i < N; ++i) {
      int a;
      scanf("%d", &a);
      --a;
      E[i] = a;
      Rev[a].PB(i);
    }
    int res = 0;
    for (int i = 0; i < N; ++i) {
      if (E[E[i]] == i && E[i] > i) {
	res += maxLink(i, E[i]) + maxLink(E[i], i) + 2;
      }
    }
    
    for (int i = 0; i < N; ++i) {
      CLEAR(U, 0);
      int a = i;
      while (!U[a]) {
	U[a] = 1;
	a = E[a];
      }
      int b = E[a];
      int k = 1;
      while (b != a) {
	++k;
	b = E[b];
      }
      res = max(res, k);
    }

    printf("Case #%d: %d\n", t+1, res);
  }
  return 0;
};
