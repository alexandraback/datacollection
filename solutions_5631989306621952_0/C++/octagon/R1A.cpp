#include <iostream>  // includes cin to read from stdin and cout to write to stdout
using namespace std;  // since cin and cout are both in namespace std, this saves some text
int main() {
  int t;
  cin >> t; cin.ignore(INT_MAX,'\n');
  for (int i = 1; i <= t; ++i) {
  	string res="";
  	string in;
    getline(cin, in);
    for(char& ch:in){
    	string tmp1 = res + ch;
    	string tmp2 = ch + res;
    	res = tmp1.compare(tmp2)>0?tmp1:tmp2;
	}
    cout << "Case #" << i << ": " << res << endl;
    // cout knows that n + m and n * m are ints, and prints them accordingly.
    // It also knows "Case #", ": ", and " " are strings and that endl ends the line.
  }
}
