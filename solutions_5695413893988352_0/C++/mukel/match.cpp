#include <bits/stdc++.h>
using namespace std;

typedef long long int64;

#define ALL(c) (c).begin(), (c).end()
	
vector<int> result;
	
void comb(string& s, int pos, int acc) {	
	if (pos >= (int)s.size()) {
		result.push_back(acc);
		return ;
	}
	if (s[pos] == '?') {
		for (int d = 0; d < 10; ++d)
			comb(s, pos + 1, acc * 10 + d);
	} else
		comb(s, pos + 1, acc * 10 + s[pos] - '0');
}

vector<int> getAll(string& s) {	
	result.clear();
	comb(s, 0, 0);
	return result;
}

string toFixed(int x, int len) {
	string r = to_string(x);
	while (r.size() < len)
		r = "0" + r;
	return r;
}
	
int main() {
	ios_base::sync_with_stdio(0);
	
	int testCount;
	cin >> testCount;
	for (int test = 1; test <= testCount; ++test) {
		
		string A, B;
		cin >> A >> B;
		
		auto as = getAll(A);
		auto bs = getAll(B);		
		sort(ALL(as));
		sort(ALL(bs));		
		
		pair<int, int> ans = {as[0], bs[0]};
				
		for (auto a : as)
		for (auto b : bs)
			if (abs(a - b) < abs(ans.first - ans.second))
				ans = {a, b};
		
		int n = A.size();
		cout << "Case #" << test << ": "
			<< toFixed(ans.first, n)
			<< " "
			<< toFixed(ans.second, n) << endl;
	}
	
	return 0;
}
