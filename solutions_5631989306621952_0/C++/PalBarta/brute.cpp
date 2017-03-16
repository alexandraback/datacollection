#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <cstring>
#include <time.h>
#include <queue>
#include <map>
using namespace std;

vector<int> a(100000);

char out[3000];
int main()
{
	int T;
	cin >> T;
	for (int t = 1; t <= T; t++) {
		cout << "Case #" << t << ": ";
		// Problem starts here
		string s;
		cin >> s;
		int ob = 1500;
		int oe = 1500;
		for (int i = 0; i < s.length(); i++) {
			if (i == 0) {
				out[oe] = s[i];
				oe++;
			}
			else if (s[i] < out[ob]) {
				out[oe] = s[i];
				oe++;
			}
			else
			{
				ob--;
				out[ob] = s[i];
			}
		}
		out[oe] = '\0';
		
		string o = s;
		const char* p = &out[ob];
		o.assign(p);

		cout << o;
		// Problem ends here
		cout << endl;
	}

	return 0;
}