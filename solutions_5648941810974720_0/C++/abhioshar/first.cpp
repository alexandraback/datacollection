#include <bits/stdc++.h>

using namespace std;

int n;
string s;
int cnts[26];
string ans;


string numtos(int x) {
	switch(x) {
		case 0:	return "0";
		case 1: return "1";
		case 2:	return "2"; 
		case 3:	return "3";
		case 4:	return "4";
		case 5:	return "5";
		case 6:	return "6";
		case 7:	return "7";
		case 8:	return "8";
		case 9:	return "9";
	}
}

int f(string s, int num) {
	if(num == 0) {
		int x = 0;
		if(cnts['Z'-'A']) {
			x = cnts['Z'-'A'];
			cnts['Z'-'A'] -= x;
			cnts['E'-'A'] -= x;
			cnts['R'-'A'] -= x;
			cnts['O'-'A'] -= x;
			for(int i = 0; i < x; ++i)
				ans += numtos(0);
		}
		return x;
	}
	if(num == 1) {
		int x = 0;
		if(cnts['O'-'A']) {
			x = cnts['O'-'A'];
			cnts['O'-'A'] -= x;
			cnts['N'-'A'] -= x;
			cnts['E'-'A'] -= x;
			for(int i = 0; i < x; ++i)
				ans += numtos(1);
		}
		return x;
	}
	if(num == 2) {
		int x = 0;
		if(cnts['W'-'A']) {
			x = cnts['W'-'A'];
			cnts['T'-'A'] -= x;
			cnts['W'-'A'] -= x;
			cnts['O'-'A'] -= x;
			for(int i = 0; i < x; ++i)
				ans += numtos(2);
		}
		return x;
	}
	if(num == 3) {
		int x = 0;
		if(cnts['T'-'A']) {
			x = cnts['T'-'A'];
			cnts['T'-'A'] -= x;
			cnts['H'-'A'] -= x;
			cnts['R'-'A'] -= x;
			cnts['E'-'A'] -= x;
			cnts['E'-'A'] -= x;
			for(int i = 0; i < x; ++i)
				ans += numtos(3);
		}
		return x;
	}
	if(num == 4) {
		int x = 0;
		if(cnts['U'-'A']) {
			x = cnts['U'-'A'];
			cnts['F'-'A'] -= x;
			cnts['O'-'A'] -= x;
			cnts['U'-'A'] -= x;
			cnts['R'-'A'] -= x;
			for(int i = 0; i < x; ++i)
				ans += numtos(4);
		}
		return x;
	}
	if(num == 5) {
		int x = 0;
		if(cnts['F'-'A']) {
			x = cnts['F'-'A'];
			cnts['F'-'A'] -= x;
			cnts['I'-'A'] -= x;
			cnts['V'-'A'] -= x;
			cnts['E'-'A'] -= x;
			for(int i = 0; i < x; ++i)
				ans += numtos(5);
		}
		return x;
	}
	if(num == 6) {
		int x = 0;
		if(cnts['X'-'A']) {
			x = cnts['X'-'A'];
			cnts['S'-'A'] -= x;
			cnts['I'-'A'] -= x;
			cnts['X'-'A'] -= x;
			for(int i = 0; i < x; ++i)
				ans += numtos(6);
		}
		return x;
	}
	if(num == 7) {
		int x = 0;
		if(cnts['S'-'A']) {
			x = cnts['S'-'A'];
			cnts['S'-'A'] -= x;
			cnts['E'-'A'] -= x;
			cnts['V'-'A'] -= x;
			cnts['E'-'A'] -= x;
			cnts['N'-'A'] -= x;
			for(int i = 0; i < x; ++i)
				ans += numtos(7);
		}
		return x;
	}
	if(num == 8) {
		int x = 0;
		if(cnts['G'-'A']) {
			x = cnts['G'-'A'];
			cnts['E'-'A'] -= x;
			cnts['I'-'A'] -= x;
			cnts['G'-'A'] -= x;
			cnts['H'-'A'] -= x;
			cnts['T'-'A'] -= x;
			for(int i = 0; i < x; ++i)
				ans += numtos(8);
		}
		return x;
	}
	if(num == 9) {
		int x = 0;
		if(cnts['N'-'A']) {
			x = cnts['N'-'A'];
			x /= 2;
			cnts['N'-'A'] -= x;
			cnts['I'-'A'] -= x;
			cnts['N'-'A'] -= x;
			cnts['E'-'A'] -= x;
			for(int i = 0; i < x; ++i)
				ans += numtos(9);
		}
		return x;
	}
}

int main(void) {

	ifstream fin;
	ofstream fout;
	fin.open("A-small-attempt0.in");
	fout.open("output.out");

	int tt;
	fin>>tt;
	for(int t = 1; t <= tt; ++t) {
		ans.clear();
		fin>>s;
		n = s.size();
		memset(cnts, 0, sizeof(cnts));
		for(int i = 0; i < n; ++i) {
			cnts[s[i]-'A']++;
		}
		for(int i = 0; i <= 8; i += 2) {
			f(s, i);
		}	
		for(int i = 1; i <= 9; i += 2) {
			f(s, i);
		}	
		sort(ans.begin(), ans.end());
		fout<<"Case #"<<t<<": "<<ans<<"\n";

	}




	fin.close();
	fout.close();
	return 0;
}

