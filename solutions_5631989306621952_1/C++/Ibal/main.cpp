#include <string>
#include <iostream>
#include <sstream>
#include <vector>

using namespace std;


//! Counting sheep
string theLastWord(
  const string i_s) {

  if (i_s.size() <= 1) {
    return i_s;
  }

  stringstream ss;
  ss << i_s[0];
  string r;
  ss >> r;
  for (size_t n = 1; n < i_s.size(); n++) {
    stringstream ss;
    ss << i_s[n];
    string s;
    ss >> s;
    if (int(r[0]) > int(i_s[n])) {
      r += s;
    }
    else {
      r = s + r;
    }
  }

  return r;
}




//! Main function
int main()
{
  //! Read the first line of the file to know the total of test
  int T;
  cin >> T;

  //! Print the lines after that
  for (int k = 1; k <= T; k++) {

    //! Read the value
    string s;
    cin >> s;

    //! Save the result
    cout << "Case #" << k << ": " << theLastWord(s) << endl;
  }

  return 0;
}
