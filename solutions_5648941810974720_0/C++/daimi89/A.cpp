#include <iostream>
#include <string>
#include <vector>

using namespace std;

int main() {
  int T;
  cin >> T;
  for (int x=1; x<=T; x++) {
    string S;
    cin >> S;
    vector<int> digits(10);
    vector<int> fq(256,0);
    for (int i=0; i<S.length(); i++) fq[(char)S[i]]++;

    digits[0] = fq['Z'];
    digits[2] = fq['W'];
    digits[4] = fq['U'];
    digits[5] = fq['F'] - digits[4];
    digits[6] = fq['X'];
    digits[7] = fq['S'] - digits[6];
    digits[8] = fq['G'];
    digits[9] = fq['I'] - digits[5] - digits[6] - digits[8];
    digits[1] = fq['O'] - digits[0] - digits[2] - digits[4];
    digits[3] = fq['H'] - digits[8];
    
    cout << "Case #" << x << ": ";
    for (int i=0; i<10; i++)
      while (digits[i]--) cout << i;
    cout << endl;
  };
  return 0;
};
