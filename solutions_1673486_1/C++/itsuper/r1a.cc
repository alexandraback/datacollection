#include <iostream>
#include <cmath>
#include <string>
#include <cstring>
#include <fstream>
using namespace std;

double sum[100036];
double p[100036];
std::ifstream input;

std:: ofstream output;
void Work(int tcase) {
  int a,b;
  input>>a>>b;
  sum[0] = 0;
  int i ;
  for (i = 1;i<= a;++i) {
    input>>p[i];
    sum[i] = sum[i-1]+log(p[i]);
  }
  
  //First keep typing
  double best = 0,res;
  double tmp = exp(sum[a]);
  best = ((b- a)+1)* tmp + ((b-a) +1+ b+1)*(1-tmp);
  //backspace i times
  for (i = 1; i<a;++i) {
    tmp = exp(sum[a-i]);
    res = (i* 2 + b - a + 1) * tmp + (i * 2 + b - a + 1 + b + 1)*(1-tmp);
    if (res < best) best = res;
  }
  //i == a
  res = a + b + 1;
  if (res < best) best = res;
  //enter right now
  tmp = exp(sum[a]);
  if ( a == b) {    
    res = tmp * 1 + (b + 1)* (1 - tmp);
    if (res < best) best = res;
  } else {
    res = (1 + b+1);
    if (res < best) best =res;
  }
  output.precision(8);
  //best = 1.0000001;
  output<<"Case #"<<tcase<<": "<<best<<endl;
  
}

int main() {
  int t = 0;
  input.open("input.in");
  output.open("output.out");
  input>>t;
  int tcase = 0;
  while (t --) {
    ++tcase;
    Work(tcase);
  }
}
