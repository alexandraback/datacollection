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

PII A[1000];
double R[1000];

int main()
{
  int T;
  scanf("%d", &T);
  for (int t = 0 ;t < T; ++t ){
    int N;
    scanf("%d", &N);
    int sum = 0;
    for (int i = 0; i < N; ++i) {
      scanf("%d", &A[i].first);
      A[i].second = i;
      sum += A[i].first;
    }
    sort(A, A+N);
    int s1 = sum;
    for (int i = N; i > 0; --i) {
      (s1 + sum) / i;
      if (A[i-1].first * i > s1 + sum) {
        R[A[i-1].second] = 0;
        s1 -= A[i-1].first;
      } else {
        for (int j = 0; j < i; ++j) {
          R[A[j].second] = ( (s1 + sum) / (double) i - A[j].first ) / (double)sum;
        }
        break;
      }
    }

    printf("Case #%d:", t+1);
    for (int i = 0; i < N; ++i)
      printf(" %.6lf", R[i] * 100.0);
    printf("\n");
  }


  return 0;
};
