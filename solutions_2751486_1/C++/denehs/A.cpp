#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <cstdlib>
#include <map>

using namespace std;

#define uint64 unsigned long long

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

	uint64 count = 0;

	vector <int> data;
	data.clear();
	int c=0;
	for (int i=0; i<len; i++) {
		if (!vowel(name[i]))
			c++;
		else
			c = 0;
		if (c>=n)
			data.push_back (i);
	}

	for (int i=0; i<len; i++) {
		int c=0;

		int start;

		if (lower_bound(data.begin(), data.end(), i+n-1)!=data.end())
			start = *lower_bound(data.begin(), data.end(), i+n-1);
		else
			continue;

		if (start-i+1<n)
			break;

		count += len - start;
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
