#include<iostream>
#include<cstdio>

using namespace std;

int main() {
  int ca;
  cin>>ca;
  for(int cas=0 ;cas<ca; ++cas){
    
    double c, f,x, rtn =0;
    double current = 2.0;
    cin>>c>>f>>x;
    while(true) {
      double nof = x/current;
      double far = c/current + x/(current+f);
      if (far < nof) {
        rtn += c/current;
        current+=f;
      } else {
        rtn += nof;
        break;
      }
    }
    printf ("Case #%d: %.7f\n", cas+1, rtn);

  }
}
