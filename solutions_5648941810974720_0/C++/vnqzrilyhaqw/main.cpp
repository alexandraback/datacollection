#include <bits/stdc++.h>
using namespace std;

const int N = 26;
const vector<string> digits{"ZERO", "ONE", "TWO", "THREE", "FOUR", "FIVE", 
	"SIX", "SEVEN", "EIGHT", "NINE"};

string single_test() {
	string s;
	cin >> s;
	vector<int> a(26, 0);
	for(char c : s) {
		int i = c - 'A';
		++a[i];
	}
	vector< pair<char, int> > dic{ 
		{'Z', 0}, 
		{'X', 6}, 
		{'W', 2}, 
		{'G', 8},		
		{'U', 4}, 
		{'S', 7},
		{'V', 5},
		{'O', 1},
		{'H', 3},		
		{'I', 9},
	};
	vector<int> res;
	for(auto& p: dic) {
		int i = p.first - 'A';
		int cur = a[i];
		if(cur) {
			vector<int> tmp(a[i], p.second);
			for(char c: digits[p.second]) {
				int j = c - 'A';
				a[j] -= cur;
			}
			res.insert(res.end(), tmp.begin(), tmp.end());
		}
	}
	sort(res.begin(), res.end());
	stringstream ss;
	for(int i: res)
		ss << i;
	return ss.str();
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.precision(10);
	cout << fixed;
	int t;
	cin >> t;
	for(int i=1; i<=t; ++i) {
		string res = single_test();
		cout << "Case #" << i << ": " << res << endl;
	}
	return 0;
}
