#include "./definitions.h"

int main(int argc, char* argv[]){
  string filename=argv[1];

  ifstream input;
  input.open(filename);
  if (!input.is_open()){
    throwException("file cannot be opened!");
  }

  string line;
  getline(input, line);
  size_t numberOfTests=atoi(line.c_str());

  for (size_t testId=0; testId<numberOfTests; ++testId){
    getline(input, line);
    vector<string> tokens=tokenize(line, " ", TrimStyle::Trim);
    unsigned Smax=stol(tokens[0]);

    vector<unsigned> numberOfPeopleInLevel;
    for (size_t pplId=0; pplId<Smax+1; ++pplId)
      numberOfPeopleInLevel.push_back(int(tokens[1].at(pplId))-int('0'));
    //cout<<Smax<<" ";
    //for (size_t pplId=0; pplId<numberOfPeopleInLevel.size(); ++pplId)
    //cout<<numberOfPeopleInLevel[pplId]<<" ";
    //cout<<endl;
    unsigned numberOfPeopleNeeded=0;
    unsigned numberOfPeopleClapped=0;

    for (size_t levelId=0; levelId<=Smax; ++levelId){
      if (numberOfPeopleClapped<levelId){
        size_t numberOfAddedPeople=levelId-numberOfPeopleClapped;
        numberOfPeopleNeeded+=numberOfAddedPeople;
        numberOfPeopleClapped+=numberOfAddedPeople;
      }
      numberOfPeopleClapped+=numberOfPeopleInLevel[levelId];
    }
    cout<<"Case #"<<testId+1<<": "<<numberOfPeopleNeeded<<endl;

  }

}
