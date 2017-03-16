#include <iostream>
#include <vector>
#include <algorithm>
#include <map>
#include <cassert>
using std::cin;
using std::endl;
#ifndef DEBUG
#define DEBUG 2
#endif
#define debug(n) if(n<=DEBUG) std::cerr


unsigned number_of_test_cases, test_number;

double Newton(unsigned N, unsigned p)
{
  if(p>N/2) return Newton(N,N-p);
  double pfact=1;
  for(unsigned i=1; i<=p; i++) {
    pfact *= (N-p+i);
    pfact /= i;
  }
  return pfact;
}

double run_test(void)
{
  int N, X, Y, R, M, P;
  cin >> N >> X >> Y;
  if(X<0) X=-X;
  R = (X+Y)/2;
  M = Y;
  int K = (2*R+1)*(2*R+2)/2;
  if(K<=N) return 1;
  if(  (2*(R-1)+1) * (2*(R-1)+2) /2  >= N) return 0;
  if(X==0) return 0;
  P = N - (2*(R-1)+1) * (2*(R-1)+2) /2;
  debug(5) << "N=" << N 
	   << ", X=" << X
	   << ", Y=" << Y
	   << ", P=" << P 
	   << endl;
  if(P<Y) return 0;
  if(P>=(R+1)+Y+1) return 1;
  double S=0;
  for(unsigned i=Y+1; i<=P; i++) S+=Newton(P,i);
  return S/pow(2,P);
}





int main(void)
{
  cin >> number_of_test_cases;
  std::cout.precision(8);
  for(test_number=1;
      test_number <= number_of_test_cases;
      test_number ++) 
    std::cout << "Case #" << test_number << ": " 
	      << run_test() << std::endl;
  return 0;
}
    

