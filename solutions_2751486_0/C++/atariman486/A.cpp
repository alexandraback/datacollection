#include <iostream>
#include <algorithm>
#include <cstdlib>
#include <vector>
#include <cstring>
#include <string>
#include <iomanip>

using namespace std;

string s;
int n;



int main() {
	bool vowel[26];
	memset(vowel, false, 26);
	vowel['a' - 'a'] = true;
	vowel['e' - 'a'] = true;
	vowel['i' - 'a'] = true;
	vowel['o' - 'a'] = true;
	vowel['u' - 'a'] = true;

	int numCases;
	cin >> numCases;

	for(int c = 0; c < numCases; c++) {
		cin >> s >> n;

		long last = -1;
		long ans = 0;
		for(long i = 0; i <= s.length() - n; i++) {
			bool cons = true;
			for(long j = 0; j < n; j++) {
				if ( vowel[s[i+j] -'a'] ) {
					cons = false;
					break;
				}
			}
			if ( cons ) {
				ans += 1;
				long m = s.length() - (i + n);
				ans += (i - (last + 1)) * (m + 1);
				ans += m;
				last = i;
			}
		}

		printf("Case #%d: ", c+1);
		cout << ans << endl;
	}

	return 1;
}