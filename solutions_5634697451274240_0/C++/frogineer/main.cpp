#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <cmath>
#include <algorithm>
using namespace std;

// Flips the top n pancakes in s.
string flipPancakes(string s, int n) {
	reverse(s.begin(), s.begin() + n);
	for(int i = 0; i < n; i++) {
		if(s[i] == '+')
			s[i] = '-';
		else s[i] = '+';
	}
	return s;
}

int main()
{
	freopen("B-small-attempt1.in", "r", stdin);
	freopen("B-small.out", "w", stdout);
	int t;
	cin >> t;
	for(int caseNum = 1; caseNum <= t; caseNum++) {
		string s;
		cin >> s;
		int numFlips = 0;
		for(int i = (int) s.length() - 1; i >= 0; i--) {
			if(s[i] == '-') {
				int firstFlip = 0;
				while(s[firstFlip] == '+') {
					firstFlip++;
				}
				if(firstFlip > 0) {
					s = flipPancakes(s, firstFlip);
					numFlips++;
				}
				s = flipPancakes(s, i+1);
				numFlips++;
			}
		}
		cout << "Case #" << caseNum << ": " << numFlips << endl;
	}
	return 0;
}