#include <iostream>
#include <string>
using namespace std;

string nw(char c, string s){
  if(c < s[0]){
    return s + c;
  }
  return c + s;
}

int main(){
  int cases; cin >> cases;
  string fin;
  for(int i = 1; i<cases + 1; i++){
    fin = "";
    string s;
    cin >> s;
    for(int j = 0; j<s.length(); j++){
      fin = nw(s[j], fin);
    }
    cout << "Case #" << i << ": " << fin << endl;
  }
  return 0;
}
