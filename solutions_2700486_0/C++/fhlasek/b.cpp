/* Written by Filip Hlasek 2013 */
#include <cstdio>
#include <cstdlib>
#include <vector>
#include <queue>
#include <stack>
#include <set>
#include <map>
#include <string>
#include <algorithm>
#include <cmath>
#include <cstring>

#define FOR(i,a,b) for(int i=(a);i<=(b);i++)
#define FORD(i,a,b) for(int i=(a);i>=(b);i--)
#define REP(i,b) for(int i=0;i<(b);i++)

using namespace std;

long double comb (int n, int k) {
  long double ans = 1;
  REP(i, k) ans = ans * (n - i) / (i + 1);
  return ans;
}

double solve(long long N, int X, int Y) {
  int d = (abs(X) + Y) / 2;
  if(!d) return 1;
  long long n = 1, a = 1;
  REP(i, d - 1) {
    a += 2;
    n += 2*a - 1;
  }
  // printf("n: %lld\n", n);
  a++;
  N -= n;
  if(N <= 0) return 0; 
  if(N >= 2*a + 1) return 1;
  if(Y == 2*d) return 0;
  // printf("N: %d\n", N);
  // printf("N: %d Y: %d a: %lld\n", N, Y, a);
  //if(Y + a + 1 < N) return 1;
  int ok = 0, all = 0;
  REP(mask, 1 << N) {
    int sum = 0;
    REP(i, N) if(mask & (1 << i)) sum++;
    if(N - sum > a) sum += (N - sum) - a;
    if(sum > Y) ok++;
  }
  /*
  long double all = 0, ok = 0;
  FOR(i, 0, N) {  // if(N - i <= a) {
    long double ways = comb(N, i);
    // printf("i: %d ways: %Lf\n", i, ways);
    all += ways;
    if(i <= Y) ok += ways;
  }
  return 1 - ok / (1 << N);
  */
  return (double)ok / (1 << N);
}

int main(int argc, char *argv[]){
  int T;
  scanf("%d", &T);
  REP(t, T) {
    printf("Case #%d: ", t + 1); 
    int N, X, Y;
    scanf("%d%d%d", &N, &X, &Y);
    printf("%.9lf\n", solve(N, X, Y));
  }
  return 0;
}
