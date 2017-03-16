#include <vector>
#include <iostream>
#include <set>
#include <algorithm>
#include <map>

using namespace std;

string names[10] = {"ZERO", "ONE", "TWO", "THREE", "FOUR", "FIVE", "SIX", "SEVEN", "EIGHT", "NINE"};
  
int main() {
  int n;
  cin >> n;


  auto solve = [](string s) -> string {
    map<char, int> ch_map;
    for (auto c : s)
      ++ch_map[c];

    int counts[10] = {0};
    auto dec_counts = [&](int d, char ch) {
      counts[d] = ch_map[ch];
      for (auto c : names[d])
	ch_map[c] -= counts[d];
    };

    dec_counts(8, 'G');
    dec_counts(3, 'H');
    dec_counts(6, 'X');
    dec_counts(0, 'Z');
    dec_counts(2, 'W');
    dec_counts(4, 'U');
    dec_counts(5, 'F');
    dec_counts(7, 'S');
    dec_counts(9, 'I');
    dec_counts(1, 'E');
    
    string res;
    for (int i = 0; i < 10; ++i) {
      for (int x = 0; x < counts[i]; ++x)
	res += ('0' + i);
    }
    return res;
  };
  
  for (int i = 1; i <= n; ++i) {
    string input;
    cin >> input;
    
    cout << "Case #" << i << ": " << solve(input) << "\n";
  }
}
