#include <bits/stdc++.h>

using namespace std;

int solve(string s) {
	if (s.size() == 1) {
		if (s[0] == '+') return 0;
		else return 1;
	}

	int high = s.size()-1;
	while (high >= 0 && s[high] == '+') high--;
	
	if (high == -1) return 0;
	
	string r="";
	int low = 0;
	while (low <= high) {
		if (s[low] == '+') r += '-';
		else r += '+';
		low++;
	}
	
	return 1 + solve(r);
}

void doCase(int t) {
	string s;
	
	cin >> s;

	cout << "Case #" << t << ": " << solve(s) << endl;
}

int main()
{
	int t;
	cin >> t;
	for (int i=0; i<t; i++) doCase(i+1);
	return 0;
}
