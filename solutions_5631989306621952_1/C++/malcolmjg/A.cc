using namespace std;
#include <iostream>

int main(){
  int T;
  cin >> T;
  for (int t=1; t<=T; t++){
    string s;
    cin >> s;
    string out(1,s.at(0));
    for (int i=1; i<s.length(); i++){
      char next = s.at(i);
      if (next >= out.at(0)) out = next + out;
      else out = out + next;
    }
    cout << "Case #" << t << ": " << out << endl;
  }
      
}
