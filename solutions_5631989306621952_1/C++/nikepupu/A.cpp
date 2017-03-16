#include <iostream>
#include <cstdlib>
#include <cctype>
#include <string>
#include <cstring>
#include <cmath>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <queue>
#include <iomanip>

template<typename T> inline bool chkmin(T &a, const T &b) { return a > b ? a = b, 1 : 0; }
template<typename T> inline bool chkmax(T &a, const T &b) { return a < b ? a = b, 1 : 0; }

using namespace std;

int main()
{
  string S,temp;
  int T;
  cin >> T;
for(int t = 1; t <= T; t++)
{
  cout << "Case #"<<t<<": ";
  cin >> S;
  temp = "";
  temp += S[0];
  for(int i = 1; i < S.length(); i++)
  {
  	
  	if(S[i] >= temp[0])
  		temp = S[i]+temp;
  	else
  		temp = temp + S[i];
  
  }
  cout << temp  << endl;
}
  return 0;
}