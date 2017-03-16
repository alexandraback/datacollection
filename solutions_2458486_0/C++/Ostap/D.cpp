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

int R[1<<21];
int MR[1<<21];
int N;
int Key[21];
vector<int> Cont[21];

int F(int maskOpen, vector<int> keys) {
  if (maskOpen == (1<<N)-1)
    return 1;
  int& res = R[maskOpen];
  if (res != -1)
    return res;
  for (int i = 0; i < N; ++i)
    if ((maskOpen & (1<<i)) == 0) {
      int j;
      for (j = 0; j < keys.size(); ++j)
	if (keys[j] == Key[i])
	  break;
      if (j < keys.size()) {
	vector<int> nkeys = keys;
	nkeys.erase(nkeys.begin() + j);
	for (int k = 0; k < Cont[i].size(); ++k)
	  nkeys.PB(Cont[i][k]);
	if (F(maskOpen | (1<<i), nkeys)) {
	  res = 1;
	  MR[maskOpen] = i;
	  return res;
	}
      }
    }
  return res = 0;
}


int main()
{
  int t, T;
  scanf("%d", &T);
  for (t = 0; t < T; ++t) {
    int K;
    scanf("%d%d", &K, &N);
    vector<int> keys;
    for (int i = 0; i < K; ++i) {
      int a;
      scanf("%d", &a);
      keys.PB(a);
    }
    for (int i = 0; i < N; ++i) {
      scanf("%d%d", &Key[i], &K);
      Cont[i].clear();
      for (int j = 0; j < K; ++j) {
	int a;
	scanf("%d", &a);
	Cont[i].PB(a);
      }
    }

    CLEAR(R, -1);
    CLEAR(MR, -1);
    int res = F(0, keys);
    printf("Case #%d:", t+1);
    if (res) {
      int mask = 0;
      while (mask != (1<<N)-1) {
	int p = MR[mask];
	printf(" %d", p+1);
	mask = (mask | (1<<p));
      }
      printf("\n");
    } else {
      printf(" IMPOSSIBLE\n");
    }
    fprintf(stderr, "Case #%d\n", t+1);

  }


  return 0;
};
