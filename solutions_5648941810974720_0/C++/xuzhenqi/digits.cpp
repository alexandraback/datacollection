#include<vector>
#include<string>
#include<iostream>
using namespace std;

void getCount(string &s, vector<int> &count) {
  for(int i = 0; i < count.size(); ++i)
    count[i] = 0;
  for(int i = 0; i < s.size(); ++i) {
    ++count[s[i] - 'A'];
  }
  /*
  for(int i = 0; i < count.size(); ++i) {
    cout << char(i + 'A') << ": " << count[i] << ", ";
  }
    cout << endl;
*/
}

void getOutcome(vector<int> &count, vector<int>& outcome) {
  outcome[0] = count['Z' - 'A'];
  count['Z' - 'A'] -= outcome[0];
  count['E' - 'A'] -= outcome[0];
  count['R' - 'A'] -= outcome[0];
  count['O' - 'A'] -= outcome[0];
  outcome[2] = count['W' - 'A'];
  count['T' - 'A'] -= outcome[2];
  count['W' - 'A'] -= outcome[2];
  count['O' - 'A'] -= outcome[2];
  outcome[4] = count['U' - 'A'];
  count['F' - 'A'] -= outcome[4];
  count['O' - 'A'] -= outcome[4];
  count['U' - 'A'] -= outcome[4];
  count['R' - 'A'] -= outcome[4];
  outcome[6] = count['X' - 'A'];
  count['S' - 'A'] -= outcome[6];
  count['I' - 'A'] -= outcome[6];
  count['X' - 'A'] -= outcome[6];
  outcome[8] = count['G' - 'A'];
  count['E' - 'A'] -= outcome[8];
  count['I' - 'A'] -= outcome[8];
  count['G' - 'A'] -= outcome[8];
  count['H' - 'A'] -= outcome[8];
  count['T' - 'A'] -= outcome[8];
  outcome[1] = count['O' - 'A'];
  count['O' - 'A'] -= outcome[1];
  count['N' - 'A'] -= outcome[1];
  count['E' - 'A'] -= outcome[1];
  outcome[3] = count['R' - 'A'];
  count['T' - 'A'] -= outcome[3];
  count['H' - 'A'] -= outcome[3];
  count['R' - 'A'] -= outcome[3];
  count['E' - 'A'] -= outcome[3];
  count['E' - 'A'] -= outcome[3];
  outcome[5] = count['F' - 'A'];
  count['F' - 'A'] -= outcome[5];
  count['I' - 'A'] -= outcome[5];
  count['V' - 'A'] -= outcome[5];
  count['E' - 'A'] -= outcome[5];
  outcome[7] = count['S' - 'A'];
  count['S' - 'A'] -= outcome[7];
  count['E' - 'A'] -= outcome[7];
  count['V' - 'A'] -= outcome[7];
  count['E' - 'A'] -= outcome[7];
  count['N' - 'A'] -= outcome[7];
  outcome[9] = count['I' - 'A'];
}


void display(vector<int> &outcome) {
  for(int i = 0; i < 10; ++i) {
    for(int j=0; j < outcome[i]; ++j) {
      cout << i;
    }
  }
}

int main() {
  int T;
  cin >> T;
  string s;
  vector<int> count(26, 0);
  vector<int> outcome(10, 0);
  for(int i = 1; i <= T; ++i) {
    cin >> s;
    getCount(s, count);
    getOutcome(count, outcome);
    cout << "Case #" << i << ": "; display(outcome); cout << endl;
  }
  return 0;
}
