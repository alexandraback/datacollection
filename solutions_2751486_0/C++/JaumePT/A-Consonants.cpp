#include <iostream>
#include <string>
using namespace std;

bool is_vowel(char c) {
  return c == 'a' or c == 'e' or c == 'i' or c == 'o' or c == 'u';
}

int main() {
  int T;
  cin >> T;
  for (int cas = 1; cas <= T; ++cas) {
    string name;
    int L, n;
    cin >> name >> n;
    L = name.size();
    int count = 0;
    int ini = 0;
    while (ini <= L - n) {
      //cerr << "bucle OUT" << endl;
      int i = ini, j = ini, cons = 0;
      while (j < L and cons < n) {
        //cerr << "bucle IN" << endl;
        if (is_vowel(name[j])) {
          cons = 0;
          i = j + 1;
        }
        else {
          ++cons;
        }
        ++j;
      }
      if (cons == n) count += (i-ini+1)*(L-j+1);
      ini = i+1;
    }
    cout << "Case #" << cas << ": " << count << endl;
  }
}
