#include <bits/stdc++.h>

using namespace std;

#define ll long long

int t;


void solve();

int main() {
	ios::sync_with_stdio(0);

	bool file = true;
	if (file) {
		freopen("A-large.in","r", stdin);
		freopen("output_large.out", "w", stdout);
	}

	cin >> t;
	for (int z = 1; z<= t; z++) {
		cout << "Case #" << z << ": ";
		solve();
		cout << endl;
	}
	return 0;
}

ll existing[300];
ll nExisting[300];


void clear_existing() {
	for (int i = 0; i < 300; i++)
		existing[i] = 0;
}

void init_nExisting() {
	for (int i = 0; i < 300; i++)
		nExisting[i] = existing[i];
}

void init_existing() {
	for (int i = 0; i < 300; i++)
		existing[i] = nExisting[i];
}

void solve() {
	// Z zero
	// -
	// W two
	// -
	// U four
	// -
	// X six
	// -
	// G eight
	// -

	// O one
	// H three
	// F five
	// V seven
	// N nine
	string nums[] = {
			"ZERO", "ONE", "TWO", "THREE", "FOUR", "FIVE", "SIX", "SEVEN", "EIGHT", "NINE"
	};
	string s;
	cin >> s;
	clear_existing();
	for (int i = 0; i < s.length(); i++) {
		existing[s[i]]++;
	}
	string res;
	//Zero
	while (existing['Z'] > 0) {
		existing['Z']--;
		existing['E']--;
		existing['R']--;
		existing['O']--;
		res+= '0';
	}
	while (existing['W'] > 0) {
		existing['T']--;
		existing['W']--;
		existing['O']--;
		res+= '2';
	}
	while (existing['U'] > 0) {
		existing['F']--;
		existing['O']--;
		existing['U']--;
		existing['R']--;
		res+= '4';
	}
	while (existing['X'] > 0) {
		existing['S']--;
		existing['I']--;
		existing['X']--;
		res+= '6';
	}
	while (existing['G'] > 0) {
		existing['E']--;
		existing['I']--;
		existing['G']--;
		existing['H']--;
		existing['T']--;
		res+= '8';
	}
	while (existing['O'] > 0) {
		existing['O']--;
		existing['N']--;
		existing['E']--;
		res+= '1';
	}
	while (existing['H'] > 0) {
		existing['T']--;
		existing['H']--;
		existing['R']--;
		existing['E']--;
		existing['E']--;
		res+= '3';
	}
	while (existing['F'] > 0) {
		existing['F']--;
		existing['I']--;
		existing['V']--;
		existing['E']--;
		res+= '5';
	}
	while (existing['V'] > 0) {
		existing['S']--;
		existing['E']--;
		existing['V']--;
		existing['E']--;
		existing['N']--;
		res+= '7';
	}
	while (existing['N'] > 0) {
		existing['N']--;
		existing['I']--;
		existing['N']--;
		existing['E']--;
		res+= '9';
	}
	sort(res.begin(), res.end());
	for (int i = 0; i < 300; i++) {
		if (existing[i] != 0) {
			cout << "FAIL: " << (char)i << ": " << (int)existing[i] << endl;
		}
	}
	cout << res;
}
