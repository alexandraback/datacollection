#include <vector>
#include <string>
#include <iostream>
using namespace std;

string doit(string s) {
  string ret="";
  for(int i=0;i<s.size();i++) {
    string val1=ret+s[i];
    string val2=s[i]+ret;
    if(val1<val2) ret=val2;
    else ret=val1;
  }
  return ret;
}

int main() {
  int tests;
  cin>>tests;
  for(int i=0;i<tests;i++) {
    string s;
    cin>>s;
    string t=doit(s);
    cout<<"Case #"<<(i+1)<<": "<<t<<endl;
  }
  return 0;
}
