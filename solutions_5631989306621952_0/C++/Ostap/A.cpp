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

char S[2000];
char res[2000];

int main()
{
  int T, t;
  scanf("%d", &T);
  for (t = 0; t < T; ++t) {
    scanf("%s", S);
    int pos = strlen(S);
    int a = 0, b = pos-1;
    while (pos > 0) {
      char mc = 0;
      int posm = -1;
      for (int i = pos-1; i >= 0; --i) {
	if (S[i] > mc) {
	  mc = S[i];
	  posm = i;
	}
      }
      res[a++] = S[posm];
      for (int i = pos-1; i > posm; --i)
	res[b--] = S[i];
      pos = posm;
    }
    res[strlen(S)] = 0;
    printf("Case #%d: %s\n", t+1, res);
  }

  return 0;
};
