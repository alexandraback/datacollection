#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <cassert>

using namespace std;

bool isPossible(string& s1, string& s2, vector<int>& v1, vector<int>& v2)
{
  v1.clear();
  v2.clear();
  char c = s1[0];
  v1.push_back(1);
  string s(1,c);
  for(int i = 1; i < s1.size(); ++i) {
    if (s1[i] != c) {
      s.push_back(s1[i]);
      v1.push_back(1);
      c = s1[i];
    }
    else {
      v1.back()++;
    }
  }
  c = s2[0];
  v2.push_back(1);
  int j = 0;
  if ( c != s[0] ) {
    return 0;
  }
  for (int i = 1; i < s2.size(); ++i) {
    if ( s2[i] != c ) {
      ++j;
      c = s2[i];
      v2.push_back(1);
      if ( c != s[j] )
        return 0;
    }
    else {
      v2.back()++;
    }
  }
  if ( j != s.size() - 1 )
    return 0;
  return 1;
}

int dist(vector<int> v1, vector<int> v2)
{
  assert(v1.size() == v2.size());
  int total = 0;
  for (int i = 0; i < v1.size(); ++i)
    total += abs(v1[i] - v2[i]);
  return total;
}

int main()
{
  int T;
  cin >> T;
  for (int C = 1; C <= T; ++C) {
    int N;
    cin >> N;
    string s1, s2;
    vector<int> v1, v2;
    cin >> s1 >> s2;
    cout << "Case #" << C << ": ";
    if ( isPossible(s1,s2, v1, v2) ) {
      cout << dist(v1,v2) << endl;
    }
    else {
      cout << "Fegla Won" << endl;
    }
  }
}
