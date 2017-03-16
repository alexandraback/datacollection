using namespace std;
#include <iostream>

int main(){
  int T;
  cin >> T;
  for (int t=1; t<=T; t++){
    string s;
    cin >> s;
    int flips = 0;
    int len = s.length();
    for (int i=1; i<len; i++)
      if (s.at(i) != s.at(i-1)) flips++;
    if (s.at(len-1) == '-') flips++;
    cout << "Case #" << t << ": " << flips << endl;
  }
}


