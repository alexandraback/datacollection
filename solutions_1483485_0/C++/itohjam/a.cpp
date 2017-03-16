#include <iostream>
#include <cstdio>
using namespace std;

int main(){
  string s, op = "yhesocvxduiglbkrztnwjpfmaq";
  int T;
  cin >> T;
  getline(cin, s);

  for(int SET = 1; SET <= T; SET++){
    printf("Case #%d: ", SET);
    getline(cin, s);
    for(int i = 0; i < s.length(); i++){
      if(s[i] == ' ') continue;
      s[i] = op[s[i] - 'a'];
    }
    cout << s << endl;
  }
}
