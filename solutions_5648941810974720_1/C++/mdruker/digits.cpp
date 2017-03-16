#include <iostream>
#include <fstream>
#include <cstdlib>
#include <vector>
#include <string>
#include <cmath>
#include <algorithm>
using namespace std;

ifstream in("data.in");
ofstream out("data.out");

vector<int> charUse, digitUse;

void countDigit(int digit, string digitName, char uniqueChar) {
  int n = charUse[uniqueChar - 'A'];
  
  digitUse[digit] = n;

  for (int i=0; i<digitName.size(); i++) {
    charUse[digitName[i]-'A'] -= n;
  }
}

string solve(string s) {
  charUse.clear();
  charUse.resize(26, 0);
  digitUse.clear();
  digitUse.resize(10,0);

  for (int i=0; i<s.size(); i++) {
    charUse[s[i]-'A']++;
  }

  countDigit(0, "ZERO", 'Z');
  countDigit(2, "TWO", 'W');
  countDigit(4, "FOUR", 'U');
  countDigit(6, "SIX", 'X');
  countDigit(8, "EIGHT", 'G');
  countDigit(3, "THREE", 'H');
  countDigit(5, "FIVE", 'F');
  countDigit(7, "SEVEN", 'S');
  countDigit(1, "ONE", 'O');
  countDigit(9, "NINE", 'I');

  string result="";
  for (int i=0; i<10; i++) {
    for (int j=0; j<digitUse[i]; j++) {
      result += char('0' + i);
    }
  }
  return result;
}

int main() {
  int t;
  in >> t;
  for (int caseNum = 1; caseNum <= t; caseNum++) {
    string s;
    in >> s;
    
    out << "Case #" << caseNum << ": " << solve(s) << endl;
  }
}
