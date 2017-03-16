#include <iostream>
#include <string>

using namespace std;

int main()
{
  char code[26] = { 'y', 'h', 'e', 's', 'o', 'c', 'v', 'x', 'd', 'u', 'i', 'g', 'l', 'b', 'k', 'r', 'z', 't', 'n', 'w', 'j', 'p', 'f', 'm', 'a', 'q' };
  
  int T;
  cin >> T;
  string line;
  getline(cin, line);

  for (int t = 0; t != T; ++t) {
    getline(cin, line);
    cout << "Case #" << t + 1 << ": ";
    for (int c = 0; c != line.length(); ++c) {
      if (line[c] == ' ') {
	cout << ' ';
      } else {
	cout << code[line[c] - 'a'];
      }
    }
    cout << endl;
  }
  return 0;
}
