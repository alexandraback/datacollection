#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <cstring>
#include <iomanip>
#include <cmath>
#include <sstream>
//#include <windows.h>

using namespace std;

/*void timer (string s)
{
	SYSTEMTIME time;
	GetSystemTime(&time);
	WORD millis = (time.wSecond * 1000) + time.wMilliseconds;
	cerr << s << ' ' << millis << endl;
}*/

#define pie pair <int, int>
#define ff first
#define ss second

const int maxN = 100 * 1000 + 100;

int main()
{
	ios::sync_with_stdio (false);
	
	string map = "yhesocvxduiglbkrztnwjpfmaq";
	int t; string s;
	cin >> t; getline (cin, s);
	for (int i = 0; i < t; i++) {
		getline (cin, s);
		for (int i = 0; i < s.size(); i++)
			if (s[i] != ' ')
				s[i] = map[s[i] - 'a'];
		cout << "Case #" << i + 1 << ": " << s << endl;
	}
	
	cin >> t;
	return 0;
}
