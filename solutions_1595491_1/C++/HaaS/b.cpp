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
	
	int t; cin >> t;
	for (int i = 0; i < t; i++) {
		int n, s, p; cin >> n >> s >> p;
		int s1 = (p - 1) * 3, s2 = s1 - 1, l = s2;
		if (p == 0) s1 = s2 = -1, l = 0;
		if (p == 1) s1 = s2 = -1, l = 1;
		
		int res = 0;
		for (int i = 0; i < n; i++) {
			int x; cin >> x;
			if (x < l) continue;
			if (x == s1 || x == s2) {
				if (s) s--, res++;
			}
			else res++;
		}
		cout << "Case #" << i + 1 << ": " << res << endl;
	}
	
	cin >> t;
	return 0;
}
