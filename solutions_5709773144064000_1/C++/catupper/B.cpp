#include<iostream>
#include<cstdio>
#include<algorithm>

using namespace std;

double solve(double c, double f, double x){
  double cps = 2;
  double res = 123456745;
  double base = 0;
  for(int i = 0;base < res;i++){
    res = min(res, base + x / cps);
    base = base + c / cps;
    cps += f;
  }
  return res;
}

int main(){
  int t;
  double c, f, x;
  cin >> t;
  for(int i = 1;i <= t;i++){
    cin >> c >> f >> x;
    cout << "Case #" << i << ": ";
    printf("%.7lf\n", solve(c, f, x));
  }
  return 0;
}
