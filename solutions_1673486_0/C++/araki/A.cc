#include <iostream>
#include <vector>
#include <string>
#include <utility>
#include <algorithm>
#include <stdio.h>

using namespace std;

double solve(int a, int b, const vector<double>& prob);

int main(){
  int num_cases;
  cin >> num_cases;
  for(int i = 0; i < num_cases; i++){
    int a, b;
    double probi;
    vector<double> prob;
    cin >> a >> b;
    for(int j = 0; j < a; j++){
      cin >> probi;
      prob.push_back(probi);
    }
    double r = solve(a,b,prob);
    cout << "Case #" << i+1 << ": ";
    printf("%f\n",r);
  }
}

double solve(int a, int b, const vector<double>& prob){
  double keep;
  vector<double> bsn(a);
  double retype;

  double tmp = 1.0;
  for(int i = 0; i < a; i++) tmp*=prob[i];
  keep = tmp*(b-a+1) + (1-tmp)*(2 * b - a + 2);

  for(int i = 0; i < a; i++){
    tmp = 1.0;
    int x = i + 1;
    for(int j = 0; j < a - x; j++) tmp *= prob[j];
    bsn[i] = tmp*(b - a + 2*x + 1) + (1-tmp)*(2*b - a + 2*x + 2);
  }

  retype = b + 2;

  double bsmax = *min_element(bsn.begin(),bsn.end());
  return min(keep,min(bsmax,retype));
}
