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


int main()
{
  int T;
  scanf("%d", &T);

  int R, N, M, K;
  scanf("%d%d%d%d", &R, &N, &M, &K);


  vector<int> V;
  vector<set<int> > Sets;
  for (int a = 2; a <= M; ++a)
    for (int b = a; b <= M; ++b)
      for (int c = b; c <= M; ++c) {
	V.PB(a*100 + b*10 + c);
	set<int> S;
	S.insert(a*b*c);
	S.insert(b*c);
	S.insert(a*b);
	S.insert(a*c);
	S.insert(a);
	S.insert(b);
	S.insert(c);
	S.insert(1);
	Sets.PB(S);
      }

  printf("Case #1:\n");

  for (int i = 0; i < R; ++i) {
    VInt p;
    for (int j = 0; j < K; ++j) {
      int a;
      scanf("%d", &a);
      p.PB(a);
    }

    VInt r;
    for (int j = 0; j < V.size(); ++j) {
      int k = 0;
      for (k = 0; k < p.size(); ++k)
	if (Sets[j].find(p[k]) == Sets[j].end())
	  break;
      if (k == p.size())
	r.PB(V[j]);
    }
    int pos = rand() % r.size();
    printf("%d\n", r[pos]);
  }



  return 0;
};
