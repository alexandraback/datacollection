#include <bits/stdc++.h>
using namespace std;

int vec[11], cnt[127];

void solve (int tc) {
	memset (vec, 0, sizeof vec);
	memset (cnt, 0, sizeof cnt);
	string s;
	cin >> s;
	for (int i = 0; i < s.length(); i++)
		cnt[s[i]]++;
	//zero
	while (cnt['Z'] > 0) {
		cnt['Z']--;
		cnt['E']--;
		cnt['R']--;
		cnt['O']--;
		vec[0]++;
	}
	//six
	while (cnt['X'] > 0) {
		cnt['S']--;
		cnt['I']--;
		cnt['X']--;
		vec[6]++;
	}
	//seven
	while (cnt['S'] > 0) {
		cnt['S']--;
		cnt['E'] -= 2;
		cnt['V']--;
		cnt['N']--;
		vec[7]++;
	}
	//five
	while (cnt['V'] > 0) {
		cnt['F']--;
		cnt['I']--;
		cnt['V']--;
		cnt['E']--;
		vec[5]++;
	}
	//two
	while (cnt['W'] > 0) {
		cnt['T']--;
		cnt['W']--;
		cnt['O']--;
		vec[2]++;
	}
	//four
	while (cnt['U'] > 0) {
		cnt['F']--;
		cnt['O']--;
		cnt['U']--;
		cnt['R']--;
		vec[4]++;
	}
	//eight
	while (cnt['G'] > 0) {
		cnt['E']--;
		cnt['I']--;
		cnt['G']--;
		cnt['H']--;
		cnt['T']--;
		vec[8]++;
	}
	//one
	while (cnt['O'] > 0) {
		cnt['O']--;
		cnt['N']--;
		cnt['E']--;
		vec[1]++;
	}
	//nine
	while (cnt['I'] > 0) {
		cnt['N'] -= 2;
		cnt['I']--;
		cnt['E']--;
		vec[9]++;
	}
	vec[3] = cnt['T'];
	printf ("Case #%d: ", tc);
	for (int i = 0; i < 10; i++) 
		for (int j = 0; j < vec[i]; j++) 
			printf ("%d", i);
	printf ("\n");
}

int main () {
	int t;
	cin >> t;
	for (int tc = 1; tc <= t; tc++)
		solve (tc);
	return 0;
}