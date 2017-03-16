#include <iostream>
#include <vector>
#include <cstdio>
#include <algorithm>
#include <cstring>

#define REP(i, N) for (int i = 0; i < (int)N; i++)
using namespace std;
typedef long long LL;

int nextInt() {
  char c;
  int res = 0;
  while (!isdigit(c = getchar())){};
  do {
    res = res * 10 + c - '0';
  } while (isdigit(c = getchar()));
  return res;
}

int N, sum, score[222];

double solve() {
  double lo = 0.0, hi = 1e20;
  REP(i, 1000) {
    double mid = (lo + hi) / 2.0;
    double tmp = 0.0;
    REP(i, N) {
      double d = (mid - score[i]) / sum;
      if (d > 0)
      tmp += (mid - score[i]) / sum;
    }
    if (tmp > 1.0) hi = mid;
    else lo = mid;
  }
  return (lo + hi) / 2;
}


int main(){
	int TestCase = nextInt();

	for(int caseCnt=1; caseCnt <= TestCase; caseCnt++){
    N = nextInt();
    sum = 0;
    REP(i, N) {
      score[i] = nextInt();
      sum += score[i];
    }
    double target = solve();
		printf("Case #%d:", caseCnt);
    double s = 0;
    REP(i, N) {
      double d = (target - score[i]) / sum * 100;
      d = d > -1e-10 ? d : 0.0;
      printf(" %.6f", d);
      s += d;
    }
    puts("");
    //fprintf(stderr, "Case %d\n", caseCnt);
	}
	return 0;
}
