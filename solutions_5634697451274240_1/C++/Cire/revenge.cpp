#include <iostream>

using namespace std;

// revenge, 9:22

int main() {
  int T;
  cin >> T;
  for(int t=1; t <= T; t++) {
    string s;
    cin >> s;
    s+='+';
    int x=0;
    for(int i = 0; i < s.length()-1; i++) {
      if (s[i]!=s[i+1])
	x++;
    }
    cout << "Case #" << t << ": " << x << endl;
  }
  return 0;
}
