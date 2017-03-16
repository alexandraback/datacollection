#include <stdio.h>
#include <iostream>
#include <string>
#include <string.h>
#include <math.h>
#include <set>
#include <queue>
#include <map>
#include <algorithm>

#define pii pair<int,int>
#define FOR(i,a,b) for (int i = a; i <= (int) b; i++)
#define FOD(i,a,b) for (int i = a; i >= (int) b; i--)

using namespace std;

int tc, A, B;
double a, b, c = 10000;
double p[100005];

int main(){
  scanf("%d ",&tc);
  for (int TC = 1; TC <= tc; TC++) {
    scanf("%d %d",&A,&B);
    double probcorrect = 1.0, probwrong = 0.0;
    c = 1e20;
    for (int i = 0; i < A; i++) {
      double d = probcorrect * (A-i+B-i+1);
      if (i == 0) 
        d = A-i+B-i+1;
      else
        d += probwrong * (A-i+B-i+1+B+1);
      //cout << A-i+B-i+1 << ", " << A-i+B-i+1+B+1 << endl;
      c = min(c,d);
      scanf("%lf ",&p[i]);
      probcorrect *= p[i];
      probwrong = 1.0 - probcorrect;
    }
    a = probwrong * (2*B - A + 1) + probcorrect * (B - A + 1);
    if (B == A) {
      b = probcorrect + probwrong * (2*B - A + 1);
    } else {
      b = B+2;
    }
    //cout << probcorrect << endl;
    //cout << a <<" " <<  b << endl;
    printf("Case #%d: %lf\n", TC, min(a,min(b,c)));
  }
  return 0;
}

