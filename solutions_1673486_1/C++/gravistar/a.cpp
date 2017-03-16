#include <iostream>
#include <vector>
#include <fstream>
using namespace std;

const int UB = 100000;

double base_probs[UB+10];
double probs[UB+10];
double cums[UB+10];
double ev[UB+10];

int main(){

  ifstream in;
  in.open("a.in");
  ofstream out;
  
  out.open("a.out");

  int T;
  in >> T;
  for(int tt=1; tt<=T; tt++){
    int A,B;
    in >> A >> B;
    for(int i=1; i<=A; i++)
      in >> base_probs[i];
      
    double all_right = 1.0;
    for(int i=1; i<=A; i++)
      all_right *= base_probs[i];
    
    double best = B + 2;
    
    for(int i=1; i<=A; i++){
      probs[i] = 1.0;
      for(int j=1; j<i; j++)
          probs[i] *= base_probs[j];
      probs[i] *= 1.0-base_probs[i];
    }

    cums[1] = probs[1];    
    for(int i=2; i<=A; i++)
      cums[i] = probs[i] + cums[i-1];
    
    
    double no_bs = (1.0-all_right)*(B-A+B+2) + all_right*(B-A+1);;

    best = min(best, no_bs);
    // backspace
    for(int i=1; i<=A; i++){
      double val = 0;
      val = cums[i]*(B-A+2.0*(A-i)+B+2) + (1.0-cums[i])*(B-A + 2.0*(A-i) + 1);
      best = min(best,val);
    }
    printf("Case #%d: %.06f\n", tt, best);
    
  }
}


