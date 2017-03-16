#include <iostream>
#include <vector>
#include <string>
using namespace std;

string getResult(string& s) {
	string ret = "";
	for (int i = 0; i<s.size(); i++) {
		if (ret == "") ret.push_back(s[i]);
		else {
			if (s[i] > ret[0]) {
				string head; head.push_back(s[i]);
				ret = head + ret;
			} else if (s[i] < ret[0]) {
				ret.push_back(s[i]);
			} else {
				string head; head.push_back(s[i]);
				string s1 = head + ret;
				string s2 = ret; s2.push_back(s[i]);
				if (s1 < s2) {
					ret.push_back(s[i]);
				} else {
					string head; head.push_back(s[i]);
					ret = head + ret;
				}
			}
		}
	}
	return ret;
}
int main() {
	int cases;
	cin >> cases;
	for (int i = 0; i<cases; i++) {
		string input;
		cin >> input;
		cout << "Case #" << i+1 << ": " << getResult(input) << endl;
	}
}