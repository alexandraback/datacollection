#include <iostream>
#include <fstream>
#include <list>
#include <string>
using namespace std;

int main() {
	ifstream in("A-large.in");
	cin.rdbuf(in.rdbuf());
	ofstream out("A-large.out");
	cout.rdbuf(out.rdbuf());
	// read
	int kase = 1, T;
	string s;
	cin >> T;
	while (T--) {
		cin >> s;
		list<char> v;
		int sz = s.size();
		v.push_front(s[0]);
		for (int i = 1; i < sz; ++i) {
			if (s[i] >= v.front()) v.push_front(s[i]);
			else v.push_back(s[i]);
		}
		cout << "Case #" << kase++ << ": ";
		for (int i = 0; i < sz; ++i) { cout << v.front(); v.pop_front();}
		cout << endl;
	}
}