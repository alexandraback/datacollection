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

void Solve(std::ifstream& input,std::ofstream& output) {
  std::size_t N;
  
  input>>N;
  
  std::vector<std::string> compactedStrings;
  std::vector<std::vector<std::size_t> > counters;
  
  for (std::size_t index=0;index<N;++index) {
    std::string s;
    
    input>>s;
    
    std::string compactedString;
    std::vector<std::size_t> counter;
    
    compactedString.push_back(s[0]);
    counter.push_back(1);
    
    for (std::size_t index2=1;index2<s.size();++index2)
      if (s[index2]!=s[index2-1]) {
        compactedString+=s[index2];
        counter.push_back(1);
      } else ++counter[counter.size()-1];
    
    compactedStrings.push_back(compactedString);
    counters.push_back(counter);
  }
  
  for (std::size_t index=1;index<compactedStrings.size();++index)
    if (compactedStrings[index]!=compactedStrings[index-1]) {
      output<<"Fegla Won";
      return;
    }
  
  std::size_t result=0;

  for (std::size_t index=0;index<compactedStrings[0].size();++index) {
    std::size_t res=std::numeric_limits<std::size_t>::max();
    
    for (std::size_t candidate=1;candidate<=100;++candidate) {
      std::size_t act=0;
      
      for (std::size_t index2=0;index2<counters.size();++index2)
        act+=static_cast<std::size_t>(std::abs(static_cast<int>(candidate)-static_cast<int>(counters[index2][index])));
      
      if (act<res) res=act;
    }
    
    result+=res;
  }
  
  output<<static_cast<unsigned int>(result);
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