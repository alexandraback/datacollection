#include <sstream>
#include <fstream>
#include <iostream>
#include <string>

using std::ofstream;
using std::ifstream;
using std::cout;
using std::endl;
using std::string;

char multiply (char a, char b, bool& positive){
  if (a == '1'){
    return b;
  }
  if (b == '1'){
    return a;
  }
  if (a == b){
    positive = !positive;
    return '1';
  }
  switch(a){
  case 'i':
    switch(b){
    case 'j':
      return 'k';
    case 'k':
      positive = !positive;
      return 'j';
    }
  case 'j':
    switch(b){
    case 'i':
      positive = !positive;
      return 'k';
    case 'k':
      return 'i';
    }
  case 'k':
    switch(b){
    case 'i':
      return 'j';
    case 'j':
      positive = !positive;
      return 'i';
    }
  default:
    return 'f';
  }
}

string chop(string s, bool& pos){
  for(unsigned long i = 0; i < s.length()-1 && s.length() > 0; ++i){
    if(s.at(i) == s.at(i+1)){
      pos = !pos;
      s = s.substr(0,i)+s.substr(i+2, s.length()-i-1);
      i-=1;
    }
  }
  return s;
}

bool isSingle(string s){
  if (s.length() == 0){
    return true;
  }
  char c = s.at(0);
  for (unsigned long i = 0; i < s.length(); i++){
    if (c != s.at(i)){
      return false;
    }
  }
  return true;

}

string manageInput(int length, int copies, ifstream& inFile){
  std::ostringstream oss;
  char c;
  string s1;
  string result = "";
  bool pos = true;
  for(int i = 0; i < length; ++i){
    inFile >> c;
    oss << c;
  }
  s1 = oss.str();
  cout << s1 << endl;
  if(isSingle(s1)){
    cout << "i"<<endl;
    return "i";
  }
  for(int i = 0; i < copies; ++i){
    result += s1;
  }
  cout << "result"<<endl;
  return result;
}

char evaluate(string s, bool& pos){
  char product = '1';
  while (s.length() > 0){
    char s1 = s.at(0);
    s = s.substr(1, s.length()-1);
    product = multiply(product, s1, pos);
  }
  return product;
}

bool partition(string s, int length){
  
  string s1;
  string s2;
  string s3;
  bool pos = true;
  if(evaluate(s, pos) == '1' && !pos){
    pos = true;
    for(int i = 1; i < length-1; i++){
      s1 = s.substr(0, i); 
      cout << s1 << endl;
      if(evaluate(s1, pos) == 'i' && pos){
	for(int j = i+1; j<length; j++){
	  
	  s2 = s.substr(i, j-i);
	  s3 = s.substr(j, length-j);
	  cout << s1 << " " << s2 << " " << s3 << endl;
	  if(evaluate(s2, pos)== 'j' && pos){
	    if(evaluate(s3, pos)=='k' && pos){
	      return true;
	    }
	    pos = true;
	    continue;
	  }
	  pos = true;
	  continue;
	}
      }
      else{
	pos = true;
	continue;
      }
    }
    return false;
  }
  return false;
}

int main(){
  int cases = 0;
  string s1;
  int length = 0;
  int copies = 0;
  ifstream inFile("C-small-attempt5.in");
  ofstream outFile("output2.txt");
  bool possible;
  
  inFile >> cases;

  for (int i = 1; i <= cases; ++i){

    inFile >> length;
    inFile >> copies; 

    s1 = manageInput(length, copies, inFile);
    possible = partition(s1, length*copies);
    if (possible){
      outFile << "Case #" << i << ": " << "YES" <<endl;
    }
    else{
      outFile << "Case #" << i << ": " << "NO" <<endl;
    }
  }
  cout << isSingle("aaaaaaaaaa");
  outFile.close();
  return 0;
}
