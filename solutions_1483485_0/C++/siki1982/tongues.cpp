#include <iostream>
#include <iomanip>
#include <sstream>
#include <cmath>
#include <algorithm>
#include <map>
#include <vector>
#include <set>
#include <string>



using namespace std;

#define PI acos(-1.)
#define EPS 1e-7
#define LL long long
#define uint32_t unsigned int



int main() {
  string from = "ejp mysljylc kd kxveddknmc re jsicpdrysirbcpc ypc rtcsra dkh wyfrepkym veddknkmkrkcdde kr kd eoya kw aej tysr re ujdr lkgc jv";
  string to = "our language is impossible to understandthere are twenty six factorial possibilitiesso it is okay if you want to just give up";

  map<char, char> dict;
  dict['a'] = 'y';
  dict['o'] = 'e';
  dict['z'] = 'q';
  dict['q'] = 'z';
  for (size_t i = 0; i < from.length(); ++i) {
    dict[from[i]] = to[i];
  }

  // Declare members
  uint32_t num_case;
  cin >> num_case;

  string line;
  getline(cin, line);
  for (uint32_t j = 1; j <= num_case; j++) {
    // Init members
    getline(cin, line);
    for (uint32_t i = 0; i < line.length(); ++i) {
      line[i] = dict[line[i]];
    }

    // Print output for case j
    cout << "Case #" << j << ": " << line << endl;
  }


  return 0;
}
