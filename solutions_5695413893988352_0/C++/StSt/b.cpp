#include <iostream>
#include <iomanip>

#include <map>
#include <queue>
#include <set>
#include <stack>
#include <unordered_map>
#include <vector>

#include <algorithm>
#include <limits>

#include <cmath>

using namespace std;

bool pattern_match(long n, string s) {
  for (int i = s.size() - 1; i >= 0; i--) {
    char c = (n % 10) + '0';
    n /= 10;
    if (c != s[i] && s[i] != '?')
      return false;
  }
  return true;
}

int main() {

  int T;
  cin >> T;

  for (int t = 1; t <= T; t++) {
    cout << "Case #" << t << ": ";

    string C, J;
    cin >> C >> J;

    int length = C.size();
    int numbers = 0;
    
    switch (length) {
    case 1: numbers = 9; break;
    case 2: numbers = 99; break;
    case 3: numbers = 999; break;
    }


    int min = numeric_limits<int>::max();
    int cmin, jmin;
    
    for (int i = 0; i <= numbers; i++)
      for (int j = 0; j <= numbers; j++) {
  	if (pattern_match(i, C) && pattern_match(j, J) && abs(i - j) < min) {
  	  min = abs(i - j);
  	  cmin = i;
  	  jmin = j;
  	}
      }
	
    cout << setfill('0') << setw(length) << cmin << " " << setfill('0') << setw(length) << jmin << endl;
    
  }
  
  return 0;
}
