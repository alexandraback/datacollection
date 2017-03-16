#include <iostream>
#include <vector>
#include <cstdio>

using namespace std;

double backn(int a, int b, int c, vector<double>& p) {
  double allCorrect = 1;
  for (int i = 0; i < a; ++i)
    allCorrect *= p[i];
  int correctKeys = (b-a) + 1 + c;
  int incorrectKeys = correctKeys + b + 1;
  //cout << correctKeys << " " << incorrectKeys << " " << a << " " << allCorrect << " " << allCorrect * correctKeys + incorrectKeys * (1-allCorrect) << endl;
  return allCorrect * correctKeys + incorrectKeys * (1-allCorrect);
} 

double case2(int a, int b, vector<double>& p) {
  double low = b*2+2;
  for (int i = 0; i <= a; ++i)
    low = min(low,backn(a-i,b,i,p));
  return low;
} 

double case3(int a, int b, vector<double>& p) {
  return b+2;
} 

double tCase() {
  int a,b;
  cin >> a >> b;
  vector<double> p(a);
  for (int i = 0; i < a; ++i)
    cin >> p[i];
  return min(case2(a,b,p),case3(a,b,p));
}

int main() {
  int tCases;
  cin >> tCases;
  for (int t = 1; t <= tCases; ++t) {
    printf("Case #%d: %.6lf\n",t,tCase());
  }
}
