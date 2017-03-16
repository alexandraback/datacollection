#include <fstream>
#include <string>
#include <vector>

bool IsConsonant(char c) {
  return !((c=='a')||(c=='e')||(c=='i')||(c=='o')||(c=='u'));
}

void SolveTask(std::ifstream& input,std::ofstream& output) {
  std::string name;
  int n;
  int result=0;
  
  input>>name>>n;
  
  int counter=0;
  int firstConsonant=0;
  int start=-1;
  
  for (size_t index=0;index<name.length();++index) {
    if (IsConsonant(name[index])) {
      ++counter;
      if (counter==1) firstConsonant=static_cast<int>(index);
      if (counter==n) {
        result+=(static_cast<int>(index)-counter-start+1)*(static_cast<int>(name.length())-static_cast<int>(index));
        start=firstConsonant++;
        --counter;
      }
    } else {
      counter=0;
    }
  }
  
  output<<static_cast<unsigned int>(result);
}

void main() {
  std::ifstream input("Input.Txt");
  std::ofstream output("Output.Txt");
  
  int numberOfCases;  
  input>>numberOfCases;
  
  for (int caseNumber=1;caseNumber<=numberOfCases;++caseNumber) {
    output<<"Case #"<<caseNumber<<": ";
    SolveTask(input,output);
    output<<std::endl;
  }
}