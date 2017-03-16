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
    unsigned ominoSize=stol(tokens[0]);
    unsigned rows=stol(tokens[1]);
    unsigned cols=stol(tokens[2]);

    if (ominoSize==1){
      cout<<"Case #"<<testId+1<<": GABRIEL"<<endl;
      continue;
    }

    if (ominoSize==2){
      if (rows*cols % 2 == 0)
        cout<<"Case #"<<testId+1<<": GABRIEL"<<endl;
      else
        cout<<"Case #"<<testId+1<<": RICHARD"<<endl;
      continue;
    }

    if (ominoSize==3){
      if (rows*cols % 3 !=0){
        cout<<"Case #"<<testId+1<<": RICHARD"<<endl;
        continue;
      }

      if (rows == 1 || cols ==1){
        cout<<"Case #"<<testId+1<<": RICHARD"<<endl;
        continue;
      }
      cout<<"Case #"<<testId+1<<": GABRIEL"<<endl;
      continue;
    }

    if (ominoSize==4){
      if (rows*cols % 4 !=0){
        cout<<"Case #"<<testId+1<<": RICHARD"<<endl;
        continue;
      }

      if (rows <= 2 || cols <=2){
        cout<<"Case #"<<testId+1<<": RICHARD"<<endl;
        continue;
      }

      cout<<"Case #"<<testId+1<<": GABRIEL"<<endl;
      continue;
    }

  }
}
