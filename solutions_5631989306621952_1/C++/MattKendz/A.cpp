#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
using namespace std;

vector<string> sett;
void recur(string &s, int index, string copy) {
	if (index > s.length())
		return;
	if (index == s.length()) {
		sett.push_back(copy);
		return;
	}

	char c = s[index];
	recur(s, index + 1, copy + c);
	recur(s, index + 1, c + copy);
}

int main() {
	int n;
	cin >> n;
	string s;
	getline(cin, s);
	 
	for (int x = 1; x <= n; x++) {
		getline(cin, s);
		/*sett.clear();
		recur(s, 0, "");
		sort(sett.begin(), sett.end());
		cout << "Case #" << i << ": " << sett[sett.size() - 1] << endl;*/
		vector<char> v;
		v.push_back(s[0]);

		for (int j = 1; j < s.length(); j++) {
			if (s[j] >= v.front()) {
				vector<char>::iterator it = v.begin();
				v.insert(it, s[j]);
			}
			else v.push_back(s[j]);
		}

		string str = "";
		for (int i = 0; i < v.size(); i++)
			str += v[i];
		cout << "Case #" << x << ": " << str << endl;
	}
}