#include <iostream>
#include <algorithm>
#include <queue>
#include <vector>
#include <map>
#include <climits>
#include <stack>
#include <string>
#include <stdio.h>
#include <ctype.h>
#include <cstdint>
#include <unordered_set>
#include <unordered_map>
#include <utility>
#include <math.h>
#include <deque>

using namespace std;

static string addString(string s){
  deque<char> myque;
  if(s.empty())
    return "";
  
  myque.push_front(s[0]);
  for(int i = 1; i < s.size(); i++){
    if(myque.front() <= s[i])
      myque.push_front(s[i]);
    else
      myque.push_back(s[i]);
  }
        
  string result;
  for(std::deque<char>::iterator it = myque.begin(); it!=myque.end(); ++it)
    result.push_back(*it);
  return result;
}

int main() {
  int t;
  string s;
  cin >> t;  // read t. cin knows that t is an int, so it reads it as such.
  for (int i = 1; i <= t; ++i) {
    cin >> s;
    string result = addString(s);
    cout << "Case #" << i << ": " << result << endl;
    // cout knows that n + m and n * m are ints, and prints them accordingly.
    // It also knows "Case #", ": ", and " " are strings and that endl ends the line.
  }
  
  return 0;
}