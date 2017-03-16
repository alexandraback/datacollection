#include "./definitions.h"

struct quat{
  char c='1';
  int sign=1;

  void push(char x){
    if (c=='1'){
      c=x;
      return;
    }

    //////////////////////
    if (c=='i') {
      if (x=='i'){
        c='1';
        sign*=-1;
        return;
      }

      if (x=='j'){
        c='k';
        return;
      }

      if (x=='k'){
        c='j';
        sign*=-1;
        return;
      }
    }

    /////////////
    if (c=='j') {
      if (x=='i'){
        c='k';
        sign*=-1;
        return;
      }

      if (x=='j'){
        c='1';
        sign*=-1;
        return;
      }

      if (x=='k'){
        c='i';
        return;
      }
    }

    /////////////////////
    if (c=='k') {
      if (x=='i'){
        c='j';
        return;
      }

      if (x=='j'){
        c='i';
        sign*=-1;
        return;
      }

      if (x=='k'){
        c='1';
        sign*=-1;
        return;
      }
    }
    /////////
    //cout<<x<<endl;
    throwException("invalid charactor got pushed! %c\n", x);
  }
};

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
    size_t numberOfRepeats=stol(tokens[1]);
    size_t numberOfChars=stol(tokens[0])*numberOfRepeats;
    getline(input, line);
    string spelling("");
    for (size_t repId=0; repId<numberOfRepeats; ++repId)
      spelling.append(line);

    if (numberOfChars<3){
      cout<<"Case #"<<testId+1<<": NO"<<endl;
      continue;
    }

    quat mul;
    string::iterator it;
    for (it=spelling.begin(); it!=spelling.end(); ++it){
      mul.push(*it);
    }

    if (mul.c!='1' || mul.sign!=-1){
      cout<<"Case #"<<testId+1<<": No"<<endl;
      continue;
    }

    string::iterator fit;
    string::iterator sit;
    bool found=false;
    quat first;

    for (fit=spelling.begin(); fit!=spelling.end(); ++fit){
      first.push(*fit);
      if (first.c=='i'){
        quat second;
        for (sit=fit+1; sit!=spelling.end(); ++sit){
          second.push(*sit);
          if (second.c=='j'){
            found =true;
            break;
          }
        }
        if (found) break;
      }
    }
    if (found)
      cout<<"Case #"<<testId+1<<": YES"<<endl;
    else
      cout<<"Case #"<<testId+1<<": NO"<<endl;
  }

}
