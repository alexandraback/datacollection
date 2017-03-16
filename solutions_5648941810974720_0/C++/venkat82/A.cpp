#include <bits/stdc++.h>
using namespace std;
map<char, int> m;
int cnt[10];
int main() {
	int test;
	cin >> test;
	for(int tt = 1; tt <= test; tt++) {
		m.clear();
		for(int i = 0; i < 10; i++) cnt[i] = 0;
		cout << "Case #" << tt << ": "; 
		string s;
		cin >> s;
		for(int i = 0; i < int(s.length()); i++) m[s[i]]++;
		cnt[0] = m['Z'];
		cnt[2] = m['W'];
		cnt[4] = m['U'];
		for(int i = 0; i < cnt[4]; i++) {
			m['F']--;
		}
		cnt[6] = m['X'];
		cnt[8] = m['G'];
		cnt[5] = m['F'];
		for(int i = 0; i < cnt[5]; i++) {
			m['F']--;
			m['I']--;
			m['V']--;
			m['E']--;
		}
		for(int i = 0; i < cnt[8]; i++) {
			m['I']--;
			m['H']--;
		}
		for(int i = 0; i < cnt[6]; i++) {
			m['S']--;
			m['I']--;
		}
		cnt[9] = m['I'];
		cnt[7] = m['S'];
		for(int i = 0; i < cnt[7]; i++) {
			m['N']--;
		}
		for(int i = 0; i < cnt[9]; i++) {
			m['N'] -= 2;
		}
		cnt[1] = m['N'];
		cnt[3] = m['H'];
		for(int i = 0; i < 10; i++) {
			for(int j = 0; j < cnt[i]; j++) cout << i;
		}
		cout << endl;
	}
}