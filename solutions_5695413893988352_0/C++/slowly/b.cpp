#include <iostream>
#include <vector>
#include <utility>
#include <set>
#include <stack>
#include <queue>
#include <unordered_map>
#include <unordered_set>
#include <climits>
using namespace std;

bool match(string a, string b) {
	for (int i = 0; i<b.size(); i++) {
		if (b[i] != '?') {
			if (a[i] != b[i]) return false;
		}
	}
	return true;
}
string getString(int num, int size) {
	string ret = "";
	while (num > 0) {
		int digit = num % 10;
		ret = to_string(digit) + ret;
		num /= 10;
	}
	int t = ret.size();
	int delta = size - t;
	string z;
	for (int i = 0; i<delta; i++) z.push_back('0');
	return z + ret;
}
int getmax(string pattern) {
	for (int i = 0; i<pattern.size(); i++) {
		if (pattern[i] == '?') pattern[i] = '9';
	}
	return stoi(pattern);
}
pair<string, string> getOLDResults(string a, string b) {
	int size = a.size();
	int minValue = INT_MAX;
	string resA, resB;
	int intresa, intresb;
	int maxA = getmax(a), maxB = getmax(b);
	for (int i = 0; i<=maxA; i++) {
		for (int j = 0; j<=maxB; j++) {
			if (match(getString(i,size), a) && match(getString(j,size),b)) {
				if (abs(i-j) < minValue) {
					minValue = abs(i-j);
					resA = getString(i, size);
					resB = getString(j, size);
					intresa = i;
					intresb = j;
				} else if (abs(i-j) == minValue) {
					if (i < intresa) {
						resA = getString(i, size);
						resB = getString(j, size);
						intresa = i;
						intresb = j;
					} else if (i == intresa && j < intresb) {
						resA = getString(i, size);
						resB = getString(j, size);
						intresa = i;
						intresb = j;	
					}
				}
			}
		}
	}
	return make_pair(resA, resB);
}
pair<string, string> getResults(string a, string b) {
	bool alarger = false, blarger = false;
	for (int i = 0; i<a.size(); i++) {
		if (a[i] != '?' && b[i] != '?') {
			if (a[i] == b[i]) continue;
			if (a[i]-'0' > b[i] - '0') {
				alarger = true;
			} else {
				blarger = true;
			}
		} else if (a[i] == '?' && b[i] != '?') {
			if (alarger == false && blarger == false) {
				a[i] = b[i]; 
				continue;
			} 
			if (alarger == true && blarger == false) {
				a[i] = '0';
				continue;
			}
			if (blarger == true && alarger == false) {
				a[i] = '9';
				continue;
			} 
		} else if (a[i] != '?' && b[i] == '?') {
			if (alarger == false && blarger == false) {
				b[i] = a[i];
				continue;
			}
			if (alarger == true && blarger == false) {
				b[i] = '9';
				continue;
			}
			if (blarger == true && alarger == false) {
				b[i] = '0';
				continue;
			}
		} else {
			// a == ? && b == ?
			if (alarger == false && blarger == false) {
				a[i] = '0';
				b[i] = '0';
				continue;
			}
			if (alarger == true && blarger == false) {
				a[i] = '0';
				b[i] = '9';
				continue;
			} 
			if (blarger == true && alarger == false) {
				a[i] = '9';
				b[i] = '0';
				continue;
			}
		}

	}
	return make_pair(a, b);
}
int main() {
	int cases;
	cin >> cases;
	for (int i = 0; i<cases; i++) {
		string a, b;
		cin >> a >> b;
		auto ret = getOLDResults(a, b);
		cout << "Case #" << i+1 << ": " << ret.first << " " << ret.second << endl; 
	}
}
