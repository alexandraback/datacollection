#include <bits/stdc++.h>
using namespace std;

void expand(string &s, int i, vector<pair<string, int>>& res, string curr, int val) {
	if (i == (int)s.size()) {
		res.emplace_back(curr, val);
		return;
	}
	
	if (s[i] != '?') expand(s, i+1, res, curr + s[i], val*10 + s[i]-'0');
	else {
		for (int j = 0; j < 10; j++)
			expand(s, i+1, res, curr + (char)('0'+j), val*10 + j);
	}
}

void solve(int t) {
	
	string a, b;
	cin >> a >> b;
	
	vector<pair<string, int>> A, B;
	
	expand(a, 0, A, "", 0);
	expand(b, 0, B, "", 0);
	
	string resA = "", resB = "";
	int delta = 1000000000;
	
	for (int i = 0; i < (int)A.size(); i++)
		for (int j = 0; j < (int)B.size(); j++) {
			int d = abs(A[i].second - B[j].second);
			
			if (d < delta || (d == delta && A[i].first < resA) || (d == delta && A[i].first == resA && B[j].first < resB)) {
				resA = A[i].first;
				resB = B[j].first;
				delta = d;
			}
		}
	cout << "Case #" << t << ": " << resA << " " << resB << endl;
}

int main() {
	int T;
	cin >> T;
	for (int t = 1; t <= T; t++) {
		solve(t);
	}
}
