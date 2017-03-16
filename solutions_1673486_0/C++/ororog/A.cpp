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

long double prob[100100];
long double expected[100100];
int A, B;
double p[100001];

double poor() {
  long double pbase = 1.0; // correct prob
  REP(i, A) {
    prob[i] = pbase * (1.0 - p[i]);
    pbase *= p[i];
  }

  prob[A] = pbase;
  expected[A+1] = 1+B+1;
  expected[A] = A+B+1;
  long double psum = 0;
  REP(i, A) {
    psum += prob[A-i];
    expected[i] += psum * (i + i + B-A + 1);
    expected[i] += (1-psum) * (i + i + B-A + 1 + B+1);
    //cout << i << ' ' << psum << ' ' << psum * (i + i + B-A + 1) << ' ' << (1-psum) * (i + i + B-A + 1 + B+1) << endl;
  }
  long double res = 1e10;
  REP(i, A+2) {
    //cout << expected[i] << endl;
    res = min(res, expected[i]);
  }
  return res;
}

int main(){
	int TestCase = nextInt();

	for(int caseCnt=1; caseCnt <= TestCase; caseCnt++){
    scanf("%d %d", &A, &B);
    memset(expected, 0, sizeof(expected));
    memset(prob, 0, sizeof(prob));
    REP(i, A) {
      scanf("%lg", p+i);
    }


		printf("Case #%d: %.10f\n", caseCnt, poor());
    //fprintf(stderr, "Case %d\n", caseCnt);
	}
	return 0;
}
