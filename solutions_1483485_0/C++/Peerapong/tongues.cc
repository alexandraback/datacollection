#include <sstream>
#include <iostream>

using namespace std;

static char map[] = {'y', 'h', 'e', 's', 'o', 'c', 'v', 'x',
		     'd', 'u', 'i', 'g', 'l', 'b', 'k', 'r',
		     'z', 't', 'n', 'w', 'j', 'p', 'f', 'm',
		     'a', 'q'};

int main(int argc, char **argv) {
  int T;
  string line;
  stringstream ss;

  getline(cin, line);
  ss << line;
  ss >> T;

  for (int i = 1; i <= T; i++) {
    getline(cin, line);
    
    cout << "Case #" << i << ": ";

    for (size_t j = 0; j < line.size(); j++) {
      if (line[j] == ' ') {
	cout << ' ';
      }
      else {
	cout << map[line[j] - 'a'];
      }
    }

    cout << endl;
  }

  return 0;
}
