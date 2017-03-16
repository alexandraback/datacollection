#include <bits/stdc++.h>
using namespace std;
string minim, maxim;
long long int minVal = INT_MAX;
void brute(string str1, string str2, int ind) {
	if(ind == str1.size()) {
		int i;
		long long int mult = 1;
		long long int ans = 0;
		for(i = str1.size() - 1; i >= 0; i--) {
			int diff = str1[i] - str2[i];
			ans = ans + diff * mult;
			mult = mult * 10;
		}
		if(abs(ans) < minVal) {
			minVal = abs(ans);
			minim = str1;
			maxim = str2;
		} else if(abs(mult) == minVal) {
			if(minim > str1) {
				minim = str1;
			} else if(minim == str1 && maxim > str2) {
				maxim = str2;
			}
		}
		return;
	} 

	if(str1[ind] == '?' && str2[ind] == '?') {
		int i, j;
		for(i = 0; i < 10; i++) {
			for(j = 0; j < 10; j++) {
				str1[ind] = i + '0';
				str2[ind] = j + '0';
				brute(str1, str2, ind + 1);
			}
		}
		return;
	}
	if(str1[ind] == '?' && str2[ind] != '?') {
		int i;
		for(i = 0; i < 10; i++) {
			str1[ind] = i + '0';
			brute(str1, str2, ind + 1);
		}
		return;
	}
	if(str1[ind] != '?' && str2[ind] == '?') {
		int i;
		for(i = 0; i < 10; i++) {
			str2[ind] = i + '0';
			brute(str1, str2, ind + 1);
		}
		return;
	}
	brute(str1, str2, ind + 1);
}
int main() {
	int t;
	cin >> t;
	int run = 0;
	for(run = 1; run <= t; run++) {
		minim = "";
		maxim = "";
		minVal = INT_MAX;
		string str1, str2;
		cin >> str1 >> str2;
		brute(str1, str2, 0);
		cout << "Case #" << run << ": " << minim << " " << maxim << endl;
	}
	return 0;
}