#include <iostream>

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

int main() {

  int T;
  cin >> T;

  vector<string> numbers = {"ZERO", "ONE", "TWO", "THREE", "FOUR", "FIVE", "SIX", "SEVEN", "EIGHT", "NINE"};
  
  vector<char> first_round = {'Z', 'W', 'U', 'X', 'G'};
  unordered_map<char, int> first_identified_as;
  first_identified_as['Z'] = 0;
  first_identified_as['W'] = 2;
  first_identified_as['U'] = 4;
  first_identified_as['X'] = 6;
  first_identified_as['G'] = 8;
  
  vector<char> second_round = {'O', 'H', 'F', 'S'};
  unordered_map<char, int> second_identified_as;
  second_identified_as['O'] = 1;
  second_identified_as['H'] = 3;
  second_identified_as['F'] = 5;
  second_identified_as['S'] = 7;
  
  for (int t = 1; t <= T; t++) {
    cout << "Case #" << t << ": ";

    string S;
    cin >> S;
    
    unordered_map<char, int> count;
    for (char & c : S)
      count[c]++;

    
    vector<int> telephone_number;

    for (char & fr : first_round) {
      if (count[fr] > 0) {
	int times = count[fr];
	for (int i = 0; i < times; i++)
	  telephone_number.push_back(first_identified_as[fr]);
	for (char & c : numbers[first_identified_as[fr]])
	  count[c] -= times;
      }
    }

    for (char & sr : second_round) {
      if (count[sr] > 0) {
	int times = count[sr];
	for (int i = 0; i < times; i++)
	  telephone_number.push_back(second_identified_as[sr]);
	for (char & c : numbers[second_identified_as[sr]])
	  count[c] -= times;
      }
    }

    for (int i = 0; i < count['E']; i++)
      telephone_number.push_back(9);

    sort(telephone_number.begin(), telephone_number.end());

    for (int & i : telephone_number)
      cout << i;
    cout << endl;
        
  }
  
  return 0;
}
