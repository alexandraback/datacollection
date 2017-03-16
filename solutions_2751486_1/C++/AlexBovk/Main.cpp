#include <fstream>
#include <string>
#include <vector>

bool IsConsonant(char c) {
  return !((c=='a')||(c=='e')||(c=='i')||(c=='o')||(c=='u'));
}

void SolveTask(std::ifstream& input,std::ofstream& output) {
  std::string name;
  int n;
  long long int result=0;
  
  input>>name>>n;
  
  int counter=0;
  int firstConsonant=0;
  int start=-1;
  
  for (size_t index=0;index<name.length();++index) {
    if (IsConsonant(name[index])) {
      ++counter;
      if (counter==1) firstConsonant=static_cast<int>(index);
      if (counter==n) {
        result+=(static_cast<long long int>(index)-static_cast<long long int>(counter)-static_cast<long long int>(start)+1)*(static_cast<long long int>(name.length())-static_cast<long long int>(index));
        start=firstConsonant++;
        --counter;
      }
    } else {
      counter=0;
    }
  }
  
  output<<result;
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