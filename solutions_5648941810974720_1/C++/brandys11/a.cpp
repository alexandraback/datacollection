#include <bits/stdc++.h>

using namespace std;

vector<int> p;
vector<string> c = {"ZERO", "EIGHT", "TWO", "THREE", "FOUR", "SIX", "SEVEN", "FIVE", "NINE", "ONE"};

void solve() {
	p.clear();
	p.resize(26, 0);
	string s;
	cin >> s;
	for(auto a: s) p[a - 'A']++;

	vector<int> res;

	bool found = true;
	while(found) {
		found = false;

		for(int i=0; i < 10; i++) {
			bool ok = true;
			for(auto ch: c[i]) p[ch - 'A']--;
			for(auto poc: p) if (poc < 0) ok = false;

 			if (ok) {
 				found = true;
 				if(c[i] == "ZERO") res.push_back( 0);
 				if(c[i] == "ONE") res.push_back( 1);
 				if(c[i] ==  "TWO") res.push_back( 2);
 				if(c[i] ==  "THREE") res.push_back( 3);
 				if(c[i] ==  "FOUR") res.push_back( 4);
 				if(c[i] ==  "FIVE") res.push_back( 5);
 				if(c[i] ==  "SIX") res.push_back( 6);
 				if(c[i] ==  "SEVEN") res.push_back( 7);
 				if(c[i] ==  "EIGHT") res.push_back( 8);
 				if(c[i] ==  "NINE") res.push_back( 9);
 				break;
 			} else {
 				for(auto ch: c[i]) p[ch - 'A']++;
 			}
		}
	}

	sort(res.begin(), res.end());
	for(auto a : res) cout << a;
}

int main(void) {
	int T;
	cin >> T;
	for(int t=1; t<=T; t++) {
		cout << "Case #" << t << ": ";
		solve();
		cout << endl;
	}
}