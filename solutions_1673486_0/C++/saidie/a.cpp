#include <iostream>
#include <cstdio>

using namespace std;

const int N = 99999;

int a, b;
double p[N];

double complete(int pos){
  double correct = 1;
  for(int i = 0; i < pos; ++i)
    correct *= p[i];
  return correct * (b - pos + 1) + (1 - correct) * ((b - pos) + 1 + b + 1);
}

int main(void){
  int t;
  cin >> t;
  for(int k = 0; k < t ; ++k){
    cin >> a >> b;
    for(int i = 0; i < a; ++i)
      cin >> p[i];

    double ans = b + 2;
    for(int i = 1; i <= a; ++i){
      ans = min(ans, complete(i) + a - i);
    }

    printf("Case #%d: %.6lf\n", k+1, ans);
  }

  return 0;
}
