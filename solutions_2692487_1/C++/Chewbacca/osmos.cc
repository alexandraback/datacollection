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
typedef unsigned long long u64;
unsigned N;
std::vector<u64> v;

unsigned try_fix(u64 mote, unsigned idx)
{
  while(idx<N) {
    if(mote>v[idx]) {
      mote += v[idx];
      idx++;
    }
    else return std::min(N-idx, 1+try_fix(mote+mote-1,idx));
  }
  return 0;
}


unsigned run_test(void)
{
  u64 A;
  cin >> A >> N;
  v.clear();
  v.reserve(N);
  for(unsigned i=0; i<N; i++) {
    u64 x;
    cin >> x;
    v.push_back(x);
  }
  if(A==1) return N;
  std::sort(v.begin(), v.end());
  return std::min(N, try_fix(A,0));
}





int main(void)
{
  cin >> number_of_test_cases;
  for(test_number=1;
      test_number <= number_of_test_cases;
      test_number ++) 
    std::cout << "Case #" << test_number << ": " 
	      << run_test() << std::endl;
  return 0;
}
    

