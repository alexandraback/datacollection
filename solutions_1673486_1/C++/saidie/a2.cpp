#include <iostream>
#include <cstdio>

using namespace std;

const int N = 99999;

int a, b;
double p[N];

int main(void){
  int t;
  cin >> t;
  for(int k = 0; k < t ; ++k){
    cin >> a >> b;
    for(int i = 0; i < a; ++i)
      cin >> p[i];

    double ans = b + 2;
    double correct = 1;
    for(int i = 1; i <= a; ++i){
      correct *= p[i-1];
      ans = min(ans, correct * (b - i + 1) + (1 - correct) * ((b - i) + 1 + b + 1) + a - i);
    }

    printf("Case #%d: %.6lf\n", k+1, ans);
  }

  return 0;
}
