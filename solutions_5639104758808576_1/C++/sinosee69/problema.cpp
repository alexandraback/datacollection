#include <iostream>
#include <vector>
#include <set>
#include <map>
#include <sstream>
#include <cmath>
#include <cctype>
#include <queue>
using namespace std;

int main() {
  int T;

  cin >> T;
  for(int t = 0; t < T; t++) {
    int s_max;
    string s_max_1;
    cin >> s_max;
    cin >> s_max_1;
    int y = 0;
    int num_people = 0;

    for(int s = 1; s < s_max_1.length(); s++) {
      num_people += (s_max_1[s-1] - '0');
      //int x = s_max_1[s-1] - (s_max_1[s-1] + prev + y); 
      int x = num_people - s;
      if(x < 0) {
        y += abs(x);
        num_people += abs(x);
      }
    }
    cout << "Case #" << t+1 << ": " <<  y << endl; 
  }
}
