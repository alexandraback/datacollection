#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <cstdlib>
#include <map>

using namespace std;

inline bool vowel(char in) {
	return in=='a' || in=='e' || in=='i' || in=='o' || in=='u';
}

void solve(int testcase) {
	cout << "Case #" << testcase << ": ";
	string name;
	int n;
	int len;

	cin >> name >> n;
	len = name.length();

	int count = 0;
	for (int i=0; i<len; i++) {
		for (int j=i+n-1; j<len; j++) {
			bool valid = false;
			int c = 0;
			for (int k=i; k<=j; k++) {
				if (!vowel(name[k])) {
					c++;
				}
				else
					c = 0;
				if (c>=n) {
					valid = true;
					break;
				}
			}

			if (valid)
				count++;
		}
	}
	cout << count;
	cout << endl;
}

int main () {
	int testcases;

	cin >> testcases; 

	for (int testcase=1; testcase<=testcases; testcase++) {
		solve(testcase);
	}
	return 0;
}
