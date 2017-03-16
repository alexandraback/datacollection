/**
 * 

5
-
-+
+-
+++
--+-

Case #1: 1
Case #2: 1
Case #3: 2
Case #4: 0
Case #5: 3


 */

#include <iostream>
#include <stack>
#include <vector>
#include <string>
using namespace std;
/**
 * 

++---+--+++--+-+-

from the last one, for the first -, count how many flips

flip+1 is the total

 */
void solve(std::string line) {
  int flipcount=0;
  char current='+';
  for (int i=line.size()-1;i>=0;i--) {
    if (line[i] != current) {
      current = line[i];
      flipcount++;
    }
  }
  cout << flipcount;
}


int main() {
  int T;
  cin >> T;
  std::string line;
  getline(cin, line);
  for (int i=0;i<T;i++) {
    std::string line;
    getline(cin, line);
    cout << "Case #" << i+1 << ": ";
    solve(line);
    cout  << "\n";
  }
}
