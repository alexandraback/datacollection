#include <iostream>
#include <sstream>

using namespace std;

int main() {

  int ncases;
  cin >> ncases;

  for (int i = 0; i < ncases; i++) {
    int max_shyness;
    string str;

    cin >> max_shyness;
    cin >> str;
    stringstream ss(str);
    
    char c;
    int standing = 0;
    int cur_shyness = 0;
    int extras = 0;
    while (ss.get(c)) {
      int n = c - '0';
      if (standing + extras < cur_shyness) {
        extras = cur_shyness - standing;
      }
      standing += n;
      cur_shyness++;
    }

    cout << "Case #" << i+1 << ": " << extras << endl;
  }
  
  return 0;
}
