#include <cstdio>
#include <cstdlib>
#include <iostream>
#include <string>

using namespace std;

int n;
string s1, s2;
unsigned long long minim = ULLONG_MAX;
string ansa, ansb;

void try_fill(int prev, string sa, string sb) {
	if (sa.size() == s1.size()) {
		unsigned long long diff = abs(stoll(sa) - stoll(sb));
		if (diff < minim) {
			minim = diff;
			ansa = sa;
			ansb = sb;
		}
		else {
			if (diff == minim) {
				if (sa < ansa) {
					ansa = sa; ansb = sb;
				}
				else {
					if (sb < ansb) {
						ansa = sa; ansb = sb;
					}
				}
			}
		}
		return;
	}

	int i = sa.size();
 	
	if (s1[i] != '?' && s2[i] != '?') {
		if (prev == 0) {
			if (s1[i] > s2[i]) {
				prev = 1;
			}
			if (s1[i] < s2[i]) {
				prev = 2;
			}
		}
		try_fill(prev, sa + s1[i], sb + s2[i]);
		return;
	}

	if (prev == 0) {
		if (s1[i] == '?' && s2[i] == '?') {
			sa.push_back('0'); sb.push_back('1');
			try_fill(2, sa, sb);
			sa.pop_back(); sb.pop_back();
			sa.push_back('1'); sb.push_back('0');
			try_fill(1, sa, sb);
			sa.pop_back(); sb.pop_back();
			sa.push_back('0'); sb.push_back('0');
			try_fill(0, sa, sb);
			sa.pop_back(); sb.pop_back();
			return;
		}
		if (s1[i] == '?' && s2[i] != '?') {
			if (s2[i] != '0') {
				sa.push_back(s2[i]-1); sb.push_back(s2[i]);
				try_fill(2, sa, sb);
				sa.pop_back(); sb.pop_back();
			}
			sa.push_back(s2[i]); sb.push_back(s2[i]);
			try_fill(0, sa, sb);
			sa.pop_back(); sb.pop_back();
			if (s2[i] != '9') {
				sa.push_back(s2[i] + 1); sb.push_back(s2[i]);
				try_fill(1, sa, sb);
				sa.pop_back(); sb.pop_back();
			}
			return;
		}
		if (s1[i] != '?' && s2[i] == '?') {
			if (s1[i] != '9') {
				sa.push_back(s1[i]); sb.push_back(s1[i]+1);
				try_fill(2, sa, sb);
				sa.pop_back(); sb.pop_back();
			}
			sa.push_back(s1[i]); sb.push_back(s1[i]);
			try_fill(0, sa, sb);
			sa.pop_back(); sb.pop_back();
			if (s1[i] != '0') {
				sa.push_back(s1[i]); sb.push_back(s1[i]-1);
				try_fill(1, sa, sb);
				sa.pop_back(); sb.pop_back();
			}
			return;
		}
	}
	else {
		if (s1[i] == '?') {
			sa.push_back((prev==1?'0':'9'));
		}
		else {
			sa.push_back(s1[i]);
		}
		if (s2[i] == '?') {
			sb.push_back((prev==1?'9':'0'));
		}
		else {
			sb.push_back(s2[i]);
		}

		try_fill(prev, sa, sb);
		return;
	}
}

int main() {
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);

	int tests;
	cin >> tests;

	for (int t = 1; t <= tests; t++) {
		minim = ULLONG_MAX;
		ansa = "a";
		ansb = "a";
		cin >> s1 >> s2;
		
		try_fill(0, "", "");

		cout << "Case #" << t << ": " << ansa << " " << ansb << "\n";
	}

	return 0;
}