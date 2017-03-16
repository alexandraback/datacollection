#include <iostream>
#include <vector>
#include <set>
#include <algorithm>

using namespace std;

int main()
{
  string line;
  getline( cin, line );
  int T = stoi( line );
  for ( int t = 1; t <= T; t++ )
  {
	getline( cin, line );
	string ans = "";
	for ( char ch : line )
	{
	  char front_ch = ans == "" ? 'a' : ans[0];
	  if ( front_ch <= ch )
	  {
		ans = ch + ans;
	  }
	  else
	  {
		ans = ans + ch;
	  }
	}
	cout << "Case #" << t << ": " << ans << endl;
  }
}
