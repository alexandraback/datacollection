#include <bits/stdc++.h>
using namespace std;
//						Z      -O     W       -R       U      -F       X      -S      --H      
string digits[10] = {"ZERO", "ONE", "TWO", "THREE", "FOUR", "FIVE", "SIX", "SEVEN", "EIGHT", "NINE"};

int f[10][26];
int freq[26];

void solve(int t) {
	string num;
	cin >> num;
	
	memset(freq, 0, sizeof(freq));
	
	for (int i = 0; i < (int)num.size(); i++)
		freq[num[i]-'A']++;
		
	string sol = "";
	
	int k = freq['Z'-'A'];
	for (int i = 0; i < k; i++) {
		sol += '0';
		freq['Z'-'A']--;
		freq['E'-'A']--;
		freq['R'-'A']--;
		freq['O'-'A']--;
	}
	k = freq['W'-'A'];
	for (int i = 0; i < k; i++) {
		sol += '2';
		freq['T'-'A']--;
		freq['W'-'A']--;
		freq['O'-'A']--;
	}
	k = freq['U'-'A'];
	for (int i = 0; i < k; i++) {
		sol += '4';
		freq['F'-'A']--;
		freq['O'-'A']--;
		freq['U'-'A']--;
		freq['R'-'A']--;
	}
	k = freq['X'-'A'];
	for (int i = 0; i < k; i++) {
		sol += '6';
		freq['S'-'A']--;
		freq['I'-'A']--;
		freq['X'-'A']--;
	}
	k = freq['O'-'A'];
	for (int i = 0; i < k; i++) {
		sol += '1';
		freq['O'-'A']--;
		freq['N'-'A']--;
		freq['E'-'A']--;
	}
	k = freq['R'-'A'];
	for (int i = 0; i < k; i++) {
		sol += '3';
		freq['T'-'A']--;
		freq['H'-'A']--;
		freq['R'-'A']--;
		freq['E'-'A']--;
		freq['E'-'A']--;
	}
	k = freq['F'-'A'];
	for (int i = 0; i < k; i++) {
		sol += '5';
		freq['F'-'A']--;
		freq['I'-'A']--;
		freq['V'-'A']--;
		freq['E'-'A']--;
	}
	k = freq['S'-'A'];
	for (int i = 0; i < k; i++) {
		sol += '7';
		freq['S'-'A']--;
		freq['E'-'A']--;
		freq['V'-'A']--;
		freq['E'-'A']--;
		freq['N'-'A']--;
	}
	k = freq['H'-'A'];
	for (int i = 0; i < k; i++) {
		sol += '8';
		freq['E'-'A']--;
		freq['I'-'A']--;
		freq['G'-'A']--;
		freq['H'-'A']--;
		freq['T'-'A']--;
	}
	k = freq['I'-'A'];
	for (int i = 0; i < k; i++) {
		sol += '9';
		freq['N'-'A']--;
		freq['I'-'A']--;
		freq['N'-'A']--;
		freq['E'-'A']--;
	}
	
	for (int i = 0; i < 26; i++)
		if (freq[i] != 0) cerr << "Error on " << (char)(i+'a') << endl;
	
	sort(sol.begin(), sol.end());
	cout << "Case #" << t << ": " << sol << endl;
}

void precompute() {
	for (int i = 0; i < 10; i++)
		for (int k = 0; k < (int)digits[i].size(); k++)
			f[i][digits[i][k]-'A']++;
}

int main() {
	int T;
	cin >> T;
	precompute();
	for (int t = 1; t <= T; t++) {
		solve(t);
	}
}
