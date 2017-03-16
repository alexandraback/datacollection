#include <iostream>

int main()
{
  unsigned number_of_tests;
  std::cin >> number_of_tests;
  std::cout.precision(10);
  for(int test_no=1; test_no<=number_of_tests;
      test_no++) {
    double C,F,X;
    double r=2, t0=0, goal0, goal1;
    unsigned N=0;
    std::cin >> C >> F >> X;
    goal0 = X/r;
    for(;;) {
      goal1 = t0 + C/r + X/(r+F);
      if(goal1>goal0) break;
      t0 += C/r;
      r += F;
      goal0 = goal1;
    }
  std::cout << "Case #" << test_no << ": "
	    << goal0 <<  std::endl;
  }
  return 0;
}
    


