#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <cstring>
#include <iomanip>
#include <cmath>
#include <sstream>
#include <windows.h>

using namespace std;

void timer (string s)
{
	SYSTEMTIME time;
	GetSystemTime(&time);
	WORD millis = (time.wSecond * 1000) + time.wMilliseconds;
	cerr << s << ' ' << millis << endl;
}

#define pie pair <int, int>
#define ff first
#define ss second

const int maxN = 100 * 1000 + 100;

int hold[maxN];

int main()
{
	ios::sync_with_stdio (false);
	
	//timer ("start");
	int t; 
	//t = 50; 
	cin >> t; 
	for (int i = 0; i < t; i++) {
		int a, b, n = 0, res = 0; 
		cin >> a >> b;
		//a = 1000000, b = 2000000;
		int p = 1; for (int b = a; b; n++, b /= 10) p *= 10; p /= 10;
		for (int i = a; i <= b; i++) {
			for (int j = 1, x = i; j < n; j++) {
				int y = x % 10;
				x = x / 10 + p * y;
				hold[j - 1] = x;
				//cerr << i << ' ' << j << ' ' << x << endl;
			}
			sort (hold, hold + n - 1);
			for (int j = 0; j < n - 1; j++)
				if (a <= hold[j] && hold[j] < i)
					if (j && hold[j] == hold[j - 1]);
					else /*cerr << i << ' ' << hold[j] << endl,*/ res++;
		}
		cout << "Case #" << i + 1 << ": " << res << endl;
		//timer ("O_O");
	}
	//timer ("end");
	
	cin >> t;
	return 0;
}
