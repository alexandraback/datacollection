#include <iostream>
#include <string>
#include <vector>

using namespace std;

string digits[10] = {"ZERO", "ONE", "TWO", "THREE", "FOUR", "FIVE", "SIX", "SEVEN", "EIGHT", "NINE"};

bool sub(int d, vector<int> & letters)
{
  bool fits = true;
  
  for (char c: digits[d])
    if (--letters[c] < 0)
      fits = false;
  
  return fits;
}

void add(int d, vector<int> & letters)
{
  for (char c: digits[d])
    ++letters[c];
}

bool solve(int d, string & result, vector<int> & letters, int numLetters)
{
  if (numLetters == 0)
    return true;
  
  while (d < 10)
  {
    if (sub(d, letters))
    {
      result.push_back(d + '0');
      if (solve(d, result, letters, numLetters - digits[d].length()))
        return true;
      result.pop_back();
    }
    add(d, letters);
    d++;
  }
  
  return false;
}

int main()
{
  int t;
  cin >> t;
  
  for (int i = 1; i <= t; i++)
  {
    string s;
    cin >> s;
    vector<int> letters('Z' - 'A' + 1, 0);
    for (char c: s)
      letters[c]++;
      
    string result;
    solve(0, result, letters, s.length());
    cout << "Case #" << i << ": " << result;
    cout << endl;
  }
  
  return 0;
}
