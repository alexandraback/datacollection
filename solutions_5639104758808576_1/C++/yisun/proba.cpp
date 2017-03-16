#include <cmath>
#include <string>
#include <iostream>
#include <fstream>
#include <vector>
#include <set>
#include <sstream>
#include <iostream>
using namespace std;

fstream in, out;

int T;
int s_max;

vector<int> digits;

int main() {
  in.open("A-large.in", fstream::in);
  out.open("proba-small.out", fstream::out);

  in >> T;
  for (int i = 0; i < T; i++) {
    in >> s_max;
    digits = vector<int>(s_max + 1);
    char temp = in.get();
    for (int j = 0; j < s_max + 1; ++j) {
      temp = in.get();
      digits[j] = ((int)temp - (int)'0');
    }    

    int count = 0;
    int added = 0;
    for (int k = 0; k < s_max + 1; ++k) {
      if (count < k) {
	added += k - count;
	count += k - count;
      }
      count += digits[k];
    }
    out << "Case #" << i + 1 << ": " << added << endl;
  }
    
  in.close();
  out.close();
  return 0;
}
