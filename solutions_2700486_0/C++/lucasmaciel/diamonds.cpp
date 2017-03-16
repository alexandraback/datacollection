#include <iostream>
#include <stdio.h>
#include <queue>
#include <algorithm>
#include <vector>
#include <list>
#include <set>
#include <map>
#include <string>
#include <cstdlib>
#include <math.h>
using namespace std;

//trocar para 0 para desabilitar output
#if 1
#define DEBUG(x) cout << x << endl
#define PAUSE() cin.get(); cin.get()
#else
#define DEBUG(x)
#define PAUSE()
#endif

#define TRACE(x) DEBUG(#x << " = " << x)
#define DEBUGS() DEBUG("***************************")
#define MAX 101

double comb(int a, int b){
  double r = 1;
  for (int i = b+1; i <= a; ++i) r *= i;
  for (int i = 1; i <= a-b; ++i) r /= i;
  return r;
}

int main(){
  int t;
  int N, x, y, tests = 0;
  scanf("%d", &t);
  while (t--){
    scanf("%d %d %d", &N, &x, &y);
    double result = 0.0;
    int n = x+y-1, nline = x+y+1;
    if (n%2){
      int alfa = N-(n*n+n)/2, alfaline = N-(nline*nline+nline)/2;
      if (alfaline < 0){
	int tst;
	if (x == 0) tst = 2*y+1;
	else tst = y+1;
	for (int p = 0; p <= alfa-tst; ++p){
	  result += comb(y+1, p)*pow(0.5, y+1+p);
	}
      }
      else result = 1.0;
    }
    if (result == 0.0 || result == 1.0)
      printf("Case #%d: %.1f\n", ++tests, result);
    else
      printf("Case #%d: %1g\n", ++tests, result);
  }
  return 0;
}
