#include <vector>
#include <string>
#include <iostream>
using namespace std;

int main() {
  int tests;
  cin >> tests;
  for(int i = 0; i < tests; i++) {
    int maxShy;
    cin >> maxShy;
    string counts;
    cin >> counts;
    int peopleClapping = 0;
    int ret = 0;
//    cout << counts << endl;
    for(int j = 0; j < counts.size(); j++) {
      if(counts[j] > '0' && j > peopleClapping) {
        ret += j - peopleClapping;
        peopleClapping = j + counts[j]-'0';
      }
      else {
        peopleClapping += counts[j]-'0';
      }
//      cout << j << " " << peopleClapping << " " << ret << endl;
    }
    cout << "Case #" << (i+1) << ": " << ret << endl;
  }
  return 0;
}
