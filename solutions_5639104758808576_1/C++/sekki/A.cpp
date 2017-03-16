#include <iostream>
#include <sstream>

using namespace std;

int main() {

  int ncases;
  cin >> ncases;

  for (int i = 0; i < ncases; i++) {
    long long max_shyness;
    string str;

    cin >> max_shyness;
    cin >> str;
    stringstream ss(str);
    
    char c;
    long long standing = 0;
    long long cur_shyness = 0;
    long long extras = 0;
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
