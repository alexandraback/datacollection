#include <algorithm>
#include <cmath>
#include <fstream>
#include <iomanip>
#include <iostream>
#include <limits>
#include <map>
#include <queue>
#include <set>
#include <stack>
#include <string>
#include <vector>

unsigned long long int F(std::size_t A,std::size_t B,std::size_t K) {
  std::size_t t=std::max(A,B);
  std::size_t maxBitNumber=0;
  
  while (t>0) {
    t/=2;
    ++maxBitNumber;
  }
  
  if (maxBitNumber==0) return 1;
  
  if ((K>A)||(K>B)) return 0;
  
  if ((K&(1<<(maxBitNumber-1)))==0) {
    unsigned long long int result=0;
    
    if (maxBitNumber==1) {
      if (((A&(1<<(maxBitNumber-1)))!=0)&&((B&(1<<(maxBitNumber-1)))!=0)) {
        result=1;
      } else if ((A&(1<<(maxBitNumber-1)))!=0) {
        result=1;
      } else {
        result=1;
      }    
    } else {
      if (((A&(1<<(maxBitNumber-1)))!=0)&&((B&(1<<(maxBitNumber-1)))!=0)) {
        result+=F((A-(1<<(maxBitNumber-1)))|(1<<(maxBitNumber-2)),(B-(1<<(maxBitNumber-1)))|(1<<(maxBitNumber-2)),K);
        result+=F(A-(1<<(maxBitNumber-1)),(B-(1<<(maxBitNumber-1)))|(1<<(maxBitNumber-2)),K);
        result+=F((A-(1<<(maxBitNumber-1)))|(1<<(maxBitNumber-2)),B-(1<<(maxBitNumber-1)),K);
      } else if ((A&(1<<(maxBitNumber-1)))!=0) {
        result+=F((A-(1<<(maxBitNumber-1)))|(1<<(maxBitNumber-2)),B|(1<<(maxBitNumber-2)),K);
        result+=F(A-(1<<(maxBitNumber-1)),B|(1<<(maxBitNumber-2)),K);
      } else {
        result+=F(A|(1<<(maxBitNumber-2)),(B-(1<<(maxBitNumber-1)))|(1<<(maxBitNumber-2)),K);
        result+=F(A|(1<<(maxBitNumber-2)),B-(1<<(maxBitNumber-1)),K);
      }    
    }
    
    return result;
  } else {
    unsigned long long int result=0;
    
    if (maxBitNumber==1) return 3;
    
    result+=F(A-(1<<(maxBitNumber-1)),B-(1<<(maxBitNumber-1)),K-(1<<(maxBitNumber-1)));
    result+=F((A-(1<<(maxBitNumber-1)))|(1<<(maxBitNumber-2)),B-(1<<(maxBitNumber-1)),K-(1<<(maxBitNumber-1)));
    result+=F(A-(1<<(maxBitNumber-1)),(B-(1<<(maxBitNumber-1)))|(1<<(maxBitNumber-2)),K-(1<<(maxBitNumber-1)));
    result+=F((A-(1<<(maxBitNumber-1)))|(1<<(maxBitNumber-2)),(B-(1<<(maxBitNumber-1)))|(1<<(maxBitNumber-2)),K-(1<<(maxBitNumber-1)));
    return result;
  }
}

void Solve(std::ifstream& input,std::ofstream& output) {
  std::size_t A,B,K;
  
  input>>A>>B>>K;
  
  unsigned long long int result=0;
  
  for (std::size_t a=0;a<A;++a)
    for (std::size_t b=0;b<B;++b)
      if ((a&b)<K) ++result;
  
  //output<<F(A,B,K-1);
  output<<result;
}

void main() {
  std::ifstream input("Input.Txt");
  std::ofstream output("Output.Txt");
  int testCases;
  
  input>>testCases;
  
  for (int testCase=1;testCase<=testCases;++testCase) {
    output<<"Case #"<<testCase<<": ";
    Solve(input,output);
    output<<std::endl;
  }
}