#include <iostream>
#include <algorithm>
#include <vector>
#include <string>

using namespace std;

int c = 0;

string getNew(string old){

  bool p = false;
  bool m = false;
  int i;
  for(i=0; i< old.length(); i++){
    if(old[i] == '-') m = true;
    if(old[i] == '+'){
      if(m) break;
      else p=true;
    }
  }
  if(p & m) c += 2;
  else if(m) c += 1;
  
  if(i == old.length()) return "";

  string s = old.substr(i, old.length() - i);
  //cout << "s:" << s << endl;
  reverse(s.begin(), s.end());
  for(i=0; i<s.length(); i++){
    if(s[i] == '+') s[i] = '-';
    else s[i] = '+';
  }
  return s;
}

int main(){

  int T;
  cin >> T;
  for(int i=0; i< T; i++){
    string s;
    cin >> s;
    c = 0;
    int j;
    
    for(j=s.length() - 1; j>=0; j--){
      if(s[j] == '-') break;
    }

    s = s.substr(0,j + 1);
    //cout << s << endl;
    while(s.compare("") != 0){
      s = getNew(s);
      //cout << s << " " << c <<  endl;
    }
    
    cout << "Case #" << (i+1) << ": " << c << endl;
    
  }

}
